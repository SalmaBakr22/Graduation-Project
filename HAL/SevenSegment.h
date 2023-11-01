/*
 * SevenSegment.h
 *
 * Created: 9/21/2023 12:55:28 AM
 *  Author: Ali Reda
 */ 


#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

#include "stdint.h"
#include "../MCAL/DIO.h"

#define segmentport  PORTC

void SEVEN_SEGMENT1(uint8_t num);


#endif /* SEVENSEGMENT_H_ */