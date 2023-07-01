/*
 * UART_int.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_MCAL_UART_UART_INT_H_
#define IMT_SCHOOL_COTS_MCAL_UART_UART_INT_H_



void MUART_vInit(void);
void MUART_vTransmit(u8 A_u8Byte);
u8   MUART_u8Recieve(void);

void MUART_vSendString(char* str);
void MUART_vSendNumber(s32 A_s32Num);
void MUART_vRecieveString(char str[],u32 A_u32Size);

void MUART_vSetBaudRate(u32 A_u32BaudRate);

#endif /* IMT_SCHOOL_COTS_MCAL_UART_UART_INT_H_ */
