/*
 * pinmap.h
 *
 *  Created on: Jan 12, 2026
 *      Author: taps
 */

#ifndef INC_PINMAP_H_
#define INC_PINMAP_H_

#include "stm32f4xx_hal.h"

typedef struct {
	GPIO_TypeDef* port;
	uint16_t selctedPin;
}pinStruct_t;

#endif /* INC_PINMAP_H_ */
