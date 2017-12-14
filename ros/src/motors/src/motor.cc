#include "motor.h"

Motor::Motor(int id): this->identifier(id), this->position(0){}

Motor::~Motor(){}

void Motor::sendData() const {
  //Send the position data to the motor through serial.
}
