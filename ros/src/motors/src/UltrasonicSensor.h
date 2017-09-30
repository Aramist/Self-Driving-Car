#ifndef ULTRASONICSENSOR_H_
#define ULTRASONICSENSOR_H_

class UltrasonicSensor {
private:
	int sensorPin; //Microcontroller port that the sensor is attached to
	int voltage;
public:
	UltrasonicSensor(int pin);
	virtual ~UltrasonicSensor();
	double getDistance(); //Returns distance from 350 millimeters to 5000 millimeters
	int getVoltage(); //Returns 0 - 5V
};

#endif /* ULTRASONICSENSOR_H_ */
