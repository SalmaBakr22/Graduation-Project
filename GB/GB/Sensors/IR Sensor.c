/*
 * IR_Sensor.c
 *
 * Created: 10/28/2023 11:36:31 PM
 *  Author: Ali Reda
 */ 

		/*----------------- Libraries and Definitions ------------*/
		
#include "IR Sensor.h"
		/*--------------------- Global Variables ------------------*/

static uint16_t x;
		
// pin will be High as any thing within the Detection Distance
// The potentiometer R5 is used to adjust how sensitive the sensor is. 
// You can use it to adjust the distance from the object at which the sensor detects it.

		/*------------------------- Function Definitions -----------------------------*/
		
uint8_t IR_Read(DIO_PIN_type p)
{
	x= DIO_Readpin(p); 
	return x;
}

