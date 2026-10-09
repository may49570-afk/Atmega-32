/*
 * USART_config.h
 *
 *  Created on: Sep 6, 2026
 *      Author: Essam
 */

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

#define Async					0
#define sync					1

#define bit_select				Async

//StopBit
#define One_StopBit				0
#define Two_StopBit				1

#define StopBit					One_StopBit


//ParityMode
#define Disabled				0
#define Even					2
#define Odd						3

#define ParityMode				Disabled

//Modes
#define Bit_5					0
#define Bit_6					1
#define Bit_7					2
#define Bit_8					3

#define  Bits_Settings			Bit_8

#endif /* USART_CONFIG_H_ */
