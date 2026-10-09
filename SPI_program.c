/*
 * SPI_program.c
 *
 *  Created on: Sep 7, 2026
 *      Author: Essam
 */

#include "../DIO/LIB/BIT_MATH.h"
#include "../DIO/LIB/STD.h"

#include "../DIO/MCAL/DIO/DIO_interface.h"

#include "SPI_private.h"
#include "SPI_interface.h"
#include "SPI_config.h"

void SPI_init(){

#if SPI_MS_MODE == SPI_Master
	SET_BIT(SPCR,MSTR);

	SetPinDir(DDRB,MOSI,DIO_OUTPUT);
	SetPinDir(DDRB,MISO,DIO_INPUT);
	SetPinDir(DDRB,SCK,DIO_OUTPUT);
	SetPinDir(DDRB,SS,DIO_OUTPUT);

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
	CLR_BIT(SPCR,MSTR);

	SetPinDir(DDRB,MOSI,DIO_INPUT);
	SetPinDir(DDRB,MISO,DIO_OUTPUT);
	SetPinDir(DDRB,SCK,DIO_INPUT);
	SetPinDir(DDRB,SS,DIO_INPUT);

#endif



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



//DATA ORDER
#if SPI_DATA_ORDER	== LSB
	SET_BIT(SPCR,DORD);

#elif SPI_DATA_ORDER == MSB
	CLR_BIT(SPCR,DORD);

#endif



//SPI_INTERRUPT_MODE
#if SPI_INTERRUPT_MODE ==SPI_INTERRUPT_ENABLE
	SET_BIT(SPCR,SPIE);

#elif SPI_INTERRUPT_MODE ==SPI_INTERRUPT_DISABLE
	CLR_BIT(SPCR,SPIE);

#endif

	SET_BIT(SPCR,SPE);

}



u8 Transfer_Data(u8 data){
	SPDR=data;
	while(GIT_BIT(SPSR,SPIF)!=1){}
	return SPDR;
}
