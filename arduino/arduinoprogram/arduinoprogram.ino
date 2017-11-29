#include <Servo.h>

/**
*   This is the program that runs on the arduino.
*   It handles the gathering of data from ultrasonic sensors,
*   controlling of motors, and transmission of the data to the
*   Jetson TX1
*/

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
*   0: A char siginifying the beginning and type of input (gas vs brake)
*   1: A char holding data for the input (motor position)
*   If 100ms has passed since the last input was received,
*   the brakes will be applied. This makes the assumption
*   that the connection has been severed or the program has
*   halted.
*/

unsigned long firstInputReceived = 0; //Timestamp of the first input received. A safety feature
unsigned long lastInputReceived = 0; //Timestamp of the last input received. A safety feature
const byte GAS_BEGIN_BYTE = 0xFF; //The character signifying gas input
const byte BRAKE_BEGIN_BYTE = 0xFE; //The character signifying brake input

void doInput(){
	if(Serial.available() < 2)
		return; //No complete input is available, return here to avoid hanging the program on Serial.read()

	byte firstByte = 0;	//The first byte of this set of input
	byte secondByte = 0; //The second byte of this set of input
	Serial.readBytes(&firstByte, 1); //Read from Serial.
	//Do not read the second byte until it is known that the first byte is OK

	if(firstByte == GAS_BEGIN_BYTE){
		//The second byte represents a position for the gas actuator
		Serial.readBytes(&secondByte, 1);
		motors(0, secondByte / 127.0);
	}else if(firstByte == BRAKE_BEGIN_BYTE){
		//The second byte represents a position for the brake actuator
		Serial.readBytes(&secondByte, 1);
		motors(1, secondByte / 127.0);
	}else{
		//Something broke
	}
}

/**Motors:
*   This part controls motors
*/

//Servo objects to control the motors
Servo gasMotor;
Servo brakeMotor;

//Constant pin numbers
const int gasPotentiometerPin = A0;
const int brakePotentiometerPin = A1;

//Constants describing the upper, mid, and lower range of speed controller input
const int MIN = 1000;
const int MID = 1500;
const int MAX = 2000;

//PD control loop Constants
const double GAS_P_CONSTANT = 0.3;
const double GAS_D_CONSTANT = 0.6;
const double BRAKE_P_CONSTANT = 0.3;
const double BRAKE_D_CONSTANT = 0.6;

//Measured potentiometer constants
//These must be manually measured
const int gasPotentiometerStartValue = 40;
const int gasPotentiometerStopValue = 400;
const int brakePotentiometerStartValue = 60;
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
    int calcGas = calculateGasPD();
    int calcBrake = calculateBrakePD();
    gasMotor.write(calculateGasPD());
    brakeMotor.write(calculateBrakePD());
    Serial.print(calcBrake);
    Serial.print(" | ");
    Serial.println(calcGas);
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
    if(millis() - lastInputReceived >= 100 && firstInputReceived != 0){
        //More than 100ms has passed since the last input. 
        motors(0, 0); //set the gas to 0
        motors(1, 0.5); //turn on the brakes
        programHalted = true;
    }
    if(!programHalted){
        doInput();
        updateMotors();
    }else{
        updateMotors();
    }
}
