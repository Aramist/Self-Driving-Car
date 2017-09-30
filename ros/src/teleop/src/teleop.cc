#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <iostream>
#include <string>
#include "ros/ros.h"
#include "sensor_msgs/Imu.h"

bool connectionExists = false;
int serverFileDescriptor, newSocketFileDescriptor, portNumber, clientAddressLength;
int opt = 1;
char buffer[1024] = {0};
struct sockaddr_in serverAddress;

ros::Subscriber imuSubscriber;
ros::Subscriber gnssSubscriber;
ros::Subscriber lidarSubscriber;

struct imu_data{
    double ax,ay,az; //Acceleration x, y, and z
    double ox,oy,oz; //Angular vel. about x, y, and z
};

imu_data lastImuReading;

void navxCallback(const sensor_msgs::Imu::ConstPtr& msg){
    lastImuReading.ax = msg -> linear_acceleration.x;
    lastImuReading.ay = msg -> linear_acceleration.y;
    lastImuReading.az = msg -> linear_acceleration.z;
    lastImuReading.ox = msg -> angular_velocity.x;
    lastImuReading.oy = msg -> angular_velocity.y;
    lastImuReading.oz = msg -> angular_velocity.z;
}

int read(){
    return read(newSocketFileDescriptor, buffer, 1024);
}

void write(std::string &toWrite){
    send(newSocketFileDescriptor, toWrite.c_str(), toWrite.length(), 0);
}

void *readLoop(void *threadArguments){
    ros::Rate readTimer(100);
    while(ros::ok()){
        if(connectionExists){
            int numChars = read();
            if(numChars < 1) continue;
            std::string stringRead(buffer, numChars);
            std::cout << stringRead << std::endl;
        }
        readTimer.sleep();
    }
    pthread_exit(NULL);
}

void writeData(){
    if(connectionExists){
        char writeBuffer[512] = {0};
        snprintf(writeBuffer, 512, "{\"type\":\"imu\",\"%s\":%f,\"%s\":%f,\"%s\":%f,\"%s\":%f,\"%s\":%f,\"%s\":%f}",
                "ax", lastImuReading.ax, "ay", lastImuReading.ay, "az", lastImuReading.az, "ox", lastImuReading.ox,
                "oy", lastImuReading.oy, "oz", lastImuReading.oz);
        write(newSocketFileDescriptor, writeBuffer, 512);
    }
}

void mainLogic(){
    std::cout << lastImuReading.ax << std::endl;
    writeData();
    ros::spinOnce();
}

void establishConnection(){
    serverFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if(serverFileDescriptor == 0){
        perror("Failed to create a socket.");
        return;
    }

    if(setsockopt(serverFileDescriptor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        return;
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8080);

    if( bind(serverFileDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0 ){
        perror("Failed to bind");
        return;
    }

    if(listen(serverFileDescriptor, 3) < 0){
        perror("Failed to listen");
        return;
    }

    newSocketFileDescriptor = accept(serverFileDescriptor, (struct sockaddr *)&serverAddress, (socklen_t*)&clientAddressLength);

    if( newSocketFileDescriptor < 0 ){
        perror("Failed to accept");
        return;
    }
    std::cout << "Successfully established a connection" << std::endl;
    connectionExists = true;
}

int main(int argc, char **argv){
    ros::init(argc, argv, "Teleop");
    ros::NodeHandle node;
    imuSubscriber = node.subscribe("navx_imu", 30, navxCallback);
    //gnssSubscriber = node.subscribe("swiftnav_gnss", 20, gnssCallback);
    //lidarSubscriber = node.subscribe("sick_lidar", 10, lidarCallback);
    
    try{
        std::cout << "Attempting to establish a connection" << std::endl;
        establishConnection();
    } catch(const char* msg){
        std::cout << "Failed to establish a connection" << std::endl << msg << std::endl;
        connectionExists = false;
    }

    pthread_t readThread;
    pthread_create(&readThread, NULL, readLoop, NULL);

    ros::Rate mainLogicTimer(10);

    while(ros::ok()){
        if(!connectionExists)
            try{
                std::cout << "Attempting to establish a connection" << std::endl;
                establishConnection();
            }catch(const char* msg){
                std::cout << "Failed to establish a connection" << std::endl << msg << std::endl;
            }
        mainLogic();
        mainLogicTimer.sleep();
    }
    pthread_exit(NULL);
    return 0;
}