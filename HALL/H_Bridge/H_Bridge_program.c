/*
 * H_Bridge_program.c
 *
 *  Created on: Aug 30, 2026
 *      Author: Mai Essam
 */

/**
 * @file H_Bridge_program.c
 * @brief Implementation of the H-Bridge motor control functions.
 */

#include "../../DIO/LIB/BIT_MATH.h"
#include "../../DIO/LIB/STD.h"
#include "DIO_interface.h"
#include "H_Bridge_interface.h"
#include "H_Bridge_private.h"
#include "H_Bridge_config.h"

/**
 * @brief Stops Motor 1.
 *
 * Sets the input and enable pins of Motor 1 to LOW.
 */
void Motor1_stop(){
	SetPinVal(Motor1_PORT,IN1_M1,DIO_LOW);
	SetPinVal(Motor1_PORT,IN2_M1,DIO_LOW);
	SetPinVal(Motor1_PORT,EN_M1,DIO_LOW);
}

/**
 * @brief Stops Motor 2.
 *
 * Sets the input and enable pins of Motor 2 to LOW.
 */
void Motor2_stop(){
	SetPinVal(Motor2_PORT,IN1_M2,DIO_LOW);
	SetPinVal(Motor2_PORT,IN2_M2,DIO_LOW);
	SetPinVal(Motor2_PORT,EN_M2,DIO_LOW);
}

/**
 * @brief Stops both motors.
 *
 * Calls the stop functions for Motor 1 and Motor 2.
 */
void H_Bridge_stop(){
	Motor1_stop();
	Motor2_stop();
}

/**
 * @brief Initializes Motor 1.
 *
 * Configures the input and enable pins of Motor 1 as output,
 * then stops the motor.
 */
void Motor1_init(){
	SetPinDir(Motor1_PORT,IN1_M1,DIO_OUTPUT);
	SetPinDir(Motor1_PORT,IN2_M1,DIO_OUTPUT);
	SetPinDir(Motor1_PORT,EN_M1,DIO_OUTPUT);

	Motor1_stop();
}

/**
 * @brief Initializes Motor 2.
 *
 * Configures the input and enable pins of Motor 2 as output,
 * then stops the motor.
 */
void Motor2_init(){
	SetPinDir(Motor2_PORT,IN1_M2,DIO_OUTPUT);
	SetPinDir(Motor2_PORT,IN2_M2,DIO_OUTPUT);
	SetPinDir(Motor2_PORT,EN_M2,DIO_OUTPUT);

	Motor2_stop();
}

/**
 * @brief Initializes the H-Bridge driver.
 *
 * Initializes both motors and stops them.
 */
void H_Bridge_init(){
	Motor1_init();
	Motor2_init();
	H_Bridge_stop();
}

/**
 * @brief Rotates Motor 1 in the forward direction.
 *
 * Sets IN1 to HIGH, IN2 to LOW, and enables Motor 1.
 */
void Motor1_Forword(){
	SetPinVal(Motor1_PORT,IN1_M1,DIO_HIGH);
	SetPinVal(Motor1_PORT,IN2_M1,DIO_LOW);
	SetPinVal(Motor1_PORT,EN_M1,DIO_HIGH);
}

/**
 * @brief Rotates Motor 2 in the forward direction.
 *
 * Sets IN1 to HIGH, IN2 to LOW, and enables Motor 2.
 */
void Motor2_Forword(){
	SetPinVal(Motor2_PORT,IN1_M2,DIO_HIGH);
	SetPinVal(Motor2_PORT,IN2_M2,DIO_LOW);
	SetPinVal(Motor2_PORT,EN_M2,DIO_HIGH);
}

/**
 * @brief Rotates both motors in the forward direction.
 */
void H_Bridge_Forword(){
	Motor1_Forword();
	Motor2_Forword();
}

/**
 * @brief Rotates Motor 1 in the backward direction.
 *
 * Sets IN1 to LOW, IN2 to HIGH, and enables Motor 1.
 */
void Motor1_backword(){
	SetPinVal(Motor1_PORT,IN1_M1,DIO_LOW);
	SetPinVal(Motor1_PORT,IN2_M1,DIO_HIGH);
	SetPinVal(Motor1_PORT,EN_M1,DIO_HIGH);
}

/**
 * @brief Rotates Motor 2 in the backward direction.
 *
 * Sets IN1 to LOW, IN2 to HIGH, and enables Motor 2.
 */
void Motor2_backword(){
	SetPinVal(Motor2_PORT,IN1_M2,DIO_LOW);
	SetPinVal(Motor2_PORT,IN2_M2,DIO_HIGH);
	SetPinVal(Motor2_PORT,EN_M2,DIO_HIGH);
}

/**
 * @brief Rotates both motors in the backward direction.
 */
void H_Bridge_backword(){
	Motor1_Forword();
	Motor2_Forword();
}

/**
 * @brief Turns the robot to the right.
 */
void H_Bridge_Right(){
	Motor1_Forword();
	Motor2_Forword();
}

/**
 * @brief Turns the robot to the left.
 *
 * Rotates Motor 1 backward and Motor 2 forward.
 */
void H_Bridge_left(){
	Motor1_backword();
	Motor2_Forword();

}
