/************************************/
/* Author		: Ali Azzouz		*/
/* SWC			: LCD				*/
/* Layer		: HAL       	    */
/* Version		: 1.0				*/
/* Date			: march 2,2024	    */
/* Last Edit	: N/A			 	*/
/************************************/
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_



void LCD_voidInit(void);
void LCD_voidWriteCmd(u8 copy_u8Cmd);

void LCD_voidClearScreen(void);
void LCD_voidSetCursor(u8 copy_u8Row,u8 copy_u8Col);
void LCD_voidCreateChar(u8 copy_u8AddressData, u8 * copy_u8charArr);

void LCD_voidWriteChar(char copy_charChar);
void LCD_voidWriteString(const char* copy_ccharpString);
void LCD_voidWriteNum(u32 copy_u32Num);


#endif  /*LCD_INTERFACE_H_*/
