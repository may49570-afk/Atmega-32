/*
 * EXT_interrupt_private.h
 *
 *  Created on: Aug 31, 2026
 *      Author: Essam
 */

#ifndef MCAL_EXT_INTERRUPT_PRIVATE_H_
#define MCAL_EXT_INTERRUPT_PRIVATE_H_

#define MCUCR  *((volatile u8 *)(0x55))
#define MCUCSR *((volatile u8 *)(0x54))
#define GICR   *((volatile u8 *)(0x5B))
#define GIFR   *((volatile u8 *)(0x5A))

#define ISC11 3
#define ISC10 2
#define ISC01 1
#define ISC00 0

#define ISC2 6

//Enable_num
#define INT0 7
#define INT1 6
#define INT2 5

#define EXT_LOW_LOGIC 0
#define EXT_ANY_LOGIC 1
#define EXT_FALLING   2
#define EXT_RISING    3


#endif /* MCAL_EXT_INTERRUPT_PRIVATE_H_ */
