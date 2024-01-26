/*
 * GB.c
 *
 * Created: 1/26/2024 4:06:37 PM
 * Author : Ali Reda
 */ 

#include "APP/To_Start.h"


int main(void)
{
	uart_init(bits_8,bit_1,Disabled,synchronous);
	Servo_Init();
	TIMER0_Init(CTC,TIMER0_SCALER_8,Disconnected);
	TIMER2_Init(cTC,TIMER2_SCALER_8,disconnected);
	LCD_Init();
	LCD_GOTO(0,4);
	LCD_WriteString("Multi Level Garage");
    while (1) 
    {
		Start();
    }
}

