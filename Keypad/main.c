/*
 * main.c
 *
 *  Created on: Jun 27, 2022
 *      Author: Nada Mamdouh
 */
#include "STD_Types.h"
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"


void KEYPAD_INIT(void)
{
	/* PORTB -> inputs|outputs */
    DDRB = 0x0F;
    PORTB = 0xFF;  // PORTB -> activating Pull up resistors|deactivate all output pins
    DDRD = 0xFF;   // for seven segments

}

u8 GetPressedKey(void)
{
   u8 pressed_key = 0;  // default value if nothing pressed
   for(u8 col=0; col<4 ;col++)
   {
	   // activate current column
	   CLR_BIT(PORTB,col);
	   for(u8 row=0;row<4;row++)
	   {
             if(GET_BIT(PINB,row+4) == 0)  // a button is pressed
             {
            	 pressed_key = row + (col*4) +1;  // key number
             }
             while(GET_BIT(PINB,row+4) == 0){}
             _delay_ms(10);

	   }
	   // deactivate column
	   SET_BIT(PORTB,col);
   }

   return pressed_key;
}

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

int main (void)
{
	KEYPAD_INIT();
	u8 key =0;
	while(1)
	{
     key = GetPressedKey();
     if(key != 0)
     {
       PORTD = ~(SevenSegmentArr[key]);
       _delay_ms(10);
     }
	}
}

