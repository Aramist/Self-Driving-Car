#include "motor.h"
#include <iomanip>
#include <sstream>
#include <serial.h>

static int SIGNAL_MIN = 5;
static int SIGNAL_MID = 90;
static int SIGNAL_MAX = 175;

serial::Serial Motor::arduinoSerial = serial::Serial(Motor::port, 115200, serial::Timeout::simpleTimeout(100))
Motor::Motor(int pwmID){
    this->motorPwmId = pwmID;
    this->currentSpeed = 0;
}
Motor::~Motor(){}
void Motor::set(int speed){
    //limit the range of speed to [-100, 100]
    speed = speed < -100 ? -100 : (speed > 100 ? 100 : speed);
    this->currentSpeed = speed;
    //map the range of speed to [-1, 1)
    double mapped = speed / 100.0;
    //when negative, map the value of mapped from [-1, 0) to [MIN, MID)
    //when approx 0, set the value of mapped to MID
    //when positive, map the value of mapped from (0, 1] to (MID, MAX]
    if(mapped < 0){
        mapped = (mapped + 1) * (MID - MIN) + MIN;
    }else if (mapped > -1e3 && mapped < 1e3){
        mapped = MID;
    }else{
        mapped = mapped * (MAX - MID) + MID;
    }
    int floored = static_cast<int>(mapped);
    //Create an istringstream for formatting the number
    std::ostringstream format;
    //Set the width to 3 and use '0' as the fill character
    format << std::setw(3) << std::setfill('0') << floored;
    Motor::arduinoSerial.write(format);
}
int Motor::get(){
    return this->currentSpeed;
}