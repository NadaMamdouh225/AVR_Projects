/** TIMER_prv.h
 *
 *  Created on: Jul 19, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_MCAL_TIMER_TIMER_PRV_H_
#define IMT_SCHOOL_COTS_MCAL_TIMER_TIMER_PRV_H_

#define ENABLE                1
#define DISABLE               0


#define NORMAL_OVF            0
#define PWM_PH_CORRECT        1
#define CTC                   2
#define FAST_PWM              3


#define NO_CLK                0b000
#define CLK_NO_PRESCALING     0b001
#define CLK_PRESCALING_8      0b010
#define CLK_PRESCALING_64     0b011
#define CLK_PRESCALING_256    0b100
#define CLK_PRESCALING_1024   0b101
#define EXT_CLK_FALLING_EDGE  0b110
#define EXT_CLK_RISING_EDGE   0b111


#define TOIE0                 0
#define OCIE0                 1

/*------- TCCR0 REG -------*/
#define CS00                  0
#define CS01                  1
#define CS02                  2
#define WGM01                 3
#define COM00                 4
#define COM01                 5
#define WGM00                 6
#define FOC0                  7

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

/*------- TIMSK ------- */
#define TICIE          5

/* -----------> TIMER0 REGs <----------- */
#define TCCR0         *((volatile u8*)(0x53))
#define TCNT0         *((volatile u8*)(0x52))
#define OCR0          *((volatile u8*)(0x5C))
#define TIMSK         *((volatile u8*)(0x59))
#define TIFR          *((volatile u8*)(0x58))

/* -----------> TIMER1 REGs <----------- */
#define TCCR1A        *((volatile u8*)(0x4F))
#define TCCR1B        *((volatile u8*)(0x4E))
#define TCNT1         *((volatile u16*)(0x4C))
#define OCR1A         *((volatile u16*)(0x4A))
#define OCR1B         *((volatile u16*)(0x48))
#define ICR1          *((volatile u16*)(0x46))


#endif /* IMT_SCHOOL_COTS_MCAL_TIMER_TIMER_PRV_H_ */
