/*
 * main.c
 *
 *  Created on: Jun 28, 2022
 *      Author: Nada Mamdouh
 */
#include "STD_Types.h"
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"

 u8 SevenSegmentArr[10] =
						{
								0b00111111 ,  // 0
								0b00000110 ,  // 1
								0b01011011 ,  // 2
								0b01001111 ,  // 3
								0b01100110 ,  // 4
								0b01101101 ,  // 5
								0b01111101 ,  // 6
								0b00000111 ,  // 7
								0b01111111 ,  // 8
								0b01101111 ,  // 9


						};

int main(void)
{
		DDRD   = 0xFF;


		while(1)
		{
			for(u8 LoopCounter=0; LoopCounter<10;LoopCounter++)
			{
				PORTD = ~(SevenSegmentArr[LoopCounter]);  // for common anode
				_delay_ms(1000);
			}
		}

}

