#include "Robot.h"

// highest level

// initialize and run robi
int main (int argc, char **argv){
	double distance;
	Robot robi = init_robot();
	forward(robi, 155, 1000);
	//backward(robi, 150, 5000);
	go(robi, 155);
	bcm2835_close();	
	return 0;
}
