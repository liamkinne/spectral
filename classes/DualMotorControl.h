#ifndef DUALMOTORCONTROL_H
#define DUALMOTORCONTROL_H

#include "Arduino.h"

class DualMotorControl {
public:
	DualMotorControl(int pinNumLeftA, int pinNumLeftB, int pinNumRightA, int pinNumRightB);
	void set(float speed, int pinA, int pinB);
	void left(float speed);
	void right(float speed);
	void tank(float left_speed, float right_speed);
private:
	int _pinNumLeftA;
	int _pinNumLeftB;
	int _pinNumRightA;
	int _pinNumRightB;
};

#endif