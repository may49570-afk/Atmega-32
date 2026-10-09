/**
 * @file trans_interface.h
 * @brief Interface file for the Hall Transducer driver.
 *
 * This file contains the function prototypes used to initialize
 * and control the transducer.
 *
 * @date Aug 30, 2026
 * @author Mai Essam
 */

#ifndef HALL_TRANS_INTERFACE_H_
#define HALL_TRANS_INTERFACE_H_

/**
 * @brief Initializes the transducer pin.
 */
void Trans_init();

/**
 * @brief Turns the transducer ON.
 */
void Trans_ON(void);

/**
 * @brief Turns the transducer OFF.
 */
void Trans_OFF(void);

/**
 * @brief Toggles the transducer state.
 */
void Trans_Toggel(void);

#endif /* HALL_TRANS_INTERFACE_H_ */
