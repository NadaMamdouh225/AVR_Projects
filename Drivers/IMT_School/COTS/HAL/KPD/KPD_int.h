/*
 * KPD_int.h
 *
 *  Created on: Jul 2, 2022
 *      Author: Nada Mamdouh
 */

#ifndef IMT_SCHOOL_COTS_HAL_KPD_KPD_INT_H_
#define IMT_SCHOOL_COTS_HAL_KPD_KPD_INT_H_


#define KPD_PORT    DIO_PORTB
#define ROWS          4
#define COLS          4

/*
 * 	u8 KeyMap[ROWS][COLS] = {   {'1','2','3','A' },
					            {'4','5','6','B' },
				                {'7','8','9','C' },
					            {'*','0','#','D' }
			                                             };

 *
 */


void KPD_vInit(void);
u8 KPD_u8GetPressedKey(u8 A_u8KeyMap[ROWS][COLS]);


#endif /* IMT_SCHOOL_COTS_HAL_KPD_KPD_INT_H_ */
