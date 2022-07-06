/*
 * ADC_prg.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Nada Mamdouh
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "ADC_int.h"
#include "ADC_cfg.h"

#include <avr/io.h>

void MADC_vInit(void)
{
	/* Reference voltage selection */
	CLR_BIT(ADMUX,REFS1);        // 7
	SET_BIT(ADMUX,REFS0);        // 6
	/* Data Adjustment direction */
	CLR_BIT(ADMUX,ADLAR);        // 5
	/* Select Prescaler Bits */
	ADCSRA =(ADCSRA & 0xF8) | (ADC_PRESCALER);
	/* Auto trigger enable */
	/* Select auto trigger source */
	CLR_BIT(ADCSRA,ADATE);
	/* Interrupt enable / disable */
	CLR_BIT(ADCSRA,ADIE);
	/* Enable ADC peripheral */
	SET_BIT(ADCSRA,ADEN);
}
u16 MADC_u16AnalogRead(u8 A_u8ChannelNo)
{
	/* Select Channel*/
	ADMUX = (ADMUX & 0xE0) | (A_u8ChannelNo & 0x07);
	/* Start Conversion */
	SET_BIT(ADCSRA,ADSC);
	/* Poll on Flag  */
    while(GET_BIT(ADCSRA,ADIF) != 1){}
	/* Clear Flag */
    SET_BIT(ADCSRA,ADIF);
	/* Return ADC Data */
    return ADC;


}

