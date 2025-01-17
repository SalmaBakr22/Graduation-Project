/*
 * Timer.c
 *
 * Created: 9/21/2023 9:07:03 PM
 *  Author: Ali Reda
 */ 

/*----------------- Libraries and Definitions ------------*/

#include "Timer0.h"


static void (*Timer0_OVF_Fptr) (void)=NULLptr;
static void (*Timer0_OC0_Fptr) (void)=NULLptr;
static void (*pf_OC) (void)=NULLptr;

/*----------------- Global Variables ------------*/

static uint32_t C_set=0;

		/****************************** Timer 0 *************************************/


/*------------------------- Function Definition Of initializing the timer 0  -----------------------------*/

void TIMER0_Init()
{
		//  CTC:
		CLEAR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
	
		// TIMER0_SCALER_8:
		CLEAR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
	
		// Disconnected:
		CLEAR_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
	
}


		/**************************** Timer 0 Interrupt functions *********************************/

/*------------------------- Function Definition Of  TIMER0_Over Flow Interrupt_Enable  -----------------------------*/

void TIMER0_OVFInterrupt_Enable(void){
	SET_BIT(TIMSK,TOIE0);
}

/*------------------------- Function Definition Of TIMER0_Over Flow Interrupt_disable  -----------------------------*/

void TIMER0_OVFInterrupt_Disable(void){
	CLEAR_BIT(TIMSK,TOIE0);

}

/*------------------------- Function Definition Of TIMER0_output compare Interrupt_disable -----------------------------*/

void TIMER0_OCInterrupt_Enable(void){
	SET_BIT(TIMSK,OCIE0);

}

/*------------------------- Function Definition Of TIMER0_output compare Interrupt_disable -----------------------------*/

void TIMER0_OCInterrupt_Disable(void){
	CLEAR_BIT(TIMSK,OCIE0);

}

/*------------------------- TIMER0_SetCallBack Function Definition -----------------------------*/

void TIMER0_OVF_SetCallBack(void (*ptr)(void))
{
	Timer0_OVF_Fptr=ptr;
}

void TIMER0_OC_SetCallBack(void (*ptr)(void))
{
	Timer0_OC0_Fptr=ptr;
}

/*------------------------- Function Definition Of Timer 0 to call fun every n. of seconds -----------------------------*/

void TIMER0_SetInterrupt_ms(uint16_t time, void (*pf)(void))
{
	
	pf_OC=pf;
	C_set=(1000000*time)/200;
	OCR0=200;
	TIMER0_OC_SetCallBack(fun_oc0);
	TIMER0_OCInterrupt_Enable();
}

void fun_oc0()
{
	static uint32_t C = 0;
	C++;
	if (C==C_set)
	{
		pf_OC();
		C=0;
	}
	
}
			/********************************* Timer 0 ISR functions ******************************/


	ISR(TIMER0_OVF_vect)
	{
		if(Timer0_OVF_Fptr!=NULLptr)
		{
			Timer0_OVF_Fptr();
		}
	}

	ISR(TIMER0_COMP_vect){
		Timer0_OC0_Fptr();
	}


		
		