/*
 * Stack.c
 *
 * Created: 12/6/2023 1:43:15 PM
 *  Author: Ali Reda
 */ 

#include "Stack.h"

#define  sl  50

uint8_t stack[sl]={0};
uint32_t sp=0;

stack_state push_s(uint8_t data)
{
	if (sp==sl)
	{
		return stack_full;
	}
	stack[sp]=data;
	sp++;
	return Done;
}


stack_state pop_s(uint8_t *data)
{
	if (sp==0)
	{
		return stack_empty;
	}
	*data=stack[sp-1];
	sp--;
	return Done;
}