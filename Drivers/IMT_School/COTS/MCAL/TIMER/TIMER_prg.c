/*
 * TIMER_prg.c
 *
 *  Created on: Jul 19, 2022
 *      Author: Nada Mamdouh
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER_int.h"
#include "TIMER_prv.h"
#include "TIMER_cfg.h"


void (*G_TIM0_OVF_Callback)(void);
u32 G_u32IntervalCount;

void MTIMER_vInit(void)
{  /**
    * Mode: Normal Overflow
    * Interrupt :enable Overflow interrupt
    * Prescaler: No CLK -> timer stopped
    *
    */
	TCCR0 = 0x00;
	SET_BIT(TIMSK,TOIE0);

}
void MTIMER_vSetPreloadValue(/*Timer ID ? */u16 A_u16Preload)
{
	TCNT0 = A_u16Preload;
}
void MTIMER_vSetInterval_Asynch(u16 A_u16IntervalCounts,void (*A_fptr)(void))
{
	G_u32IntervalCount = A_u16IntervalCounts;
	G_TIM0_OVF_Callback = A_fptr;
	/* start timer */
	MTIMER_vStartTimer();

}
void MTIMER_vStartTimer(/* Timer ID */)
{
#if CLOCK_SELECT == NO_CLK
	TCCR0 = (TCCR0 & 0xF8) | (NO_CLK);
#elif CLOCK_SELECT == CLK_NO_PRESCALING
	TCCR0 = (TCCR0 & 0xF8) | (CLK_NO_PRESCALING);
#elif CLOCK_SELECT == CLK_PRESCALING_8
	TCCR0 = (TCCR0 & 0xF8) | (CLK_PRESCALING_8);
#elif CLOCK_SELECT == CLK_PRESCALING_64
	TCCR0 = (TCCR0 & 0xF8) | (CLK_PRESCALING_64);
#elif CLOCK_SELECT == CLK_PRESCALING_256
	TCCR0 = (TCCR0 & 0xF8) | (CLK_PRESCALING_256);
#elif CLOCK_SELECT == CLK_PRESCALING_1024
	TCCR0 = (TCCR0 & 0xF8) | (CLK_PRESCALING_1024);
#elif CLOCK_SELECT == EXT_CLK_FALLING_EDGE
	TCCR0 = (TCCR0 & 0xF8) | (EXT_CLK_FALLING_EDGE);
#elif CLOCK_SELECT == EXT_CLK_RISING_EDGE
	TCCR0 = (TCCR0 & 0xF8) | (EXT_CLK_RISING_EDGE);

#endif
}
void MTIMER_vStopTimer(/* Timer ID */)
{
	TCCR0 = (TCCR0 & 0xF8) | (NO_CLK);
}


void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	 static u32 LS_u32Counter = 0;

	 LS_u32Counter++;
	 if (LS_u32Counter == G_u32IntervalCount)
	 {
		 if(G_TIM0_OVF_Callback != NULL)
		      {
		     	 G_TIM0_OVF_Callback();
		     	LS_u32Counter = 0;
		      }
	 }

}




