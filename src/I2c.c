#include "I2c.h"
#include <stdio.h>

// takes slave address and returns I2C struct
// address should be 0x60
extern void i2c_init(uint8_t addr){
	if (!bcm2835_i2c_begin()){
		printf("\nI2C failed\nMake sure bcm2835_init was successful and user is root\n");
		return;
	}
/*	if (!bcm2835_init()){
		printf("\n\t\tHow did you mess up that bad\n");
	}
	bcm2835_i2c_setSlaveAddress(addr);
	printf("\n\n\t\tAddress: 0x%x", addr);
*/	return;
}

// returns reason
extern uint8_t write8(uint8_t reg, uint8_t value){
	char buf [2];
	buf[0] = reg;
	buf[1] = value;
//	return reg;
	return bcm2835_i2c_write(buf, 2);
}

extern uint8_t read8(uint8_t reg){
	char buf [2];
	buf[0] = reg;
	bcm2835_i2c_read(buf, 2);
	return buf[0];
}
