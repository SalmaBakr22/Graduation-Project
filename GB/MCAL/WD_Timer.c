/*
 * WD_Timer.c
 *
 * Created: 10/4/2023 11:21:07 AM
 *  Author: Ali Reda
 */ 

/*----------------- Libraries and Definitions ------------*/

#include "WD_Timer.h"

/*----------------- Function Definitions ---------------------*/

void WD_Timer_Start(WDT_Cycles n)
{
	uint8_t WD_val = 0x08;
	WD_val |=n;
	WDTCR |= (1<<WDE) | (1<<WDTOE); // In the same operation, write a logic one to WDTOE and WDE
	WDTCR = WD_val;
}

void WD_Stop()
{
	WDTCR |= (1<<WDE) | (1<<WDTOE); // In the same operation, write a logic one to WDTOE and WDE
	WDTCR = 0;
}