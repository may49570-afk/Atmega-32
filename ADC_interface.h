/*
 * ADC_interface.h
 *
 *  Created on: Sep 1, 2026
 *      Author: Mai Essam
 */

#ifndef MCAL_ADC_INTERFACE_H_
#define MCAL_ADC_INTERFACE_H_

/**
 * @brief Initializes the ADC module.
 */
void ADC_init();

/**
 * @brief Performs a synchronous ADC conversion on the selected channel.
 *
 * @param ch_select The ADC channel to be selected.
 * @return The ADC digital conversion result.
 */
u16 ADC_sync(u8 ch_select);

/**
 * @brief Starts an asynchronous ADC conversion on the selected channel.
 *
 * @param ch_select The ADC channel to be selected.
 */
void ADC_Async(u8 ch_select);

#endif /* MCAL_ADC_INTERFACE_H_ */