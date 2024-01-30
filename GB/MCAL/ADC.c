/*
 * ADC.c
 *
 * Created: 10/11/2023 2:29:05 PM
 *  Author: Ali Reda
 */ 

/*----------------- Libraries and Definitions ------------*/

#include "ADC.h"

/*------------------------- Function Definitions -----------------------------*/

void ADC_Init(ADC_VoltageReference reference , ADC_Scaler_Type scaler)
{
	switch(reference)
	{
		case ADC_AREF:
		CLEAR_BIT(ADMUX , REFS0);
		CLEAR_BIT(ADMUX , REFS1);
		break;
		case ADC_AVCC:
		SET_BIT(ADMUX , REFS0);
		CLEAR_BIT(ADMUX , REFS1);
		break;
		case ADC_2_56V:
		SET_BIT(ADMUX , REFS0);
		SET_BIT(ADMUX , REFS1);
		break;
	}
	// prescaler selection
	
	ADCSRA &= 0xF8; // 0B11111000
	switch(scaler)
	{
		case ADC_SCALER_2:
		CLEAR_BIT(ADCSRA,ADPS0);
		CLEAR_BIT(ADCSRA,ADPS1);
		CLEAR_BIT(ADCSRA,ADPS2);
		break;
		case ADC_SCALER_4:
		CLEAR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLEAR_BIT(ADCSRA,ADPS2);
		break;
		case ADC_SCALER_8_:
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLEAR_BIT(ADCSRA,ADPS2);
		break;
		case ADC_SCALER_16:
		CLEAR_BIT(ADCSRA,ADPS0);
		CLEAR_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		break;
		case ADC_SCALER_32:
		SET_BIT(ADCSRA,ADPS0);
		CLEAR_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		break;
		case ADC_SCALER_64_:
		CLEAR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		break;
		case ADC_SCALER_128:
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		break;
	}
	// read adjust right
	CLEAR_BIT(ADMUX , ADLAR);
	
	// Enable
	SET_BIT(ADCSRA , ADEN);
}

uint16_t ADC_ReadChannel(ADC_Channel channel)
{
	// channel selection
	ADMUX &= 0xE0; // 0B11100000
	ADMUX |= channel;
	//  ADC Start Conversion
	SET_BIT(ADCSRA,ADSC);
	// polling while conversion
	while(READ_BIT(ADCSRA,ADSC));
	return ADC;
}

