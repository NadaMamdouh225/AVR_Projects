/*
 * UART_prv.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_MCAL_UART_UART_PRV_H_
#define IMT_SCHOOL_COTS_MCAL_UART_UART_PRV_H_
/* ------------ UCSRA REG ------------*/
#define UDRE                   5
#define RXC                    7

/* ------------ USART REGs ------------*/
#define UDR                    *((volatile u8*)(0x2C))
#define UCSRA                  *((volatile u8*)(0x2B))
#define UCSRB                  *((volatile u8*)(0x2A))
#define UCSRC                  *((volatile u8*)(0x40))
#define UBRRL                  *((volatile u8*)(0x29))
#define UBRRH                  *((volatile u8*)(0x40))


#endif /* IMT_SCHOOL_COTS_MCAL_UART_UART_PRV_H_ */
