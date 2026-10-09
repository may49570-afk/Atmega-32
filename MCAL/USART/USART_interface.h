/**
 * @file USART_interface.h
 * @brief Interface file for the USART driver.
 *
 * This file contains the function prototypes used to initialize
 * USART communication and send or receive data.
 *
 * @date Sep 6, 2026
 * @author Mai Essam
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#include"../DIO/LIB/BIT_MATH.h"

/**
 * @brief Initializes the USART peripheral according to the configuration settings.
 */
void USART_init();

/**
 * @brief Transmits a single character through USART.
 * @param data The character to be transmitted.
 */
void USART_SendChar(u8 data);

/**
 * @brief Receives a single character through USART.
 * @return The received character.
 */
u8 USART_ReceiveChar();

/**
 * @brief Transmits a string through USART.
 * @param ptr Pointer to the string to be transmitted.
 */
void USART_SendString(u8 * ptr);

#endif /* USART_INTERFACE_H_ */
