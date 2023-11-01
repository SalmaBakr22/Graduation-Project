/*
 * DCmotor.c
 *
 * Created: 10/14/2023 11:28:24 PM
 *  Author: Ali Reda
 */ 

			/*----------------- Libraries and Definitions ------------*/

#include "../MCAL/DIO.h"
#include "../MCAL/Timer0.h"
#include "DCmotor.h"

		   /*--------------- Function Definitions -----------------*/

/*------------- Function to set motor direction---------------*/

void Mdir(Motor_dir dir)
{
	if (dir == left)
	{
		DIO_Writepin(IN1,LOW);
		DIO_Writepin(IN2,HIGH);
		DIO_Writepin(EN1,HIGH);
	}
	else if(dir == right)
	{
		DIO_Writepin(IN1,HIGH);
		DIO_Writepin(IN2,LOW);
		DIO_Writepin(EN1,HIGH);
	}
}

/*------------- Function to set motor direction with specific speed ---------------*/

void Mspeed(uint8_t s,Motor_dir dir)
{
	// timer 0 with fast pwm mode to control speed
	TIMER0_Init(FAST_PWM,TIMER0_SCALER_8,Inverting);
	OCR0=255-((uint16_t)255*s)/100;
	if (dir == left)
	{
		DIO_Writepin(IN1,LOW);
		DIO_Writepin(EN1,HIGH);
	}
	else if (dir == right)
	{
		DIO_Writepin(IN2,LOW);
		DIO_Writepin(EN1,HIGH);
	}
}