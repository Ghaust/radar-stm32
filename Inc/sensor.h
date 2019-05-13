typedef struct{
	 float distance;
	 GPIO_TypeDef *ECHO_GPIOx;
	 uint16_t ECHO_GPIO_Pin;
	 GPIO_TypeDef* TRIGGER_GPIOx;
	 uint16_t TRIGGER_GPIO_Pin;
} SENSOR;

uint8_t SENSOR_Init(SENSOR *HCSR04, GPIO_TypeDef* ECHO_GPIOx, uint16_t ECHO_GPIO_Pin, GPIO_TypeDef* TRIGGER_GPIOx, uint16_t TRIGGER_GPIO_Pin);

float TM_HCSR04_Read(SENSOR *HCSR04);


