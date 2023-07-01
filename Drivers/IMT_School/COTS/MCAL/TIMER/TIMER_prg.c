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


//static void (*G_TIM0_OVF_Callback)(void);
//static void (*G_TIM0_CTC_Callback)(void);
u32 G_u32IntervalCount;

static void(*G_TIM0_Callback[2])(void);  // array of function pointer -- another way of organizing ur work
static void(*G_TIM1_ICU_Callback)(void);

void MTIMER_vInit(void)
{  /**
    * Mode: Normal Overflow
    * Interrupt :enable Overflow interrupt
    * Prescaler: No CLK -> timer stopped
    *
    */
#if TIMER0_ENABLE == ENABLE
    /* Wave Generation Mode */
#if WAVEFORM_GEN_MODE == NORMAL_OVF
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
#elif WAVEFORM_GEN_MODE == PWM_PH_CORRECT
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
#elif WAVEFORM_GEN_MODE == CTC
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
#elif WAVEFORM_GEN_MODE == FAST_PWM
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);

#else
#error "Please Select a Valid Timer Mode"
#endif
	/* Compare match mode */
	CLR_BIT(TCCR0,COM00);         // CLR OC0 non inverting mode on fast PWM mode
    SET_BIT(TCCR0,COM01);

	/* Interrupt enable */

	/* by Default no CLK will be selected and force output compare will be read as zero*/
    CLR_BIT(TCCR0,CS00);
    CLR_BIT(TCCR0,CS01);
    CLR_BIT(TCCR0,CS02);

    CLR_BIT(TCCR0,FOC0);
#endif

#if TIMER1_ENABLE  == ENABLE

#endif


   // TCCR0 =0b01101000 ;  // fast PWM
	//SET_BIT(TIMSK,1); // CTC mode
}
void MTIMER_vSetPreloadValue(u8 A_u8TimerId ,u16 A_u16Preload)
{
	switch(A_u8TimerId)
	{
	case TIMER0:
		TCNT0 = A_u16Preload;
		break;
	}

}

void MTIMER_vSetCompareValue(u8 A_u8TimerId ,u16 A_u16CompareValue)
{
	switch(A_u8TimerId)
		{
		case TIMER0:
			OCR0 = A_u16CompareValue;
			break;
		}


}
void MTIMER_vSetInterval_OVF_Asynch(u16 A_u16IntervalCounts,void (*A_fptr)(void))
{
	G_u32IntervalCount = A_u16IntervalCounts;
	//G_TIM0_OVF_Callback = A_fptr;
	G_TIM0_Callback[TIM_CB_OVF] = A_fptr;
	/* start timer */
	MTIMER_vStartTimer();

}

void MTIMER_vSetInterval_CTC_Asynch(u16 A_u16IntervalCounts,u16 A_u16CompareValue,void (*A_fptr)(void))
{
	G_u32IntervalCount = A_u16IntervalCounts;
	//G_TIM0_CTC_Callback = A_fptr;
	G_TIM0_Callback[TIM_CB_CTC] = A_fptr;
	MTIMER_vSetCompareValue(TIMER0,A_u16CompareValue);
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

u16  MTIMER_u16GetElapsedTime(u8 A_u8TimerId)
{
	u16 L_u16ElapsedTime = 0;
	switch(A_u8TimerId)
	{
	case TIMER0:
		L_u16ElapsedTime = TCNT0;
		break;
	case TIMER1:
		L_u16ElapsedTime = TCNT1;
		break;
	}


	return L_u16ElapsedTime;
}
void MTIMER_vSetICUTrigger(ICU_Trigger_t A_xIcuTrigger)
{
	switch(A_xIcuTrigger)
	{
	case ICU_Falling:
		CLR_BIT(TCCR1B,ICES1);
		break;
	case ICU_Rising:
		SET_BIT(TCCR1B,ICES1);
		break;

	}

}
u16  MTIMER_u16GetCapturedValue(void)
{
	return ICR1;
}
void MTIMER_vEnableInterrupt(u8 A_u8TimerId, u8 A_u8InterrutType/* OVF or Normal or Input Capture*/)
{
	switch(A_u8TimerId)
	{
	case TIMER1:
		if(A_u8InterrutType == ICI)
			SET_BIT(TIMSK,TICIE);
		break;
	}

}
void MTIMER_vDisableInterrupt(u8 A_u8TimerId, u8 A_u8InterrutType/* OVF or Normal or Input Capture*/)
{
	switch(A_u8TimerId)
		{
		case TIMER1:
			if(A_u8InterrutType == ICI)
				CLR_BIT(TIMSK,TICIE);
			break;
		}

}
void MTIMER_vSetcallback(/* Timer ID */ void(*A_xFptr)(void))
{
	G_TIM1_ICU_Callback = A_xFptr;
}
/* Timer0 OVF ISR */
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	 static u32 LS_u32Counter = 0;

	 LS_u32Counter++;
	 if (LS_u32Counter == G_u32IntervalCount)
	 {
		 if(G_TIM0_Callback[TIM_CB_OVF] != NULL)
		      {
			 G_TIM0_Callback[TIM_CB_OVF]();
		     	LS_u32Counter = 0;
		      }
	 }

}

/*Timer0 CTC ISR*/
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	 static u32 LS_u32Counter = 0;

		 LS_u32Counter++;
		 if (LS_u32Counter == G_u32IntervalCount)
		 {
			 if(G_TIM0_Callback[TIM_CB_CTC] != NULL)
			      {
				 G_TIM0_Callback[TIM_CB_CTC]();
			     	LS_u32Counter = 0;
			      }
		 }
}
/* Timer1 ICU ISR */
void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	G_TIM1_ICU_Callback();
}


