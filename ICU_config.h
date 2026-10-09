/*
 * ICU_config.h
 *
 *  Created on: Sep 3, 2026
 *      Author: Essam
 */

#ifndef ICU_CONFIG_H_
#define ICU_CONFIG_H_


#define ICU_CANCELER 			ICU_DISABLE

//EDGE
#define ICU_EDGE_SELECT 		ICU_FALLING_EDGE

//PRESCALER
#define ICU_PRESCALER 			ICU_PRESCALER_256

//INTERRUPT
//Overflow Interrupt Enable
#define ICU_OVF1_INTERRUPT 		ICU_ENABLE
//Capture Interrupt Enable
#define ICU_CAPT_INTERRUPT 		ICU_ENABLE

#endif /* ICU_CONFIG_H_ */
