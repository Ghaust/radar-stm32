#include "gpio.h"

typedef struct {
	GPIO_TypeDef * gpio_port_trigger;
	uint16_t pin_trigger;
	GPIO_TypeDef * gpio_port_echo;
	uint16_t pin_echo;
} SENSOR;

void SENSOR_Init(SENSOR *HCSR04, GPIO_TypeDef* ECHO_GPIOx, uint16_t ECHO_GPIO_Pin, GPIO_TypeDef* TRIGGER_GPIOx, uint16_t TRIGGER_GPIO_Pin);

//float TM_HCSR04_Read(SENSOR *HCSR04);

uint8_t SENSOR_isOn(SENSOR *HCSR04);

uint8_t SENSOR_isOff(SENSOR *HCSR04);

int sensor_dist(SENSOR *HCSR04);
