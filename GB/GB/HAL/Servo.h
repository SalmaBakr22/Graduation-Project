/*
 * Servo.h
 *
 * Created: 10/9/2023 1:09:03 PM
 *  Author: Ali Reda
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include "../MemoryMap.h"
#include "stdint.h"

#define  SERVO_PIN       OCR1A

void Servo_Init(void);
void Servo_Angle(uint8_t angle);





#endif /* SERVO_H_ */