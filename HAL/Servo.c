/*
 * Servo.c
 *
 * Created: 10/9/2023 1:08:49 PM
 *  Author: Ali Reda
 */ 

/*----------------- Libraries and Definitions ------------*/

#include "Servo.h"
#include "../MCAL/Timer1/TIM1.h"
#include "../MCAL/DIO/DIO.h"

/*------------------------- Function Definitions -----------------------------*/

void Servo_Init(void)
{
	TIM1_vidInit() ;
	ICR1L = 19999;
	DIO_enuSetPinValue(SERVO_PIN,999);
}

void Servo_Angle(uint8 angle)
{
	DIO_enuSetPinValue(SERVO_PIN , ((uint32)angle * 1000)/180 + 999);
	
}