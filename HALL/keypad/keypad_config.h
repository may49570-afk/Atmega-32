/**
 * @file config.h
 * @brief Configuration file for the Hall Keypad driver.
 *
 * This file defines the keypad port, row and column pin assignments,
 * keypad dimensions, key mapping, and the value representing no key pressed.
 *
 * @date Aug 30, 2026
 * @author Mai Essam
 */

#ifndef HALL_KEYPAD_CONFIG_H_
#define HALL_KEYPAD_CONFIG_H_

/**
 * @brief Specifies the port connected to the keypad.
 */
#define Keypad_PORT DIO_PORTA
//#define Led_PORT DIO_PORTB

/**
 * @brief Defines the pins connected to the keypad columns.
 */
//columns
#define C0 PIN0
#define C1 PIN1
#define C2 PIN2
#define C3 PIN3

/**
 * @brief Defines the pins connected to the keypad rows.
 */
//Rows
#define R0 PIN4
#define R1 PIN5
#define R2 PIN6
#define R3 PIN7

/**
 * @brief Specifies the number of keypad rows.
 */
#define ROWS_SIZE 4

/**
 * @brief Specifies the number of keypad columns.
 */
#define COL_SIZE 4

/**
 * @brief Defines the keypad button layout.
 *
 * Each nested array represents one row of the keypad.
 * The values correspond to the characters or numbers assigned
 * to the individual buttons.
 */
#define KEYPAD_VAL {{7,8,9,'/'}, \
					{4,5,6,'*'}, \
					{1,2,3,'-'}, \
					{'C',0,'=','+'}}

/**
 * @brief Represents the condition when no key is pressed.
 */
#define NO_KEY -1

#endif /* HALL_KEYPAD_CONFIG_H_ */
