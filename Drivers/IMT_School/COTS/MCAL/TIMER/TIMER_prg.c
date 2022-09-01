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


void G_TIM0_OF_CallBack();

void MTIMER_vInit(void)
{  /**
    * Mode: Normal Overflow
    * Interrupt :enable Overflow interrupt
    * Prescaler: No CLK -> timer stop
    *
    */
	TCCR0 = 0x00;
	SET_BIT(TIMSK,0);

}
void MTIMER_vSetPreloadValue(/*Timer ID ? */u16 A_u16Preload)
{
	TCNT0 = A_u16Preload;
}
void MTIMER_vSetInterval_Asynch(u16 A_u16IntervalCounts,void (*A_fptr)(void))
{

}
void MTIMER_vStartTimer(/* Timer ID */)
{
	TCCR0 = (TCCR0 & 0xF8) | (0b010);
}
void MTIMER_vStopTimer(/* Timer ID */)
{
	TCCR0 = (TCCR0 & 0xF8) | (0b000);
}


void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
     if(G_TIM0_OF_CallBack != NULL)
     {
    	 G_TIM0_OF_CallBack();
     }
}




