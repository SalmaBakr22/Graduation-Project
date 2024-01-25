/*
 * Limit_Switch.c
 *
 * Created: 10/29/2023 12:50:39 AM
 *  Author: Ali Reda
 */ 


		/*----------------- Libraries and Definitions ------------*/

#include "Limit Switch.h"

		/*--------------------- Global Variables ------------------*/

static uint16 x;

		
// PIN connected to the limit switch should read 1 when switch is pressed in case of NO 
// remember to connect 10k resistor between the pin and limit switch

		/*------------------------- Function Definitions -----------------------------*/
uint8 LS_Read(uint8 p)
{
	 DIO_enuReadPinValue(p,x);
	return x;
}