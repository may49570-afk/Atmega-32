/*
 * ICU_private.h
 *
 *  Created on: Sep 3, 2026
 *      Author:Mai Essam
 */

#ifndef ICU_PRIVATE_H_
#define ICU_PRIVATE_H_

#include "../DIO/LIB/BIT_MATH.h"

#define NULL 				0

//GIE
#define SREG 				(*(int *)(0x58))
#define I 					7

#define TCCR1A 				*((volatile u8*)(0x4F))
#define TCCR1B 				*((volatile u8*)(0x4E))
#define TIMSK 				*((volatile u8*)(0x59))
#define TIFR 				*((volatile u8*)(0x58))

//TCNTA
#define TCNT1H 				*((volatile u8*)(0x4D))
#define TCNT1L 				*((volatile u8*)(0x4C))
#define TCNT1 				*((volatile u16*)(0x4C))

//OCR1A
#define OCR1AH 				*((volatile u8*)(0x4B))
#define OCR1AL 				*((volatile u8*)(0x4A))
#define OCR1A 				*((volatile u16*)(0x4A))

//OCR1B
#define OCR1BH 				*((volatile u8*)(0x49))
#define OCR1BL 				*((volatile u8*)(0x48))
#define OCR1B 				*((volatile u16*)(0x48)

//ICR
#define ICR1H 				*((volatile u8*)(0x47))
#define ICR1L 				*((volatile u8*)(0x46))
#define ICR1 				*((volatile u16*)(0x46))

//TCCR1A
#define COM1A1 				7
#define COM1A0 				6
#define COM1B1 				5
#define COM1B0	 			4
#define FOC1A 				3
#define FOC1B 				2
#define WGM11 				1
#define WGM10 				0

//TCCR1B
#define ICNC1 				7
#define ICES1 				6

#define WGM13 				4
#define WGM12 				3
#define CS12 				2
#define CS11 				1
#define CS10 				0

//TIMSK
#define TICIE1				5
#define OCIE1A				4
#define OCIE1B				3
#define TOIE1				2

//TIFR
#define ICF1				5
#define OCF1A				4
#define OCF1B				3
#define TOV1				2


#define ICU_PRESCALER_MSK 			0xF8



#endif /* ICU_PRIVATE_H_ */
