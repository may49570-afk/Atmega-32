/*
 * ICU_program.c
 *
 *  Created on: Sep 3, 2026
 *      Author: Mai Essam
 */

#include "../DIO/LIB/BIT_MATH.h"
#include "../DIO/LIB/STD.h"
#include "../DIO/MCAL/DIO/DIO_config.h"
#include "../DIO/MCAL/DIO/DIO_private.h"
#include "../DIO/MCAL/DIO/DIO_interface.h"
#include "ICU_private.h"
#include "ICU_config.h"
#include "ICU_interface.h"

static u8 g_prescaler = ICU_PRESCALER;
void (*g_ICU_ptr)()= NULL;
u16 Timer1OverFlow;

void ICU_init(){

	//WGM=NORMAL
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);


	//ICNC1
#if ICU_CANCELER==ICU_DISABLE
	CLR_BIT(TCCR1B,ICNC1);
#elif ICU_CANCELER==ICU_ENABLE
	SET_BIT(TCCR1B,ICNC1);
#else
#error "ERROR"
#endif


	//ICES1
#if ICU_EDGE_SELECT==ICU_FALLING_EDGE
	CLR_BIT(TCCR1B,ICNC1);
#elif ICU_EDGE_SELECT==ICU_RISING_EDGE
	SET_BIT(TCCR1B,ICNC1);
#else
#error "ERROR"
#endif

	//CS
#if ICU_PRESCALER >=ICU_PRESCALER_NO_CLK && ICU_PRESCALER <=ICU_PRESCALER_1024
	TCCR1B &= ICU_PRESCALER_MSK;
	TCCR1B |= ICU_PRESCALER;
#else
#error "ERROR"
#endif

	//TOIE1
#if ICU_OVF1_INTERRUPT==ICU_ENABLE
	SET_BIT(TIMSK,TOIE1);
#elif ICU_OVF1_INTERRUPT==ICU_DISABLE
	CLR_BIT(TIMSK,TOIE1);
#else
#error "ERROR"
#endif

	//TICIE1
#if ICU_CAPT_INTERRUPT==ICU_ENABLE
	SET_BIT(TIMSK,TICIE1);
#elif ICU_CAPT_INTERRUPT==ICU_DISABLE
	CLR_BIT(TIMSK,TICIE1);
#else
#error "ERROR"
#endif
}

void ICU_SetPrescaler(u8 prescaler){
	if(prescaler >=ICU_PRESCALER_NO_CLK && prescaler <=ICU_PRESCALER_1024)
	{
		TCCR1B &= ICU_PRESCALER_MSK;
		TCCR1B |=prescaler;
		g_prescaler=prescaler;
	}
}

void ICU_SetRising(){
	SET_BIT(TCCR1B,ICES1);
}

void ICU_SetFalling(){
	CLR_BIT(TCCR1B,ICES1);
}

void ICU_SetTime(u16 value){
	TCNT1=value;
}

u16 ICU_GetTime(){
	return ICR1;
}

void ICU_SetOverFlow(u16 OVF_value){
	Timer1OverFlow= OVF_value;
}

u16 ICU_GetOverFlow(){
	return Timer1OverFlow;
}

u16 Get_prescaler(){
	u16 prescaler;

	switch (g_prescaler) {
		case ICU_PRESCALER_NO_CLK:			prescaler=0;	 break;
		case ICU_PRESCALER_NO_PRESCALING: 	prescaler=1; 	 break;
		case ICU_PRESCALER_8:			  	prescaler=8;  	 break;
		case ICU_PRESCALER_64:				prescaler=64; 	 break;
		case ICU_PRESCALER_256:				prescaler=256; 	 break;
		case ICU_PRESCALER_1024:			prescaler=1024;  break;
		default:											 break;
	}
	return prescaler;
}

//GIE
void GIE_enable(){
	SET_BIT(SREG,I);
}

void GIE_disable(){
	CLR_BIT(SREG,I);
}

//Call_Back_Function
void ICU_SetCallBack(void (*ptr)()){

	g_ICU_ptr = ptr;
}

//ISR
void __vector6__() __attribute__((signal,used));
void __vector6__(){
	if(g_ICU_ptr != NULL){
		g_ICU_ptr();
	}

}

void __vector9__() __attribute__((signal,used));
void __vector9__(){
	Timer1OverFlow++;

}
