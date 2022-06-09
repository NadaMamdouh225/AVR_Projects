/*
 * main.c
 *
 *  Created on: May 10, 2022
 *      Author: Nada Mamdouh
 */
#include "STD_Types.h"
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"


int main(void)
{
    DDRA = 0b00000001;  //0x0f // PA0 -> output
    PORTA = 0b00000010; // input pull up enable
    while(1) // super loop
    {
    	if(GET_BIT(PINA,1) == 0)  // if button is pressed
    	{

    		while(GET_BIT(PINA,1) == 0)
    		{
    			_delay_ms(10);
    			TOG_BIT(PORTA,0);
    		}
    		//SET_BIT(PORTA,0);
    	}
    	/*else
    	{
    		CLR_BIT(PORTA,0);
    	}*/



    }
}
