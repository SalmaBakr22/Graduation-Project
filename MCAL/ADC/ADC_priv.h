
#ifndef ADC_PRIV_H
#define ADC_PRIV_H


#define ADC_AREF     0
#define ADC_AVCC     1
#define ADC_INTERNAL 2



#define ADC_10BIT  0
#define ADC_8BIT   1


#define ADC_PRE_2      1
#define ADC_PRE_4      2
#define ADC_PRE_8      3
#define ADC_PRE_16     4
#define ADC_PRE_32     5
#define ADC_PRE_64     6
#define ADC_PRE_128    7


#define ADC_SNGL_MODE  0
#define ADC_AUTO_TRIG  1


#define ADC_FREE_RUN           0
#define ADC_ANA_CMP_TRIG       1
#define ADC_EXT0_TRIG          2
#define ADC_TIM0_CMP_TRIG      3


#define ADMUX    *((volatile uint8 *) 0x27)
#define ADCSRA   *((volatile uint8 *) 0x26)
#define ADCH     *((volatile uint8 *) 0x25)
#define ADCL     *((volatile uint8 *) 0x24)
#define SFIOR    *((volatile uint8 *) 0x50)



#endif 
