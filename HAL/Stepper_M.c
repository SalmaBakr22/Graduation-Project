/*
 * Stepper_M.c
 *
 * Created: 10/26/2023 1:17:29 AM
 *  Author: Ali Reda
 */ 
	
	/*----------------- Libraries and Definitions ------------*/

#include "Stepper_M.h"

	/*----------------- Functions Definitions ------------*/

void tog()
{
	DIO_Toggle(step);
}

	/*------------------------- Function Definition of stepper motor to turn only one turn -----------------------------*/
void Stepper_ON(Microstep_Resolution s, direction d)
{
	switch(s)
	{
		case Full_Step:
		DIO_Writepin(MS1,LOW);
		DIO_Writepin(MS2,LOW);
		DIO_Writepin(MS3,LOW);
		break;
		case Half_Step:
		DIO_Writepin(MS1,HIGH);
		DIO_Writepin(MS2,LOW);
		DIO_Writepin(MS3,LOW);
		break;
		case Quarter_Step:
		DIO_Writepin(MS1,LOW);
		DIO_Writepin(MS2,HIGH);
		DIO_Writepin(MS3,LOW);
		break;
		case Eighth_Step:
		DIO_Writepin(MS1,HIGH);
		DIO_Writepin(MS2,HIGH);
		DIO_Writepin(MS3,LOW);
		break;
		case Sixteenth_Step:
		DIO_Writepin(MS1,HIGH);
		DIO_Writepin(MS2,HIGH);
		DIO_Writepin(MS3,HIGH);
		break;
	}
	switch(d)
	{
		case right:
		DIO_Writepin(dir,HIGH);
		break;
		case left:
		DIO_Writepin(dir,LOW);
		break;
	}
	DIO_Writepin(enable,HIGH);
	TIMER2_Init(cTC,TIMER2_SCALER_8,disconnected);
	for (uint8_t i=0; i<(200*s); i++)
	{
		TIMER2_SetInterrupt_ms(0.1,tog);
	}
}

	/*------------------------- Function Definition Of stepper motor to turn it off-----------------------------*/
void Stepper_off()
{
	DIO_Writepin(enable,LOW);
}
