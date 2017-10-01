#include "teleop/socket.h"

int port;
int serverFileDesc;
int socketFileDesc;
bool isConnected;
socklen_t clientAddrLen;
sockaddr_in serverAddr;

Socket::~Socket(){
    if(this -> isConnected){
        close(this -> socketFileDesc);
        close(this -> serverFileDesc);
    }
}

void Socket::connect(){
    this -> serverFileDesc = socket(AF_INET, SOCK_STREAM, 0);
    if(this -> serverFileDesc == 0){
        //failed to create the socket
    }

    int socketOptions = setsockopt(this -> serverFileDesc, SOL_SOCKET, SO_REUSEADDR |
        SO_REUSEPORT, &(this -> opt), sizeof(this -> opt));
    if(socketOptions){
        //Failed to set the socket's options
    }

    this -> serverAddr.sin_family = AF_INET;
    this -> serverAddr.sin_addr.s_addr = INADDR_ANY;
    this -> serverAddr.sin_port = htons(this -> port);

    int bind = bind(this -> serverFileDesc, (sockaddr *) &(this -> serverAddr),
        sizeof(this -> serverAddr));
    if(bind < 0){
        //this failed
    }

    if(listen(this -> serverFileDesc, 3) < 0){
        //Failed to allow the server to be open to connections
    }

    this -> socketFileDesc = accept(this -> serverFileDesc, (sockaddr *) &(this -> serverAddr), (socklen_t *) &(this -> clientAddrLen))
    if(this -> socketFileDesc < 0){
        //the accept line failed
    }

    //If it got this far then a connection has been established
    this -> isConnected = true;
}

bool Socket::isConnected(){
    return this -> isConnected;
}

void Socket::send(std::string &data){
    if(this -> isConnected)
        send(this -> socketFileDescriptor, data.c_str(), data.length(), 0)
}

std::string Socket::receive(){
    if(this -> isConnected){
        char buffer[4096] = {0};
        int amountRead = read(socketFileDesc, buffer, 4096);
        return std::string(buffer, amountRead);
    }else{
        return NULL;
    }
}