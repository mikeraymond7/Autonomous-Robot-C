#include "MotorHat.h" // includes PWM.h
#include "PWM.h"
#include <stdio.h>
// Functions for DCMotor

DCMotor init_DCMotor(int num) {
	DCMotor self;
	int pwm = 0;
	int in1 = 0;
	int in2 = 0;

	if (num == 0) {
		pwm = 8;
		in2 = 9;
		in1 = 10;
	}
	else if (num == 1) {
		pwm = 13;
		in2 = 12;
		in1 = 11;
	}
	else if (num == 2) {
		pwm = 2;
		in2 = 3;
		in1 = 4;
	}
	else if (num == 3) {
		pwm = 7;
		in2 = 6;
		in1 = 5;
	}

	else{
		printf("An error has occurred\nDC Motor not properly initialized\nReturning empty motor");
		return self;
	}

	self.PWMpin = pwm;
	self.IN1pin = in1;
	self.IN2pin = in2;
	return self; 
}

extern void run(DCMotor self, int command) {
	if (command == FORWARD){
		// calls from PWM.h
		setPin(self.IN2pin, 0);
		setPin(self.IN1pin, 1);
	}
	if (command == BACKWARD){
		// calls from PWM.h
		setPin(self.IN2pin, 1);
		setPin(self.IN1pin, 0);
	}
	if (command == RELEASE){
		// calls from PWM.h
		setPin(self.IN2pin, 0);
		setPin(self.IN1pin, 0);
	}
}

extern void setSpeed(DCMotor self, int speed) {
	// speed should not need to be adjusted because restrictions are already implemented in Robot.c
	if (speed < 0) {
		speed = 0;
	}
	if (speed > 255) {
		speed = 255;
	}
	// call to PWM.h
	setPWM(self.PWMpin, 0, speed*16);
}

// Functions for MotorHat

extern MotorHat init_MotorHat()	{
	MotorHat self;
	//self.i2caddr = 0x60;
	self.frequency = 1600;
	setPWMFreq(self.frequency);

	int i;
	for (i = 0; i < 4; i++){
		self.motors[i] = init_DCMotor(i);
	}

	init_PWM();
	return self;
}

void setPin(int pin, int value)	{
	if (pin < 0 || pin > 15) {
		printf("\n\nPin cannot be set... Invalid pin number\n\n");
		return;
	}
	if (value != 0 && value != 1) {
		printf("\n\nPin cannot be set... Invalid value\n\n");
		return;
	}
	if (value == 0) {
		// call to PWM.h
		setPWM(pin, 0, 4096);
	}
	if (value == 1){
		setPWM(pin, 4096, 0);
	}
}

