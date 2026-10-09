/*
 * H_Bridge_interface.h
 *
 *  Created on: Aug 30, 2026
 *      Author: Essam
 */

#ifndef HALL_H_BRIDGE_INTERFACE_H_
#define HALL_H_BRIDGE_INTERFACE_H_

void Motor1_init();
void Motor2_init();
void H_Bridge_init();

void Motor1_Forword();
void Motor2_Forword();
void H_Bridge_Forword();

void Motor1_backword();
void Motor2_backword();
void H_Bridge_backword();

void H_Bridge_Right();
void H_Bridge_left();

void Motor1_stop();
void Motor2_stop();
void H_Bridge_stop();

#endif /* HALL_H_BRIDGE_INTERFACE_H_ */
