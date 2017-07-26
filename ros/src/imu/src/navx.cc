#include <chrono>
#include <string>
#include <thread>

#include <ros/ros.h>
#include <ros/time.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Vector3.h>
#include <sensor_msgs/Imu.h>
#include <std_msgs/Header.h>

#include "navxlib/AHRS.h"

int main(int argc, char **argv){
    AHRS navx("/dev/ttyACM0");
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    ros::init(argc, argv, "navx");
    ros::NodeHandle n;
    ros::Publisher imuPublisher = n.advertise<sensor_msgs::Imu>("navx_imu", 150);
    uint32_t count = 0;
    ros::Rate timer(15);
    std::string global_frame("0");
    double noCovariance[] = new double[9];
    while (ros::ok()){
        std_msgs::Header header;
        geometry_msgs::Quaternion orientation;
        geometry_msgs::Vector3 acceleration;
        geometry_msgs::Vector3 rotationRate;
        sensor_msgs::Imu message;
        header.seq = count++;
        header.stamp = ros::Time::now();
        header.frame_id = global_frame;
        acceleration.x = navx.GetWorldLinearAccelX;
        acceleration.y = navx.GetWorldLinearAccelY;
        acceleration.z = navx.GetWorldLinearAccelZ;
        rotationRate.x = navx.GetRawGyroX;
        rotationRate.y = navx.GetRawGyroY;
        rotationRate.z = navx.GetRawGyroZ;
        orientation.x = navx.GetQuaternionX;
        orientation.y = navx.GetQuaternionY;
        orientation.z = navx.GetQuaternionZ;
        orientation.w = navx.GetQuaternionW;
        message.header = header;
        message.orientation = orientation;
        message.orientation_covariance = noCovariance;
        message.angular_velocity = rotationRate;
        message.angular_velocity_covariance = noCovariance;
        message.linear_acceleration = acceleration;
        message.linear_acceleration_covariance = noCovariance;
        imuPublisher.publish(message);
        timer.sleep();
    }
}