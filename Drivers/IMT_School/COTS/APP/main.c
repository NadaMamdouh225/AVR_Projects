/*
 * main.c
 *
 *  Created on: May 17, 2022
 *      Author: Nada Mamdouh
 */
#include "../LIB/STD_Types.h"
#include <util/delay.h>
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../MCAL/ADC/ADC_int.h"

int main (void)
{
   MADC_vInit();
   DIO_vSetPortDir(DIO_PORTB,0xFF);
   u16 ADC_value = 0;

 /*
  *  255 -> 1023
  *  ??   ->  ADC Value
  *
  *  mapped value =??
  *
  */
   u8 BitValue = 0x01;
   u8 PinValue = 0x00;
   // create array of leds

	while(1)
	{
		ADC_value = MADC_u16AnalogRead(CHANNEL_0);
	    u16 LedLevel = MADC_u8Map(ADC_value,0,1023,0,8);
	    for(u8 Level = 0; Level < LedLevel ;Level++)
	    {

	    	if(Level <LedLevel)
	    	{
	    		DIO_vSetPinVal(DIO_PORTB,PinValue+Level,DIO_HIGH);
	    	}
	    	else
	    	{
	    		DIO_vSetPinVal(DIO_PORTB,PinValue+Level,DIO_LOW);
	    	}
	   }



	}

}

/*DIO_vSetPinVal(DIO_PORTB,PinValue,BitValue);
				_delay_ms(1000);
				BitValue = BitValue >>1;
				BitValue = (BitValue & 0xFE) | (0x01);
				PinValue ++;
				*/


