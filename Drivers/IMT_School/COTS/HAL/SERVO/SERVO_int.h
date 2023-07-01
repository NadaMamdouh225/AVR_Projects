/*
 * SERVO_int.h
 *
 *  Created on: Sep 19, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_HAL_SERVO_SERVO_INT_H_
#define IMT_SCHOOL_COTS_HAL_SERVO_SERVO_INT_H_

void HSERVO_vInit(void);
void HSERVO_vAttach(u8 A_u8PortNum,u8 A_u8PinNum);
void HSERVO_vWrite(u8 A_u8SetAngle);

#endif /* IMT_SCHOOL_COTS_HAL_SERVO_SERVO_INT_H_ */
