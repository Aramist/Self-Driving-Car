#include "imu/navx.h"
#include <chrono>
#include <thread>
#include <ros/ros.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Vector3.h>
#include <sensor_msgs/Imu.h>
#include <std_msgs/Header.h>
#include "AHRS.h"

int main(int argc, char **argv){
    AHRS navx("/dev/ttyACM0");
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    ros::init(argc, argv, "navx");
    ros::NodeHandle n;
    ros::Publisher imuPublisher = n.advertise<sensor_msgs::Imu>("navx_imu", 150);
    uint32_t count = 0;
    ros::Rate timer(15);
    //Pre allocated objects:
    geometry_msgs::Quaternion orientation;
    geometry_msgs::Vector3 acceleration;
    geometry_msgs::Vector3 rotationRate;
    double noCovariance[] = new double[9];
    while (ros::ok()){
        sensor_msgs::Imu message;
        message.angular_velocity_covariance = noCovariance;
        message.linear_acceleration_covariance = noCovariance;
        acceleration.x = 
        timer.sleep();
    }
}