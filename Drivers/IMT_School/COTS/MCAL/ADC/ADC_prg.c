/*
 * ADC_prg.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Nada Mamdouh
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_int.h"

#include "ADC_int.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"

#include <avr/io.h>

void MADC_vInit(void)
{
	/* Reference voltage selection */
	CLR_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);
	/* Data Adjustment direction */
	CLR_BIT(ADMUX,ADLAR);
	/* Select Prescaler Bits */
	ADCSRA =(ADCSRA & 0xF8) | (ADC_PRESCALER);
	/* Auto trigger enable /disable*/
	/* Select auto trigger source :Single Conversion Mode */
	CLR_BIT(ADCSRA,ADATE);
	/* Interrupt enable / disable */
#if ADC_INTERRUPT_ENABLE == DISABLE
	CLR_BIT(ADCSRA,ADIE);             // disable
#elif ADC_INTERRUPT_ENABLE == ENABLE
	SET_BIT(ADCSRA,ADIE);             // enable
#endif
	/* Enable ADC peripheral */
	SET_BIT(ADCSRA,ADEN);
}
u16 MADC_u16AnalogRead(u8 A_u8ChannelNo)
{
	/* Select Channel*/
	ADMUX = (ADMUX & 0xE0) | (A_u8ChannelNo & 0x07);    // anded with 0x07 to validate the input as we have 8 channels in this single ended input
	/* Start Conversion */
	SET_BIT(ADCSRA,ADSC);
	/* Poll on Flag  (conversion complete flag) */
    while(GET_BIT(ADCSRA,ADIF) != 1){}
	/* Clear Flag */
    SET_BIT(ADCSRA,ADIF);
	/* Return ADC Data */
    return ADC;


}
u8 MADC_u8Map(f32 A_f32ADC_Value,u16 A_u16OriginalMin ,u16 A_u16OriginalMax,u16 A_u16NewMin,u16 A_u16NewMax)
{
	u16 L_u16OriginalRange;
	u16 L_u16NewRange;
	u8  L_u8Step;
	u16 L_u16MappedValue;

	L_u16OriginalRange = A_u16OriginalMax - A_u16OriginalMin +1 ;      //ex: 1024
	L_u16NewRange = A_u16NewMax - A_u16NewMin +1;                    //ex: 8
	L_u8Step = L_u16OriginalRange / L_u16NewRange;                    // ex: 128

	if(A_f32ADC_Value)
	{
		if((A_f32ADC_Value>=(A_u16NewMin*L_u8Step) )|(A_f32ADC_Value<= (L_u8Step-1)))
		{
			L_u16MappedValue = 0;
		}
		else if(A_f32ADC_Value>=(1*L_u8Step) |A_f32ADC_Value<= (2*L_u8Step-1))
		{
			L_u16MappedValue = 1;
		}
		else if(A_f32ADC_Value>=(2*L_u8Step) |A_f32ADC_Value<= (3*L_u8Step-1))
		{
			L_u16MappedValue = 2;
		}
		else if(A_f32ADC_Value>=(3*L_u8Step) |A_f32ADC_Value<= (4*L_u8Step-1))
		{
			L_u16MappedValue = 3;
		}
		else if(A_f32ADC_Value>=(4*L_u8Step) |A_f32ADC_Value<= (5*L_u8Step-1))
		{
			L_u16MappedValue = 4;
		}
		else if(A_f32ADC_Value>=(5*L_u8Step) |A_f32ADC_Value<= (6*L_u8Step-1))
		{
			L_u16MappedValue = 5;
		}
		else if(A_f32ADC_Value>=(6*L_u8Step) |A_f32ADC_Value<= (7*L_u8Step-1))
		{
			L_u16MappedValue = 6;
		}
		else if(A_f32ADC_Value>=(7*L_u8Step) |A_f32ADC_Value<= (8*L_u8Step-1))
		{
			L_u16MappedValue = 7;
		}
	}


	return L_u16MappedValue ;

}

void MADC_vStartConvertion(u8 A_u8ChannelNo)
{
	/* Select Channel*/
	ADMUX = (ADMUX & 0xE0) | (A_u8ChannelNo & 0x07);    // anded with 0x07 to validate the input as we have 8 channels in this single ended input
	/* Start Conversion */
	SET_BIT(ADCSRA,ADSC);
}
u16 MADC_vGetADCData(void)
{
	/* Return ADC Data */
	return ADC;

}

/* ADC ISR */
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{

}











