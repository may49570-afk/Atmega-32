/*
 * USART_interface.h
 *
 *  Created on: Sep 6, 2026
 *      Author: Essam
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#include"../DIO/LIB/BIT_MATH.h"

void USART_init();

void USART_SendChar(u8 data);

u8 USART_ReceiveChar();

void USART_SendString(u8 * ptr);



#endif /* USART_INTERFACE_H_ */
