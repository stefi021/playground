#include "servo.h"

int main(void) {

	HAL_Init();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_TIM4_CLK_ENABLE();

	pinStruct_t servoPin = {GPIOD, GPIO_PIN_14};

	static Servo servo(servoPin, TIM4, GPIO_AF2_TIM4, TIM_CHANNEL_3);

	while(1){
		servo.TurnShaft(SERVO_LEFTPOSITION);
		HAL_Delay(1000);
		servo.TurnShaft(SERVO_MIDPOSITION);
		HAL_Delay(1000);
		servo.TurnShaft(SERVO_RIGHTPOSITION);
		HAL_Delay(1000);
	}

	return 0;
}

extern "C" void SysTick_Handler(void) {

	HAL_IncTick();
}
