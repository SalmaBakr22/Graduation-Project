#include "../../Lib/STD_Types.h"
#include "../../Lib/BIT_Math.h"

#include "TIM0.h"
#include "TIM0_cfg.h"
#include "TIM0_priv.h"

pf TIM0_pfOvfFun ;
pf TIM0_pfCmpFun ;

void TIM0_vidInit(void) 
{
 uint8 u8Tccr0Loc = 0 ;
 #if   TIM0_MODE == TIM0_NORMAL
	CLR_BIT(u8Tccr0Loc , 6);
	CLR_BIT(u8Tccr0Loc , 3);
 #elif TIM0_MODE == TIM0_CTC
 	CLR_BIT(u8Tccr0Loc , 6);
	SET_BIT(u8Tccr0Loc , 3);
 #elif TIM0_MODE == TIM0_FAST_PWM
    SET_BIT(u8Tccr0Loc , 6);
	SET_BIT(u8Tccr0Loc , 3);
 #elif TIM0_MODE == TIM0_PHASE_CORR
    SET_BIT(u8Tccr0Loc , 6);
	CLR_BIT(u8Tccr0Loc , 3);
 #endif 
 
 u8Tccr0Loc |= TIM0_OUTPUT_MODE << 4 ;
 u8Tccr0Loc |= TIM0_PRESC  ;
 
 /* apply data collected in variable officially regester by write operation */
 TCCR0 = u8Tccr0Loc ;
 /* clr timer value , clr ocr value 34an a2om 2la ndafa */
 TCNT0 = 0 ;
 OCR0  = 0 ;
 /* clr PIE ovf enable , cmp enable flags */
 CLR_BIT(TIMSK ,0);
 CLR_BIT(TIMSK ,1);
 
 /** Clr Event flags ovf cmp*/
 SET_BIT(TIFR ,0);
 SET_BIT(TIFR ,1);
 
 
}

void TIM0_vidEnableOvfInt(void)
{
	SET_BIT(TIMSK , 0);
}
void TIM0_vidDisableOvfInt(void)
{
	CLR_BIT(TIMSK , 0);
}

void TIM0_vidEnableCmpInt(void)
{
	SET_BIT(TIMSK , 1);
}
void TIM0_vidDisableCmpInt(void)
{
	CLR_BIT(TIMSK , 1);
}

void TIM0_SetTimVal(uint8 u8TimValCpy)
{
	TCNT0 = u8TimValCpy;
}
void TIM0_SetOutputCmpVal(uint8 u8OutputCmpValCpy)
{
	OCR0 = u8OutputCmpValCpy;
}

void TIM0_vidSetCallBackOvf(pf pfovfFunCpy)
{
    TIM0_pfOvfFun = pfovfFunCpy ;
}
void TIM0_vidSetCallBackCmp(pf pfCmpFunCpy)
{
	TIM0_pfCmpFun = pfCmpFunCpy ;
}

void __vector_11 (void) __attribute__((signal,used));
void __vector_11 (void) 
{
	
	TIM0_pfOvfFun();
}

void __vector_10 (void) __attribute__((signal,used));
void __vector_10 (void) 
{
	
	TIM0_pfCmpFun();
}