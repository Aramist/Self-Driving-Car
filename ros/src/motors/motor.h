#ifndef MOTORS_MOTOR_H
#define MOTORS_MOTOR_H

#include <serial.h>
#include <string>

class Motor{
    private:
        const static std::string port = "arduino_serial_port" //TODO: set udev rules
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