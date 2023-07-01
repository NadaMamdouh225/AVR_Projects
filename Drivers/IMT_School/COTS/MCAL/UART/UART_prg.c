/*
 * UART_prg.c
 *
 *  Created on: Sep 24, 2022
 *      Author: Nada Mamdouh
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "UART_int.h"
#include "UART_prv.h"
#include "UART_cfg.h"

void MUART_vInit(void)
{
	UCSRB = 0b00011000;
	UCSRC = 0b10000110;
	UBRRL = 51; // 9600
}
void MUART_vTransmit(u8 A_u8Byte)
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR = A_u8Byte;
}
u8   MUART_u8Recieve(void)
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR;
}

void MUART_vSendString(char* str)
{

//	for(u32 i = 0; str[i]!='\0' ; i++)       // (i++) difference: this is a data arithmetic - limitation because of u32(there is an over flow)
//	{
//		MUART_vTransmit(str[i]);
//	}

	while(*str != '\0')
	 {
		MUART_vTransmit(*str);
		str++;                               // (str++) difference: this is pointer arithmetic - there is no limit for the number of characters sent
	}

}
void MUART_vSendNumber(s32 A_s32Num)
{
//	s32 Remainder;
//	while(A_s32Num > 0)
	//{
		//Remainder = A_s32Num%10;

	//}
}
void MUART_vRecieveString(char str[],u32 A_u32Size)
{
	for(u32 i=0 ; i<A_u32Size ; i++ )
	{
		str[i] = MUART_u8Recieve();
		if(str[i] == '\n' || str[i] == '\r')   // if user pressed Enter
		{
			str[i] = '\0';
			break;
		}
	}
	str[A_u32Size-1]='\0';
}

void MUART_vSetBaudRate(u32 A_u32BaudRate)
{

}
