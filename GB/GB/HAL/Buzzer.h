/*
 * Buzzer.h
 *
 * Created: 10/26/2023 1:54:52 AM
 *  Author: Ali Reda
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

		/*----------------- Libraries and Definitions ------------*/

#include "../MCAL/DIO.h"

#define  buzzer PINB6
		/*--------------------- Functions Prototypes ---------------------------*/

void Buzzer_on();
void Buzzer_off();



#endif /* BUZZER_H_ */