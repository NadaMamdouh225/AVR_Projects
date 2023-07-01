/*
 * TIMER_int.h
 *
 *  Created on: Jul 19, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_MCAL_TIMER_TIMER_INT_H_
#define IMT_SCHOOL_COTS_MCAL_TIMER_TIMER_INT_H_

#define TIM_CB_OVF            0
#define TIM_CB_CTC            1

#define TIMER0                0
#define TIMER1                1
#define TIMER2                2

#define ICI                   1

typedef enum
{
	ICU_Falling,
	ICU_Rising
}ICU_Trigger_t;

void MTIMER_vInit(void);
void MTIMER_vSetPreloadValue(u8 A_u8TimerId ,u16 A_u16Preload);
void MTIMER_vSetCompareValue(u8 A_u8TimerId ,u16 A_u16CompareValue);
void MTIMER_vSetInterval_OVF_Asynch(u16 A_u16IntervalCounts,void (*A_fptr)(void));
void MTIMER_vSetInterval_CTC_Asynch(u16 A_u16IntervalCounts,u16 A_u16CompareValue,void (*A_fptr)(void));
void MTIMER_vStartTimer(/* Timer ID */);
void MTIMER_vStopTimer(/* Timer ID */);
void MTIMER_vSetcallback(/* Timer ID */ void(*A_xFptr)(void));
u16  MTIMER_u16GetElapsedTime(u8 A_u8TimerId);   // like millis in arduino
u16  MTIMER_u16GetCapturedValue(void);
void MTIMER_vSetICUTrigger(ICU_Trigger_t A_xIcuTrigger);
void MTIMER_vEnableInterrupt(u8 A_u8TimerId, u8 A_u8InterrutType/* OVF or Normal or Input Capture*/);
void MTIMER_vDisableInterrupt(u8 A_u8TimerId, u8 A_u8InterrutType/* OVF or Normal or Input Capture*/);


#endif /* IMT_SCHOOL_COTS_MCAL_TIMER_TIMER_INT_H_ */
