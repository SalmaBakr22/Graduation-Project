/*
 * App.c
 *
 *  Created on: Sep 2, 2023
 *      Author: WIN
 */

#include <util/delay.h>
#include  "BIT_Math.h"
#include  "STD_Types.h"

#include  "DIO.h"
#include  "LCD.h"


int main(void)
{
	uint8 i=0;
	DIO_vidInit();
	LCD_vidInit();

	while(1)
	{
		LCD_vidSendCmd(0 , LCD_CLR);
		LCD_vidSendCmd(0 , LCD_LINE_1+1);
		LCD_vidWriteData(0 , 'A');
		LCD_vidWriteData(0 , 'L');
		LCD_vidWriteData(0 , 'I');
		_delay_ms(1000);
		i++;

		if(i==11)
		{
			i=0;
		}
	}

	return 0;
}
