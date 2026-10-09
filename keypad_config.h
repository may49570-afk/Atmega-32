/*
 * config.h
 *
 *  Created on: Aug 30, 2026
 *      Author: Essam
 */

#ifndef HALL_KEYPAD_CONFIG_H_
#define HALL_KEYPAD_CONFIG_H_

#define Keypad_PORT DIO_PORTA
//#define Led_PORT DIO_PORTB

//columns
#define C0 PIN0
#define C1 PIN1
#define C2 PIN2
#define C3 PIN3

//Rows
#define R0 PIN4
#define R1 PIN5
#define R2 PIN6
#define R3 PIN7

#define ROWS_SIZE 4
#define COL_SIZE 4

#define KEYPAD_VAL {{7,8,9,'/'}, \
					{4,5,6,'*'}, \
					{1,2,3,'-'}, \
					{'C',0,'=','+'}}

#define NO_KEY -1

#endif /* HALL_KEYPAD_CONFIG_H_ */
