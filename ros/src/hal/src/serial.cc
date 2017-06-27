#include "serial.h"
#include <stdexcept>

SerialDevice::SerialDevice(const char *filePath): path(filePath){
  this->fileDescriptor = open(this->path, SerialDevice::OPEN_FLAG);
  if(this->fileDescriptor == -1){
    throw std::runtime_error("Could not construct SerialDevice, error opening"
    + " file.");
  }
}

SerialDevice::SerialDevice(const std::string filePath){
  this->path = filePath.c_str();
  this-fileDescriptor = open(this->path, SerialDevice::OPEN_FLAG);
  if(this->fileDescriptor == -1){
    throw std::runtime_error("Could not construct SerialDevice, error opening"
    + " file.");
  }
}

SerialDevice::~SerialDevice(){
  close(this->fileDescriptor);
}

void SerialDevice::write(const char *buffer, int length){
  write(this->fileDescriptor, buffer, length);
}

void SerialDevice::write(const std::string buffer){
  write(this->fileDescriptor, buffer.c_str(), buffer.length());
}

void SerialDevice::read(char *buffer, int length){
  int response = read(this->fileDescriptor, buffer, length);
  if(response == -1){
    throw std::runtime_error("Error reading from file");
  }
}
