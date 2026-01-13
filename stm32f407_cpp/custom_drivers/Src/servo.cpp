#include "servo.h"

Servo::Servo(pinStruct_t &servoPin,
		TIM_TypeDef *TIMx,
		uint8_t gpioAFSelTIMx,
		uint8_t pwmChannel) {

	pwmCh = pwmChannel;

	/* GPIO config */

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = servoPin.selctedPin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.Alternate = gpioAFSelTIMx;
	HAL_GPIO_Init(servoPin.port, &GPIO_InitStruct);

	/* TIM config */

	/* System clock by default is 16MHz
	 * 1 tick freq = 16MHz / (1 + prescaler) = 1.6MHz
	 * 1 tick time = 1 / 1.6 MHz = 0.626 us
	 * PWM period = 32000 x 0.625 us = 20 ms -> freq = 50 Hz
	 * right position 1200 × 0.625 µs = 750 µs ≈ 0.75 ms
	 * mid position 2250 × 0.625 µs = 1406 µs ≈ 1.4 ms
	 * left position 3350 × 0.625 µs = 2094 µs ≈ 2.1 ms
	 * */

	TIM_OC_InitTypeDef sConfigOC = {0};
	htim.Instance = TIMx;
	htim.Init.Prescaler = 10 - 1;
	htim.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim.Init.Period = 32000 - 1;
	htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_PWM_Init(&htim);

	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = SERVO_MIDPOSITION;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	HAL_TIM_PWM_ConfigChannel(&htim, &sConfigOC, pwmChannel);

	HAL_TIM_PWM_Start(&htim, pwmChannel);
}

void Servo::TurnShaft(uint32_t position) {

	__HAL_TIM_SET_COMPARE(&htim, pwmCh, position);
}

