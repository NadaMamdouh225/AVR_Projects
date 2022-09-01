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

u8 MADC_u8Map(f32 A_f32Sensor_Value,u16 A_u16InputMin ,u16 A_u16InputMax,u16 A_u16OutputMin,u16 A_u16OutputMax)
{
	u16 L_u16Slope  = 0;
	u16 L_u16Value  = 0;
	u16 L_u16Input = 0;
	u16 L_u16Output = 0;
	 /* y = mx + c */    /* =>input: t =>  output: t*slope(y/x) */
	 /*slope = (y2 - y1) / (x2 - x1)*/
	A_u16InputMin  = 0;
	A_u16OutputMin = 0;
	L_u16Slope = (A_u16OutputMax - A_u16OutputMin)/(A_u16InputMax - A_u16InputMin);
	L_u16Input = A_u16InputMax - A_u16InputMin;
	L_u16Output = (L_u16Slope* L_u16Input );
	A_u16InputMax  = L_u16Input;
	A_u16OutputMax = L_u16Output;
	L_u16Value = (A_u16OutputMax * A_f32Sensor_Value )/A_u16InputMax;

	return L_u16Value ;
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











