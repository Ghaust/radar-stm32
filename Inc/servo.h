/*#include "tm_stm32f4_pwm.h"
#define SERVO_MICROS_MIN 1000
#define SERVO_MICROS_MAX 2000

typedef struct {
	TM_PWM_TIM_t PWM;
	TIM_TypeDef *TIM;
	TM_PWM_Channel_t Channel;
	TM_PWM_PinsPack_t Pinspack;
	float Degrees;
	uint16_t Micros;

}TM_SERVO_t;

typedef enum{
	TM_SERVO_Result_OK = 0,
	TM_SERVO_Result_Error

}TM_SERVO_Result_t;


//fonction qui permet d'initialiser le servo moteur
int TM_SERVO_Init(TM_SERVO_t *ServoStruct, TM_PWM_TIM_t PWM, TIM_TypeDef *TIMx, TM_PWM_Channel_t PWMChannel, TM_PWM_PinsPack_t Pinspack);

//set rotation degrees for servo (between 0 and 180)
int TM_SERVO_SetDegrees(TM_SERVO_t *ServoStruct, float degrees);

//set pulse length in ms
int TM_SERVO_SetMicros(TM_SERVO_t *ServoStruct, uint16_t micros);
*/
