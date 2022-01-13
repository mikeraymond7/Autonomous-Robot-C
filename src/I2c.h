#include <bcm2835.h>
/*
// Registers/etc
#define __MODE1 0x00
#define __MODE2 0x01
#define __PRESCALE 0xFE
#define __LED_ON_L 0x06
#define __LED_ON_H 0x07
#define __LED0_OFF_L 0x08
#define __LED0_OFF_H 0x09
#define __ALL_LED_ON_L 0xFA
#define __ALL_LED_ON_H 0xFB
#define __ALL_LED_OFF_L 0xFC
#define __ALL_LED_OFF_H 0xFD

// Bits
#define __RESTART 0x80 // not used
#define __SLEEP 0x10
#define __ALLCALL 0x01
#define __INVRT 0x10 // not used
#define __OUTDRV 0x04 
*/
extern void i2c_init(uint8_t);
extern uint8_t write8(uint8_t, uint8_t);
extern uint8_t read8(uint8_t);
