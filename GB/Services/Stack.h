/*
 * Stack.h
 *
 * Created: 12/6/2023 1:43:32 PM
 *  Author: Ali Reda
 */ 


#ifndef STACK_H_
#define STACK_H_

#include "stdint.h"

typedef enum
{
	stack_full,
	stack_empty,
	Done
}stack_state;

stack_state push_s(uint8_t data);
stack_state pop_s(uint8_t *data);

#endif /* STACK_H_ */