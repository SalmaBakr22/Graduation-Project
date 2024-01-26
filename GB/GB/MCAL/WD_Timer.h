/*
 * WD_Timer.h
 *
 * Created: 10/4/2023 11:21:27 AM
 *  Author: Ali Reda
 */ 


#ifndef WD_TIMER_H_
#define WD_TIMER_H_

/*----------------- Libraries and Definitions ------------*/

#include "../MemoryMap.h"
#include "../Utils.h"

/*----------------- Enumurations ------------*/

typedef enum
{
	cycles_16k=0,
	cycles_32k,
	cycles_64k,
	cycles_128k,
	cycles_256k,
	cycles_512k,
	cycles_1024k,
	cycles_2048k
	}WDT_Cycles;

/*--------------------- Watch Dog Timer Functions Prototypes ---------------------*/

void WD_Timer_Start(WDT_Cycles n);
void WD_Stop();


#endif /* WD_TIMER_H_ */