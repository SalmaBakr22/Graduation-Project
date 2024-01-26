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
typedef enum{
	NORMAL_MODE,
	PWM,
	CTC,
	FAST_PWM
	}Operation_Mode0;
	
typedef enum{
	TIMER0_STOP=0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNAL0_FALLING,
	EXTERNAL0_RISING
	}Timer0_Scaler;
	
typedef enum{
	Disconnected,
	Toggle,
	Inverting,
	NonInverting
	}OC0_Mode;

/*--------------------- Timer 0 Functions Prototypes ---------------------------*/

void TIMER0_Init(Operation_Mode0 mode,Timer0_Scaler scalar,OC0_Mode OC);
void TIMER0_OVFInterrupt_Enable(void);
void TIMER0_OVFInterrupt_Disable(void);
void TIMER0_OCInterrupt_Enable(void);
void TIMER0_OCInterrupt_Disable(void);
void TIMER0_OC_SetCallBack(void (*ptr)(void));
void TIMER0_OVF_SetCallBack(void (*ptr)(void));
void TIMER0_SetInterrupt_ms(uint16_t time, void (*pf)(void));
void fun_oc0();
#endif 