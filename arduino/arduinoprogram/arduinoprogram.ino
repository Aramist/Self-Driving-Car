#include <Servo.h>

/**
*   This is the program that runs on the arduino.
*   It handles the gathering of data from ultrasonic sensors,
*   controlling of motors, and transmission of the data to the
*   Jetson TX1
*/

const boolean DEBUG = 0;

/**
*   Equivalent to the Arduino Standard Library's map function, but isn't limited to integers
*   value: the original value, doesn't have to be within the range [fromMin, fromMax)
*   fromMin / fromMax: The original range of the value
*   toMin / toMax: The new range of the value
*   returns: the value mapped from the old range to the new range. Doesn't modify the given value
*/
double doubleMap(double value, double fromMin, double fromMax, double toMin, double toMax){
    //1: Subtract fromMin from value.   [fromMin, fromMax) -> [0, fromMax - fromMin) == [0, fromRange)
    //2: Divide by fromRange.   [0, fromRange) -> [0, 1)
    //3: Multiply by toRange.   [0, 1) -> [0, toRange] == [0, toMax - toMin)
    //4: Add toMin.   [0, toMax - toMin) -> [toMin, toMax)
    return (value - fromMin) * (toMax - toMin) / (fromMax - fromMin) + toMin;
}


/*Input:
*   All input will be in the following form:
*   0: A char siginifying the beginning of an input
*   1: 
*   2: A char holding data for the input (motor position)
*   3: A char signifying the end of an input
*   If 100ms has passed since the last input was received,
*   the brakes will be applied. This makes the assumption
*   that the connection has been severed or the program has
*   halted.
*/

unsigned long firstInputReceived = 0; //Timestamp of the first input received. A safety feature
unsigned long lastInputReceived = 0; //Timestamp of the last input received. A safety feature
const char INPUT_BEGIN_CHAR = '\x02'; //The character signifying the beginning of an input
const char INPUT_END_CHAR = '\x04'; //The character signifying the end of an input
char input[4] = {0, 0, 0, 0};
int inputIndex = 0;

void doInput(){
    while(Serial.available > 0){
        //Read from serial input when possible
        input[inputIndex++] = Serial.read();
        if(firstInputReceived == 0) firstInputReceived = millis();
        lastInputReceived = millis();
        if(inputIndex > 3) break;
    }
    
    //Check to see if all input has been received
    if(input[0] == INPUT_BEGIN_CHAR && input[3] == INPUT_END_CHAR){
        int a = (int) input[2]; //Convert the data from a char to an int
        int id = (int) input[1];
        double percent = a / 127.0; //Convert it to a percent by dividing by 128
        motor(id, percent);
        //Reset all values to their original state
        inputIndex = 0;
        input[0] = '\x00';
        input[1] = '\x00';
        input[2] = '\x00';
        input[3] = '\x00';
    }else if((input[0] == '\x00' || input[4] == '\x00') && inputIndex < 4){
        //The input is not yet complete
        return;
    }else{
        //The input was either improperly formed or corrupt. panic?
        inputIndex = 0;
        input[0] = '\x00';
        input[1] = '\x00';
        input[2] = '\x00';
        input[3] = '\x00';
        brake(); //TODO: Activate Brakes
    }
}

/**Motors:
*   This part controls motors
*/

//Servo objects to control the motors
Servo gasMotor;
Servo brakeMotor;

//Constants allowing the use of Servo objects
const int MIN = 6;
const int MID = 91;
const int MAX = 180;

//PD control loop Constants
const double GAS_P_CONSTANT = 0.1;
const double GAS_D_CONSTANT = 0.3;
const double BRAKE_P_CONSTANT = 0.1;
const double BRAKE_D_CONSTANT = 0.3;

//Measured potentiometer constants
const int gasPotentiometerStartValue = 0;
const int gasPotentiometerStopValue = 400;
const int brakePotentiometerStartValue = 0;
const int brakePotentiometerStopValue = 600;

//Setpoints
int gasSetpoint = 0;
int brakeSetpoint = 0;

int getGasPotentiometer(){return analogRead(gasPotentiometerPin);}
int getBrakePotentiometer(){return analogRead(brakePotentiometerPin);}

void motors(int id, double percent){
    if(id == 0){ //ID of 0: gas actuator
        gasSetpoint = (int)doubleMap(percent, 0.0, 1.0, gasPotentiometerStartValue, gasPotentiometerStopValue);
    }else if(id == 1){ //ID of 1: brake actuator
        brakeSetpoint = (int)doubleMap(percent, 0.0, 1.0, brakePotentiometerStartValue, brakePotentiometerStopValue);
    }
}

void updateMotors(){
    gasMotor.write(calculateGasPD());
    brakeMotor.write(calculateBrakePD());
}

/**
*   This function converts a motor speed percentage to a degree to write to a servo object
*   percent: The percentage measure of the motor's desired speed. Range: [-1, 1]
*/
int percentToServoTiming(double percent){
    double constraint = percent < -1.0 ? -1.0 : (percent > 1.0 ? 1.0 : percent); //Sets the value of percent to -1.0 or 1.0 if it is out of range
    if(constraint < -1e-4){
        return (int)doubleMap(constraint, -1.0, 0.0, MIN, MID);
    }else if(constraint <= 1e-4){
        return MID;
    }else{
        return (int)doubleMap(constraint, 0.0, 1.0, MID, MAX);//Double map is used here because without it, the input (between 0 and 1) would be coerced to 0.
    }
}

int lastGasPotentiometerError = 0;
int lastGasPotentiometerErrorTimestamp = millis();

double calculateGasPD(){
    int current = getGasPotentiometer(); //Current measured gas potentiometer value
    double error = (double)(current - gasSetpoint);
    double pCorrection = error * GAS_P_CONSTANT;
    double derivative = (double)(error - lastGasPotentiometerError) / (double)(millis() - lastGasPotentiometerErrorTimestamp); //de(t) / dt
    double dCorrection = derivative * GAS_D_CONSTANT;
    lastGasPotentiometerError = error;
    lastGasPotentiometerErrorTimestamp = millis();
    return pCorrection + dCorrection;
}


int lastBrakePotentiometerError = 0;
int lastBrakePotentiometerErrorTimestamp = millis();

double calculateBrakePD(){
    int current = getBrakePotentiometer(); //Current measured gas potentiometer value
    double error = (double)(current - brakeSetpoint);
    double pCorrection = error * BRAKE_P_CONSTANT;
    double derivative = (double)(error - lastBrakePotentiometerError) / (double)(millis() - lastBrakePotentiometerErrorTimestamp); //de(t) / dt
    double dCorrection = derivative * BRAKE_D_CONSTANT;
    lastBrakePotentiometerError = error;
    lastBrakePotentiometerErrorTimestamp = millis();
    return pCorrection + dCorrection;
}

void setup(){
    Serial.begin(115200); //Highest supported baudrate on an Arduino
    gasMotor.attach(9);
    brakeMotor.attach(10);
    while(!Serial); //Wait here until a serial connection has been established
}

boolean programHalted = false;
void loop(){
    if(millis() - lastInputReceived >= 100){
        //More than 100ms has passed since the last input. 
        motor(0, 0); //set the gas to 0
        motor(1, 0.5); //turn on the brakes
        programHalted = true;
    }
    if(!programHalted){
        doInput();
        updateMotors();
    }else{
        updateMotors();
    }
}