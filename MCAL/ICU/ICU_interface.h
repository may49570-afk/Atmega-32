/**
 * @file ICU_interface.h
 * @brief Interface file for the Input Capture Unit (ICU) driver.
 *
 * This file contains the ICU configuration constants and function
 * prototypes used to initialize and control the ICU.
 *
 * @date Sep 3, 2026
 * @author Mai Essam
 */

#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_

/**
 * @brief Enables a peripheral feature or interrupt.
 */
#define ICU_ENABLE 							1

/**
 * @brief Disables a peripheral feature or interrupt.
 */
#define ICU_DISABLE 						0

/**
 * @brief Selects the falling edge for input capture.
 */
#define ICU_FALLING_EDGE 					0

/**
 * @brief Selects the rising edge for input capture.
 */
#define ICU_RISING_EDGE 					1

/**
 * @brief Stops the timer clock.
 */
#define ICU_PRESCALER_NO_CLK  				0

/**
 * @brief Selects the timer clock without prescaling.
 */
#define ICU_PRESCALER_NO_PRESCALING   		1

/**
 * @brief Selects a timer prescaler of 8.
 */
#define ICU_PRESCALER_8  					2

/**
 * @brief Selects a timer prescaler of 64.
 */
#define ICU_PRESCALER_64					3

/**
 * @brief Selects a timer prescaler of 256.
 */
#define ICU_PRESCALER_256  					4

/**
 * @brief Selects a timer prescaler of 1024.
 */
#define ICU_PRESCALER_1024   				5

/**
 * @brief Initializes the Input Capture Unit.
 */
void ICU_init();

/**
 * @brief Sets the ICU timer prescaler.
 * @param prescaler The prescaler value to be selected.
 */
void ICU_SetPrescaler(u8 prescaler);

/**
 * @brief Configures the ICU to capture on the rising edge.
 */
void ICU_SetRising();

/**
 * @brief Configures the ICU to capture on the falling edge.
 */
void ICU_SetFalling();

/**
 * @brief Sets the captured timer value.
 * @param value The timer value to be set.
 */
void ICU_SetTime(u16 value);

/**
 * @brief Gets the captured timer value.
 * @return The captured timer value.
 */
u16 ICU_GetTime();

/**
 * @brief Sets the timer overflow value.
 * @param OVF_value The overflow value to be set.
 */
void ICU_SetOverFlow(u16 OVF_value);

/**
 * @brief Gets the timer overflow value.
 * @return The timer overflow value.
 */
u16 ICU_GetOverFlow();

/**
 * @brief Gets the currently configured prescaler.
 * @return The prescaler value.
 */
u16 Get_prescaler();

/**
 * @brief Enables global interrupts.
 */
void GIE_enable();

/**
 * @brief Disables global interrupts.
 */
void GIE_disable();

/**
 * @brief Sets the callback function for the ICU.
 * @param ptr Pointer to the callback function.
 */
void ICU_SetCallBack(void (*ptr)());

#endif /* ICU_INTERFACE_H_ */
