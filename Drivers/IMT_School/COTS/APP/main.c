/*
 * main.c
 *
 *  Created on: May 17, 2022
 *      Author: Nada Mamdouh
 */
#include "../LIB/STD_Types.h"
#include <avr/io.h>
#include <util/delay.h>
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/SSD/SSD_int.h"


int main (void)
{
	SSD_vInit();

	for(u8 i=0;i<10;i++)
	{
		SSD_vDisplayNum(i);
		_delay_ms(500);
	}

	while(1)
	{

	}
}

