#ifndef ADC_H
#define ADC_H

#define ADC_CH0  0
#define ADC_CH1  1
#define ADC_CH2  2
#define ADC_CH3  3
#define ADC_CH4  4
#define ADC_CH5  5
#define ADC_CH6  6
#define ADC_CH7  7
#define ADC_CH0_DIF_CH0_G10  8
#define ADC_CH1_DIF_CH0_G10  9

void   ADC_vidInit(void);
void   ADC_vidSelCh(uint8 u8ChNbCpy);
void   ADC_vidEnable(void);
void   ADC_vidDisable(void);
void   ADC_vidStartConv(void);
uint16 ADC_u16ReadSync(void);
uint16 ADC_u16ReadAsync(void);
void   ADC_vidEnableInt(void);
void   ADC_vidDisableInt(void);




#endif


