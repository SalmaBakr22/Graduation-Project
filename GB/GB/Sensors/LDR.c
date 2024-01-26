/*
 * LDR.c
 *
 * Created: 10/29/2023 1:02:15 AM
 *  Author: Ali Reda
 */ 

		/*----------------- Libraries and Definitions ------------*/

#include "LDR.h"
		
		/*--------------------- Global Variables ------------------*/

static uint8_t x;

		/*--------------------------- Function to return the percentage of max light intensity ----------------------------------*/

uint8_t LDR_Read(ADC_Channel cha)
{
	x= ADC_ReadChannel(cha);
	x= ((uint16_t)x*100)/1024;
	return x;  
}