#include "MotorHat.h"

typedef struct robot {
	// address is 0x60
 //       uint8_t addr;

        MotorHat mh; // from MotorHat.h
        //int left;
        //int right;
        int left_trim;
        int right_trim;
} Robot;

extern Robot init_robot(void);
extern void left_speed(Robot, int);
extern void right_speed(Robot, int);
void stop(Robot);
extern void go(Robot, int);
extern void forward(Robot, int, int);
extern void backward(Robot, int, int);
extern void right(Robot, int, int);
extern void left(Robot, int, int);
