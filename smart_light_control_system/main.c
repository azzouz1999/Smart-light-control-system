/*
 * main.c
 *
 *  Created on: Mar 12, 2024
 *      Author: ali_a
 */
#include "util/delay.h"
#include "BIT_math.h"
#include"STD_types.h"

#include "KPD_interface.h"
#include "LCD_interface.h"

#include "DIO_interface.h"
#include "ADC_interface.h"

int main()
{
	u16 adc_value=0;
	u8 digital_value=0;
	u8 thershold_value=0;
	u8 count=0;
	u8 arr[2]={0};
	const char ldr_text[]="ldr value: ";
	const char kpd_text[]="kpd value: ";


	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN7,DIO_PIN_OUTPUT);
	/*ADC init and pin choice*/
	DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_INPUT);
	ADC_voidInit(ADC_VREF_AVCC,ADC_PRESCALER_2);
	/*keypad init*/
	KPD_init();
	/*lcd init*/
	LCD_voidInit();

	/*lcd text*/
	LCD_voidSetCursor(0,0);
	LCD_voidWriteString(ldr_text);
	LCD_voidSetCursor(1,0);
	LCD_voidWriteString(kpd_text);
	while(1)
	{

		ADC_voidReadDigitalValue(ADC_CHANNEL_ADC0,&adc_value);
		digital_value=adc_value/10;
		LCD_voidSetCursor(0,10);
		LCD_voidWriteNum(digital_value);//dig

		/*made this condition to not get stuck in 2nd while*/
		if(KPD_GetPressedKey()!=0)
		{
			while(count<2)
			{
				arr[count]=KPD_GetPressedKey();
				if(arr[count]==0)
				{

				}
				else
				{
					/*to avoid overwriting*/
					LCD_voidSetCursor(1,9+count);
					LCD_voidWriteChar(arr[count]);
					/*numbers coming from keypad are ascii*/
					thershold_value=((arr[0]-48)*10)+(arr[1]-48);
					_delay_ms(200);
					count++;
				}
			}

		}
		/*led on/off conditions*/
		if(thershold_value>digital_value)
		{
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,DIO_PIN_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(DIO_PORTD,DIO_PIN7,DIO_PIN_LOW);
		}

		count=0;
	}
}
