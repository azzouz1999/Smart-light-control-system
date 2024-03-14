/************************************/
/* Author		: Ali Azzouz		*/
/* SWC			: LCD				*/
/* Layer		: HAL       	    */
/* Version		: 1.0				*/
/* Date			: march 2,2024	    */
/* Last Edit	: N/A			 	*/
/************************************/
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*Available modes*/
#define LCD_4_BIT 4
#define LCD_8_BIT 8

/*choose mode*/
#define LCD_MODE  LCD_4_BIT

/*data and control port for either 4 or 8 bit*/
#define LCD_Data_Port DIO_PORTD
#define LCD_Ctrl_Port DIO_PORTC

/*control pins for either 4 or 8 bit*/
#define LCD_RS_Pin	0
#define LCD_RW_Pin	1
#define LCD_EN_Pin	2

/*data pins for 4 bit*/
#define LCD_4Bit_Pin4   0
#define LCD_4Bit_Pin5   1
#define LCD_4Bit_Pin6   2
#define LCD_4Bit_Pin7   3

/*data pins for 8 bit*/
#define LCD_8Bit_Pin0   0
#define LCD_8Bit_Pin1   1
#define LCD_8Bit_Pin2   2
#define LCD_8Bit_Pin3   3
#define LCD_8Bit_Pin4   4
#define LCD_8Bit_Pin5   5
#define LCD_8Bit_Pin6   6
#define LCD_8Bit_Pin7   7


#endif /*_HLCD_CONFIG_H_*/
