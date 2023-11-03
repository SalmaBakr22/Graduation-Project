#ifndef ADC_CFG_H
#define ADC_CFG_H

   
#define ADC_VOLT_REF    ADC_AVCC

#define ADC_BIT_MODE    ADC_8BIT

#define ADC_CHN_SEL     ADC_CH3

#define ADC_PRESCALLER  ADC_PRE_8

#define ADC_CON_MODE    ADC_SNGL_MODE

#if ADC_CON_MODE == ADC_AUTO_TRIG
#define ADC_TIG_SRC   ADC_FREE_RUN  
#endif 






#endif
