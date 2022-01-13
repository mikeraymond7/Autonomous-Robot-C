#include "PWM.h"

#define FORWARD 1
#define BACKWARD 2
#define BRAKE 3
#define RELEASE 4

typedef struct dcMotor {
        int PWMpin;
        int IN1pin;
        int IN2pin;
} DCMotor;


typedef struct motorHat {
//        uint8_t i2caddr;
        int frequency;
        DCMotor motors[4]; // might be motors[4]
} MotorHat;

extern DCMotor init_DCMotor(int);
extern void run(DCMotor, int);
extern void setSpeed(DCMotor, int);
extern MotorHat init_MotorHat();
extern void setPin(int, int);
