#include "Robot.h"
#include "sensor.h"
#include <bcm2835.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

extern Robot init_robot() {
	Robot self;

//	self.addr = 0x60;
	// functions from MotorHat.h
	bcm2835_init();
	self.mh = init_MotorHat(); // initialize motorhat
	int i;

	// initialize trim for speed
	self.left_trim = 0;
	self.right_trim = 0;

	return self;
}

void left_speed(Robot self, int speed) {
	if (speed > 255) {
		speed = 255;
	}
	else if (speed < 0) {
		speed = 0;
	}

	speed += self.left_trim;
	//speed = max(0, min(255, speed)); // constrains speed between 0-255
	// set left motor
	setSpeed(self.mh.motors[0], speed); // call from MotorHat.h 
} 

void right_speed(Robot self, int speed) {
	if (speed > 255) {
		speed = 255;
	}
	else if (speed < 0) {
		speed = 0;
	}

	speed += self.right_trim;
	//speed = max(0, min(255, speed)); // constrains speed between 0-255
	// set right motor
	setSpeed(self.mh.motors[1], speed); // call from MotorHat.h 
} 

void stop(Robot self) {
	// calls from MotorHat.h
	run(self.mh.motors[0], RELEASE); // find out how RELEASE correlates to the rest of the code
	run(self.mh.motors[1], RELEASE); // find out how RELEASE correlates to the rest of the code

}

extern void go(Robot self, int speed) {
	init_sensor();
	double distance;
	while (1){
		forward(self, speed, 500);
		// set robi forward
		/*left_speed(self, speed);
		right_speed(self, speed);
	
		run(self.mh.motors[1], FORWARD); // right motor
		run(self.mh.motors[0], FORWARD); // left motor
*/
		distance = pulse();
		printf("\nDistance: %d\n", distance);
		if (distance < 50){
			left(self, speed, 500);
			
		}
	}

}

extern void forward(Robot self, int speed, int time) {
	left_speed(self, speed);
	right_speed(self, speed);

	// find out how these functions will take BACKWARD
	run(self.mh.motors[1], FORWARD); // right motor
	run(self.mh.motors[0], FORWARD); // left motor

	bcm2835_delay(time);
	stop(self);
}

extern void backward(Robot self, int speed, int time) {
	left_speed(self, speed);
	right_speed(self, speed);

	// find out how these functions will take BACKWARD
	run(self.mh.motors[1], BACKWARD);
	run(self.mh.motors[0], BACKWARD);

	bcm2835_delay(time);
	stop(self);
}

extern void right(Robot self, int speed, int time) {
	left_speed(self, speed);
	right_speed(self, speed);

	// find out how these functions will take FORWARD
	run(self.mh.motors[1], BACKWARD);
	run(self.mh.motors[0], FORWARD);

	bcm2835_delay(time);
	stop(self);
}

extern void left(Robot self, int speed, int time) {
	left_speed(self, speed);
	right_speed(self, speed);

	// find out how these functions will take FORWARD
	run(self.mh.motors[1], FORWARD);
	run(self.mh.motors[0], BACKWARD);

	bcm2835_delay(time);
	stop(self);
}

