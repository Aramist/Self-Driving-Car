#include "ros/ros.h"
#include "hal/DigitalOutput.h"
#include "hal/DigitalInput.h"
#include "hal/AnalogInput.h"
#include "hal/PWM.h"

bool pwmHandler(PWM::Request &request, PWM::Response &response){
  //The response here is empty
  ROS_INFO("PWM Request: %i @ pin %i", request.value, request.pin);
}

int main(int argc, char **argv){
  ros::init(argc, argv, "hal");
  ros::NodeHandler handler;
  
  ros::Rate loopTimer(15);
  while(ros::ok()){
    loopTimer.sleep();
  }
}
