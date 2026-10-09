/**
 * @file ICU_program.c
 * @brief Implementation file for the Input Capture Unit (ICU) driver.
 *
 * This file contains the functions responsible for initializing Timer1
 * in Normal mode, configuring the input capture edge and prescaler,
 * handling interrupts, and managing the captured timer value and
 * overflow count.
 *
 * @date Sep 3, 2026
 * @author Mai Essam
 */

#include "../DIO/LIB/BIT_MATH.h"
#include "../DIO/LIB/STD.h"
#include "../DIO/MCAL/DIO/DIO_config.h"
#include "../DIO/MCAL/DIO/DIO_private.h"
#include "../DIO/MCAL/DIO/DIO_interface.h"
#include "ICU_private.h"
#include "ICU_config.h"
#include "ICU_interface.h"

/**
 * @brief Stores the currently configured ICU prescaler.
 */
static u8 g_prescaler = ICU_PRESCALER;

/**
 * @brief Pointer to the callback function executed by the ICU interrupt.
 */
void (*g_ICU_ptr)()= NULL;

/**
 * @brief Stores the number of Timer1 overflows.
 */
u16 Timer1OverFlow;

/**
 * @brief Initializes the ICU and configures Timer1.
 *
 * Configures Timer1 in Normal mode and sets the noise canceler,
 * capture edge, prescaler, overflow interrupt, and input capture
 * interrupt according to the configuration file.
 */
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

/**
 * @brief Changes the Timer1 prescaler.
 * @param prescaler The prescaler selection value.
 *
 * Updates the timer clock prescaler if the supplied value is valid.
 * The selected value is also stored in g_prescaler.
 */
void ICU_SetPrescaler(u8 prescaler){
	if(prescaler >=ICU_PRESCALER_NO_CLK && prescaler <=ICU_PRESCALER_1024)
	{
		TCCR1B &= ICU_PRESCALER_MSK;
		TCCR1B |=prescaler;
		g_prescaler=prescaler;
	}
}

/**
 * @brief Selects the rising edge for input capture.
 */
void ICU_SetRising(){
	SET_BIT(TCCR1B,ICES1);
}

/**
 * @brief Selects the falling edge for input capture.
 */
void ICU_SetFalling(){
	CLR_BIT(TCCR1B,ICES1);
}

/**
 * @brief Sets the Timer1 counter value.
 * @param value The value to load into TCNT1.
 */
void ICU_SetTime(u16 value){
	TCNT1=value;
}

/**
 * @brief Reads the captured input value.
 * @return The value stored in the Timer1 Input Capture Register.
 */
u16 ICU_GetTime(){
	return ICR1;
}

/**
 * @brief Sets the Timer1 overflow count.
 * @param OVF_value The overflow count to store.
 */
void ICU_SetOverFlow(u16 OVF_value){
	Timer1OverFlow= OVF_value;
}

/**
 * @brief Gets the Timer1 overflow count.
 * @return The current overflow count.
 */
u16 ICU_GetOverFlow(){
	return Timer1OverFlow;
}

/**
 * @brief Gets the numerical value of the configured prescaler.
 * @return The corresponding prescaler value.
 *
 * Converts the prescaler selection constant into its numerical
 * division factor.
 */
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

/**
 * @brief Enables global interrupts.
 */
void GIE_enable(){
	SET_BIT(SREG,I);
}

/**
 * @brief Disables global interrupts.
 */
void GIE_disable(){
	CLR_BIT(SREG,I);
}

//Call_Back_Function

/**
 * @brief Registers the callback function for the ICU interrupt.
 * @param ptr Pointer to the function to be called when the interrupt occurs.
 */
void ICU_SetCallBack(void (*ptr)()){

	g_ICU_ptr = ptr;
}

//ISR

/**
 * @brief Timer1 Input Capture Interrupt Service Routine.
 *
 * Calls the registered callback function if it is not NULL.
 */
void __vector6__() __attribute__((signal,used));
void __vector6__(){
	if(g_ICU_ptr != NULL){
		g_ICU_ptr();
	}

}

/**
 * @brief Timer1 Overflow Interrupt Service Routine.
 *
 * Increments the Timer1 overflow counter each time an overflow occurs.
 */
void __vector9__() __attribute__((signal,used));
void __vector9__(){
	Timer1OverFlow++;

}
