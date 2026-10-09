/**
 * @file SPI_private.h
 * @brief Private definitions for the SPI driver.
 *
 * This file contains the memory-mapped register definitions,
 * register bit positions, SPI configuration constants, clock
 * prescaler options, interrupt settings, and SPI pin assignments.
 *
 * @date Sep 7, 2026
 * @author Mai Essam
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/**
 * @brief SPI Control Register.
 */
#define SPCR 				*((volatile u8*)(0x2D))

/**
 * @brief SPI Status Register.
 */
#define SPSR 				*((volatile u8*)(0x2E))

/**
 * @brief SPI Data Register.
 */
#define SPDR 				*((volatile u8*)(0x2F))

/**
 * @brief Port B Data Direction Register.
 */
#define DDRB 				*((volatile u8*)(0x37))


/**
 * @brief Bit positions in the SPI Control Register (SPCR).
 */
//SPCR Register
#define SPR0				0
#define SPR1				1
#define CPHA				2
#define CPOL				3
#define MSTR				4
#define DORD				5
#define SPE					6
#define SPIE				7


/**
 * @brief Bit positions in the SPI Status Register (SPSR).
 */
//SPSR Register
#define SPI2X				0
#define WCOL				6
#define SPIF				7


/**
 * @brief Selects SPI Master mode.
 */
#define SPI_Master 				1

/**
 * @brief Selects SPI Slave mode.
 */
#define SPI_Slave 				0

/**
 * @brief Selects an SPI clock frequency of F_CPU / 4.
 */
#define SPI_clk_F_4 			0

/**
 * @brief Selects an SPI clock frequency of F_CPU / 16.
 */
#define SPI_clk_F_16 			1

/**
 * @brief Selects an SPI clock frequency of F_CPU / 64.
 */
#define SPI_clk_F_64 			2

/**
 * @brief Selects an SPI clock frequency of F_CPU / 128.
 */
#define SPI_clk_F_128 			3

/**
 * @brief Selects an SPI clock frequency of F_CPU / 2.
 */
#define SPI_clk_F_2 			4

/**
 * @brief Selects an SPI clock frequency of F_CPU / 8.
 */
#define SPI_clk_F_8 			5

/**
 * @brief Selects an SPI clock frequency of F_CPU / 32.
 */
#define SPI_clk_F_32 			6


/**
 * @brief Mask used to clear the SPI clock selection bits.
 */
#define SPI_clk_mask 			0xFC//=============

/**
 * @brief Mask used to select the SPI clock prescaler bits.
 */
#define SPI_clk_mask2 			0x03//=============


/**
 * @brief Enables SPI interrupts.
 */
#define SPI_INTERRUPT_ENABLE			1

/**
 * @brief Disables SPI interrupts.
 */
#define SPI_INTERRUPT_DISABLE			0


/**
 * @brief SPI clock mode definitions.
 */
//SPI MODE
#define SPI_MODE0 				0 //Sample (Rising) Setup (Falling)
#define SPI_MODE2 				1 //Setup (Rising) Sample (Falling)
#define SPI_MODE1 				2 //Sample (Falling) Setup (Rising)
#define SPI_MODE3 				3 //Setup (Falling) Sample (Rising)

//
/**
 * @brief Port B pin number used for Slave Select (SS).
 */
#define SS 				4

/**
 * @brief Port B pin number used for Master Out Slave In (MOSI).
 */
#define MOSI 			5

/**
 * @brief Port B pin number used for Master In Slave Out (MISO).
 */
#define MISO 			6

/**
 * @brief Port B pin number used for the SPI Clock (SCK).
 */
#define SCK 			7


/**
 * @brief Configures data transmission to start with the least significant bit.
 */
//DATA BIT
#define LSB 				4

/**
 * @brief Configures data transmission to start with the most significant bit.
 */
#define MSB 				5

#endif /* SPI_PRIVATE_H_ */
