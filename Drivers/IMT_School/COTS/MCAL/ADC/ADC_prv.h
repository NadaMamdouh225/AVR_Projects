/*
 * ADC_prv.h
 *
 *  Created on: Jul 7, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_MCAL_ADC_ADC_PRV_H_
#define IMT_SCHOOL_COTS_MCAL_ADC_ADC_PRV_H_

#define ADMUX         *((volatile u8*)(0x27))
#define ADCSRA        *((volatile u8*)(0x26))
#define ADCL          *((volatile u8*)(0x24))
#define ADCH          *((volatile u8*)(0x25))
#define SFIOR         *((volatile u8*)(0x50))

#define ADC           *((volatile u16*)(0x24))

#define REFS1          7
#define REFS0          6
#define ADLAR          5
#define ADATE          5
#define ADIE           3
#define ADIF           4
#define ADEN           7
#define ADSC           6


#endif /* IMT_SCHOOL_COTS_MCAL_ADC_ADC_PRV_H_ */
