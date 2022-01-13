#include "PWM.h"
#include "I2c.h"
#include <bcm2835.h>
#include <math.h>
#include <stdio.h>

extern void init_PWM() {
	i2c_init(0x60); // initializes i2c, and sets slave

	setAllPWM(0,0);
	write8(__MODE2, __OUTDRV);
	write8(__MODE1, __ALLCALL);
	bcm2835_delay(5);
	
	uint8_t mode1 = read8(__MODE1);
	mode1 = mode1 & __SLEEP;
	write8(__MODE1, mode1);
	bcm2835_delay(5);
}

extern void setPWMFreq(int freq) {
	float prescaleval = 25000000.0;
	prescaleval /= 4096.0;
	prescaleval /= (float)freq;
	prescaleval -= 1.0;
	
	prescaleval = floor(prescaleval + 0.5);
	
	uint8_t oldmode = read8(__MODE1);
	uint8_t newmode = (oldmode & 0x7F) | 0x10;
	write8(__MODE1, newmode);
	write8(__PRESCALE, (int)(floor(prescaleval)));
	write8(__MODE1, oldmode);
	bcm2835_delay(5);
	write8(__MODE1, oldmode | 0x80);
}

extern void setPWM(int channel, int on, int off) {
	// likely error because channel is an int and not uint8_t
	write8(__LED_ON_L + 4*channel, on & 0xFF);
	write8(__LED_ON_H + 4*channel, on >> 8);
	write8(__LED0_OFF_L + 4*channel, off & 0xFF);
	write8(__LED0_OFF_H + 4*channel, off >> 8);
}

void setAllPWM(int on, int off) {
	write8(__ALL_LED_ON_L, on & 0xFF);
	write8(__ALL_LED_ON_H, on >> 8);
	write8(__ALL_LED_OFF_L, off & 0xFF);
	write8(__ALL_LED_OFF_H, off >> 8);
}
