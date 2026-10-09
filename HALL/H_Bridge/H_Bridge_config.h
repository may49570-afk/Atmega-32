/*
 * H_Bridge_config.h
 *
 *  Created on: Aug 30, 2026
 *      Author: Mai Essam
 */

/**
 * @file H_Bridge_config.h
 * @brief Configuration file for the H-Bridge motor control driver.
 */

#ifndef HALL_H_BRIDGE_CONFIG_H_
#define HALL_H_BRIDGE_CONFIG_H_

/**
 * @brief Specifies the ports connected to the motors.
 */
#define Motor1_PORT DIO_PORTA
#define Motor2_PORT DIO_PORTA

/**
 * @brief Pin assignments for Motor 1.
 */
#define IN1_M1 PIN0
#define IN2_M1 PIN1
#define EN_M1 PIN2

/**
 * @brief Pin assignments for Motor 2.
 */
#define IN1_M2 PIN3
#define IN2_M2 PIN4
#define EN_M2 PIN5

#endif /* HALL_H_BRIDGE_CONFIG_H_ */
