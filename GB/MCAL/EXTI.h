/*
 * EXTI.h
 *
 * Created: 9/21/2023 5:35:27 PM
 *  Author: Ali Reda
 */ 


#ifndef EXTI_H_
#define EXTI_H_

/*--------------------- enumerations ------------------*/

typedef enum{
	EXI_0,
	EXI_1,
	EXI_2
}Exteral_Interrput_Type;

typedef enum{
	LOW_LEVEL,
	ANY_LOGICAL_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}Triggerring_Mode;

/*--------------------- Functions Prototypes ---------------------------*/

void EXI_TriggerEdge(Exteral_Interrput_Type interrupt,Triggerring_Mode mode);
void EXI_Enable(Exteral_Interrput_Type interrupt);
void EXI_Disable(Exteral_Interrput_Type interrupt);
void EXI_SetCallBack(Exteral_Interrput_Type interrupt,void (*F_local)(void));



#endif /* EXTI_H_ */