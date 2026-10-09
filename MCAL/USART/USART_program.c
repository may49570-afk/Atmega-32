/**
 * @file USART_program.c
 * @brief Implementation file for the USART driver.
 *
 * This file contains the functions used to initialize USART
 * communication, transmit a single character, receive a character,
 * and transmit a string.
 *
 * @date Sep 6, 2026
 * @author Mai Essam
 */

#include "../DIO/LIB/BIT_MATH.h"
#include "../DIO/LIB/STD.h"
#include "../DIO/MCAL/DIO/DIO_config.h"
#include "../DIO/MCAL/DIO/DIO_private.h"
#include "../DIO/MCAL/DIO/DIO_interface.h"
#include "USART_private.h"
#include "USART_config.h"
#include "USART_interface.h"

/**
 * @brief Initializes the USART peripheral.
 *
 * Configures the baud rate, communication mode, number of stop bits,
 * parity mode, and data frame size according to the configuration
 * settings.
 */
void USART_init(){


	/*
	 * baudrate 9600
	 *  F_CPU 8M
	 *  UBRR
	 */

	UBRRH=0;
	UBRRL=51;

	SET_BIT(UCSRC,URSEL);

	//======================================================

	/**
	 * @brief Selects synchronous or asynchronous communication mode.
	 */
	//Select Bit(sync--Async)
	switch(bit_select)
	{

	case Async: CLR_BIT(UCSRC,UMSEL); break;

	case sync: SET_BIT(UCSRC,UMSEL); break;

	}


	/**
	 * @brief Configures the number of stop bits.
	 */
	//StopBit (one--two)
	switch(StopBit)
	{

	case One_StopBit: CLR_BIT(UCSRC,USBS); break;

	case Two_StopBit: SET_BIT(UCSRC,USBS); break;

	}


	/**
	 * @brief Configures the USART parity mode.
	 */
	//ParityMode (Disable--even--odd)
	switch(ParityMode)
	{

	case Disabled: CLR_BIT(UCSRC,UPM0); CLR_BIT(UCSRC,UPM1); break;

	case Even:	   CLR_BIT(UCSRC,UPM0); SET_BIT(UCSRC,UPM1); break;

	case Odd:      SET_BIT(UCSRC,UPM0); SET_BIT(UCSRC,UPM1); break;

	}


	/**
	 * @brief Configures the number of data bits in each frame.
	 */
	//Bits_Settings (5bit--6bit--7bit--8bit)
	switch(Bits_Settings)
	{

	case Bit_5: CLR_BIT(UCSRC,UCSZ0); CLR_BIT(UCSRC,UCSZ1); CLR_BIT(UCSRC,UCSZ2); break;

	case Bit_6:	SET_BIT(UCSRC,UCSZ0); CLR_BIT(UCSRC,UCSZ1); CLR_BIT(UCSRC,UCSZ2); break;

	case Bit_7: CLR_BIT(UCSRC,UCSZ0); SET_BIT(UCSRC,UCSZ1); CLR_BIT(UCSRC,UCSZ2); break;

	case Bit_8: SET_BIT(UCSRC,UCSZ0); SET_BIT(UCSRC,UCSZ1); CLR_BIT(UCSRC,UCSZ2); break;

	}


}

/**
 * @brief Transmits a single character through USART.
 *
 * Waits for the USART Data Register to become empty, then writes
 * the supplied data to the USART Data Register.
 *
 * @param data The character to transmit.
 */
void USART_SendChar(u8 data){

	while (GET_BIT(UCSRA,UDRE)==0){
	UDR = data;//==============
	}
}

/**
 * @brief Receives a single character through USART.
 *
 * Waits until data is available in the receive buffer, then returns it.
 *
 * @return The received character.
 */
u8 USART_ReceiveChar(){

	while (GET_BIT(UCSRA,RXC)==0);
	return UDR;
}

/**
 * @brief Transmits a null-terminated string through USART.
 *
 * Sends the characters in the string one by one until the null
 * terminator is encountered.
 *
 * @param ptr Pointer to the string to transmit.
 */
void USART_SendString(u8 * ptr){

	u8 iterator=0;
	while(ptr[iterator] != NULL){

		USART_SendChar(ptr[iterator]);

	}
}
