/************************************/
/* Author		: Ali Azzouz		*/
/* SWC			: HKPD				*/
/* Layer		: HAL			    */
/* Version		: 1.0				*/
/* Date			: December 16,2023	*/
/* Last Edit	: N/A			 	*/
/************************************/
#include "util/delay.h"

#include "BIT_math.h"
#include "STD_types.h"

#include "DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_config.h"
#include "KPD_private.h"
#include "KPD_Interface.h"

u8 static KPD_Arr[4][4] = { {'7','8','9','/'},
							{'4','5','6','*'},
							{'1','2','3','-'},
							{'C','0','=','+'} };

void KPD_init(void)
{
	//R0->R3 (rows)    //b0->b3 //0x0f
	//C0->C3 (columns) //b4->b7 //0xf0

	/*rows input*/
	for (u8 i=0;i<4;i++)
	{
		DIO_voidSetPinDirection(KPD_ROW_PORT, i, DIO_PIN_INPUT);
	}
	/*col output*/
	for (u8 i=4;i<8;i++)
	{
		DIO_voidSetPinDirection(KPD_COL_PORT, i, DIO_PIN_OUTPUT);
	}
	/*Output high & input pull-up*/
	DIO_voidSetPortValue(KPD_COL_PORT, 0xFF);
}

u8 KPD_GetPressedKey(void)
{
	u8 KeyValue = 1;
	u8 ReturnKeyPressed = 0;

	for(u8 col = KPD_C0 ; col <= KPD_C3 ; col++)  //4 to 7
	{
		DIO_voidSetPinValue(KPD_COL_PORT, col , DIO_PIN_LOW);

		for(u8 row = KPD_R0;  row <= KPD_R3 ; row++ )//0 to 3
		{
			DIO_voidGetPinValue(KPD_ROW_PORT, row ,&KeyValue);

			if(KeyValue==0)  //If key is pressed
			{
				ReturnKeyPressed=KPD_Arr[row-KPD_R0][col-KPD_C0];	//get the arr
				_delay_ms(50);
				while(KeyValue==0) 	//get stuck in while as long as key is pressed
				{
					DIO_voidGetPinValue(KPD_ROW_PORT, row ,&KeyValue);
				}
			}


		}
		DIO_voidSetPinValue(KPD_COL_PORT,col,DIO_PIN_HIGH);

	}
	return ReturnKeyPressed;
}
