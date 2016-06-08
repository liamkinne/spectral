#include "Arduino.h"
#include "MotorControl.h"

MotorControl::MotorControl(int pinNumA, int pinNumB) {
	// Set pin mode to output
	pinMode(pinNumA, OUTPUT);
	pinMode(pinNumB, OUTPUT);

	// Set PinNums to private variables
	_pinNumA = pinNumA;
	_pinNumB = pinNumB;
}

void MotorControl::set(float speed) {
	// Convert to 8 bit decimal
	speed *= 255;

	// Set pin output
	if (speed >= 0) {
    	analogWrite(_pinNumA, speed);
    	digitalWrite(_pinNumB, LOW);
  	}
  	else {
    	analogWrite(_pinNumA, LOW);
    	digitalWrite(_pinNumB, abs(speed)); // Absolute speed, no negatives!
  	}
}

