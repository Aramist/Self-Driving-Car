#ifndef MOTOR_H
#define MOTOR_H

class Motor{
public:
  int position;
  int identifier;
  Motor(int id);
  ~Motor();
  void sendData() const;
};
#endif
