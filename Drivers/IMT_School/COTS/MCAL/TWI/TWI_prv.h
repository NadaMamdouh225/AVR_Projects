/*
 * TWI_prv.h
 *
 *  Created on: Nov 16, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_MCAL_TWI_TWI_PRV_H_
#define IMT_SCHOOL_COTS_MCAL_TWI_TWI_PRV_H_

#define TWBR           *((volatile u8*)(0x20))
#define TWCR           *((volatile u8*)(0x56))
#define TWSR           *((volatile u8*)(0x21))
#define TWDR           *((volatile u8*)(0x23))
#define TWAR           *((volatile u8*)(0x22))


#define TWIE        0



#endif /* IMT_SCHOOL_COTS_MCAL_TWI_TWI_PRV_H_ */
