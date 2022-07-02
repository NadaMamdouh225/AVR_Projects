/*
 * KPD_int.h
 *
 *  Created on: Jul 2, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_HAL_KPD_KPD_INT_H_
#define IMT_SCHOOL_COTS_HAL_KPD_KPD_INT_H_


#define KPD_PORT    DIO_PORTB


void KPD_vInit(void);
u8 KPD_u8GetPressedKey(void);

#endif /* IMT_SCHOOL_COTS_HAL_KPD_KPD_INT_H_ */
