#include "motor.h"

Motor::Motor(int motorId){
    this->motorId = motorId;
    this->currentSetpoint = 0;
}

Motor::~Motor(){}

void Motor::set(int position){
    //Arduino expects four characters (bytes) of input for one command
    //first byte: \x02. this signifies the start of the input
    //second byte: an id, either 0 (\x30) or 1 (\x31). 0 for gas, 1 for brake
    //third byte: a data value, ranges from 0x00 to 0x7F (127)
    //fourth byte: \x04. this signifies the end of the input

    std::ostringstream output;

    output << "\x02"; //Starting byte
    output << (char)(this->motorId + 48); //Id byte
    output << (char)(position > 127 ? 127 : (position < 0 ? 0 : position)) //Data byte
    output << "\x04"; //Starting byte

    Motor::arduinoSerial.write(format);
}

int Motor::getSetpoint(){
    return this->currentSetpoint;
}
