/*
 * EXT_interrupt_private.h
 *
 *  Created on: Aug 31, 2026
 *      Author: Mai Essam
 */

/**
 * @file EXT_interrupt_private.h
 * @brief Private header file for the external interrupt driver.
 *
 * Contains register addresses, bit positions, and external interrupt
 * triggering mode definitions.
 */

#ifndef MCAL_EXT_INTERRUPT_PRIVATE_H_
#define MCAL_EXT_INTERRUPT_PRIVATE_H_

/**
 * @brief External interrupt control and flag register addresses.
 */
#define MCUCR  *((volatile u8 *)(0x55))
#define MCUCSR *((volatile u8 *)(0x54))
#define GICR   *((volatile u8 *)(0x5B))
#define GIFR   *((volatile u8 *)(0x5A))

/**
 * @brief Interrupt Sense Control (ISC) bit positions.
 *
 * Used to select the triggering condition for INT0 and INT1.
 */
#define ISC11 3
#define ISC10 2
#define ISC01 1
#define ISC00 0

/**
 * @brief Interrupt Sense Control bit position for INT2.
 */
#define ISC2 6

/**
 * @brief External interrupt enable bit positions in GICR.
 */
#define INT0 7
#define INT1 6
#define INT2 5

/**
 * @brief External interrupt triggering mode options.
 */
#define EXT_LOW_LOGIC 0
#define EXT_ANY_LOGIC 1
#define EXT_FALLING   2
#define EXT_RISING    3

#endif /* MCAL_EXT_INTERRUPT_PRIVATE_H_ */
