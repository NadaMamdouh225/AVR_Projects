/*
 * KPD_prg.c
 *
 *  Created on: Jul 2, 2022
 *      Author: Nada Mamdouh
 */

#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_int.h"
#include <util/delay.h>
#include "KPD_int.h"

void KPD_vInit(void)
{
	DIO_vSetPortDir(KPD_PORT, 0x0f);
	DIO_vSetPortVal(KPD_PORT, 0xff);
}

u8 KPD_u8GetPressedKey(u8 A_u8KeyMap[ROWS][COLS])
{

	for(u8 L_u8IDX_I = 0;L_u8IDX_I < ROWS ;L_u8IDX_I++ )
	{
		for(u8 L_u8IDX_J = 0;L_u8IDX_J < COLS ;L_u8IDX_J++ )
		{
			A_u8KeyMap[L_u8IDX_I][L_u8IDX_J] ;
		}
	}


	u8 pressed_key = 0;  // default value if nothing pressed
	for(u8 L_u8Col=0; L_u8Col<4 ;L_u8Col++)
	{
		// activate current column
		DIO_vSetPinVal(KPD_PORT,L_u8Col,DIO_LOW);

		for(u8 L_u8Row=0;L_u8Row<4;L_u8Row++)
		{
			if(DIO_u8GetPinVal(KPD_PORT,L_u8Row+4) == 0)  // a button is pressed
			{
				pressed_key = A_u8KeyMap[L_u8Row][L_u8Col];  // key number   L_u8Row + (L_u8Col*4) +1
			}
			while(DIO_u8GetPinVal(KPD_PORT,L_u8Row+4) == 0){}
			_delay_ms(10);

		}
		// deactivate column
		DIO_vSetPinVal(KPD_PORT,L_u8Col,DIO_HIGH);
	}

	return pressed_key;
}

