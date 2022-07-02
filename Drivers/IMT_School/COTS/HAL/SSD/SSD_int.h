/*
 * SSD_int.h
 *
 *  Created on: Jul 1, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_HAL_SSD_SSD_INT_H_
#define IMT_SCHOOL_COTS_HAL_SSD_SSD_INT_H_


#define COM_CATHODE      1
#define COM_ANODE        0

#define SSD_TYPE   COM_ANODE
#define SSD_PORT   DIO_PORTB

void SSD_vInit(void);
void SSD_vDisplayNum(u8 A_u8Num);
void SSD_vTurnOff(void);


#endif /* IMT_SCHOOL_COTS_HAL_SSD_SSD_INT_H_ */
