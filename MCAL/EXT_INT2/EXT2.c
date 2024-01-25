#include "../../Lib/STD_Types.h"
#include "../../Lib/BIT_Math.h"
#include "EXT2.h"
#include "EXT2_cfg.h"
#include "EXT2_priv.h"

volatile pf EXT2_pfCallBack ;
 
void EXT2_vidInit(void)
{
	MCUCSR &=0b10111111;               
	MCUCSR |= (EXT2_SENSE_MODE&0x40);
	CLR_BIT(GICR , 5);
	SET_BIT(GIFR , 5);
}

void EXT2_vidEnable(void)
{
	SET_BIT(GICR , 5);
}
void EXT2_vidDisable(void)
{
	CLR_BIT(GICR , 5);
}

void EXT2_vidChgMod(uint8 u8ModeCpy)
{
	MCUCSR &=0b10111111;
	MCUCSR |= (u8ModeCpy&0x40);
}

void EXT2_vidSetCallBack(pf pfCpy)
{
	EXT2_pfCallBack = pfCpy ;
}

void __vector_3(void) __attribute__((signal , used));
void __vector_3(void)
{
	EXT2_pfCallBack();
}





