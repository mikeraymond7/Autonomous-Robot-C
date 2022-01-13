all: test.c
	gcc -c Robot.c MotorHat.c PWM.c I2c.c sensor.c -lbcm2835
	gcc -o test test.c *.o -lbcm2835 -lm
clean:
	$(RM) test
	$(RM) *.o
