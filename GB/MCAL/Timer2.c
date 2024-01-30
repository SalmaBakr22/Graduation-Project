/*
 * Timer2.c
 *
 * Created: 10/2/2023 1:06:46 AM
 *  Author: Ali Reda
 */ 

/*----------------- Libraries and Definitions ------------*/

#include "Timer2.h"

static void (*Timer2_OVF_Fptr) (void)=NULLptr;
static void (*Timer2_OC2_Fptr) (void)=NULLptr;
static void (*pf_OC) (void)=NULLptr;

/*----------------- Global Variables ------------*/

static uint32_t C_set=0;

	/****************************** Timer 2 *************************************/

	/*------------------------- Function Definition Of setting TCNT register  -----------------------------*/

	void TIMER2_SET(uint8_t time){
		TCNT2=time;
	}

	/*------------------------- Function Definition Of setting OCR2 register -----------------------------*/

	void TIMER2_OC(uint8_t time){
		OCR2=time;
	}

	/*------------------------- Function Definition Of initializing the timer 2  -----------------------------*/

	void TIMER2_Init()
	{	
		// cTC:
		CLEAR_BIT(TCCR2,WGM20);
		SET_BIT(TCCR2,WGM21);
			
		// TIMER2_SCALER_8:
		CLEAR_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);
			
		// disconnected:
		CLEAR_BIT(TCCR2,COM20);
		CLEAR_BIT(TCCR2,COM21);
	}

	/****************************Timer 2 Interrupt functions*********************************/

	/*------------------------- Function Definition Of  TIMER2_Over Flow Interrupt_Enable  -----------------------------*/

	void TIMER2_OVFInterrupt_Enable(void){
		SET_BIT(TIMSK,TOIE2);
	}

	/*------------------------- Function Definition Of TIMER2_Over Flow Interrupt_disable  -----------------------------*/

	void TIMER2_OVFInterrupt_Disable(void){
		CLEAR_BIT(TIMSK,TOIE2);

	}

	/*------------------------- Function Definition Of TIMER2_output compare Interrupt_disable -----------------------------*/

	void TIMER2_OCInterrupt_Enable(void){
		SET_BIT(TIMSK,OCIE2);

	}

	/*------------------------- Function Definition Of TIMER2_output compare Interrupt_disable -----------------------------*/

	void TIMER2_OCInterrupt_Disable(void){
		CLEAR_BIT(TIMSK,OCIE2);

	}

	/*------------------------- TIMER2_SetCallBack Function Definition -----------------------------*/

	void TIMER2_OVF_SetCallBack(void (*ptr)(void))
	{
		Timer2_OVF_Fptr=ptr;
	}

	void TIMER2_OC_SetCallBack(void (*ptr)(void)){
		Timer2_OC2_Fptr=ptr;
	}
	
	/*------------------------- Function Definition Of Timer 2 to call fun every n. of seconds -----------------------------*/
	
	void TIMER2_SetInterrupt_ms(uint16_t time, void (*pf)(void))
	{
		
		pf_OC=pf;
		C_set=(1000000*time)/200;
		OCR2=200;
		TIMER2_OC_SetCallBack(fun_oc2);
		TIMER2_OCInterrupt_Enable();
	}

	 void fun_oc2()
	{
		static uint32_t C = 0;
		C++;
		if (C==C_set)
		{
			pf_OC();
			C=0;
		}
		
	}

	/********************************* Timer 2 ISR functions ******************************/

	ISR(TIMER2_OVF_vect)
	{
		if(Timer2_OVF_Fptr!=NULLptr)
		{
			Timer2_OVF_Fptr();
		}
	}

	ISR(TIMER2_COMP_vect){
		Timer2_OC2_Fptr();
	}

