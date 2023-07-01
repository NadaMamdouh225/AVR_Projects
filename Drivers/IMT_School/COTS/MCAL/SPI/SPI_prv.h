/*
 * SPI_prv.h
 *
 *  Created on: Oct 5, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_MCAL_SPI_SPI_PRV_H_
#define IMT_SCHOOL_COTS_MCAL_SPI_SPI_PRV_H_


#define SPCR            *((volatile u8*)(0x2D))
#define SPSR            *((volatile u8*)(0x2E))
#define SPDR            *((volatile u8*)(0x2F))

#define SPIF            7

#define SPI_MASTER      0
#define SPI_SLAVE       1

#endif /* IMT_SCHOOL_COTS_MCAL_SPI_SPI_PRV_H_ */
