#ifndef MOTORS_MOTOR_H
#define MOTORS_MOTOR_H

#include <serial.h>
#include <string>

class Motor{
    private:
        static serial::Serial arduinoSerial;
        int motorPwmId;
        int currentSpeed;
    public:
        Motor(int pwmID);
        ~Motor();
        void set(int speed);
        int get();
};

#endif //MOTORS_MOTOR_H