/** TIMER_prv.h
 *
 *  Created on: Jul 19, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_MCAL_TIMER_TIMER_PRV_H_
#define IMT_SCHOOL_COTS_MCAL_TIMER_TIMER_PRV_H_


#define TCCR0         *((volatile u8*)(0x53))
#define TCNT0         *((volatile u8*)(0x52))
#define OCR0          *((volatile u8*)(0x5C))
#define TIMSK         *((volatile u8*)(0x59))
#define TIFR          *((volatile u8*)(0x58))



#endif /* IMT_SCHOOL_COTS_MCAL_TIMER_TIMER_PRV_H_ */
