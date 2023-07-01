/*
 * SPI_prg.c
 *
 *  Created on: Oct 5, 2022
 *      Author: Nada Mamdouh
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_int.h"

#include "SPI_int.h"
#include "SPI_prv.h"
#include "SPI_cfg.h"


void MSPI_vInit(void)
{
#if SPI_MODE == SPI_MASTER
	DIO_vSetPinDir(DIO_PORTB,DIO_PIN5,DIO_OUTPUT);   // MOSI ->Output
	DIO_vSetPinDir(DIO_PORTB,DIO_PIN7,DIO_OUTPUT);   // SCK -> Output
	DIO_vSetPinDir(DIO_PORTB,DIO_PIN6,DIO_INPUT);   // MISO -> Input
	DIO_vSetPinVal(DIO_PORTB,DIO_PIN6,DIO_HIGH);    //pull up resistor
#elif SPI_MODE == SPI_SLAVE
	DIO_vSetPinDir(DIO_PORTB,DIO_PIN5,DIO_INPUT);   // MOSI ->Output
	DIO_vSetPinDir(DIO_PORTB,DIO_PIN7,DIO_INPUT);   // SCK -> Output
	DIO_vSetPinDir(DIO_PORTB,DIO_PIN6,DIO_OUTPUT);   // MISO -> Input
#endif
	u8 spcr_setting = 0b01011110;   // clk rate Fosc/64

	SPCR = spcr_setting;
}
u8   MSPI_u8Transceive(u8 A_u8Data)
{
	/* Start transmission */
	SPDR = A_u8Data;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)))
	;

	return SPDR;
}
