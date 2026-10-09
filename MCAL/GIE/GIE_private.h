/*
 * interrupt_private.h
 *
 *  Created on: Aug 30, 2026
 *      Author: Mai Essam
 */

/**
 * @file interrupt_private.h
 * @brief Private header file for the interrupt driver.
 *
 * Contains the global interrupt register definition and
 * the global interrupt enable bit position.
 */

#include "../../../DIO/LIB/STD.h"

#ifndef MCAL_INTERRUPT_PRIVATE_H_
#define MCAL_INTERRUPT_PRIVATE_H_

/**
 * @brief Status Register (SREG) memory address.
 */
#define SREG (*(int *)(0x58))

/**
 * @brief Global interrupt enable bit position in SREG.
 */
#define I 7

#endif /* MCAL_INTERRUPT_PRIVATE_H_ */
