#ifndef TIM2_H
#define TIM2_H


void TIM2_vidInit(void) ;

void TIM2_vidEnableOvfInt(void);
void TIM2_vidDisableOvfInt(void);

void TIM2_vidEnableCmpInt(void);
void TIM2_vidDisableCmpInt(void);

void TIM2_SetTimVal(uint8 u8TimValCpy);
void TIM2_SetOutputCmpVal(uint8 u8OutputCmpValCpy);

void TIM2_vidSetCallBackOvf(pf pfovfFunCpy);
void TIM2_vidSetCallBackCmp(pf pfCmpFunCpy);

#endif
