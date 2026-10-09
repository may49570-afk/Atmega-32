/*
 * USART_program.c
 *
 *  Created on: Sep 6, 2026
 *      Author: Essam
 */


#include "../DIO/LIB/BIT_MATH.h"
#include "../DIO/LIB/STD.h"
#include "../DIO/MCAL/DIO/DIO_config.h"
#include "../DIO/MCAL/DIO/DIO_private.h"
#include "../DIO/MCAL/DIO/DIO_interface.h"
#include "USART_private.h"
#include "USART_config.h"
#include "USART_interface.h"


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

	//Select Bit(sync--Async)
	switch(bit_select)
	{

	case Async: CLR_BIT(UCSRC,UMSEL); break;

	case sync: SET_BIT(UCSRC,UMSEL); break;

	}


	//StopBit (one--two)
	switch(StopBit)
	{

	case One_StopBit: CLR_BIT(UCSRC,USBS); break;

	case Two_StopBit: SET_BIT(UCSRC,USBS); break;

	}


	//ParityMode (Disable--even--odd)
	switch(ParityMode)
	{

	case Disabled: CLR_BIT(UCSRC,UPM0); CLR_BIT(UCSRC,UPM1); break;

	case Even:	   CLR_BIT(UCSRC,UPM0); SET_BIT(UCSRC,UPM1); break;

	case Odd:      SET_BIT(UCSRC,UPM0); SET_BIT(UCSRC,UPM1); break;

	}


	//Bits_Settings (5bit--6bit--7bit--8bit)
	switch(Bits_Settings)
	{

	case Bit_5: CLR_BIT(UCSRC,UCSZ0); CLR_BIT(UCSRC,UCSZ1); CLR_BIT(UCSRC,UCSZ2); break;

	case Bit_6:	SET_BIT(UCSRC,UCSZ0); CLR_BIT(UCSRC,UCSZ1); CLR_BIT(UCSRC,UCSZ2); break;

	case Bit_7: CLR_BIT(UCSRC,UCSZ0); SET_BIT(UCSRC,UCSZ1); CLR_BIT(UCSRC,UCSZ2); break;

	case Bit_8: SET_BIT(UCSRC,UCSZ0); SET_BIT(UCSRC,UCSZ1); CLR_BIT(UCSRC,UCSZ2); break;

	}


}

void USART_SendChar(u8 data){

	while (GET_BIT(UCSRA,UDRE)==0){
	UDR = data;//==============
	}
}

u8 USART_ReceiveChar(){

	while (GET_BIT(UCSRA,RXC)==0);
	return UDR;
}

void USART_SendString(u8 * ptr){

	u8 iterator=0;
	while(ptr[iterator] != NULL){

		USART_SendChar(ptr[iterator]);

	}
}

