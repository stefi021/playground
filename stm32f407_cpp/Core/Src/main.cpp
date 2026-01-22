#include "servo.h"
#include "hc05.h"
#include "lcd.h"

char bluetoothData = '\0';

void servoApplication(void);
void lcdApplication(void);

int main(void) {

	HAL_Init();
	lcdApplication();
	return 0;
}

void lcdApplication(void) {

	__HAL_RCC_GPIOC_CLK_ENABLE();

	pinStruct_t rs = {GPIOC, GPIO_PIN_0};
	pinStruct_t en = {GPIOC, GPIO_PIN_1};
	pinStruct_t d4 = {GPIOC, GPIO_PIN_2};
	pinStruct_t d5 = {GPIOC, GPIO_PIN_3};
	pinStruct_t d6 = {GPIOC, GPIO_PIN_4};
	pinStruct_t d7 = {GPIOC, GPIO_PIN_5};

	static LCD lcd(rs, en, d4, d5, d6, d7);

	HAL_Delay(1000);

	lcd.SetCursor(0, 0);
	lcd.Print('A');
	lcd.SetCursor(1, 0);
	lcd.Print("How are you?");
	lcd.Clear();
	uint8_t number = 35;
	lcd.Print(number);
	lcd.Clear();

	uint32_t var = 0;

	while(1) {
		lcd.SetCursor(0,0);
		lcd.Print(var);
		var++;
		HAL_Delay(300);
	}
}

void servoApplication(void) {

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_USART1_CLK_ENABLE();
	__HAL_RCC_TIM4_CLK_ENABLE();

	pinStruct_t servoPin = {GPIOD, GPIO_PIN_14};
	pinStruct_t uartRxPin = {GPIOA, GPIO_PIN_10};

	static Servo servo(servoPin, TIM4, GPIO_AF2_TIM4, TIM_CHANNEL_3);
	static HC05 hc05(uartRxPin, USART1, 9600, GPIO_AF7_USART1, UART_MODE_RX);

	while(1)
	{
		bluetoothData = hc05.GetChar();
		switch(bluetoothData)
		{
			case 'l':
			case 'L':
				servo.TurnShaft(SERVO_LEFTPOSITION);
				break;
			case 'm':
			case 'M':
				servo.TurnShaft(SERVO_MIDPOSITION);
				break;
			case 'r':
			case 'R':
				servo.TurnShaft(SERVO_RIGHTPOSITION);
				break;
		}
	}

}

extern "C" void SysTick_Handler(void) {

	HAL_IncTick();
}
