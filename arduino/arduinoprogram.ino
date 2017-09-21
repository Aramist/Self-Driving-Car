/**
*   This is the program that runs on the arduino.
*   It handles the gathering of data from ultrasonic sensors,
*   controlling of motors, and transmission of the data to the
*   Jetson TX1
*/

long long int timeSinceProgramStart = 0; //A clock, unit: millisecond

/*Input:
*   All input will be in the following form:
*   0: A char siginifying the beginning of an input
*   1: A char holding data for the input (motor position)
*   2: A char signifying the end of an input
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
        input[inputIndex++] = Serial.read();
        if(firstInputReceived == 0) firstInputReceived = millis();
        lastInputReceived = millis();
        if(inputIndex > 3) break;
    }
    
    //Check to see if all input has been received
    if(input[0] == INPUT_BEGIN_CHAR && input[3] == INPUT_END_CHAR){
        int a = (int) input[1]; //Convert the data from a char to an int
        int id = (int) input[2];
        double percent = a / 127.0; //Convert it to a percent by dividing by 128
        motor(id, percent);
        //Reset all values to their original state
        inputIndex = 0;
        input[0] = '\x00';
        input[1] = '\x00';
        input[2] = '\x00';
        input[3] = '\x00';
    }else if(input[0] == '\x00' || input[4] == '\x00'){
        //The input is not yet complete
        return;
    }else{
        //The input was either improperly formed or corrupt. panic?
        brake(); //TODO: Activate Brakes
    }
}

void readPotentiometers(){}

void setup(){
    Serial.begin(115200); //Highest supported baudrate on an Arduino
    while(!Serial); //Wait here until a serial connection has been established
}