/*
 * Servo.c
 *
 * Created: 10/9/2023 1:08:49 PM
 *  Author: Ali Reda
 */ 

/*----------------- Libraries and Definitions ------------*/

#include "Servo.h"
#include "../MCAL/Timer1.h"

/*------------------------- Function Definitions -----------------------------*/

void Servo_Init(void)
{
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE , TIMER1_SCALER_8 , OCRA_NON_INVERTING , OCRB_DISCONNECTED);
	ICR1 = 19999;
	SERVO_PIN = 999;
}

void Servo_Angle(uint8_t angle)
{
	SERVO_PIN = ((uint32_t)angle * 1000)/180 + 999;
	
}