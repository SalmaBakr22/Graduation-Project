/*
 * queue.c
 *
 * Created: 12/6/2023 2:01:47 PM
 *  Author: Ali Reda
 */ 

#include "queue.h"

#define ql 50

uint8_t queue[ql]={0};
uint8_t qp_f=0;
uint8_t qp_l=0;

queue_state push_q(uint8_t data)
{
	if (qp_l==ql)
	{
		qp_l=0;
		return queue_full;
	}
	queue[qp_l]=data;
	qp_l++;
}

queue_state pop_q(uint8_t *data)
{
	if (qp_f>=qp_l)
	{
		return queue_empty;
	}
	*data=queue[qp_f];
	qp_f++;
}
