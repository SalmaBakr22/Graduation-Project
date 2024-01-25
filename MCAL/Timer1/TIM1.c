#include "../../Lib/STD_Types.h"
#include "../../Lib/BIT_Math.h"

#include "TIM1.h"
#include "TIM1_cfg.h"
#include "TIM1_priv.h"

pf TIM1_pfOvfFun ;
pf TIM1_pfCmpAFun ;
pf TIM1_pfCmpBFun ;
pf TIM1_pfCaptFun;

void TIM1_vidInit(void)
{
	uint8 u8Tccr1aLoc = 0 ;
	uint8 u8Tccr1bLoc = 0 ;

	u8Tccr1aLoc |= (TIM1_MODE & 0b00000011) ;             
	u8Tccr1aLoc |= (TIM1_OUTPUTA_MODE << 6) ;
	u8Tccr1aLoc |= (TIM1_OUTPUTB_MODE << 4) ;

	u8Tccr1bLoc |= ((TIM1_MODE & 0b00001100) << 1 );
	u8Tccr1bLoc |= (TIM1_NOISE_CANCELER & 0b10000000) << 7;
	u8Tccr1bLoc |= ((TIM1_ICU_EDGE_SELECT << 6) & 0b10000000);
	u8Tccr1bLoc |= TIM1_PRESC;     

	/* apply data collected in variable officially regester by write operation */
	TCCR1A = u8Tccr1aLoc ;
	TCCR1B = u8Tccr1bLoc;
	/* clr timer value , clr ocr value 34an a2om 2la ndafa */
	TCNT1H = 0 ;
	TCNT1L = 0 ;
	OCR1AH = 0 ;
	OCR1AL = 0 ;
	OCR1BH = 0 ;
	OCR1BL = 0 ;
	

	/* clr PIE ovf enable , cmp enable flags */
	CLR_BIT(TIMSK ,2);
	CLR_BIT(TIMSK ,3);
	CLR_BIT(TIMSK ,4);
	CLR_BIT(TIMSK ,5);

	/** Clr Event flags ovf cmp*/

	SET_BIT(TIFR ,2);
	SET_BIT(TIFR ,3);
	SET_BIT(TIFR ,4);
	SET_BIT(TIFR ,5);

}

void TIM1_vidEnableOvfInt(void)
{
	SET_BIT(TIMSK , 2);
}
void TIM1_vidDisableOvfInt(void)
{
	CLR_BIT(TIMSK , 2);
}

void TIM1_vidEnableCmpBInt(void)
{
	SET_BIT(TIMSK , 3);
}
void TIM1_vidDisableCmpBInt(void)
{
	CLR_BIT(TIMSK , 3);
}
void TIM1_vidEnableCmpAInt(void)
{
	SET_BIT(TIMSK , 4);

}
void TIM1_vidDisableCmpAInt(void)
{
	CLR_BIT(TIMSK , 4);
}
void TIM1_vidEnableICUInt(void)
{
	SET_BIT(TIMSK , 5);

}
void TIM1_vidDisableBICUInt(void)
{
	CLR_BIT(TIMSK , 5);
}


void TIM1_SetTimVal(uint16 u16TimValCpy)
{
	TCNT1H =( u16TimValCpy >> 8 ) ;
	TCNT1L = u16TimValCpy;
}

void TIM1_SetOutputCmpAVal(uint16 u16OutputCmpAValCpy)
{
	OCR1AH = (u16OutputCmpAValCpy >> 8);
	OCR1AL = u16OutputCmpAValCpy;
}

void TIM1_SetOutputCmpBVal(uint16 u16OutputCmpBValCpy)
{
	OCR1BH = (u16OutputCmpBValCpy >> 8);
	OCR1BL = u16OutputCmpBValCpy;
}

uint16 TIM1_GetICUValue(void)
{
	uint16 u16ICUValCpy = 0 ;
	u16ICUValCpy |= (uint8)ICR1L;
	u16ICUValCpy |= (uint16)ICR1H << 8;
	
	return u16ICUValCpy;
}

void TIM1_vidChgICUMod(uint8 u8ModeCpy)
{
	if(u8ModeCpy == TIM1_ICU_FALLINGEDGE)
	{
		SET_BIT(TCCR1B , 6);
	}
	else if(u8ModeCpy == TIM1_ICU_RISINGEDGE)
	{
		CLR_BIT(TCCR1B , 5);
	}
}

void TIM1_vidSetCallBackOvf(pf pfovfFunCpy)
{
	TIM1_pfOvfFun = pfovfFunCpy ;
}
void TIM1_vidSetCallBackCmpA(pf pfCmpaFunCpy)
{
	TIM1_pfCmpAFun = pfCmpaFunCpy ;
}
void TIM1_vidSetCallBackCmpB(pf pfCmpBFunCpy)
{
	TIM1_pfCmpBFun = pfCmpBFunCpy ;
}
void TIM1_vidSetCallBackCapt(pf pfCaptFunCpy)
{
	TIM1_pfCaptFun = pfCaptFunCpy ;
}

void __vector_9 (void) __attribute__((signal,used));
void __vector_9 (void)
{

	TIM1_pfOvfFun();
}

void __vector_8 (void) __attribute__((signal,used));
void __vector_8 (void)
{

	TIM1_pfCmpBFun();
}

void __vector_7 (void) __attribute__((signal,used));
void __vector_7 (void)
{

	TIM1_pfCmpAFun();
}
void __vector_6 (void) __attribute__((signal,used));
void __vector_6 (void)
{

	TIM1_pfCaptFun();
}
