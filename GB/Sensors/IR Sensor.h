/*
 * IR_Sensor.h
 *
 * Created: 10/28/2023 11:36:46 PM
 *  Author: Ali Reda
 */ 


#ifndef IR SENSOR_H_
#define IR SENSOR_H_

		/*----------------- Libraries and Definitions ------------*/

#include "../MCAL/DIO.h"

		/*--------------------- Functions Prototypes ---------------------------*/

uint8_t IR_Read(DIO_PIN_type p);

#endif /* IR SENSOR_H_ */