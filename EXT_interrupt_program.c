/*
 * EXT_interrupt_program.c
 *
 *  Created on: Aug 31, 2026
 *      Author: Essam
 */

#include "../../DIO/LIB/BIT_MATH.h"
#include "../../DIO/LIB/STD.h"
#include "../../DIO/MCAL/DIO/DIO_interface.h"
#include "EXT_interrupt_interface.h"
#include "EXT_interrupt_private.h"
#include "EXT_interrupt_config.h"

//#include<avr\io.h>


void EXT_Enable(u8 Enable_num){
	if((Enable_num >= INT2)&&(Enable_num <=INT0)){
		SET_BIT(GICR,Enable_num);
	}
}

void EXT_Disable(u8 Enable_num){
	if((Enable_num >= INT2)&&(Enable_num <=INT0)){
		CLR_BIT(GICR,Enable_num);
	}
}

void EXT_Sensecontrol(u8 Enable_num,u8 sense){
	switch (Enable_num){
	case INT1:
	switch (sense){ // MCUCR+ISC10+ISC11
			case EXT_LOW_LOGIC :
				CLR_BIT(MCUCR,ISC10);
				CLR_BIT(MCUCR,ISC11);
				break;
			case EXT_ANY_LOGIC:
				SET_BIT(MCUCR,ISC10);
				CLR_BIT(MCUCR,ISC11);
				break;
			case EXT_FALLING :
				CLR_BIT( MCUCSR,ISC10);
				SET_BIT( MCUCSR,ISC11);
				break;
			case EXT_RISING :
				SET_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
				break;
		}
		break;
	case INT0:
	switch (sense){
			case EXT_LOW_LOGIC :
				SET_BIT(MCUCR,ISC00);
				CLR_BIT(MCUCR,ISC01);
				break;
			case EXT_ANY_LOGIC:
				SET_BIT(MCUCR,ISC00);
				CLR_BIT(MCUCR,ISC01);
				break;
			case EXT_FALLING :
				SET_BIT(MCUCR,ISC00);
				CLR_BIT(MCUCR,ISC01);
				break;
			case EXT_RISING :
				SET_BIT(MCUCR,ISC00);
				CLR_BIT(MCUCR,ISC01);
				break;
		}
		break;
	case INT2:
	switch (sense){
			case EXT_FALLING :
				CLR_BIT(GICR,ISC2);
				break;
			case EXT_RISING :
				SET_BIT(GICR,ISC2);
				break;
		}
	break;

	}

}
