#ifndef TIM0_PRIV_H
#define TIM0_PRIV_H

#define TIM0_NORMAL      0
#define TIM0_CTC         1
#define TIM0_FAST_PWM    2
#define TIM0_PHASE_CORR  3


#define TIM0_DISC    0
#define TIM0_TGL     1
#define TIM0_CLR     2
#define TIM0_SET     3
#define TIM0_NON_INV 2
#define TIM0_INV     3


#define TIM0_NO_PRES         0
#define TIM0_1_PRES          1
#define TIM0_8_PRES          2
#define TIM0_64_PRES         3
#define TIM0_256_PRES        4
#define TIM0_1024_PRES       5
#define TIM0_EXT_CLK_FALL    6
#define TIM0_EXT_CLK_RISING  7


#define TCCR0   *((volatile uint8 * ) 0x53 )
#define TCNT0   *((volatile uint8 * ) 0x52 )
#define OCR0    *((volatile uint8 * ) 0x5C )
#define TIMSK   *((volatile uint8 * ) 0x59 )
#define TIFR    *((volatile uint8 * ) 0x58 )



#endif