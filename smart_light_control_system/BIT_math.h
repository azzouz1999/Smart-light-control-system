/************************************/
/* Author		: Ali Azzouz		*/
/* SWC			: BIT_math			*/
/* Layer		: Library		    */
/* Version		: 1.0				*/
/* Date			: February 26,2024	*/
/* Last Edit	: N/A			 	*/
/************************************/
#ifndef _LBIT_MATH_H_
#define _LBIT_MATH_H_

#define SET_BIT(reg,bit)		reg = reg | (1<<bit)

#define CLEAR_BIT(reg,bit)		reg = reg & ~(1<<bit)

#define GET_BIT(reg,bit)		((reg >> bit) & 1)

#define TOGGLE_BIT(reg,bit)     reg = reg ^ (1<<bit)

#endif /*_LBIT_MATH_H_*/