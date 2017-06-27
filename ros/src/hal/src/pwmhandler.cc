//implemented header file
#include "hal/pwmhandler.h"

//standard libraries
#include <future>
#include <time>
#include <thread>

//user defined headers
#include "hal/serial.h"

const int NUM_PINS = 16;
const double PWM_PERIOD = 3.0; //milliseconds

double pinDuties[NUM_PINS];
std::packaged_task<void> tasks[NUM_PINS];

PWMHandler::PWMHandler(SerialDevice *serialDevice): device(serialDevice){}
PWMHandler::~PWMHandler(){}
void PWMHandler::pwm(int pin, uint8_t value){
  double duty = PWM_PERIOD * value / 255.0;
  pinDuties[pin] = duty;
  std::packages_task<void> pinTask(task(pin));
  tasks[pin] = pinTask;
  std::thread(std::move(task)).detach();
}

void task(int pin){

}
