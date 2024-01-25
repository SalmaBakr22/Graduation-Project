/*
 * Flame_Sensor.c
 *
 * Created: 10/29/2023 1:02:51 AM
 *  Author: Ali Reda
 */ 

/*----------------- Libraries and Definitions ------------*/

#include "Flame Sensor.h"

/*--------------------- Global Variables ------------------*/

static uint16 x;

	
// PIN connected to the Flame Sensor should read 1 when fire is detected

/*------------------------- Function Definitions -----------------------------*/

uint8_t Flame_Read(uint8 p)
{
	 DIO_enuReadPinValue(p,x);
	return x;
}