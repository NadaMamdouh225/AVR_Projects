/*
 * SERVO_prv.h
 *
 *  Created on: Sep 19, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_HAL_SERVO_SERVO_PRV_H_
#define IMT_SCHOOL_COTS_HAL_SERVO_SERVO_PRV_H_

/*------- TCCR1A REG -------*/
#define WGM10                  0
#define WGM11                  1
#define FOC1B                  2
#define FOC1A                  3
#define COM1B0                 4
#define COM1B1                 5
#define COM1A0                 6
#define COM1A1                 7

/*------- TCCR1B REG -------*/
#define CS10                   0
#define CS11                   1
#define CS12                   2
#define WGM12                  3
#define WGM13                  4
#define RESERVED_BIT           5
#define ICES1                  6
#define ICNC1                  7


/* -----------> TIMER1 REGs <----------- */
#define TCCR1A        *((volatile u8*)(0x4F))
#define TCCR1B        *((volatile u8*)(0x4E))
#define TCNT1         *((volatile u16*)(0x4C))
#define OCR1A         *((volatile u16*)(0x4A))
#define OCR1B         *((volatile u16*)(0x48))
#define ICR1          *((volatile u16*)(0x46))



#endif /* IMT_SCHOOL_COTS_HAL_SERVO_SERVO_PRV_H_ */
