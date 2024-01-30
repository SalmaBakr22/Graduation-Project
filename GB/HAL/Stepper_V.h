/*
 * Stepper_V.h
 *
 * Created: 1/26/2024 11:52:16 PM
 *  Author: Ali Reda
 */ 


#ifndef STEPPER_V_H_
#define STEPPER_V_H_

typedef enum
{
	up=0,
	down
}directionV;

/*--------------------- Stepper Motor Functions Prototypes ---------------------------*/

void StepperV_ON(directionV d);
void StepperV_off();



#endif /* STEPPER_V_H_ */