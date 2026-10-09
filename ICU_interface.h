/*
 * ICU_interface.h
 *
 *  Created on: Sep 3, 2026
 *      Author: Essam
 */

#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_

#define ICU_ENABLE 							1
#define ICU_DISABLE 						0

#define ICU_FALLING_EDGE 					0
#define ICU_RISING_EDGE 					1

#define ICU_PRESCALER_NO_CLK  				0
#define ICU_PRESCALER_NO_PRESCALING   		1
#define ICU_PRESCALER_8  					2
#define ICU_PRESCALER_64					3
#define ICU_PRESCALER_256  					4
#define ICU_PRESCALER_1024   				5

//Function
void ICU_init();
void ICU_SetPrescaler(u8 prescaler);
void ICU_SetRising();
void ICU_SetFalling();
void ICU_SetTime(u16 value);
u16 ICU_GetTime();
void ICU_SetOverFlow(u16 OVF_value);
u16 ICU_GetOverFlow();
u16 Get_prescaler();
void GIE_enable();
void GIE_disable();
void ICU_SetCallBack(void (*ptr)());


#endif /* ICU_INTERFACE_H_ */
