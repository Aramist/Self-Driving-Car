#include "ros/ros.h"
#include "sensor_msgs/Imu.h"

ros::Subscriber imuSubscriber;

void navxCallback(const sensor_msgs::Imu::ConstPtr &msg){
    //TODO: Send this data
}

int main(int argc, char **argv){
    ros::init(argc, argv, "teleop");
    ros::NodeHandle node;
    imuSubscriber = node.subscribe("navx_imu", 10, navxCallback);
}