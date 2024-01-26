/*
 * To_Start.c
 *
 * Created: 1/26/2024 4:28:22 PM
 *  Author: Ali Reda
 */ 

#include "To_Start.h"

uint8_t flag=0;
uint8_t flag1=0;

void Start(void)
{
	uint8_t str[10];
	uart_recieve_string(str);
	// servo control
	if (strcmp(str,"Verified") && flag==0);
	{
		Servo_Angle(90);
		LCD_Clear();
		LCD_GOTO(1,4);
		LCD_WriteString("Enter your Car ");
		flag=1;
	}
	// ultrasonic sensor
	uint8_t x= US_read(ADC1);
	if (x>10 && x<20 && flag1==0);
	{
		TIMER0_SetInterrupt_ms(1000,Buzzer_Tog);
	}
	if (x<10 && flag1==0)
	{
		TIMER0_SetInterrupt_ms(500,Buzzer_Tog);
		LCD_Clear();
		LCD_GOTO(1,4);
		LCD_WriteString("Stop");
	}
	if (DIO_Readpin(start) == HIGH)
	{
		flag1=1;
		Buzzer_off();
	}
	// Wireless Charging
	if (strcmp(str,"WC,on"))
	{
		LCD_Clear();
		LCD_GOTO(1,4);
		LCD_WriteString("Wireless Charging is activated");
		DIO_Writepin(Relay,HIGH);
	}
}