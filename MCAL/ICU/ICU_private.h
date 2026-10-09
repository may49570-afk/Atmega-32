/**
 * @file ICU_private.h
 * @brief Private definitions for the Input Capture Unit (ICU) driver.
 *
 * This file contains the memory-mapped register definitions and bit
 * positions required to configure and control Timer1 and the ICU.
 *
 * @date Sep 3, 2026
 * @author Mai Essam
 */

#ifndef ICU_PRIVATE_H_
#define ICU_PRIVATE_H_

#include "../DIO/LIB/BIT_MATH.h"

/**
 * @brief Defines a null pointer value.
 */
#define NULL 				0

/**
 * @brief Global interrupt control register.
 */
 //GIE
#define SREG 				(*(int *)(0x58))

/**
 * @brief Global interrupt enable bit position in SREG.
 */
#define I 					7

/**
 * @brief Timer1 Control Register A.
 */
#define TCCR1A 				*((volatile u8*)(0x4F))

/**
 * @brief Timer1 Control Register B.
 */
#define TCCR1B 				*((volatile u8*)(0x4E))

/**
 * @brief Timer/Counter Interrupt Mask Register.
 */
#define TIMSK 				*((volatile u8*)(0x59))

/**
 * @brief Timer/Counter Interrupt Flag Register.
 */
#define TIFR 				*((volatile u8*)(0x58))

/**
 * @brief Timer1 Counter Register - High byte.
 */
//TCNTA
#define TCNT1H 				*((volatile u8*)(0x4D))

/**
 * @brief Timer1 Counter Register - Low byte.
 */
#define TCNT1L 				*((volatile u8*)(0x4C))

/**
 * @brief Timer1 Counter Register - 16-bit access.
 */
#define TCNT1 				*((volatile u16*)(0x4C))

/**
 * @brief Timer1 Output Compare Register A - High byte.
 */
//OCR1A
#define OCR1AH 				*((volatile u8*)(0x4B))

/**
 * @brief Timer1 Output Compare Register A - Low byte.
 */
#define OCR1AL 				*((volatile u8*)(0x4A))

/**
 * @brief Timer1 Output Compare Register A - 16-bit access.
 */
#define OCR1A 				*((volatile u16*)(0x4A))

/**
 * @brief Timer1 Output Compare Register B - High byte.
 */
//OCR1B
#define OCR1BH 				*((volatile u8*)(0x49))

/**
 * @brief Timer1 Output Compare Register B - Low byte.
 */
#define OCR1BL 				*((volatile u8*)(0x48))

/**
 * @brief Timer1 Output Compare Register B - 16-bit access.
 */
#define OCR1B 				*((volatile u16*)(0x48)

/**
 * @brief Timer1 Input Capture Register - High byte.
 */
//ICR
#define ICR1H 				*((volatile u8*)(0x47))

/**
 * @brief Timer1 Input Capture Register - Low byte.
 */
#define ICR1L 				*((volatile u8*)(0x46))

/**
 * @brief Timer1 Input Capture Register - 16-bit access.
 */
#define ICR1 				*((volatile u16*)(0x46))

/**
 * @brief Timer1 Control Register A bit positions.
 */
//TCCR1A
#define COM1A1 				7
#define COM1A0 				6
#define COM1B1 				5
#define COM1B0	 			4
#define FOC1A 				3
#define FOC1B 				2
#define WGM11 				1
#define WGM10 				0

/**
 * @brief Timer1 Control Register B bit positions.
 */
//TCCR1B
#define ICNC1 				7
#define ICES1 				6

#define WGM13 				4
#define WGM12 				3
#define CS12 				2
#define CS11 				1
#define CS10 				0

/**
 * @brief Timer/Counter Interrupt Mask Register bit positions.
 */
//TIMSK
#define TICIE1				5
#define OCIE1A				4
#define OCIE1B				3
#define TOIE1				2

/**
 * @brief Timer/Counter Interrupt Flag Register bit positions.
 */
//TIFR
#define ICF1				5
#define OCF1A				4
#define OCF1B				3
#define TOV1				2

/**
 * @brief Mask used to clear the Timer1 prescaler selection bits.
 */
#define ICU_PRESCALER_MSK 			0xF8

#endif /* ICU_PRIVATE_H_ */
