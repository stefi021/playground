/*
 * servo.h
 *
 *  Created on: Jan 13, 2026
 *      Author: taps
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include "pinmap.h"

enum {
	SERVO_RIGHTPOSITION = 600,
	SERVO_MIDPOSITION = 2000,
	SERVO_LEFTPOSITION = 3350
};

class Servo {
private:
	TIM_HandleTypeDef htim;
	uint8_t pwmCh;
public:
	Servo(pinStruct_t &servoPin,
			TIM_TypeDef *TIMx,
			uint8_t gpioAFSelTIMx,
			uint8_t pwmChannel);
	void TurnShaft(uint32_t position);
};

#endif /* INC_SERVO_H_ */
