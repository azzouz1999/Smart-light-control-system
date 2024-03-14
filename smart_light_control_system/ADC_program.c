/*
 * ADC_program.c

 *
 *  Created on: Mar 4, 2024
 *      Author: ali_a
 */
#include "STD_types.h"
#include "BIT_math.h"
#include "ADC_interface.h"
#include "ADC_private.h"

void ADC_voidInit(u8 copy_u8ReferenceVoltage, u8 copy_u8Prescaler)
{
	if((copy_u8ReferenceVoltage<=1 || copy_u8ReferenceVoltage==3)&&(copy_u8Prescaler<=7))
	{
		ADMUX = (ADMUX & 0x3F) | (copy_u8ReferenceVoltage<<REFS0);  //mask all bits except 6&7 (0x3f) and write refv in them
		ADCSRA = (ADCSRA &  0xF8) | copy_u8Prescaler;
	}
	else
	{
		/*report an error*/
	}
	CLEAR_BIT(ADMUX,ADLAR); //Right adjust
	CLEAR_BIT(ADCSRA,ADIE);  //disable interrupt
	CLEAR_BIT(ADCSRA,ADATE);  //disable AutoTrigger
	SET_BIT(ADCSRA,ADEN);  // Enable ADC

}
void ADC_voidReadDigitalValue(u8 copy_u8Channel,u16 * copy_pu16read)
{

	if(copy_u8Channel<=31)
		{
			ADMUX = (ADMUX & 0xE0) | copy_u8Channel ;      /*choose pin*/

			SET_BIT(ADCSRA,ADSC);  /*start conversion bit*/

			while(GET_BIT(ADCSRA,ADIF)==0);  /*polling*/

			SET_BIT(ADCSRA,ADIF);         /*clear flag*/

			*copy_pu16read=ADCL;			/*read flag*/

		}
		else
		{
		/*error*/
		}
}

