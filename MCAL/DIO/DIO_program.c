/**
 * @file DIO_program.c
 * @brief Implementation of the Digital Input/Output (DIO) driver functions.
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/**
 * @brief Sets the direction of a specific pin.
 *
 * Configures the selected pin as output, input, or input with pull-up.
 *
 * @param PORT The port containing the selected pin.
 * @param PIN The pin number to be configured.
 * @param DIR The required pin direction.
 */
void SetPinDir(u8 PORT,u8 PIN,u8 DIR)
{
	switch (DIR)
	{
	case DIO_OUTPUT :
		switch (PORT)
		{
		case DIO_PORTA :
			SET_BIT(DDRA,PIN);
			break;
		case DIO_PORTB :
			SET_BIT(DDRB,PIN);
			break;
		case DIO_PORTC :
			SET_BIT(DDRC,PIN);
			break;
		case DIO_PORTD :
			SET_BIT(DDRD,PIN);
			break;
		default :
			break;
		}
		break;

	case DIO_INPUT  :
		switch (PORT)
		{
		case DIO_PORTA :
			CLR_BIT(DDRA,PIN);
			break;
		case DIO_PORTB :
			CLR_BIT(DDRB,PIN);
			break;
		case DIO_PORTC :
			CLR_BIT(DDRC,PIN);
			break;
		case DIO_PORTD :
			CLR_BIT(DDRD,PIN);
			break;
		default : break;
		}
		break;

	case DIO_PULLUP :
		switch (PORT)
		{
		case DIO_PORTA :
			CLR_BIT(DDRA,PIN);   //INPUT
			SET_BIT(PORTA,PIN);   //PULLUP -- ENABLE 1
			break;
		case DIO_PORTB :
			CLR_BIT(DDRB,PIN);
			SET_BIT(PORTB,PIN);
			break;
		case DIO_PORTC :
			CLR_BIT(DDRC,PIN);
			SET_BIT(PORTC,PIN);
			break;
		case DIO_PORTD :
			CLR_BIT(DDRD,PIN);
			SET_BIT(PORTD,PIN);
			break;
		default : break;
		}
		break;
		}

}

/**
 * @brief Sets the direction of all pins in a port.
 *
 * Configures the selected port as output, input, or input with pull-up.
 *
 * @param PORT The port to be configured.
 * @param DIR The required port direction.
 */
void SetPortDir(u8 PORT,u8 DIR)
{
	switch (DIR)
	{
	case DIO_OUTPUT :
		switch (PORT)
		{
		case DIO_PORTA :
			DDRA =OUTPUT_PORT ;
			break;
		case DIO_PORTB :
			DDRB =OUTPUT_PORT ;
			break;
		case DIO_PORTC :
			DDRC =OUTPUT_PORT ;
			break;
		case DIO_PORTD :
			DDRD =OUTPUT_PORT ;
			break;
		default :
			break;
		}
		break;

	case DIO_INPUT  :
		switch (PORT)
		{
		case DIO_PORTA :
			DDRA =INPUT_PORT ;
			break;
		case DIO_PORTB :
			DDRB =INPUT_PORT ;
			break;
		case DIO_PORTC :
			DDRC =INPUT_PORT ;
			break;
		case DIO_PORTD :
			DDRD =INPUT_PORT ;
			break;
		default : break;
		}
		break;

	case DIO_PULLUP :
		switch (PORT)
		{
		case DIO_PORTA :
			DDRA =INPUT_PORT ;
			PORTA = OUTPUT_PORT;
			break;
		case DIO_PORTB :
			DDRB =INPUT_PORT ;
			PORTB = OUTPUT_PORT;
			break;
		case DIO_PORTC :
			DDRC =INPUT_PORT ;
			PORTC = OUTPUT_PORT;
			break;
		case DIO_PORTD :
			DDRD =INPUT_PORT ;
			PORTD = OUTPUT_PORT;
			break;
		default : break;
		}
		break;
		}

}

/**
 * @brief Sets the value of a specific output pin.
 *
 * @param PORT The port containing the selected pin.
 * @param PIN The pin number to be modified.
 * @param Val The required pin value (high or low).
 */
