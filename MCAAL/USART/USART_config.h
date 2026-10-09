/**
 * @file USART_config.h
 * @brief Configuration file for the USART driver.
 *
 * This file defines the USART communication mode, stop bit
 * configuration, parity mode, and data frame size.
 *
 * @date Sep 6, 2026
 * @author Mai Essam
 */

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/**
 * @brief Selects asynchronous communication mode.
 */
#define Async					0

/**
 * @brief Selects synchronous communication mode.
 */
#define sync					1

/**
 * @brief Selects the USART communication mode.
 */
#define bit_select				Async

/**
 * @brief Selects one stop bit.
 */
//StopBit
#define One_StopBit				0

/**
 * @brief Selects two stop bits.
 */
#define Two_StopBit				1

/**
 * @brief Configures the number of stop bits.
 */
#define StopBit					One_StopBit


/**
 * @brief Disables parity checking.
 */
//ParityMode
#define Disabled				0

/**
 * @brief Selects even parity.
 */
#define Even					2

/**
 * @brief Selects odd parity.
 */
#define Odd						3

/**
 * @brief Configures the USART parity mode.
 */
#define ParityMode				Disabled

/**
 * @brief Selects a 5-bit data frame.
 */
//Modes
#define Bit_5					0

/**
 * @brief Selects a 6-bit data frame.
 */
#define Bit_6					1

/**
 * @brief Selects a 7-bit data frame.
 */
#define Bit_7					2

/**
 * @brief Selects an 8-bit data frame.
 */
#define Bit_8					3

/**
 * @brief Configures the USART data frame size.
 */
#define  Bits_Settings			Bit_8

#endif /* USART_CONFIG_H_ */
