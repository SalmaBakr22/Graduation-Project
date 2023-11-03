#ifndef TIM2_PRIV_H
#define TIM2_PRIV_H

#define TIM2_NORMAL      0
#define TIM2_CTC         1
#define TIM2_FAST_PWM    2
#define TIM2_PHASE_CORR  3


#define TIM2_DISC    0
#define TIM2_TGL     1
#define TIM2_CLR     2
#define TIM2_SET     3
#define TIM2_NON_INV 2
#define TIM2_INV     3


#define TIM2_NO_PRES         0
#define TIM2_1_PRES          1
#define TIM2_8_PRES          2
#define TIM2_64_PRES         3
#define TIM2_256_PRES        4
#define TIM2_1024_PRES       5
#define TIM2_EXT_CLK_FALL    6
#define TIM2_EXT_CLK_RISING  7


#define TCCR2   *((volatile uint8 * ) 0x45 )
#define TCNT2   *((volatile uint8 * ) 0x44 )
#define OCR2    *((volatile uint8 * ) 0x43 )
#define TIMSK   *((volatile uint8 * ) 0x59 )
#define TIFR    *((volatile uint8 * ) 0x58 )



#endif