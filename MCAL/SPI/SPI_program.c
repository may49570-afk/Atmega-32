/**
 * @file SPI_program.c
 * @brief Implementation file for the SPI driver.
 *
 * This file contains the SPI initialization function and the data
 * transfer function. The SPI peripheral is configured according to
 * the selected master/slave mode, clock settings, operating mode,
 * data order, and interrupt configuration.
 *
 * @date Sep 7, 2026
 * @author Mai Essam
 */

#include "../DIO/LIB/BIT_MATH.h"
#include "../DIO/LIB/STD.h"

#include "../DIO/MCAL/DIO/DIO_interface.h"

#include "SPI_private.h"
#include "SPI_interface.h"
#include "SPI_config.h"

/**
 * @brief Initializes the SPI peripheral.
 *
 * Configures the SPI operating role, pin directions, clock frequency,
 * clock polarity and phase, data transmission order, and interrupt
 * settings according to SPI_config.h. Finally, enables the SPI peripheral.
 */
void SPI_init(){

#if SPI_MS_MODE == SPI_Master
	/**
	 * @brief Selects Master mode.
	 */
	SET_BIT(SPCR,MSTR);

	/**
	 * @brief Configures SPI pins for Master mode.
	 */
	SetPinDir(DDRB,MOSI,DIO_OUTPUT);
	SetPinDir(DDRB,MISO,DIO_INPUT);
	SetPinDir(DDRB,SCK,DIO_OUTPUT);
	SetPinDir(DDRB,SS,DIO_OUTPUT);

	/**
	 * @brief Configures the SPI clock speed.
	 */
	#if SPI_CLK<=SPI_clk_F_4 && SPI_CLK>=SPI_clk_F_32

		#if SPI_CLK<=SPI_clk_F_4 && SPI_CLK>SPI_clk_F_128
			CLR_BIT(SPSR,SPI2X);

		#else
			SET_BIT(SPSR,SPI2X);
		#endif
	#endif
		SPCR &= SPI_clk_mask;
		SPCR |= (SPI_CLK & SPI_clk_mask2);


#elif	SPI_MS_MODE == SPI_Slave
	/**
	 * @brief Selects Slave mode.
	 */
	CLR_BIT(SPCR,MSTR);

	/**
	 * @brief Configures SPI pins for Slave mode.
	 */
	SetPinDir(DDRB,MOSI,DIO_INPUT);
	SetPinDir(DDRB,MISO,DIO_OUTPUT);
	SetPinDir(DDRB,SCK,DIO_INPUT);
	SetPinDir(DDRB,SS,DIO_INPUT);

#endif



/**
 * @brief Configures the SPI clock polarity and phase.
 */
//SPI_MODES
#if SPI_MODE == SPI_MODE0
	CLR_BIT(SPDR,CPOL);
	CLR_BIT(SPDR,CPHA);


#elif SPI_MODE == SPI_MODE1
	CLR_BIT(SPDR,CPOL);
	SET_BIT(SPDR,CPHA);


#elif SPI_MODE == SPI_MODE2
	SET_BIT(SPDR,CPOL);
	CLR_BIT(SPDR,CPHA);


#elif SPI_MODE == SPI_MODE3
	SET_BIT(SPDR,CPOL);
	SET_BIT(SPDR,CPHA);


#endif



/**
 * @brief Configures the SPI data transmission order.
 */
//DATA ORDER
#if SPI_DATA_ORDER	== LSB
	SET_BIT(SPCR,DORD);

#elif SPI_DATA_ORDER == MSB
	CLR_BIT(SPCR,DORD);

#endif



/**
 * @brief Enables or disables the SPI interrupt.
 */
//SPI_INTERRUPT_MODE
#if SPI_INTERRUPT_MODE ==SPI_INTERRUPT_ENABLE
	SET_BIT(SPCR,SPIE);

#elif SPI_INTERRUPT_MODE ==SPI_INTERRUPT_DISABLE
	CLR_BIT(SPCR,SPIE);

#endif

	/**
	 * @brief Enables the SPI peripheral.
	 */
	SET_BIT(SPCR,SPE);

}


/**
 * @brief Transfers one byte through SPI.
 *
 * Writes the supplied byte to the SPI Data Register, waits until
 * the transfer is complete, and then returns the received byte.
 *
 * @param data The byte to transmit.
 * @return The byte received during the SPI transfer.
 */
u8 Transfer_Data(u8 data){
	SPDR=data;
	while(GIT_BIT(SPSR,SPIF)!=1){}
	return SPDR;
}
