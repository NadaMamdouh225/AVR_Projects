/*
 * TIMER_int.h
 *
 *  Created on: Jul 19, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_MCAL_TIMER_TIMER_INT_H_
#define IMT_SCHOOL_COTS_MCAL_TIMER_TIMER_INT_H_

#define TOIE0                 0

#define NO_CLK                0b000
#define CLK_NO_PRESCALING     0b001
#define CLK_PRESCALING_8      0b010
#define CLK_PRESCALING_64     0b011
#define CLK_PRESCALING_256    0b100
#define CLK_PRESCALING_1024   0b101
#define EXT_CLK_FALLING_EDGE  0b110
#define EXT_CLK_RISING_EDGE   0b111


void MTIMER_vInit(void);
void MTIMER_vSetPreloadValue(/*Timer ID ? */u16 A_u16Preload);
void MTIMER_vSetInterval_Asynch(u16 A_u16IntervalCounts,void (*A_fptr)(void));
void MTIMER_vStartTimer(/* Timer ID */);
void MTIMER_vStopTimer(/* Timer ID */);


#endif /* IMT_SCHOOL_COTS_MCAL_TIMER_TIMER_INT_H_ */
