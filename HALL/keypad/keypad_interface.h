/**
 * @file interface.h
 * @brief Interface file for the Hall Keypad driver.
 *
 * This file contains the function prototypes used to initialize
 * the keypad and retrieve the pressed key.
 *
 * @date Aug 30, 2026
 * @author Mai Essam
 */

#ifndef HALL_KEYPAD_INTERFACE_H_
#define HALL_KEYPAD_INTERFACE_H_

/**
 * @brief Initializes the keypad pins and prepares the keypad for use.
 */
void Keypad_init();

/**
 * @brief Gets the currently pressed keypad key.
 * @return The value corresponding to the pressed key.
 */
u8 Get_pressed();

#endif /* HALL_KEYPAD_INTERFACE_H_ */
