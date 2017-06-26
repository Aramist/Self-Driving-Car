#ifndef GOLFCART_HAL_SERIAL_H
#define GOLFCART_HAL_SERIAL_H
#include <fcntl.h>
#include <string>

class SerialDevice{
  private:
    const char *path;
    int fileDescriptor;
  public:
    SerialDevice(const char *filePath);
    SerialDevice(const std::string filePath);
    ~SerialDevice();
    void write(const char *buffer, int length);
    void write(const std::string buffer);
    void read(char *buffer, int numBytes);
    static int OPEN_FLAG = O_RDWR;
};
#endif
