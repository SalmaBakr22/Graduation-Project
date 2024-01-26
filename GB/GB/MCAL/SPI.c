/*
 * SPI.c
 *
 * Created: 12/8/2023 3:03:18 PM
 *  Author: Ali Reda
 */ 

#include "SPI.h"
#include "../Utils.h"
#include "../MemoryMap.h"

uint8_t *pdata;

void SPI_master_init(clock_rate r)
{
	// clock freq
	switch(r)
	{
		case f_dividedby4:
		CLEAR_BIT(SPCR,SPR0);
		CLEAR_BIT(SPCR,SPR1);
		CLEAR_BIT(SPSR,SPI2X);
		break;
		case f_dividedby16:
		SET_BIT(SPCR,SPR0);
		CLEAR_BIT(SPCR,SPR1);
		CLEAR_BIT(SPSR,SPI2X);
		break;
		case f_dividedby64:
		CLEAR_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		CLEAR_BIT(SPSR,SPI2X);
		break;
		case f_dividedby128:
		SET_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		CLEAR_BIT(SPSR,SPI2X);
		break;
		case f_dividedby2:
		CLEAR_BIT(SPCR,SPR0);
		CLEAR_BIT(SPCR,SPR1);
		SET_BIT(SPSR,SPI2X);
		break;
		case f_dividedby8:
		SET_BIT(SPCR,SPR0);
		CLEAR_BIT(SPCR,SPR1);
		SET_BIT(SPSR,SPI2X);
		break;
		case f_dividedby32:
		CLEAR_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		SET_BIT(SPSR,SPI2X);
		break;
	}
	// master select
	SET_BIT(SPCR,MSTR);
	// clock polarity
	CLEAR_BIT(SPCR,CPOL);
	// Clock Phase
	CLEAR_BIT(SPCR,CPHA);
	// Data Order
	SET_BIT(SPCR,DORD);
	// SPI Enable
	SET_BIT(SPCR,SPE);
}
void SPI_slave_init()
{
	// slave select
	CLEAR_BIT(SPCR,MSTR);
	// clock polarity
	CLEAR_BIT(SPCR,CPOL);
	// Clock Phase
	CLEAR_BIT(SPCR,CPHA);
	// Data Order
	SET_BIT(SPCR,DORD);
	// SPI Enable
	SET_BIT(SPCR,SPE);
}

uint8_t SPI_send_recieve(uint8_t data)
{
	SPDR=data;
	while(!(READ_BIT(SPSR,SPIF)==1));
	return SPDR;
}

void SPI_send_noblock(uint8_t data)
{
	SPDR=data;
}

void SPI_recieve_noblock(uint8_t *data)
{
	*data=SPDR;
}

uint8_t SPI_send_PC(uint8_t data)
{
	if (READ_BIT(SPSR,SPIF))
	{
		SPDR=data;
		return 1;
	}
	return 0;
}

uint8_t SPI_recieve_PC(uint8_t *data)
{
	if (READ_BIT(SPSR,SPIF))
	{
		*data=SPDR;
		return 1;
	}
	return 0;
}

void SPI_recieve_setcallback(uint8_t *data)
{
	*pdata=*data;
}

void SPI_interrupt_enable()
{
	SET_BIT(SPCR,SPIE);
}

void SPI_interrupt_disable()
{
	CLEAR_BIT(SPCR,SPIE);
}

ISR(SPI_STC_vect)
{
	SPI_recieve_noblock(pdata);
}