void SetPinVal(u8 PORT,u8 PIN,u8 Val)
{
	switch (Val)
	{
	case DIO_HIGH :
		switch (PORT)
		{
		case DIO_PORTA :
			SET_BIT(PORTA,PIN);
			break;
		case DIO_PORTB :
			SET_BIT(PORTB,PIN);
			break;
		case DIO_PORTC :
			SET_BIT(PORTC,PIN);
			break;
		case DIO_PORTD :
			SET_BIT(PORTD,PIN);
			break;
		default :
			break;
		}
		break;

	case DIO_LOW  :
		switch (PORT)
		{
		case DIO_PORTA :
			CLR_BIT(PORTA,PIN);
			break;
		case DIO_PORTB :
			CLR_BIT(PORTB,PIN);
			break;
		case DIO_PORTC :
			CLR_BIT(PORTC,PIN);
			break;
		case DIO_PORTD :
			CLR_BIT(PORTD,PIN);
			break;
		default : break;
		}
		break;
	}
}

/**
 * @brief Sets the value of an entire port.
 *
 * @param PORT The port to be modified.
 * @param Val The value to be written to the port.
 */
void SetPortVal(u8 PORT,u8 Val)
{
		switch (PORT)
		{
		case DIO_PORTA :
			PORTA = Val;
			break;
		case DIO_PORTB :
			PORTB = Val;
			break;
		case DIO_PORTC :
			PORTC = Val;
			break;
		case DIO_PORTD :
			PORTD = Val;
			break;
		default :
			break;
		}
}

/**
 * @brief Reads the value of a specific input pin.
 *
 * @param PORT The port containing the selected pin.
 * @param PIN The pin number to be read.
 * @return The value of the selected pin (0 or 1).
 */
u8 GetPinVal(u8 PORT , u8 PIN )
{
	switch (PORT)
	{
	case DIO_PORTA :
		 return GET_BIT(PINA,PIN);
		break;
	case DIO_PORTB :
		return GET_BIT(PINB,PIN);
		break;
	case DIO_PORTC :
		return GET_BIT(PINC,PIN);
		break;
	case DIO_PORTD :
		return GET_BIT(PIND,PIN);
		break;
	default :
		return 0;
	}
}

/**
 * @brief Reads the input value of an entire port.
 *
 * @param PORT The port to be read.
 * @return The current input value of the selected port.
 */
u8 GetPortVal(u8 PORT)
{
	switch (PORT)
	{
	case DIO_PORTA :
		return PINA;
		break;
	case DIO_PORTB :
		return PINB;
		break;
	case DIO_PORTC :
		return PINC;
		break;
	case DIO_PORTD :
		return PIND;
		break;
	default :
		return 0;
	}
}

/**
 * @brief Toggles the value of a specific output pin.
 *
 * Changes the pin value from high to low or from low to high.
 *
 * @param PORT The port containing the selected pin.
 * @param PIN The pin number to be toggled.
 */
void TogPinVal(u8 PORT,u8 PIN)
{
		switch (PORT)
		{
		case DIO_PORTA :
			TOG_BIT(PORTA,PIN);
			break;
		case DIO_PORTB :
			TOG_BIT(PORTB,PIN);
			break;
		case DIO_PORTC :
			TOG_BIT(PORTC,PIN);
			break;
		case DIO_PORTD :
			TOG_BIT(PORTD,PIN);
			break;
		default :
			break;
		}
}

/**
 * @brief Toggles the output values of an entire port.
 *
 * Inverts all bits in the selected port register.
 *
 * @param PORT The port whose output values will be inverted.
 */
void TogPortDir(u8 PORT)
{
		switch (PORT)
		{
		case DIO_PORTA :
			PORTA=~PORTA ;
			break;
		case DIO_PORTB :
			PORTB=~PORTB ;
			break;
		case DIO_PORTC :
			PORTC=~PORTC ;
			break;
		case DIO_PORTD :
			PORTD=~PORTD ;
			break;
		default :
			break;
		}
}
