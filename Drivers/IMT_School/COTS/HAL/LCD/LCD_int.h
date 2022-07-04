/*
 * LCD_int.h
 *
 *  Created on: Jul 2, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_HAL_LCD_LCD_INT_H_
#define IMT_SCHOOL_COTS_HAL_LCD_LCD_INT_H_


#define LCD_CLEAR             0x01

#define LCD_CTRL_PORT         DIO_PORTA
#define LCD_DATA_PORT         DIO_PORTD
#define LCD_RS_PIN            DIO_PIN0
#define LCD_RW_PIN            DIO_PIN1
#define LCD_EN_PIN            DIO_PIN2


void HLCD_vInit(void);
void HLCD_vSendCommand(u8 A_u8Cmd);
void HLCD_vSendData(u8 A_u8Data);
void HLCD_vPrintString(char A_s8String[]);
void HLCD_vPrintNumber(s32 A_s32Number);
void HLCD_vSetCursorPosition(u8 A_u8LinePostion,u8 A_u8LineNo);
void HLCD_vSaveCustomChar(/* TODO: to be provided */);
void HLCD_vDisplayCustomChar(/* TODO: to be done */);


#endif /* IMT_SCHOOL_COTS_HAL_LCD_LCD_INT_H_ */
