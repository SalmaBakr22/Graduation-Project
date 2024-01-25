/*
 * SPI.c
 *
 *  Created on: Oct 21, 2023
 *      Author: ASUS
 */
#include "../../Lib/STD_Types.h"
#include "../../Lib/BIT_MATH.h"

#include "SPI.h"
#include "SPI_cfg.h"
#include "SPI_priv.h"


pf SPI_pfCallFunc ;


void SPI_vidInit(void)
{
	uint8 u8SpcrLoc =0b01000000,u8SpsrLoc = 0 ;
	u8SpcrLoc |= SPI_DATA_ORDER << 5 ;
	u8SpcrLoc |= SPI_MODE << 4 ;
	u8SpcrLoc |= SPI_CLK_IDLE_STATE << 3 ;
	u8SpcrLoc |= SPI_PHASE << 2;
#if SPI_MODE == SPI_MASTER
	u8SpcrLoc |= (SPI_PRESCALLER & 0b00000011);
	u8SpsrLoc |= (SPI_PRESCALLER & 0b00000100)>>2;
#endif
	SPSR = u8SpsrLoc;
	SPCR = u8SpcrLoc ;
}

void SPI_vidEnable(void)
{
	SET_BIT(SPCR,6);
}
void SPI_vidDisable(void)
{
	CLR_BIT(SPCR,6);
}

void SPI_vidEnableInt(void)
{
	SET_BIT(SPCR,7);
}
void SPI_vidDisableInt(void)
{
	CLR_BIT(SPCR,7);
}

void SPI_vidSetCallBack(pf pfCallFuncCpy)
{
	SPI_pfCallFunc = pfCallFuncCpy ;
}

uint8 SPI_u8GetMode(void)
{
	return GET_BIT(SPCR , 4);
}
void SPI_vidChgMode(uint8 u8ModeCpy)
{
	if(u8ModeCpy == SPI_MASTER)
	{
		SET_BIT(SPCR , 4);
	}
	else
	{
		CLR_BIT(SPCR , 4);
	}
}

uint8 SPI_u8Transmit(uint8 u8DataCpy)
{
	SPDR = u8DataCpy;
	while(GET_BIT(SPSR,7) != 1);
	return SPDR ;
}

void SPI_vidSendData(uint8 u8DataCpy)
{
	SPDR = u8DataCpy;
}
uint8 SPI_u8RecvData(void)
{
	return SPDR ;
}

void __vector_12 (void) __attribute__((signal,used));
void __vector_12 (void)
{
	SPI_pfCallFunc();
}



