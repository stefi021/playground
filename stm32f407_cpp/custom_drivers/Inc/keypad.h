#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_

#include "pinmap.h"

#define NUMBER_OF_ROWS			4
#define NUMBER_OF_COLUMNS		4

class Keypad {
private:
	pinStruct_t *pRow;
	pinStruct_t *pCol;
	bool pinPrevPressed[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
	void SelectRow(uint8_t pinIndex);
	bool isDebounced(uint8_t pinIndex);
public:
	Keypad(pinStruct_t *pRowPins, pinStruct_t *pColumnPins);
	char GetCharShortPress(void);
	char GetCharLongPress(void);
};

#endif /* INC_KEYPAD_H_ */
