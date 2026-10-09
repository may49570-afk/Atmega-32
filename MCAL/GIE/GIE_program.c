/*
 * interrupt_program.c
 *
 *  Created on: Aug 30, 2026
 *      Author: Mai Essam
 */

/**
 * @file interrupt_program.c
 * @brief Implementation of the Global Interrupt Enable (GIE) functions.
 */

#include "../../../DIO/LIB/STD.h"
#include "../../../DIO/LIB/BIT_MATH.h"
#include "GIE_private.h"

/**
 * @brief Enables global interrupts.
 *
 * Sets the global interrupt enable bit in the SREG register.
 */
void GIE_enable(){
	SET_BIT(SREG,I);
}

/**
 * @brief Disables global interrupts.
 *
 * Clears the global interrupt enable bit in the SREG register.
 */
void GIE_disable(){
	CLR_BIT(SREG,I);
}
