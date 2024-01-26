/*
 * EXTI.c
 *
 * Created: 9/21/2023 5:35:04 PM
 *  Author: Ali Reda
 */ 

/*----------------- Libraries and Definitions ------------*/

#include "../MemoryMap.h"
#include "../Utils.h"
#include "DIO.h"
#include "EXTI.h"

/*--------------------- Global Variables ------------------*/

static  void (*Fptr_EXI0)(void)=NULL_ptr;
static  void (*Fptr_EXI1)(void)=NULL_ptr;
static  void (*Fptr_EXI2)(void)=NULL_ptr;

/*---------------------  Functions Definitions  ---------------------------*/

void EXI_TriggerEdge(Exteral_Interrput_Type interrupt,Triggerring_Mode mode){
	switch(interrupt){
		case EXI_0:
		switch(mode){
			case LOW_LEVEL:
			CLEAR_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;
			case ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;
			case FALLING_EDGE:
			CLEAR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		}
		break;
		case EXI_1:
		switch(mode){
			case LOW_LEVEL:
			CLEAR_BIT(MCUCR,ISC10);
			CLEAR_BIT(MCUCR,ISC11);
			break;
			case ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR,ISC10);
			CLEAR_BIT(MCUCR,ISC11);
			break;
			case FALLING_EDGE:
			CLEAR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
		}
		break;
		case EXI_2:
		switch(mode){
			case FALLING_EDGE:
			CLEAR_BIT(MCUCSR,ISC2);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCSR,ISC2);
			break;
			default:
			break;
		}
		break;
	}
	
}

void EXI_Enable(Exteral_Interrput_Type interrupt){
	switch(interrupt){
		case EXI_0:
		SET_BIT(GICR,INT0);
		break;
		case EXI_1:
		SET_BIT(GICR,INT1);
		break;
		case EXI_2:
		SET_BIT(GICR,INT2);
		break;
	}
	
}

void EXI_Disable(Exteral_Interrput_Type interrupt){
	switch(interrupt){
		case EXI_0:
		CLEAR_BIT(GICR,INT0);
		break;
		case EXI_1:
		CLEAR_BIT(GICR,INT1);
		break;
		case EXI_2:
		CLEAR_BIT(GICR,INT2);
		break;
	}
	
}

void EXI_SetCallBack(Exteral_Interrput_Type interrupt,void (*F_local)(void)){
	
	switch(interrupt){
		case EXI_0:
		Fptr_EXI0=F_local;
		break;
		case EXI_1:
		Fptr_EXI1=F_local;
		break;
		case EXI_2:
		Fptr_EXI2=F_local;
		break;
	}
}

/*--------------------- Interrupt Functions (ISRs)  ---------------------------*/

/*-------------  (ISR of EXI0) ----------------*/

ISR(INT0_vect){
	if(Fptr_EXI0!=NULL_ptr){
		Fptr_EXI0();
	}
}

/*-------------  (ISR of EXI1) ----------------*/

ISR(INT1_vect){
	
	if(Fptr_EXI1!=NULL_ptr){
		Fptr_EXI1();
	}
}

/*-------------  (ISR of EXI2) ----------------*/

ISR(INT2_vect){
	
	if(Fptr_EXI2!=NULL_ptr){
		Fptr_EXI2();
	}
}