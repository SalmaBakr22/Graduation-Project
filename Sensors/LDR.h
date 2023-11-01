/*
 * LDR.h
 *
 * Created: 10/29/2023 1:02:29 AM
 *  Author: Ali Reda
 */ 


#ifndef LDR_H_
#define LDR_H_

		/*----------------- Libraries and Definitions ------------*/

#include "../MCAL/ADC.h"
		
		/*--------------------- Functions Prototypes ---------------------------*/

uint8_t LDR_Read(ADC_Channel cha);


#endif /* LDR_H_ */