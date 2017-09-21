#include <serial.h>
#include "motor.h"
#include <ros/ros.h>
#include <ros/time.h>

//TODO: Rename this package to hardwareinterface

/**Ultrasonic sensor 0: UM30-214111
*   Range: 0.350m - 3.40m
*   Switching Frequency: 4Hz
*   Response Time: 180ms
*   Output Time: 43 ms
*/
uint32_t ultrasonic0Counter = 0; //A running total of the number of readings taken of this sensor
const float ultrasonic0FOV; //This sensor's field of view
const float ultrasonic0MinRange = 0.350; //The minimum range of this ultrasonic sensor in meters
const float ultrasonic0MaxRange = 3.500; //The maximum range of this ultrasonic sensor in meters
const std::string global_frame("0"); //constant string representing the global frame. will be changed later
double ultrasonic0ReportedRange = -1.0; //Latest range reported by Arduino
long int ultrasonic0ReportedTimestamp = 0; //Timestamp for latest reported range

const serial::Serial Motor::arduinoSerial = serial::Serial(Motor::port,
     115200, serial::Timeout::simpleTimeout(100))

int main(int argc, char **argv){
    ros::init(argc, argv, "HardwareInterface");
    ros::NodeHandle node;
    ros::Publisher ultrasonicPublisher = node.advertise<sensor_msgs::Range>("ultrasonic_0", 50);
    
    ros::Rate timer(15);
    while(ros::ok()){
        timer.sleep();
    }
}

void readUltrasonic0(uint32_t &counter){
    std_msgs::Header header;
    sensor_msgs::Range message;
    header.seq = ultrasonic0Counter;
    header.stamp = ros::Time::now();
    header.frame_id = global_frame;

    message.header = header;
    message.field_of_view = ultrasonic0FOV;
    message.min_range = ultrasonic0MinRange;
    message.max_range = ultrasonic0MaxRange;
    //message.range = 
    //TODO: read ultrasonic range from serial

}