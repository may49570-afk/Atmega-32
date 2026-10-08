/*
 * ADC_private.h
 *
 *  Created on: Sep 1, 2026
 *      Author: Mai Essam
 */

#ifndef MCAL_ADC_PRIVATE_H_
#define MCAL_ADC_PRIVATE_H_

/**
 * @brief ADC input channel pins.
 */
#define ADC_PIN0 		PIN0
#define ADC_PIN1 		PIN1
#define ADC_PIN2 		PIN2
#define ADC_PIN3 		PIN3
#define ADC_PIN4 		PIN4
#define ADC_PIN5 		PIN5
#define ADC_PIN6 		PIN6
#define ADC_PIN7 		PIN7

/**
 * @brief ADC registers and status register addresses.
 */
#define ADMUX		*((volatile u8*)0x27)
#define ADCSRA 		*((volatile u8*)0x26)
#define ADCH	 	*((volatile u16*)0x25)
#define ADCL 		*((volatile u16*)0x24)
#define ADCDATA 	*((volatile u16*)0x24)//?????????
#define SREG 		*((volatile u8*)0x5f)

/**
 * @brief ADMUX register bit positions.
 */
#define MUX0 			0
#define MUX1 			1
#define MUX2 			2
#define MUX3 			3
#define MUX4 			4
#define ADLAR 			5
#define REFS0 			6
#define REFS1 			7

/**
 * @brief ADCSRA register bit positions.
 */
#define ADPS0 			0
#define ADPS1 		 	1
#define ADPS2 		 	2
#define ADIE 		 	3
#define ADIF 		 	4
#define ADATE 		 	5
#define ADSC 		 	6
#define ADEN 		 	7

/**
 * @brief SREG register bit position.
 */
#define I 				7

/**
 * @brief ADC prescaler configuration.
 */
#define ADC_prescaler 	0x06

/**
 * @brief ADC voltage reference selection.
 */
#define V_selection 	0xC0

#endif /* MCAL_ADC_PRIVATE_H_ */