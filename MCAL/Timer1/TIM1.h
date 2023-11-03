#ifndef TIM0_H
#define TIM0_H


void TIM1_vidInit(void) ;

void TIM1_vidEnableOvfInt(void);
void TIM1_vidDisableOvfInt(void);

void TIM1_vidEnableCmpInt(void);
void TIM1_vidDisableCmpInt(void);

void TIM1_vidEnableCmpBInt(void);
void TIM1_vidDisableCmpBInt(void);
void TIM1_vidEnableCmpAInt(void);
void TIM1_vidDisableCmpAInt(void);
void TIM1_vidEnableICUInt(void);
void TIM1_vidDisableBICUInt(void);
void TIM1_SetTimVal(uint16 u16TimValCpy);
void TIM1_SetOutputCmpAVal(uint16 u16OutputCmpAValCpy);
void TIM1_SetOutputCmpBVal(uint16 u16OutputCmpBValCpy);
uint16 TIM1_GetICUValue(void);
void TIM1_vidChgICUMod(uint8 u8ModeCpy);
void TIM1_vidSetCallBackOvf(pf pfovfFunCpy);
void TIM1_vidSetCallBackCmpA(pf pfCmpaFunCpy);
void TIM1_vidSetCallBackCmpB(pf pfCmpBFunCpy);
void TIM1_vidSetCallBackCapt(pf pfCaptFunCpy);


#endif
