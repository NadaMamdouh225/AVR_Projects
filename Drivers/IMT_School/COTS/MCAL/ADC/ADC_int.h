/*
 * ADC_int.h
 *
 *  Created on: Jul 5, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_MCAL_ADC_ADC_INT_H_
#define IMT_SCHOOL_COTS_MCAL_ADC_ADC_INT_H_


#define CHANNEL_0           0
#define CHANNEL_1           1
#define CHANNEL_2           2
#define CHANNEL_3           3
#define CHANNEL_4           4
#define CHANNEL_5           5
#define CHANNEL_6           6
#define CHANNEL_7           7


void MADC_vInit(void);
u16 MADC_u16AnalogRead(u8 A_u8ChannelNo);
u8 MADC_u8Map(f32 A_f32ADC_Value,u16 A_u16OriginalMin ,u16 A_u16OriginalMax,u16 A_u16NewMin,u16 A_u16NewMax);

 /* Interrupt based APIs */
void MADC_vStartConvertion(u8 A_u8ChannelNo);
u16 MADC_vGetADCData(void);


#endif /* IMT_SCHOOL_COTS_MCAL_ADC_ADC_INT_H_ */
