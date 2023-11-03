#include "STD_Types.h"
#include "BIT_Math.h"
#include "EXT1.h"
#include "EXT1_cfg.h"
#include "EXT1_priv.h"

volatile pf EXT1_pfCallBack ;
 
void EXT1_vidInit(void)
{
	MCUCR &=0b11110011;               
	MCUCR |= (EXT1_SENSE_MODE&0x0C);
	CLR_BIT(GICR , 7);
	SET_BIT(GIFR , 7);
}

void EXT1_vidEnable(void)
{
	SET_BIT(GICR , 7);
}
void EXT1_vidDisable(void)
{
	CLR_BIT(GICR , 7);
}

void EXT1_vidChgMod(uint8 u8ModeCpy)
{
	MCUCR &=0b11110011;
	MCUCR |= (u8ModeCpy&0x0C);
}

void EXT1_vidSetCallBack(pf pfCpy)
{
	EXT1_pfCallBack = pfCpy ;
}

void __vector_2(void) __attribute__((signal , used));
void __vector_2(void)
{
	EXT1_pfCallBack();
}





