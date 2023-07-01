/*
 * SERVO_prg.c
 *
 *  Created on: Sep 19, 2022
 *      Author: Nada Mamdouh
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"

#include "SERVO_int.h"
#include "SERVO_cfg.h"
#include "SERVO_prv.h"


void HSERVO_vInit(void)
{
	/* TCCR1A REG */
	CLR_BIT(TCCR1A,FOC1A);
	CLR_BIT(TCCR1A,FOC1B);
	CLR_BIT(TCCR1A,COM1B0);
	CLR_BIT(TCCR1A,COM1B1);
	/* Fast PWM Mode channel A */
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	/* Waveform Generation */ /* TOP = ICR1 */
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);

	/* TCCR1B REG */
	CLR_BIT(TCCR1B,ICNC1);
	CLR_BIT(TCCR1B,ICES1);
	CLR_BIT(TCCR1B,RESERVED_BIT);
	/* Waveform Generation */
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	/* CLK Selection 64 */
	CLR_BIT(TCCR1B,CS12);
	SET_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS10);

	/* Frequency */
	ICR1 = 625; // 20ms

}


void HSERVO_vAttach(u8 A_u8PortNum,u8 A_u8PinNum)
{
	DIO_vSetPinDir(A_u8PortNum,A_u8PinNum,DIO_OUTPUT);
}

void HSERVO_vWrite(u8 A_u8SetAngle)
{    /* Duty Cycle*/
	OCR1A = ((125 * A_u8SetAngle)/180) + 125 ;
}

