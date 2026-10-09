/*
 * H_Bridge_interface.h
 *
 *  Created on: Aug 30, 2026
 *      Author: Mai Essam
 */

/**
 * @file H_Bridge_interface.h
 * @brief Interface header file for the H-Bridge motor control driver.
 */

#ifndef HALL_H_BRIDGE_INTERFACE_H_
#define HALL_H_BRIDGE_INTERFACE_H_

/**
 * @brief Initializes Motor 1.
 */
void Motor1_init();

/**
 * @brief Initializes Motor 2.
 */
void Motor2_init();

/**
 * @brief Initializes the H-Bridge driver.
 */
void H_Bridge_init();

/**
 * @brief Rotates Motor 1 in the forward direction.
 */
void Motor1_Forword();

/**
 * @brief Rotates Motor 2 in the forward direction.
 */
void Motor2_Forword();

/**
 * @brief Rotates both motors in the forward direction.
 */
void H_Bridge_Forword();

/**
 * @brief Rotates Motor 1 in the backward direction.
 */
void Motor1_backword();

/**
 * @brief Rotates Motor 2 in the backward direction.
 */
void Motor2_backword();

/**
 * @brief Rotates both motors in the backward direction.
 */
void H_Bridge_backword();

/**
 * @brief Turns the robot to the right.
 */
void H_Bridge_Right();

/**
 * @brief Turns the robot to the left.
 */
void H_Bridge_left();

/**
 * @brief Stops Motor 1.
 */
void Motor1_stop();

/**
 * @brief Stops Motor 2.
 */
void Motor2_stop();

/**
 * @brief Stops both motors.
 */
void H_Bridge_stop();

#endif /* HALL_H_BRIDGE_INTERFACE_H_ */
