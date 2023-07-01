/*
 * TWI_int.h
 *
 *  Created on: Nov 16, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_MCAL_TWI_TWI_INT_H_
#define IMT_SCHOOL_COTS_MCAL_TWI_TWI_INT_H_


void MTWI_vInit(void);
void MTWI_vSendStartCondition(void);
void MTWI_vSendSlaveAddressRW(u8 A_u8SLA, u8 A_u8RW);
void MTWI_vSendByte(u8 A_u8Byte);
u8   MTWI_u8RecieveByte(u8 A_u8Ack);
void MTWI_vSendStopCondition(void);
u8   MTWI_u8GetStatus(void);

void MTWI_vSetBitRate(u32 A_u32BitRate);
void MTWI_vSetSlaveAddress(u8 A_u8UwnSLA);

#endif /* IMT_SCHOOL_COTS_MCAL_TWI_TWI_INT_H_ */
