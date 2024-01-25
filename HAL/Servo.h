/*
 * Servo.h
 *
 * Created: 10/9/2023 1:09:03 PM
 *  Author: Ali Reda
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include "../Lib/STD_Types.h"
#include "../MCAL/Timer1/TIM1_priv.h"
#include "../MCAL/Timer1/TIM1_cfg.h"
#define  SERVO_PIN       29

void Servo_Init(void);
void Servo_Angle(uint8 angle);





#endif /* SERVO_H_ */