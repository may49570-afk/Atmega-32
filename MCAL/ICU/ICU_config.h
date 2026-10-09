/**
 * @file ICU_config.h
 * @brief Configuration file for the Input Capture Unit (ICU) driver.
 *
 * This file contains the configuration options for the ICU,
 * including the canceler, edge selection, prescaler, and interrupts.
 *
 * @date Sep 3, 2026
 * @author Mai Essam
 */

#ifndef ICU_CONFIG_H_
#define ICU_CONFIG_H_

/**
 * @brief Enables or disables the ICU noise canceler.
 */
#define ICU_CANCELER 			ICU_DISABLE

/**
 * @brief Selects the input capture edge.
 * @details The ICU captures the signal on the falling edge.
 */
//EDGE
#define ICU_EDGE_SELECT 		ICU_FALLING_EDGE

/**
 * @brief Selects the ICU prescaler value.
 * @details The selected prescaler is 256.
 */
//PRESCALER
#define ICU_PRESCALER 			ICU_PRESCALER_256

/**
 * @brief Configures the ICU interrupt settings.
 */
//INTERRUPT

/**
 * @brief Enables or disables Timer1 overflow interrupt.
 */
//Overflow Interrupt Enable
#define ICU_OVF1_INTERRUPT 		ICU_ENABLE

/**
 * @brief Enables or disables the input capture interrupt.
 */
//Capture Interrupt Enable
#define ICU_CAPT_INTERRUPT 		ICU_ENABLE

#endif /* ICU_CONFIG_H_ */
