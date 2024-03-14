/************************************/
/* Author		: Ali Azzouz		*/
/* SWC			: LCD				*/
/* Layer		: HAL       	    */
/* Version		: 1.0				*/
/* Date			: march 2,2024	    */
/* Last Edit	: N/A			 	*/
/************************************/
#include <util/delay.h>

#include "BIT_math.h"
#include "STD_types.h"

#include "DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

void LCD_voidInit(void)
{
	/*control pins*/
	DIO_voidSetPinDirection(LCD_Ctrl_Port,LCD_EN_Pin,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_Ctrl_Port,LCD_RS_Pin,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_Ctrl_Port,LCD_RW_Pin,DIO_PIN_OUTPUT);

	/*4bit or 8bit data initialization */


	#if LCD_MODE == LCD_4_BIT
	/*choose the 4 bits of data*/
	DIO_voidSetPinDirection(LCD_Data_Port,LCD_4Bit_Pin4,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_Data_Port,LCD_4Bit_Pin5,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_Data_Port,LCD_4Bit_Pin6,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_Data_Port,LCD_4Bit_Pin7,DIO_PIN_OUTPUT);

	_delay_ms(40);
	LCD_voidWriteCmd(0x33);
	LCD_voidWriteCmd(0x32);
	LCD_voidWriteCmd(0x28);
	_delay_ms(1);
	LCD_voidWriteCmd(0x0E);
	_delay_ms(1);
	LCD_voidWriteCmd(0x01);
	_delay_ms(2);

	
	#elif LCD_MODE == LCD_8_BIT

	/*choose the 4 bits of data*/

	DIO_voidSetPinDirection(LCD_Data_Port, LCD_8Bit_Pin0, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_Data_Port, LCD_8Bit_Pin1, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_Data_Port, LCD_8Bit_Pin2, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_Data_Port, LCD_8Bit_Pin3, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_Data_Port, LCD_8Bit_Pin4, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_Data_Port, LCD_8Bit_Pin5, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_Data_Port, LCD_8Bit_Pin6, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_Data_Port, LCD_8Bit_Pin7, DIO_PIN_OUTPUT);

	
	_delay_ms(30);
	LCD_voidWriteCmd(0x3F);  /*function set */
	_delay_us(40);
	LCD_voidWriteCmd(0x0F); /*Display command*/
	_delay_us(40);
	LCD_voidClearScreen();
	LCD_voidWriteCmd(0x06);/*Entry mode set*/
	_delay_us(40);

	#endif

}

