/*
 * LM35.h
 *
 * Created: 10/11/2023 9:23:33 PM
 *  Author: Ali Reda
 */ 


#ifndef LM35_H_
#define LM35_H_

#include "../MCAL/ADC.h"
#include "stdint.h"

uint8_t Temp_sensor(ADC_Channel cha);


#endif /* LM35_H_ */