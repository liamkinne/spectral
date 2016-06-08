#include "Arduino.h"
#include "UltrasonicSense.h"


UltrasonicSense::UltrasonicSense(int pingPin) {
	_pingPin = pingPin;
}

int UltrasonicSense::getCM() {
	return getRawMicroSec() / 58;
}

int UltrasonicSense::getMM() {
	return getRawMicroSec() / 5.8;
}

int UltrasonicSense::getRawMicroSec() {
	digitalWrite(_pingPin, LOW);                // Set the trigger pingPin to low for 2uS
  	delayMicroseconds(2);
  	digitalWrite(_pingPin, HIGH);               // Send a 10uS high to trigger ranging
  	delayMicroseconds(10);
	digitalWrite(_pingPin, LOW);                // Send pingPin low again
	int pulse = pulseIn(_pingPin, HIGH);        // Read Pulse
	return pulse;							// Return Pulse Length
}