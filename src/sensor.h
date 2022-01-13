#define ECHO RPI_V2_GPIO_P1_18
#define TRIG RPI_V2_GPIO_P1_16


extern double get_time(void);
extern void gpio_reset(void);
extern void init_sensor(void);
extern double pulse(void);
