#include "Arduino.h"
#include "DualMotorControl.h"

DualMotorControl::DualMotorControl(int pinNumLeftA, int pinNumLeftB, int pinNumRightA, int pinNumRightB) {
	// Set pin mode to output
	pinMode(pinNumLeftA, OUTPUT);
	pinMode(pinNumLeftB, OUTPUT);
	pinMode(pinNumRightA, OUTPUT);
	pinMode(pinNumRightB, OUTPUT);

	// Set PinNums to private variables
	_pinNumLeftA = pinNumLeftA;
	_pinNumLeftB = pinNumLeftB;
	_pinNumRightA = pinNumRightA;
	_pinNumRightB = pinNumRightB;
}

void DualMotorControl::left(float speed) {
	// Use set function
	set(speed, _pinNumLeftA, _pinNumLeftB);
}

void DualMotorControl::right(float speed) {
	// Use set function
	set(speed, _pinNumRightA, _pinNumRightB);
}

void DualMotorControl::tank(float left_speed, float right_speed) {
	// Use Left and Right functions
	left(left_speed);
	right(right_speed);
}

void DualMotorControl::set(float speed, int pinA, int pinB) {
	// Convert to 8 bit decimal
	speed *= 255;

	// Set pin output
	if (speed >= 0) {
    	analogWrite(pinA, speed);
    	digitalWrite(pinB, LOW);
  	}
  	else {
    	analogWrite(pinA, LOW);
    	digitalWrite(pinB, abs(speed)); // Absolute speed, no negatives!
  	}
}

