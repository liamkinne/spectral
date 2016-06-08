#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include "Arduino.h"

class MotorControl {
public:
	MotorControl(int pinNumA, int pinNumB);
	void set(float speed);
private:
	int _pinNumA;
	int _pinNumB;
};

#endif