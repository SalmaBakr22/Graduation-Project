/*
 * Timer1.h
 *
 * Created: 10/2/2023 1:06:17 AM
 *  Author: Ali Reda
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_


/*----------------- Libraries and Definitions ------------*/

#include "../MemoryMap.h"
#include "../Utils.h"

#define  NULLptr  ((void*)0)

/********************************* Timer1 ************************************/

typedef enum{
	TIMER1_STOP=0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	EXTERNAL1_FALLING,
	EXTERNAL1_RISING
}Timer1_Scaler;

typedef enum
{
	TIMER1_NORMAL_MODE=0,
	TIMER1_CTC_ICR_TOP_MODE,
	TIMER1_CTC_OCRA_TOP_MODE,
	TIMER1_FASTPWM_ICR_TOP_MODE,
	TIMER1_FASTPWM_OCRA_TOP_MODE
}Timer1_Mode;

typedef enum
{
	OCRA_DISCONNECTED=0,
	OCRA_TOGGLE,
	OCRA_NON_INVERTING,
	OCRA_INVERTING
}Timer1_OC1A_Mode;

typedef enum
{
	OCRB_DISCONNECTED=0,
	OCRB_TOGGLE,
	OCRB_NON_INVERTING,
	OCRB_INVERTING
}Timer1_OC1B_Mode;

typedef enum
{
	RISING,
	FALLING
}ICU_Edge_type;

/*--------------------- Timer 1 Functions Prototypes ---------------------------*/

void Timer1_Init( Timer1_Mode mode1,Timer1_Scaler scaler,Timer1_OC1A_Mode oc1a_mode,Timer1_OC1B_Mode oc1b_mode);
void TIMER1_SET(uint16_t time);
void TIMER1_OCA(uint16_t time);
void TIMER1_OCB(uint16_t time);
void Timer1_InputCaptureEdge(ICU_Edge_type edge);
void Timer1_ICU_InterruptEnable(void);
void Timer1_ICU_InterruptDisable(void);
void Timer1_OVF_InterruptEnable(void);
void Timer1_OVF_InterruptDisable(void);
void Timer1_OCA_InterruptEnable(void);
void Timer1_OCA_InterruptDisable(void);
void Timer1_OCB_InterruptEnable(void);
void Timer1_OCB_InterruptDisable(void);
void Timer1_OVF_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void));
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void));
void TIMER1_SetInterrupt_ms(uint16_t time, void (*pf)(void));
void fun_oc1();



#endif /* TIMER1_H_ */