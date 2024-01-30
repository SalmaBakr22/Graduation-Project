/*
 * LM35.c
 *
 * Created: 10/11/2023 9:23:15 PM
 *  Author: Ali Reda
 */ 

#include "LM35.h"

static uint16_t z;
static uint16_t f;

uint8_t Temp_sensor(ADC_Channel cha)
{
	z= ADC_ReadChannel(cha);
	z=((uint32_t)z*5000)/1024;
	f=z/10;
	return f;
}