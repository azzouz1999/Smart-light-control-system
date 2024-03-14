/************************************/
/* Author		: Ali Azzouz		*/
/* SWC			: DIO				*/
/* Layer		: MCAL			    */
/* Version		: 1.0				*/
/* Date			: February 29,2024	*/
/* Last Edit	: N/A			 	*/
/************************************/
#include "STD_types.h"
#include "BIT_math.h"

#include "DIO_interface.h"
#include "DIO_private.h"

void DIO_voidSetPinDirection            (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection)
{
	
	if(copy_u8PinId<=7)
	{
		if(DIO_PIN_INPUT==copy_u8PinDirection)
		{
			switch(copy_u8PortId)
			{
			case DIO_PORTA: CLEAR_BIT(GPIOA ->DDR,copy_u8PinId); break;
			case DIO_PORTB: CLEAR_BIT(GPIOB ->DDR,copy_u8PinId); break;
			case DIO_PORTC: CLEAR_BIT(GPIOC ->DDR,copy_u8PinId); break;
			case DIO_PORTD: CLEAR_BIT(GPIOD ->DDR,copy_u8PinId); break;
			default: break;
		
			}
		}
		else if(DIO_PIN_OUTPUT==copy_u8PinDirection)
		{
			switch(copy_u8PortId)
			{
			case DIO_PORTA: SET_BIT(GPIOA ->DDR,copy_u8PinId); break;
			case DIO_PORTB: SET_BIT(GPIOB ->DDR,copy_u8PinId); break;
			case DIO_PORTC: SET_BIT(GPIOC ->DDR,copy_u8PinId); break;
			case DIO_PORTD: SET_BIT(GPIOD ->DDR,copy_u8PinId); break;
			default: break;
			}
		
		
		}
		else if(DIO_PIN_INPUT_PULLUP==copy_u8PinDirection)
		{
			
				switch(copy_u8PortId)
			{
			case DIO_PORTA: CLEAR_BIT(GPIOA ->DDR,copy_u8PinId); SET_BIT(GPIOA ->PORT,copy_u8PinId); break;
			case DIO_PORTB: CLEAR_BIT(GPIOB ->DDR,copy_u8PinId); SET_BIT(GPIOB ->PORT,copy_u8PinId); break;
			case DIO_PORTC: CLEAR_BIT(GPIOC ->DDR,copy_u8PinId); SET_BIT(GPIOC ->PORT,copy_u8PinId); break;
			case DIO_PORTD: CLEAR_BIT(GPIOD ->DDR,copy_u8PinId); SET_BIT(GPIOD ->PORT,copy_u8PinId); break;
			default: break;
			}
			
		}
		else
		{
	/*report an error*/
		}
		
	}
	else
	{
	/*report an error*/
	}
}

void DIO_voidSetPinValue                (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue)
{
	if(copy_u8PinId<=7)
	{
		if(DIO_PIN_LOW==copy_u8PinValue )
		{
		switch(copy_u8PortId)
			{
			case DIO_PORTA: CLEAR_BIT(GPIOA ->PORT,copy_u8PinId); break;
			case DIO_PORTB: CLEAR_BIT(GPIOB ->PORT,copy_u8PinId); break;
			case DIO_PORTC: CLEAR_BIT(GPIOC ->PORT,copy_u8PinId); break;
			case DIO_PORTD: CLEAR_BIT(GPIOD ->PORT,copy_u8PinId); break;
			default: break;
			}	
			
		}
	    else if (DIO_PIN_HIGH==copy_u8PinValue)
		{
			switch(copy_u8PortId)
			{
			case DIO_PORTA: SET_BIT(GPIOA ->PORT,copy_u8PinId); break;
			case DIO_PORTB: SET_BIT(GPIOB ->PORT,copy_u8PinId); break;
			case DIO_PORTC: SET_BIT(GPIOC ->PORT,copy_u8PinId); break;
			case DIO_PORTD: SET_BIT(GPIOD ->PORT,copy_u8PinId); break;
			default: break;
			}	
			
		}
         else if(DIO_PIN_TOGGLE==copy_u8PinValue)
		 {
			 	switch(copy_u8PortId)
			{
			case DIO_PORTA: TOGGLE_BIT(GPIOA ->PORT,copy_u8PinId); break;
			case DIO_PORTB: TOGGLE_BIT(GPIOB ->PORT,copy_u8PinId); break;
			case DIO_PORTC: TOGGLE_BIT(GPIOC ->PORT,copy_u8PinId); break;
			case DIO_PORTD: TOGGLE_BIT(GPIOD ->PORT,copy_u8PinId); break;
			default: break;
			}	
		 
		 }
		 else
		 {
			 /*report an error*/
		 }
	}
	else
	{
			 /*report an error*/
	}
		 
}

