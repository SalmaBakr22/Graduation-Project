/*
 * Timer2.h
 *
 * Created: 10/2/2023 1:06:32 AM
 *  Author: Ali Reda
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_


/*----------------- Libraries and Definitions ------------*/

#include "../MemoryMap.h"
#include "../Utils.h"

#define  NULLptr  ((void*)0)

/*********************************Timer2************************************/

typedef enum{
	nORMAL_MODE,
	pWM,
	cTC,
	fAST_PWM
}Operation_Mode2;

typedef enum{
	TIMER2_STOP=0,
	TIMER2_SCALER_1,
	TIMER2_SCALER_8,
	TIMER2_SCALER_32,
	TIMER2_SCALER_64,
	TIMER2_SCALER_128,
	TIMER2_SCALER_256,
	TIMER2_SCALER_1024
}Timer2_Scaler;

typedef enum{
	disconnected,
	toggle,
	inverting,
	noninverting
}OC2_Mode;

/*--------------------- Timer 2 Functions Prototypes ---------------------------*/

void TIMER2_Init(Operation_Mode2 mode,Timer2_Scaler scalar,OC2_Mode OC);
void TIMER2_SET(uint8_t time);
void TIMER2_OC(uint8_t time);
void TIMER2_OVFInterrupt_Enable(void);
void TIMER2_OVFInterrupt_Disable(void);
void TIMER2_OCInterrupt_Enable(void);
void TIMER2_OCInterrupt_Disable(void);
void TIMER2_OC_SetCallBack(void (*ptr)(void));
void TIMER2_OVF_SetCallBack(void (*ptr)(void));
void TIMER2_SetInterrupt_ms(uint16_t time, void (*pf)(void));
void fun_oc2();




#endif /* TIMER2_H_ */