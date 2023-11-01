/*
 * Stepper_M.h
 *
 * Created: 10/26/2023 1:17:49 AM
 *  Author: Ali Reda
 */ 


#ifndef STEPPER_M_H_
#define STEPPER_M_H_

	/*----------------- Libraries and Definitions ------------*/

#include "../MCAL/Timer2.h"
#include "../MCAL/DIO.h"
#include "../Utils.h"

#define enable PINB0
#define step   PINB1
#define dir    PINB2
#define MS1    PINB3
#define MS2    PINB4
#define MS3    PINB5

typedef enum
{
	Full_Step=1,
	Half_Step=2,
	Quarter_Step=4,
	Eighth_Step=8,
	Sixteenth_Step=16
	}Microstep_Resolution;

typedef enum
{
	right=0,
	left
	}direction;
	
	/*--------------------- Stepper Motor Functions Prototypes ---------------------------*/
	
void Stepper_ON(Microstep_Resolution s, direction d);
void Stepper_off();




#endif /* STEPPER_M_H_ */