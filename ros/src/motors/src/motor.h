#ifndef MOTORS_MOTOR_H
#define MOTORS_MOTOR_H

#include <serial/serial.h>
#include <sstream>
#include <string>

class Motor{
    private:
        static serial::Serial arduinoSerial;
        int motorId;
        int currentSetpoint;
    public:
        Motor(int MotorId);
        ~Motor();
        void set(int position);
        int getSetpoint();
};

#endif //MOTORS_MOTOR_H