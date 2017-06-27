#ifndef GOLFCART_HAL_PWMHANDLER_H
#define GOLFCART_HAL_PWMHANDLER_H

#include "serial.h"

class PWMHandler{
  private:
    SerialDevice *device;
  public:
    PWMHandler(SerialDevice *serialDevice);
    ~PWMHandler();
    void pwm(int pin, uint8_t value);
};

#endif
