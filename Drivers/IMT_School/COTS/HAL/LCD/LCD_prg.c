/*
 * LCD_prg.c
 *
 *  Created on: Jul 2, 2022
 *      Author: Nada Mamdouh
 */

#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_int.h"
#include <util/delay.h>
#include "LCD_int.h"

void HLCD_vSendCommand(u8 A_u8Cmd) {
	/* Control RS and RW pins */
	DIO_vSetPinVal(LCD_CTRL_PORT, LCD_RS_PIN, DIO_LOW);   //RS
	DIO_vSetPinVal(LCD_CTRL_PORT, LCD_RW_PIN, DIO_LOW);   //RW

	/* Write Command on the data pins */
	DIO_vSetPortVal(LCD_DATA_PORT, A_u8Cmd);

	/* Pulse on the enable pin */
	DIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN, DIO_HIGH);   //Enable
	_delay_ms(1);
	DIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN, DIO_LOW);
	_delay_ms(1);

}
void HLCD_vSendData(u8 A_u8Data) {
	/* Control RS and RW pins */
	DIO_vSetPinVal(LCD_CTRL_PORT, LCD_RS_PIN, DIO_HIGH);   //RS
	DIO_vSetPinVal(LCD_CTRL_PORT, LCD_RW_PIN, DIO_LOW);    //RW

	/* Write Data on the data pins */
	DIO_vSetPortVal(LCD_DATA_PORT, A_u8Data);

	/* Pulse on the enable pin */
	DIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN, DIO_HIGH);   //Enable
	_delay_ms(1);
	DIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN, DIO_LOW);
	_delay_ms(1);

}

void HLCD_vInit(void) { /* Set pin direction */
	DIO_vSetPinDir(LCD_CTRL_PORT, LCD_RS_PIN, DIO_OUTPUT);
	DIO_vSetPinDir(LCD_CTRL_PORT, LCD_RW_PIN, DIO_OUTPUT);
	DIO_vSetPinDir(LCD_CTRL_PORT, LCD_EN_PIN, DIO_OUTPUT);
	DIO_vSetPortDir(LCD_DATA_PORT, 0xFF);

	/* 8-bit Initialization sequence */
	_delay_ms(50);
	HLCD_vSendCommand(0x38);          // function set
	_delay_ms(1);
	HLCD_vSendCommand(0x0C); // display on/off control , Cursor and Blink cursor are off
	_delay_ms(1);
	HLCD_vSendCommand(LCD_CLEAR);          // display clear
	_delay_ms(2);
	HLCD_vSendCommand(0x06);          // enter mode set
	_delay_ms(1);
}

void HLCD_vPrintString(char A_s8String[]) {
	for (u8 L_u8String = 0; A_s8String[L_u8String] != '\0'; L_u8String++) {
		HLCD_vSendData(A_s8String[L_u8String]);
	}

}

void HLCD_vPrintNumber(s32 A_s32Number) {
	u8 L_u8Digits[10] = { 0 };
	u8 L_u8Counter = 0;
	/* TODO: IMplement negative number handling  	*/
	/* TODO: implement Zero in units corner case    */
	/* save reversed in array */
	while (A_s32Number > 0) {
		L_u8Digits[L_u8Counter] = A_s32Number % 10;
		L_u8Counter++;
		A_s32Number /= 10;
	}

	/* print array in reverese  */
	for (s8 L_s8PrintIndex = 0; L_s8PrintIndex >= 0; L_s8PrintIndex--) {
		HLCD_vSendData('0' + L_u8Digits[L_s8PrintIndex]);
	}
}
void HLCD_vSetCursorPosition(u8 A_u8Row, u8 A_u8Col) {


	/* Valid Range */
	if ((A_u8Row < Max_IDX_OF_ROWS) && (A_u8Col < Max_IDX_OF_COLS))
	{
		switch (A_u8Row) {
		case FIRST_ROW_IDX:
			HLCD_vSendCommand(DDRAM_BASE_ADDRESS + FIRST_ROW_START + A_u8Col);
			break;
		case SECOND_ROW_IDX:
			HLCD_vSendCommand(DDRAM_BASE_ADDRESS + SECOND_ROW_START + A_u8Col);
			break;
		}

	} else {
		/* Do Nothing */
	}

}


void HLCD_vSaveCustomChar(u8 A_u8CGRAM_IDK, u8 A_u8CustomCharData[]) {
	/* Set AC on CGRAM */
	if (A_u8CGRAM_IDK < CGRAM_NUM_OF_PATTERNS) {
		HLCD_vSendCommand(CGRAM_BASE_ADDRESS + (A_u8CGRAM_IDK * CGRAM_NUM_OF_PATTERNS));
	}
	/* Write Pattern */
	for (u8 L_u8Idx = 0; L_u8Idx < 8; L_u8Idx++) {
		HLCD_vSendData(A_u8CustomCharData[L_u8Idx]);
	}
	/* Set AC on DDRAM */
	HLCD_vSendCommand(DDRAM_BASE_ADDRESS);

}
void HLCD_vDisplayCustomChar(u8 A_u8CGRAM_IDX) {
	if (A_u8CGRAM_IDX < CGRAM_NUM_OF_PATTERNS) {
		HLCD_vSendData(A_u8CGRAM_IDX);
	}

}
void HLCD_vClearScreen(void) {
	HLCD_vSendCommand(LCD_CLEAR);
}
