#include "sensor.h"
#include "usart.h"


void SENSOR_Init (SENSOR * HCSR04, GPIO_TypeDef * portTrigger, uint16_t pin_trigger, GPIO_TypeDef * portEcho, uint16_t pin_echo){

	//TRIGGER

	HCSR04 -> gpio_port_trigger=portTrigger;
	HCSR04 -> pin_trigger=pin_trigger;

	//Activation de l'horloge sur le port
	uint8_t nb_portTrigger ;
	nb_portTrigger = (uint32_t)((uint32_t*)portTrigger -IOPPERIPH_BASE)/ (uint32_t)0x400;

	//activation de l'hologe
	RCC -> IOPENR|=1<<nb_portTrigger;

	//configuration de la pin en sortie
	HCSR04 -> gpio_port_trigger -> MODER&=~(0b11<<2*pin_trigger); //activer la pin
	HCSR04 -> gpio_port_trigger -> MODER|=(0b01<<2*pin_trigger); //configurer la pin en sortie 


	//ECHO

	HCSR04 -> gpio_port_echo=portEcho;
	HCSR04 -> pin_echo=pin_echo;

	//Activation de l'horloge sur le port 
	uint8_t nb_portEcho ;
	nb_portEcho = (uint32_t)((uint32_t*)portEcho -IOPPERIPH_BASE)/ (uint32_t)0x400;

	//activation de l'hologe
	RCC -> IOPENR|=1<<nb_portEcho;

	//configuration de la pin en sortie
	HCSR04 -> gpio_port_echo -> MODER&=~(0b11<<2*pin_echo);
}

uint8_t HCSR04_isOn (SENSOR *HCSR04){
	return ((HCSR04->gpio_port_echo->IDR&(1<<HCSR04->pin_echo))!=0);
}

uint8_t HCSR04_isOff(SENSOR *HCSR04){
	return ((HCSR04->gpio_port_echo->IDR&(1<<HCSR04->pin_echo))==0);
}

int sensor_dist(SENSOR *HCSR04){
	int dist=0;
	HCSR04->gpio_port_trigger->ODR|=(1<<HCSR04->pin_trigger);
	LL_mDelay(10);
	HCSR04->gpio_port_trigger->ODR&=~(1<<HCSR04->pin_trigger);
	while(HCSR04_isOff(HCSR04));
	while(HCSR04_isOn(HCSR04)) {
		LL_mDelay(58);
		dist++;
	}
	LL_mDelay(80000);
	return dist;

}
