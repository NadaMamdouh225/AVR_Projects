/*
 * LCD_int.h
 *
 *  Created on: Jul 2, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_HAL_LCD_LCD_INT_H_
#define IMT_SCHOOL_COTS_HAL_LCD_LCD_INT_H_

#define LCD_CLEAR             0x01

#define LCD_CTRL_PORT         DIO_PORTC
#define LCD_DATA_PORT         DIO_PORTD
#define LCD_RS_PIN            DIO_PIN0
#define LCD_RW_PIN            DIO_PIN1
#define LCD_EN_PIN            DIO_PIN2

#define Max_IDX_OF_ROWS              2
#define Max_IDX_OF_COLS              16
#define FIRST_ROW_IDX                0
#define SECOND_ROW_IDX               1
#define FIRST_ROW_START              0x00
#define SECOND_ROW_START             0x40
#define CGRAM_NUM_OF_PATTERNS        8
#define CGRAM_BASE_ADDRESS           0x40
#define DDRAM_BASE_ADDRESS           0x80


void HLCD_vInit(void);
void HLCD_vSendCommand(u8 A_u8Cmd);
void HLCD_vSendData(u8 A_u8Data);
void HLCD_vPrintString(char A_s8String[]);
void HLCD_vPrintNumber(s32 A_s32Number);
void HLCD_vSetCursorPosition(u8 A_u8Row, u8 A_u8Col);
void HLCD_vSaveCustomChar(u8 A_u8CGRAM_IDK, u8 A_u8CustomCharData[]);
void HLCD_vDisplayCustomChar(u8 A_u8CGRAM_IDX);
void HLCD_vClearScreen(void);

#endif /* IMT_SCHOOL_COTS_HAL_LCD_LCD_INT_H_ */
