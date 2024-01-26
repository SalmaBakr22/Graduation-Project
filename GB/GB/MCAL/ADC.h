/*
 * ADC.h
 *
 * Created: 10/11/2023 2:29:17 PM
 *  Author: Ali Reda
 */ 


#ifndef ADC_H_
#define ADC_H_

/*----------------- Libraries and Definitions ------------*/

#include "stdint.h"
#include "../MemoryMap.h"
#include "../Utils.h"

typedef enum{
	ADC_AREF,
	ADC_AVCC,
	ADC_2_56V
}ADC_VoltageReference;

typedef enum{
	ADC_SCALER_2,
	ADC_SCALER_4,
	ADC_SCALER_8_,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64_,
	ADC_SCALER_128
}ADC_Scaler_Type;

typedef enum{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
}ADC_Channel;

/*--------------------- Functions Prototypes ---------------------------*/

void ADC_Init(ADC_VoltageReference reference , ADC_Scaler_Type scaler);
uint16_t ADC_ReadChannel(ADC_Channel channel);





#endif /* ADC_H_ */