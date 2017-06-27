//Any ROS-created headers
#include "ros/ros.h"

//User-created headers
#include "hal/serial.h"
#include "hal/pwmhandler.h"

//All of the msgs
#include "hal/DigitalOutput.h"
#include "hal/DigitalInput.h"
#include "hal/AnalogInput.h"
#include "hal/PWM.h"

const char *GPIO_DEVICE = "/dev/ttyACM0"; //The GPIO expansion device path
const int NUM_PINS = 16;

SerialDevice gpio(GPIO_DEVICE);
PWMHandler handler(gpio);

bool pwmHandler(PWM::Request &request, PWM::Response &response){
  //The response here is empty
  if(request.pin < 0 || request.pin > NUM_PINS){
    ROS_INFO("Invalid pin for PWM: %i", request.pin);
    return false;
  }
  ROS_INFO("PWM Request: %i @ pin %i", request.value, request.pin);
  
  int32_t pin   = request.pin;
  uint8_t value = request.value;
  handler.pwm(pin, value);
}

int main(int argc, char **argv){
  ros::init(argc, argv, "hal");
  ros::NodeHandler handler;
  
  ros::Rate loopTimer(15);
  while(ros::ok()){
    loopTimer.sleep();
  }
}
