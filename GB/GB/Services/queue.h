/*
 * queue.h
 *
 * Created: 12/6/2023 2:02:27 PM
 *  Author: Ali Reda
 */ 


#ifndef QUEUE_H_
#define QUEUE_H_

#include "stdint.h"

typedef enum
{
	queue_full,
	queue_empty,
	Done
	}queue_state;

queue_state push_q(uint8_t data);
queue_state pop_q(uint8_t *data);


#endif /* QUEUE_H_ */