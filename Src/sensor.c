#include "sensor.h"
#include "usart.h"
#include "gpio.h"
#include "tm_stm32f4_hcsr04.h"

uint8_t SENSOR_Init(SENSOR *HCSR04, GPIO_TypeDef* ECHO_GPIOx, uint16_t ECHO_GPIO_Pin, GPIO_TypeDef* TRIGGER_GPIOx, uint16_t TRIGGER_GPIO_Pin){

	HCSR04->ECHO_GPIOx = ECHO_GPIOx;
	HCSR04->ECHO_GPIO_Pin = ECHO_GPIO_Pin;
	HCSR04->TRIGGER_GPIOx = TRIGGER_GPIOx;
	HCSR04->TRIGGER_GPIO_Pin = TRIGGER_GPIO_Pin;
}

float TM_HCSR04_Read(SENSOR *HCSR04){
	uint32_t time, timeout;
		/* Trigger low */
		TM_GPIO_SetPinLow(HCSR04->TRIGGER_GPIOx, HCSR04->TRIGGER_GPIO_Pin);
		/* Delay 2 us */
		Delay(2);
		/* Trigger high for 10us */
		TM_GPIO_SetPinHigh(HCSR04->TRIGGER_GPIOx, HCSR04->TRIGGER_GPIO_Pin);
		/* Delay 10 us */
		Delay(10);
		/* Trigger low */
		TM_GPIO_SetPinLow(HCSR04->TRIGGER_GPIOx, HCSR04->TRIGGER_GPIO_Pin);

		/* Give some time for response */
		timeout = HCSR04_TIMEOUT;
		while (!TM_GPIO_GetInputPinValue(HCSR04->ECHO_GPIOx, HCSR04->ECHO_GPIO_Pin)) {
			if (timeout-- == 0x00) {
				return -1;
			}
		}

		/* Start time */
		time = 0;
		/* Wait till signal is low */
		while (TM_GPIO_GetInputPinValue(HCSR04->ECHO_GPIOx, HCSR04->ECHO_GPIO_Pin)) {
			/* Increase time */
			time++;
			/* Delay 1us */
			Delay(1);
		}

		/* Convert us to cm */
		HCSR04->distance =  (float)time * HCSR04_NUMBER;

		/* Return distance */
	return HCSR04->distance;
}



