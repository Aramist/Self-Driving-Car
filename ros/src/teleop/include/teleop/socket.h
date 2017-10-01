#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <iostream>
#include <string>
#include "ros/ros.h"

class Socket{
private:
    int port;
    int serverFileDesc;
    int socketFileDesc;
    bool isConnected;
    socklen_t clientAddrLen;
    sockaddr_in serverAddr;
public:
    Socket(int port): port(port), isConnected(false), serverFileDesc(0),
                      socketFileDesc(0);
    ~Socket();
    void connect();
    bool isConnected();
    void send(std::string &data);
    std::string receive();
};