/*
 * DIO_private.h
 *
 *  Created on: Aug 25, 2026
 *      Author: Mai Essam
 */

/**
 * @file DIO_private.h
 * @brief Private header file for the DIO driver.
 *
 * Contains the register definitions for the Digital Input/Output (DIO)
 * peripheral of the microcontroller.
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

/**
 * @brief Data Direction Registers (DDRx) for Ports A, B, C, and D.
 *
 * Used to configure each port pin as input or output.
 */
#define DDRA *((volatile u8 *)(0x3A))
#define DDRB *((volatile u8 *)(0x37))
#define DDRC *((volatile u8 *)(0x34))
#define DDRD *((volatile u8 *)(0x31))

/**
 * @brief Data Registers (PORTx) for Ports A, B, C, and D.
 *
 * Used to write output values to port pins or enable internal pull-up
 * resistors for input pins.
 */
#define PORTA *((volatile u8 *)(0x3B))
#define PORTB *((volatile u8 *)(0x38))
#define PORTC *((volatile u8 *)(0x35))
#define PORTD *((volatile u8 *)(0x32))

/**
 * @brief Input Pin Registers (PINx) for Ports A, B, C, and D.
 *
 * Used to read the logical input values present on the port pins.
 */
#define PINA *((volatile u8 *)(0x39))
#define PINB *((volatile u8 *)(0x36))
#define PINC *((volatile u8 *)(0x33))
#define PIND *((volatile u8 *)(0x30))


#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
