/*
 * TWI_prg.c
 *
 *  Created on: Nov 16, 2022
 *      Author: Nada Mamdouh
 */
#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_MATH.h"

#include "TWI_int.h"
#include "TWI_prv.h"
#include "TWI_cfg.h"

void MTWI_vInit(void)
{
	/* interrupt enable/disable*/
	CLR_BIT(TWCR,TWIE);
	/* bit rate*/
	TWBR = 10;
}
void MTWI_vSendStartCondition(void)
{

}
void MTWI_vSendSlaveAddressRW(u8 A_u8SLA, u8 A_u8RW)
{

}
void MTWI_vSendByte(u8 A_u8Byte)
{

}
u8   MTWI_u8RecieveByte(u8 A_u8Ack)
{

}
void MTWI_vSendStopCondition(void)
{

}
u8   MTWI_u8GetStatus(void)
{

}

