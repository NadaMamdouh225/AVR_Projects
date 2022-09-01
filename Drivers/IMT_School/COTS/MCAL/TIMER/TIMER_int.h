/*
 * TIMER_int.h
 *
 *  Created on: Jul 19, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_MCAL_TIMER_TIMER_INT_H_
#define IMT_SCHOOL_COTS_MCAL_TIMER_TIMER_INT_H_



void MTIMER_vInit(void);
void MTIMER_vSetPreloadValue(/*Timer ID ? */u16 A_u16Preload);
void MTIMER_vSetInterval_Asynch(u16 A_u16IntervalCounts,void (*A_fptr)(void));
void MTIMER_vStartTimer(/* Timer ID */);
void MTIMER_vStopTimer(/* Timer ID */);


#endif /* IMT_SCHOOL_COTS_MCAL_TIMER_TIMER_INT_H_ */
