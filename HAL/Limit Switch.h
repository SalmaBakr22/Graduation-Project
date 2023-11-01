/*
 * Limit_Switch.h
 *
 * Created: 10/29/2023 12:50:55 AM
 *  Author: Ali Reda
 */ 


#ifndef LIMIT SWITCH_H_
#define LIMIT SWITCH_H_

/*----------------- Libraries and Definitions ------------*/

#include "../MCAL/DIO.h"

/*--------------------- Functions Prototypes ---------------------------*/

uint8_t LS_Read(DIO_PIN_type p);

#endif /* LIMIT SWITCH_H_ */