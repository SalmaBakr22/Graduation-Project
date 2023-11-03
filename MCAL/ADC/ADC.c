#include "STD_Types.h"
#include "BIT_Math.h"

#include "ADC.h"
#include "ADC_cfg.h"
#include "ADC_priv.h"

volatile uint16 ADC_u16Data = 0 ;
void   ADC_vidInit(void)
{
	uint8 u8DataAdcsraLoc = 0 ;
	uint8 u8DataAdmuxLoc = 0 ;
	uint8 u8DataSfiorLoc = 0 ;
	#if ADC_VOLT_REF == ADC_INTERNAL
		SET_BIT(u8DataAdmuxLoc , 7);
		SET_BIT(u8DataAdmuxLoc , 6);
	#elif ADC_VOLT_REF == ADC_AVCC
	
		CLR_BIT(u8DataAdmuxLoc , 7);
		SET_BIT(u8DataAdmuxLoc , 6);
	#else 
		CLR_BIT(u8DataAdmuxLoc , 7);
		CLR_BIT(u8DataAdmuxLoc , 6);
	#endif
	#if ADC_BIT_MODE ==ADC_8BIT
	
		SET_BIT(u8DataAdmuxLoc , 5);
	#else
		CLR_BIT(u8DataAdmuxLoc , 5);
	#endif
	u8DataAdmuxLoc |= ADC_CHN_SEL & 0x1F;
	
	SET_BIT(u8DataAdcsraLoc , 7); // enable adc
	#if ADC_CON_MODE == ADC_AUTO_TRIG
		SET_BIT(u8DataAdcsraLoc , 6); // start conv
		SET_BIT(u8DataAdcsraLoc , 5); // auto trig
		u8DataSfiorLoc = ADC_TIG_SRC<<5 ; // select src
	#else 
		CLR_BIT(u8DataAdcsraLoc , 5); // single mode conv
	#endif
	SET_BIT(u8DataAdcsraLoc , 4); // Clear interrupt flag 
	CLR_BIT(u8DataAdcsraLoc , 3); // Clear m7bs el so8ier 
	u8DataAdcsraLoc |= ADC_PRESCALLER& 0x07;
    ADMUX  = u8DataAdmuxLoc ;
    ADCSRA = u8DataAdcsraLoc ;
	SFIOR &= 0b00011111;
    SFIOR |= u8DataSfiorLoc; 	
	
}
void   ADC_vidSelCh(uint8 u8ChNbCpy)
{ 
    ADMUX &=0b11100000; 
	ADMUX |= u8ChNbCpy & 0x1F;
}
uint16 ADC_u16ReadSync(void)
{
	uint16 u16ResLoc = 0 ;
	SET_BIT(ADCSRA , 6); // start conv
	while (GET_BIT(ADCSRA,4) == 0); //wait flag
	if (ADC_BIT_MODE == ADC_8BIT)
	{
		u16ResLoc = ADCH & 0xFF ;
	}
	else
	{
		u16ResLoc  =ADCL;
		u16ResLoc |= ADCH<<8 ;
		u16ResLoc &= 0x03FF;// 0b0000 0011 1111 1111
	}
	SET_BIT(ADCSRA , 4); // clear flag
	
	return u16ResLoc ;
}

void   ADC_vidEnable(void)
{
	SET_BIT(ADCSRA , 7);
}
void   ADC_vidDisable(void)
{
	CLR_BIT(ADCSRA , 7);
}
void   ADC_vidStartConv(void)
{
	SET_BIT(ADCSRA , 6);
}
void   ADC_vidDisableInt(void)
{
	CLR_BIT(ADCSRA , 3);
}

void   ADC_vidEnableInt(void)
{
	SET_BIT(ADCSRA , 3);
}

uint16 ADC_u16ReadAsync(void)
{
	return ADC_u16Data ;
}
void __vector_16 (void) __attribute__ ((signal,used));
void __vector_16 (void)
{
	if (ADC_BIT_MODE == ADC_8BIT)
	{
		ADC_u16Data = ADCH & 0xFF ;
	}
	else
	{
		ADC_u16Data  =ADCL;
		ADC_u16Data |= ADCH<<8 ;
		ADC_u16Data &= 0x03FF;// 0b0000 0011 1111 1111
	}
}