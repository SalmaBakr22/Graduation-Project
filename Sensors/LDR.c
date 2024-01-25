/*
 * LDR.c
 *
 * Created: 10/29/2023 1:02:15 AM
 *  Author: Ali Reda
 */ 

		/*----------------- Libraries and Definitions ------------*/

#include "LDR.h"
		
		/*--------------------- Global Variables ------------------*/

static uint8 x;

		/*--------------------------- Function to return the percentage of max light intensity ----------------------------------*/

uint8 LDR_Read(uint8 cha)
{
	x= ADC_u16ReadSync(cha);
	x= ((uint16)x*100)/1024;
	return x;  
}