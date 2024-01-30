/*
 * Timer1.c
 *
 * Created: 10/2/2023 1:06:01 AM
 *  Author: Ali Reda
 */ 

/*----------------- Libraries and Definitions ------------*/

#include "Timer1.h"

static void (*Timer1_OVF_Fptr) (void)=NULLptr;
static void (*Timer1_OCA_Fptr) (void)=NULLptr;
static void (*Timer1_OCB_Fptr) (void)=NULLptr;
static void (*Timer1_ICU_Fptr) (void)=NULLptr;
static void (*pf_OC) (void)=NULLptr;

/*----------------- Global Variables ------------*/

static uint64_t C_set=0;



/****************************** Timer 1 *************************************/

/*------------------------- Function Definition Of setting TCNT register  -----------------------------*/

void TIMER1_SET(uint16_t time){
	TCNT1=time;
}

/*------------------------- Function Definition Of setting OCR1A register -----------------------------*/

void TIMER1_OCA(uint16_t time){
	OCR1A=time;
}

/*------------------------- Function Definition Of setting OCR1B register -----------------------------*/

void TIMER1_OCB(uint16_t time)
{
	OCR1B=time;	
}

/*------------------------- Function Definition Of initializing Timer 1 -----------------------------*/

void Timer1_Init(Timer1_Mode mode1, Timer1_Scaler scaler, Timer1_OC1A_Mode oc1a_mode, Timer1_OC1B_Mode oc1b_mode)
{
	switch (mode1)
	{
		case TIMER1_NORMAL_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_CTC_ICR_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_CTC_OCRA_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_ICR_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_OCRA_TOP_MODE:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
	}
	switch(scaler){
		case TIMER1_STOP:
		CLEAR_BIT(TCCR1B,CS10);
		CLEAR_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
		break;
		case TIMER1_SCALER_1:
		SET_BIT(TCCR1B,CS10);
		CLEAR_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
		break;
		case TIMER1_SCALER_8:
		CLEAR_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
		break;
		case TIMER1_SCALER_64:
		SET_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
		break;
		case TIMER1_SCALER_256:
		CLEAR_BIT(TCCR1B,CS10);
		CLEAR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
		break;
		case TIMER1_SCALER_1024:
		SET_BIT(TCCR1A,CS10);
		CLEAR_BIT(TCCR1A,CS11);
		SET_BIT(TCCR1A,CS12);
		break;
		case EXTERNAL1_FALLING:
		CLEAR_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
		break;
		case EXTERNAL1_RISING:
		SET_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
		break;

	}
	switch (oc1a_mode)
	{
		case OCRA_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_TOGGLE:
		SET_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_NON_INVERTING:
		CLEAR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_INVERTING:
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
	}
	switch (oc1b_mode)
	{
		case OCRB_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_TOGGLE:
		SET_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_NON_INVERTING:
		CLEAR_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_INVERTING:
		SET_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
	}
	
}

void Timer1_InputCaptureEdge(ICU_Edge_type edge)
{
	if(edge==RISING)
	{
		SET_BIT(TCCR1B,ICES1);
	}
	else if(edge==FALLING)
	{
		CLEAR_BIT(TCCR1B,ICES1);
	}
}

/****************************Timer 1 Interrupt functions**************************************/

void Timer1_ICU_InterruptEnable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void Timer1_ICU_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TICIE1);
}
void Timer1_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void Timer1_OVF_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TOIE1);
}
void Timer1_OCA_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1A);
}
void Timer1_OCA_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1A);
}
void Timer1_OCB_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1B);
}
void Timer1_OCB_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1B);
}

/*********************************Timer 1 Call Back functions*****************************************/

void Timer1_OVF_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OVF_Fptr=LocalFptr;
}
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCA_Fptr=LocalFptr;
}
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCB_Fptr=LocalFptr;
}
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_ICU_Fptr=LocalFptr;
}

/*------------------------- Function Definition Of Timer 1 to call fun every n. of seconds -----------------------------*/

void TIMER1_SetInterrupt_ms(uint16_t time, void (*pf)(void))
{
	
	pf_OC=pf;
	C_set=(1000000*time)/1000;
	OCR1A=1000;
	Timer1_OCA_SetCallBack(fun_oc1);
	Timer1_OCA_InterruptEnable();
}

void fun_oc1()
{
	static uint64_t C = 0;
	C++;
	if (C==C_set)
	{
		pf_OC();
		C=0;
	}
}

/*********************************Timer 1 ISR functions*********************************************/

ISR(TIMER1_OVF_vect)
{
	Timer1_OVF_Fptr();
}
ISR(TIMER1_COMPA_vect)
{
	Timer1_OCA_Fptr();
}
ISR(TIMER1_COMPB_vect)
{
	Timer1_OCB_Fptr();
}
ISR(TIMER1_CAPT_vect)
{
	Timer1_ICU_Fptr();
}
