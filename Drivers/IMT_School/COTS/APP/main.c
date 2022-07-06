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
   HLCD_vInit();
   u16 adc_value = 0;


	while(1)
	{
		adc_value = MADC_u16AnalogRead(0);
		HLCD_vSendCommand(LCD_CLEAR);
		HLCD_vPrintNumber(adc_value);
		_delay_ms(2000);


	}
}