void LCD_voidWriteCmd(u8 copy_u8Cmd)
{
	DIO_voidSetPinValue(LCD_Ctrl_Port, LCD_RS_Pin, DIO_PIN_LOW); /*command*/
	DIO_voidSetPinValue(LCD_Ctrl_Port, LCD_RW_Pin, DIO_PIN_LOW); /*write*/
	
#if LCD_MODE == LCD_4_BIT

	DIO_voidSetPinValue(LCD_Data_Port, LCD_4Bit_Pin4, (GET_BIT(copy_u8Cmd,4)));
	DIO_voidSetPinValue(LCD_Data_Port, LCD_4Bit_Pin5, (GET_BIT(copy_u8Cmd,5)));
	DIO_voidSetPinValue(LCD_Data_Port, LCD_4Bit_Pin6, (GET_BIT(copy_u8Cmd,6)));
	DIO_voidSetPinValue(LCD_Data_Port, LCD_4Bit_Pin7, (GET_BIT(copy_u8Cmd,7)));


	DIO_voidSetPinValue(LCD_Ctrl_Port,LCD_EN_Pin,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_Ctrl_Port,LCD_EN_Pin,DIO_PIN_LOW);
	_delay_ms(5);


	DIO_voidSetPinValue(LCD_Data_Port ,LCD_4Bit_Pin4, (GET_BIT(copy_u8Cmd,0)));
	DIO_voidSetPinValue(LCD_Data_Port ,LCD_4Bit_Pin5, (GET_BIT(copy_u8Cmd,1)));
	DIO_voidSetPinValue(LCD_Data_Port ,LCD_4Bit_Pin6, (GET_BIT(copy_u8Cmd,2)));
	DIO_voidSetPinValue(LCD_Data_Port ,LCD_4Bit_Pin7, (GET_BIT(copy_u8Cmd,3)));


    DIO_voidSetPinValue(LCD_Ctrl_Port,LCD_EN_Pin, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_Ctrl_Port,LCD_EN_Pin, DIO_PIN_LOW);
	_delay_ms(5);

	
	
#elif LCD_MODE == LCD_8_BIT

	DIO_voidSetPinValue(LCD_Data_Port, LCD_8Bit_Pin0, (GET_BIT(copy_u8Cmd,0)));
	DIO_voidSetPinValue(LCD_Data_Port, LCD_8Bit_Pin1, (GET_BIT(copy_u8Cmd,1)));
	DIO_voidSetPinValue(LCD_Data_Port, LCD_8Bit_Pin2, (GET_BIT(copy_u8Cmd,2)));
	DIO_voidSetPinValue(LCD_Data_Port, LCD_8Bit_Pin3, (GET_BIT(copy_u8Cmd,3)));
	DIO_voidSetPinValue(LCD_Data_Port, LCD_8Bit_Pin4, (GET_BIT(copy_u8Cmd,4)));
	DIO_voidSetPinValue(LCD_Data_Port, LCD_8Bit_Pin5, (GET_BIT(copy_u8Cmd,5)));
	DIO_voidSetPinValue(LCD_Data_Port, LCD_8Bit_Pin6, (GET_BIT(copy_u8Cmd,6)));
	DIO_voidSetPinValue(LCD_Data_Port, LCD_8Bit_Pin7, (GET_BIT(copy_u8Cmd,7)));

	DIO_voidSetPinValue(LCD_Ctrl_Port,LCD_EN_Pin,DIO_PIN_LOW);
	DIO_voidSetPinValue(LCD_Ctrl_Port,LCD_EN_Pin,DIO_PIN_HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_Ctrl_Port,LCD_EN_Pin,DIO_PIN_LOW);

#endif



}
void LCD_voidWriteChar(char copy_charChar)
{

DIO_voidSetPinValue(LCD_Ctrl_Port,LCD_RS_Pin,DIO_PIN_HIGH);  /*data*/
DIO_voidSetPinValue(LCD_Ctrl_Port,LCD_RW_Pin,DIO_PIN_LOW);  /*data*/

#if LCD_MODE== LCD_4_BIT


DIO_voidSetPinValue(LCD_Data_Port ,LCD_4Bit_Pin7, (GET_BIT(copy_charChar,7)));
DIO_voidSetPinValue(LCD_Data_Port ,LCD_4Bit_Pin6, (GET_BIT(copy_charChar,6)));
DIO_voidSetPinValue(LCD_Data_Port ,LCD_4Bit_Pin5, (GET_BIT(copy_charChar,5)));
DIO_voidSetPinValue(LCD_Data_Port ,LCD_4Bit_Pin4, (GET_BIT(copy_charChar,4)));

//DIO_voidSetPinValue(LCD_Ctrl_Port,LCD_EN_pin,DIO_PIN_LOW);
DIO_voidSetPinValue(LCD_Ctrl_Port,LCD_EN_Pin,DIO_PIN_HIGH);
_delay_ms(1);
DIO_voidSetPinValue(LCD_Ctrl_Port,LCD_EN_Pin,DIO_PIN_LOW);


DIO_voidSetPinValue(LCD_Data_Port ,LCD_4Bit_Pin7, (GET_BIT(copy_charChar,3)));
DIO_voidSetPinValue(LCD_Data_Port ,LCD_4Bit_Pin6, (GET_BIT(copy_charChar,2)));
DIO_voidSetPinValue(LCD_Data_Port ,LCD_4Bit_Pin5, (GET_BIT(copy_charChar,1)));
DIO_voidSetPinValue(LCD_Data_Port ,LCD_4Bit_Pin4, (GET_BIT(copy_charChar,0)));


DIO_voidSetPinValue(LCD_Ctrl_Port,LCD_EN_Pin, DIO_PIN_HIGH);
_delay_ms(1);
DIO_voidSetPinValue(LCD_Ctrl_Port,LCD_EN_Pin, DIO_PIN_LOW);

	

#elif LCD_MODE== LCD_8_BIT

	DIO_voidSetPinValue(LCD_Data_Port, LCD_8Bit_Pin0, (GET_BIT(copy_charChar,0)));
	DIO_voidSetPinValue(LCD_Data_Port, LCD_8Bit_Pin1, (GET_BIT(copy_charChar,1)));
	DIO_voidSetPinValue(LCD_Data_Port, LCD_8Bit_Pin2, (GET_BIT(copy_charChar,2)));
	DIO_voidSetPinValue(LCD_Data_Port, LCD_8Bit_Pin3, (GET_BIT(copy_charChar,3)));
	DIO_voidSetPinValue(LCD_Data_Port, LCD_8Bit_Pin4, (GET_BIT(copy_charChar,4)));
	DIO_voidSetPinValue(LCD_Data_Port, LCD_8Bit_Pin5, (GET_BIT(copy_charChar,5)));
	DIO_voidSetPinValue(LCD_Data_Port, LCD_8Bit_Pin6, (GET_BIT(copy_charChar,6)));
	DIO_voidSetPinValue(LCD_Data_Port, LCD_8Bit_Pin7, (GET_BIT(copy_charChar,7)));

	DIO_voidSetPinValue(LCD_Ctrl_Port,LCD_EN_Pin,DIO_PIN_LOW);
	DIO_voidSetPinValue(LCD_Ctrl_Port,LCD_EN_Pin,DIO_PIN_HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_Ctrl_Port,LCD_EN_Pin,DIO_PIN_LOW);

#endif


}
void LCD_voidClearScreen(void)
{
	LCD_voidWriteCmd(0x01);
	_delay_ms(2);
}
void LCD_voidSetCursor(u8 copy_u8Row,u8 copy_u8Col)
{
	LCD_voidWriteCmd((128+(copy_u8Row*64)+copy_u8Col));
}
void LCD_voidWriteString(const char* copy_ccharpString)
{
	u8 local_u8i;
	do{
		LCD_voidWriteChar(copy_ccharpString[local_u8i]);
		local_u8i++;
	  }while(copy_ccharpString[local_u8i]!='\0');

}

void LCD_voidWriteNum(u32 copy_u32Num)
{
	if(0==copy_u32Num)
	{
		LCD_voidWriteChar((copy_u32Num%10)+48);
	}
	else
	{
		u32 reverse=1;
		while(copy_u32Num!=0)
		{
			reverse=(reverse*10)+(copy_u32Num%10);
			copy_u32Num/=10;
		}
		while(reverse!=1)
		{
			LCD_voidWriteChar((reverse%10)+48);
			reverse/=10;
		}
	}
}

void LCD_voidCreateChar(u8 copy_u8AddressData, u8 * copy_u8charArr)
{
	LCD_voidWriteCmd(0x40|(copy_u8AddressData*8));  //cgram
	for(u8 i=0;i<8;i++)
	{
		LCD_voidWriteChar(copy_u8charArr[i]);
	}
	LCD_voidWriteCmd(0x80);//return to ddram
}














