/************************************/
/* Author		: Ali Azzouz		*/
/* SWC			: DIO				*/
/* Layer		: MCAL			    */
/* Version		: 1.0				*/
/* Date			: February 29,2024	*/
/* Last Edit	: N/A			 	*/
/************************************/

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

typedef struct
{
	const u8 PIN;
	u8 DDR;
	u8 PORT;
	
}GPIO_t;
#define GPIOA		((volatile GPIO_t*)0x39)
#define GPIOB		((volatile GPIO_t*)0x36)
#define GPIOC		((volatile GPIO_t*)0x33)
#define GPIOD		((volatile GPIO_t*)0x30)


#endif /*_MDIO_PRIVATE_H_*/
