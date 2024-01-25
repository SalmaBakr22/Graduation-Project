#ifndef TIM0_PRIV_H
#define TIM0_PRIV_H


#define TIM1_NOISE_DIACTIVATE              0
#define TIM1_NOISE_ACTIVATE                1

#define TIM1_ICU_FALLINGEDGE               0
#define TIM1_ICU_RISINGEDGE                1

#define TIM1_NORMAL                        0
#define TIM1_PWM_8                         1
#define TIM1_PWM_9                         2
#define TIM1_PWM_10                        3
#define TIM1_CTC                           4
#define TIM1_FAST_PWM_8                    5
#define TIM1_FAST_PWM_9                    6
#define TIM1_FAST_PWM_10                   7
#define TIM1_PWM_PHASE_FREQ_CORRECT        8
#define TIM1_PWM_PHASE_FREQ_CORRECT        9
#define TIM1_PWM_PHASE_CORRECT             10
#define TIM1_PWM_PHASE_CORRECT             11
#define TIM1_CTC                           12
#define TIM1_FAST_PWM                      14
#define TIM1_FAST_PWM                      15


#define TIM1_DISC    0
#define TIM1_TGL     1
#define TIM1_CLR     2
#define TIM1_SET     3
#define TIM1_NON_INV 2
#define TIM1_INV     3


#define TIM1_NO_PRES         0
#define TIM1_1_PRES          1
#define TIM1_8_PRES          2
#define TIM1_64_PRES         3
#define TIM1_256_PRES        4
#define TIM1_1024_PRES       5
#define TIM1_EXT_CLK_FALL    6
#define TIM1_EXT_CLK_RISING  7

#define TCCR1A    *((volatile uint8 *) 0x4F)
#define TCCR1B    *((volatile uint8 *) 0x4E)
#define TCNT1H    *((volatile uint8 *) 0x4D)
#define TCNT1L    *((volatile uint8 *) 0x4C)
#define OCR1AH    *((volatile uint8 *) 0x4B)
#define OCR1AL    *((volatile uint8 *) 0x4A)
#define OCR1BH    *((volatile uint8 *) 0x49)
#define OCR1BL    *((volatile uint8 *) 0x48)
#define ICR1L     *((volatile uint16 *) 0x46)
#define ICR1H     *((volatile uint8 *) 0x47)
#define TIMSK     *((volatile uint8 *) 0x59)
#define TIFR      *((volatile uint8 *) 0x58)

#endif
