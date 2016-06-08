#ifndef ULTRASONICSENSE_H
#define ULTRASONICSENSE_H

#include "Arduino.h"

class UltrasonicSense {
public:
	UltrasonicSense(int pingPin);
	int getCM();
	int getMM();
	int getRawMicroSec();
private:
	int _pingPin;
};

#endif