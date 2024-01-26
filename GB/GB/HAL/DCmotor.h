/*
 * DCmotor.h
 *
 * Created: 10/14/2023 11:28:39 PM
 *  Author: Ali Reda
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "stdint.h"

/****************** configration ******************/

#define IN1 PINB3
#define IN2 PINB6
#define EN1  PINB7

typedef enum
{
	left,
	right
}Motor_dir;

/*--------------------- Functions Prototypes ---------------------------*/

void Mdir(Motor_dir dir);
void Mspeed(uint8_t s,Motor_dir dir);




#endif /* DCMOTOR_H_ */