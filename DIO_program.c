#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

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

