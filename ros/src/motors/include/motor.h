#ifndef MOTOR_H
#define MOTOR_H

class Motor{
public:
	int position;
	int identifier;
	Motor(int id);
	void sendData() const;

};

#endif