void DIO_voidGetPinValue                (u8 copy_u8PortId, u8 copy_u8PinId, u8* copy_pu8PinValue)
{
	if(copy_u8PinId<=7)
	{
		switch(copy_u8PortId)
		{
		case DIO_PORTA: * copy_pu8PinValue = GET_BIT(GPIOA -> PIN, copy_u8PinId); break;
		case DIO_PORTB: * copy_pu8PinValue = GET_BIT(GPIOB -> PIN, copy_u8PinId); break;
		case DIO_PORTC: * copy_pu8PinValue = GET_BIT(GPIOC -> PIN, copy_u8PinId); break;
		case DIO_PORTD: * copy_pu8PinValue = GET_BIT(GPIOD -> PIN, copy_u8PinId); break;
		default: break;
		}
		
	}
	else
	{
		 /*report an error*/
	}
	
}
void DIO_voidTogglePinValue             (u8 copy_u8PortId, u8 copy_u8PinId)
{
	if(copy_u8PinId>=7)
	{
		 	switch(copy_u8PortId)
			{
			case DIO_PORTA: TOGGLE_BIT(GPIOA ->PORT,copy_u8PinId); break;
			case DIO_PORTB: TOGGLE_BIT(GPIOB ->PORT,copy_u8PinId); break;
			case DIO_PORTC: TOGGLE_BIT(GPIOC ->PORT,copy_u8PinId); break;
			case DIO_PORTD: TOGGLE_BIT(GPIOD ->PORT,copy_u8PinId); break;
			default: break;
			}
		
	}
	else
	{
			 /*report an error*/
	}
}

void DIO_voidActivePinInPullUpResistance(u8 copy_u8PortId, u8 copy_u8PinId)
{
	if(copy_u8PinId>=7)
	{
		switch(copy_u8PortId)
			{
			case DIO_PORTA: CLEAR_BIT(GPIOA ->DDR,copy_u8PinId); SET_BIT(GPIOA ->PORT,copy_u8PinId); break;
			case DIO_PORTB: CLEAR_BIT(GPIOB ->DDR,copy_u8PinId); SET_BIT(GPIOB ->PORT,copy_u8PinId); break;
			case DIO_PORTC: CLEAR_BIT(GPIOC ->DDR,copy_u8PinId); SET_BIT(GPIOC ->PORT,copy_u8PinId); break;
			case DIO_PORTD: CLEAR_BIT(GPIOD ->DDR,copy_u8PinId); SET_BIT(GPIOD ->PORT,copy_u8PinId); break;
			default: break;
			}
	}
	else
	{
			/*report an error*/
	}
}

void DIO_voidSetPortDirection            (u8 copy_u8PortId, u8 copy_u8PortDirection)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA: GPIOA -> DDR = copy_u8PortDirection; break;
		case DIO_PORTB: GPIOB -> DDR = copy_u8PortDirection; break;
		case DIO_PORTC: GPIOC -> DDR = copy_u8PortDirection; break;
		case DIO_PORTD: GPIOD -> DDR = copy_u8PortDirection; break;
		default: break;
		
	}
}
void DIO_voidSetPortValue                (u8 copy_u8PortId, u8 copy_u8PortValue)
{
		switch(copy_u8PortId)
	{
		case DIO_PORTA: GPIOA -> PORT = copy_u8PortValue; break;
		case DIO_PORTB: GPIOB -> PORT = copy_u8PortValue; break;
		case DIO_PORTC: GPIOC -> PORT = copy_u8PortValue; break;
		case DIO_PORTD: GPIOD -> PORT = copy_u8PortValue; break;
		default: break;
		
	}
	
}
void DIO_voidGetPortValue                (u8 copy_u8PortId, u8* copy_pu8PortValue)
{
		switch(copy_u8PortId)
	{
		case DIO_PORTA: * copy_pu8PortValue = GPIOA -> PIN; break;
		case DIO_PORTB: * copy_pu8PortValue = GPIOB -> PIN; break;
		case DIO_PORTC: * copy_pu8PortValue = GPIOC -> PIN; break;
		case DIO_PORTD: * copy_pu8PortValue = GPIOD -> PIN; break;
		default: break;
		
	}
}

void DIO_voidTogglePortValue             (u8 copy_u8PortId)
{
	
		switch(copy_u8PortId)
	{
		case DIO_PORTA: GPIOA -> PORT^= DIO_PORT_HIGH; break;
		case DIO_PORTB: GPIOB -> PORT^= DIO_PORT_HIGH; break;
		case DIO_PORTC: GPIOC -> PORT^= DIO_PORT_HIGH; break;
		case DIO_PORTD: GPIOD -> PORT^= DIO_PORT_HIGH; break;
		default: break;
		
	}

}
void DIO_voidActivePortInPullUpResistance(u8 copy_u8PortId)
{
			switch(copy_u8PortId)
	{
		case DIO_PORTA: GPIOA -> PORT = DIO_PORT_HIGH; break;
		case DIO_PORTB: GPIOB -> PORT = DIO_PORT_HIGH; break;
		case DIO_PORTC: GPIOC -> PORT = DIO_PORT_HIGH; break;
		case DIO_PORTD: GPIOD -> PORT = DIO_PORT_HIGH; break;
		default: break;
		
	}
}
