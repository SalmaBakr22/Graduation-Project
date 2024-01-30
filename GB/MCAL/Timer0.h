/*
 * Timer.h
 *
 * Created: 9/21/2023 9:07:17 PM
 *  Author: Ali Reda
 */ 


#ifndef TIMER_H_
#define TIMER_H_

/*----------------- Libraries and Definitions ------------*/

#include "../MemoryMap.h"
#include "../Utils.h"

#define  NULLptr  ((void*)0)

/*********************************Timer0************************************/


/*--------------------- Timer 0 Functions Prototypes ---------------------------*/

void TIMER0_Init();
void TIMER0_OVFInterrupt_Enable(void);
void TIMER0_OVFInterrupt_Disable(void);
void TIMER0_OCInterrupt_Enable(void);
void TIMER0_OCInterrupt_Disable(void);
void TIMER0_OC_SetCallBack(void (*ptr)(void));
void TIMER0_OVF_SetCallBack(void (*ptr)(void));
void TIMER0_SetInterrupt_ms(uint16_t time, void (*pf)(void));
void fun_oc0();
#endif 