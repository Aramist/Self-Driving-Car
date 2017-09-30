#include <chrono>
#include <string>
#include <thread>

#include "ros/ros.h"
//#include "ros/time.h" included in ros/ros.h
#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/Vector3.h"
#include "sensor_msgs/Imu.h"
#include "std_msgs/Header.h"

#include "navxlib/AHRS.h"

int main(int argc, char **argv){
    AHRS navx("/dev/navx");
    usleep(1000 * 1500);
    ros::init(argc, argv, "navx");
    ros::NodeHandle n;
    ros::Publisher imuPublisher = n.advertise<sensor_msgs::Imu>("navx_imu", 150);
    uint32_t count = 0;
    ros::Rate timer(15);
    std::string global_frame("0");
    double noCovariance[9];
    while (ros::ok()){
        std_msgs::Header header;
        geometry_msgs::Quaternion orientation;
        geometry_msgs::Vector3 acceleration;
        geometry_msgs::Vector3 rotationRate;
        sensor_msgs::Imu message;
        header.seq = count++;
        header.stamp = ros::Time::now();
        header.frame_id = global_frame;
        acceleration.x = static_cast<double>(navx.GetWorldLinearAccelX());
        acceleration.y = static_cast<double>(navx.GetWorldLinearAccelY());
        acceleration.z = static_cast<double>(navx.GetWorldLinearAccelZ());
        // rotationRate.x = static_cast<double>(navx.GetRawGyroX());
        // rotationRate.y = static_cast<double>(navx.GetRawGyroY());
        // rotationRate.z = static_cast<double>(navx.GetRawGyroZ());
        rotationRate.x = static_cast<double>(navx.GetPitch());
        rotationRate.y = static_cast<double>(navx.GetRoll());
        rotationRate.z = static_cast<double>(navx.GetYaw());
        orientation.x = static_cast<double>(navx.GetQuaternionX());
        orientation.y = static_cast<double>(navx.GetQuaternionY());
        orientation.z = static_cast<double>(navx.GetQuaternionZ());
        orientation.w = static_cast<double>(navx.GetQuaternionW());
        message.header = header;
        message.orientation = orientation;
        // message.orientation_covariance = noCovariance;
        message.angular_velocity = rotationRate;
        // message.angular_velocity_covariance = noCovariance;
        message.linear_acceleration = acceleration;
        // message.linear_acceleration_covariance = noCovariance;
        imuPublisher.publish(message);
        ros::spinOnce();
        timer.sleep();
    }
}