/*
 * ADC_program.c
 *
 *  Created on: Sep 1, 2026
 *      Author: Mai Essam
 */

#include "../../DIO/LIB/BIT_MATH.h"
#include "../../DIO/LIB/STD.h"
#include "../../DIO/MCAL/DIO/DIO_interface.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


/**
 * @brief Stores the ADC reading obtained through interrupt.
 */
u16 interrupt_reading;

/**
 * @brief Initializes the ADC module.
 *
 * Configures the global interrupt, ADC interrupt, voltage reference,
 * prescaler, and enables the ADC.
 */
void ADC_init(){
	//clear global interrupt
	CLR_BIT(SREG,I);

	//clear ADC interrupt
	SET_BIT(ADCSRA,ADIE);

	//clear ADC enable
	CLR_BIT(ADCSRA,ADEN);

	//set ref to internal ADLAR->right
	ADMUX=V_selection;

	//set prescaler
	 ADCSRA=ADC_prescaler;

	//set ADC enable
	SET_BIT(ADCSRA,ADEN);
}

/**
 * @brief Performs a synchronous ADC conversion.
 *
 * Starts an ADC conversion on the selected channel and waits until
 * the conversion is completed before returning the ADC reading.
 *
 * @param ch_select The ADC channel to be selected.
 * @return The ADC digital conversion result.
 */
u16 ADC_sync(u8 ch_select){//adc1
	u16 ADC_reading=0;

	ADMUX=V_selection|ch_select;

	//start conversion
	SET_BIT(ADCSRA,ADSC);

	while(GET_BIT(ADCSRA,ADIF)!=1){}

	ADC_reading=ADCL;
	ADC_reading |= (8<<ADCH);

	return ADC_reading;
}

/**
 * @brief Starts an asynchronous ADC conversion.
 *
 * Selects the required ADC channel, enables the required interrupts,
 * and starts the ADC conversion without waiting for the result.
 *
 * @param ch_select The ADC channel to be selected.
 */
void ADC_Async(u8 ch_select){
	ADMUX |= ch_select;

	//set global interrupt
	SET_BIT(SREG,I);

	//set ADC interrupt
	SET_BIT(ADCSRA,ADIE);//=======

	//Start conversion
	SET_BIT(ADCSRA,ADSC);

}

/**
 * @brief ADC conversion complete interrupt service routine.
 *
 * Reads the ADC result after the conversion is completed and stores
 * it in the global interrupt_reading variable.
 */
void __vector_16() __attribute__((signal,used));
void __vector_16(){
	interrupt_reading=ADCL;
	interrupt_reading |= (8<<ADCH);
}