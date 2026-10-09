/*
 * SPI_private.h
 *
 *  Created on: Sep 7, 2026
 *      Author: Essam
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


#define SPCR 				*((volatile u8*)(0x2D))
#define SPSR 				*((volatile u8*)(0x2E))
#define SPDR 				*((volatile u8*)(0x2F))
#define DDRB 				*((volatile u8*)(0x37))



//SPCR Register
#define SPR0				0
#define SPR1				1
#define CPHA				2
#define CPOL				3
#define MSTR				4
#define DORD				5
#define SPE					6
#define SPIE				7


//SPSR Register
#define SPI2X				0
#define WCOL				6
#define SPIF				7



#define SPI_Master 				1
#define SPI_Slave 				0

#define SPI_clk_F_4 			0
#define SPI_clk_F_16 			1
#define SPI_clk_F_64 			2
#define SPI_clk_F_128 			3
#define SPI_clk_F_2 			4
#define SPI_clk_F_8 			5
#define SPI_clk_F_32 			6


#define SPI_clk_mask 			0xFC//=============
#define SPI_clk_mask2 			0x03//=============



#define SPI_INTERRUPT_ENABLE			1
#define SPI_INTERRUPT_DISABLE			0


//SPI MODE
#define SPI_MODE0 				0 //Sample (Rising) Setup (Falling)
#define SPI_MODE2 				1 //Setup (Rising) Sample (Falling)
#define SPI_MODE1 				2 //Sample (Falling) Setup (Rising)
#define SPI_MODE3 				3 //Setup (Falling) Sample (Rising)

//
#define SS 				4
#define MOSI 			5
#define MISO 			6
#define SCK 			7


//DATA BIT
#define LSB 				4
#define MSB 				5

#endif /* SPI_PRIVATE_H_ */
