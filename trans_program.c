/*
 * trans_program.c
 *
 *  Created on: Aug 30, 2026
 *      Author: Essam
 */

#include "../../DIO/LIB/BIT_MATH.h"
#include "../../DIO/LIB/STD.h"
#include "../../DIO/MCAL/DIO/DIO_interface.h"
#include "Trans_interface.h"
#include "Trans_private.h"
#include "Trans_config.h"

void Trans_init(){
	SetPinDir(Trans_PORT,Trans_PIN,DIO_OUTPUT);
	Trans_OFF();
}
void Trans_ON(void){
	SetPinVal(Trans_PORT,Trans_PIN,DIO_HIGH);
}
void Trans_OFF(void){
	SetPinVal(Trans_PORT,Trans_PIN,DIO_LOW);
}
void Trans_Toggel(void){
	TogPinVal(Trans_PORT,Trans_PIN);
}

