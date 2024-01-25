#include "../../Lib/STD_Types.h"
#include "../../Lib/BIT_Math.h"
#include "EXT0.h"
#include "EXT0_cfg.h"
#include "EXT0_priv.h"

volatile pf EXT0_pfCallBack ;
 
void EXT0_vidInit(void)
{
	MCUCR &=0b11111100;
	MCUCR |= (EXT0_SENSE_MODE&0x03);
	CLR_BIT(GICR , 6);
	SET_BIT(GIFR , 6);
}

void EXT0_vidEnable(void)
{
	SET_BIT(GICR , 6);
}
void EXT0_vidDisable(void)
{
	CLR_BIT(GICR , 6);
}

void EXT0_vidChgMod(uint8 u8ModeCpy)  
{
	MCUCR &=0b11111100;
	MCUCR |= (u8ModeCpy&0x03);
}

void EXT0_vidSetCallBack(pf pfCpy)
{
	EXT0_pfCallBack = pfCpy ;
}

void __vector_1(void) __attribute__((signal , used));
void __vector_1(void)
{
	EXT0_pfCallBack();
}





