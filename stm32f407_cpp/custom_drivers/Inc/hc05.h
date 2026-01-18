/*
 * hc05.h
 *
 *  Created on: Jan 15, 2026
 *      Author: stefan
 */

#ifndef INC_HC05_H_
#define INC_HC05_H_

#include "pinmap.h"

class HC05 {
private:
	UART_HandleTypeDef huart;
public:
	HC05(pinStruct_t &uartPin,
			USART_TypeDef *USARTx,
			uint32_t baudRate,
			uint32_t gpioAFSelUSARTx,
			uint32_t mode);
	char GetChar(void);
};

#endif /* INC_HC05_H_ */
