/*
 * interrupt_program.c
 *
 *  Created on: Aug 30, 2026
 *      Author: Essam
 */

#include "../../../DIO/LIB/STD.h"
#include "../../../DIO/LIB/BIT_MATH.h"
#include "GIE_private.h"

void GIE_enable(){
	SET_BIT(SREG,I);
}

void GIE_disable(){
	CLR_BIT(SREG,I);
}
