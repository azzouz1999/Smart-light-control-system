/*
 * ADC_interface.h
 *
 *  Created on: Mar 4, 2024
 *      Author: ali_a
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_VREF_AREF	0
#define ADC_VREF_AVCC	1
#define ADC_VREF_2_56V 3

#define ADC_PRESCALER_2    1
#define ADC_PRESCALER_4    2
#define ADC_PRESCALER_8    3
#define ADC_PRESCALER_16   4
#define ADC_PRESCALER_32	5
#define ADC_PRESCALER_64	6
#define ADC_PRESCALER_128	7

#define ADC_CHANNEL_ADC0   0
#define ADC_CHANNEL_ADC1   1
#define ADC_CHANNEL_ADC2   2
#define ADC_CHANNEL_ADC3   3
#define ADC_CHANNEL_ADC4   4
#define ADC_CHANNEL_ADC5   5
#define ADC_CHANNEL_ADC6   6
#define ADC_CHANNEL_ADC7   7

void ADC_voidInit(u8 copy_u8ReferenceVoltage, u8 copy_u8Prescaler);
void ADC_voidReadDigitalValue(u8 copy_u8Channel,u16 * copy_pu16read);

#endif /* ADC_INTERFACE_H_ */
