#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include "Arduino.h"

class MotorControl {
public:
	MotorControl(float pinNumA, float pinNumB);
	void set(float speed);
private:
	float _pinNumA;
	float _pinNumB;
};

#endif