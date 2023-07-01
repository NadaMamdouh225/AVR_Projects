/*
 * TIMER_cfg.h
 *
 *  Created on: Jul 19, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_MCAL_TIMER_TIMER_CFG_H_
#define IMT_SCHOOL_COTS_MCAL_TIMER_TIMER_CFG_H_

/* ---------> Timer 0 configuration <--------- */

#define TIMER0_ENABLE              ENABLE




/**
 * CLOCK SELECT OPTIONS:
 * NO_CLK
 * CLK_NO_PRESCALING
 * CLK_PRESCALING_8
 * CLK_PRESCALING_64
 * CLK_PRESCALING_256
 * CLK_PRESCALING_1024
 * EXT_CLK_FALLING_EDGE
 * EXT_CLK_RISING_EDGE
 */
/**
 * Waveform Generation Mode Option:
 * NORMAL_OVF
 * PWM_PH_CORRECT
 * CTC
 * FAST_PWM
 *
 */

#define CLOCK_SELECT          CLK_PRESCALING_8
#define WAVEFORM_GEN_MODE     FAST_PWM

/* ---------> Timer 1 configuration <--------- */
#define TIMER1_ENABLE         DISABLE

/* ---------> Timer 2 configuration <--------- */



#endif /* IMT_SCHOOL_COTS_MCAL_TIMER_TIMER_CFG_H_ */
