#include "../../Lib/STD_Types.h"
#include "../../Lib/BIT_Math.h"

#include "TIM2.h"
#include "TIM2_cfg.h"
#include "TIM2_priv.h"

pf TIM2_pfOvfFun ;
pf TIM2_pfCmpFun ;
void TIM2_vidInit(void) 
{
 uint8 u8Tccr2Loc = 0 ;
 
 u8Tccr2Loc |= (TIM2_MODE & 0b00000001) << 6;
 u8Tccr2Loc |= (TIM2_MODE & 0b00000010) << 3;
 u8Tccr2Loc |= TIM2_OUTPUT_MODE << 4 ;
 u8Tccr2Loc |= TIM2_PRESC  ;
  /* apply data collected in variable officially regester by write operation */
 TCCR2 = u8Tccr2Loc ;
 /* clr timer value , clr ocr value 34an a2om 2la ndafa */
 TCNT2 = 0 ;
 OCR2  = 0 ;
 /* clr PIE ovf enable , cmp enable flags */
 CLR_BIT(TIMSK ,6);
 CLR_BIT(TIMSK ,7);
 
 /** Clr Event flags ovf cmp*/
 SET_BIT(TIFR ,6);
 SET_BIT(TIFR ,7);
 
 
}

void TIM2_vidEnableOvfInt(void)
{
	SET_BIT(TIMSK , 6);
}
void TIM2_vidDisableOvfInt(void)
{
	CLR_BIT(TIMSK , 6);
}

void TIM2_vidEnableCmpInt(void)
{
	SET_BIT(TIMSK , 7);
}
void TIM2_vidDisableCmpInt(void)
{
	CLR_BIT(TIMSK , 7);
}

void TIM2_SetTimVal(uint8 u8TimValCpy)
{
	TCNT2 = u8TimValCpy;
}
void TIM2_SetOutputCmpVal(uint8 u8OutputCmpValCpy)
{
	OCR2 = u8OutputCmpValCpy;
}

void TIM2_vidSetCallBackOvf(pf pfovfFunCpy)
{
    TIM2_pfOvfFun = pfovfFunCpy ;
}
void TIM2_vidSetCallBackCmp(pf pfCmpFunCpy)
{
	TIM2_pfCmpFun = pfCmpFunCpy ;
}

void __vector_5 (void) __attribute__((signal,used));
void __vector_5 (void) 
{
	
	TIM2_pfOvfFun();
}

void __vector_4 (void) __attribute__((signal,used));
void __vector_4 (void) 
{
	
	TIM2_pfCmpFun();
}