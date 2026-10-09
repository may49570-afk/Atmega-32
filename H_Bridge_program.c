/*
 * H_Bridge_program.c
 *
 *  Created on: Aug 30, 2026
 *      Author: Essam
 */

#include "../../DIO/LIB/BIT_MATH.h"
#include "../../DIO/LIB/STD.h"
#include "DIO_interface.h"
#include "H_Bridge_interface.h"
#include "H_Bridge_private.h"
#include "H_Bridge_config.h"

void Motor1_stop(){
	SetPinVal(Motor1_PORT,IN1_M1,DIO_LOW);
	SetPinVal(Motor1_PORT,IN2_M1,DIO_LOW);
	SetPinVal(Motor1_PORT,EN_M1,DIO_LOW);
}

void Motor2_stop(){
	SetPinVal(Motor2_PORT,IN1_M2,DIO_LOW);
	SetPinVal(Motor2_PORT,IN2_M2,DIO_LOW);
	SetPinVal(Motor2_PORT,EN_M2,DIO_LOW);
}

void H_Bridge_stop(){
	Motor1_stop();
	Motor2_stop();
}

void Motor1_init(){
	SetPinDir(Motor1_PORT,IN1_M1,DIO_OUTPUT);
	SetPinDir(Motor1_PORT,IN2_M1,DIO_OUTPUT);
	SetPinDir(Motor1_PORT,EN_M1,DIO_OUTPUT);

	Motor1_stop();
}

void Motor2_init(){
	SetPinDir(Motor2_PORT,IN1_M2,DIO_OUTPUT);
	SetPinDir(Motor2_PORT,IN2_M2,DIO_OUTPUT);
	SetPinDir(Motor2_PORT,EN_M2,DIO_OUTPUT);

	Motor2_stop();
}

void H_Bridge_init(){
	Motor1_init();
	Motor2_init();
	H_Bridge_stop();
}

void Motor1_Forword(){
	SetPinVal(Motor1_PORT,IN1_M1,DIO_HIGH);
	SetPinVal(Motor1_PORT,IN2_M1,DIO_LOW);
	SetPinVal(Motor1_PORT,EN_M1,DIO_HIGH);
}

void Motor2_Forword(){
	SetPinVal(Motor2_PORT,IN1_M2,DIO_HIGH);
	SetPinVal(Motor2_PORT,IN2_M2,DIO_LOW);
	SetPinVal(Motor2_PORT,EN_M2,DIO_HIGH);
}

void H_Bridge_Forword(){
	Motor1_Forword();
	Motor2_Forword();
}

void Motor1_backword(){
	SetPinVal(Motor1_PORT,IN1_M1,DIO_LOW);
	SetPinVal(Motor1_PORT,IN2_M1,DIO_HIGH);
	SetPinVal(Motor1_PORT,EN_M1,DIO_HIGH);
}

void Motor2_backword(){
	SetPinVal(Motor2_PORT,IN1_M2,DIO_LOW);
	SetPinVal(Motor2_PORT,IN2_M2,DIO_HIGH);
	SetPinVal(Motor2_PORT,EN_M2,DIO_HIGH);
}

void H_Bridge_backword(){
	Motor1_Forword();
	Motor2_Forword();
}

void H_Bridge_Right(){
	Motor1_Forword();
	Motor2_Forword();
}


void H_Bridge_left(){
	Motor1_backword();
	Motor2_Forword();

}
