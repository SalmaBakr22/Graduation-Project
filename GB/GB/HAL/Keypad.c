/*
 * Keybad.c
 *
 * Created: 9/27/2023 6:19:36 PM
 *  Author: Ali Reda
 */ 


#include "Keypad.h"
#include "../MCAL/DIO.h"

static uint8_t key_array[ROW][COLUMN]={
	{'7' , '8' , '9' , '/'},
	{'4' , '5', '6' , '*'},
	{'1' , '2' , '3' , '-'},
	{'c' , '0' , '=' , '+'}
};


uint8_t keypad_Data(void)
{
	uint8_t r , c , key = DEFAULT_KEY;
	// set all output pins to High
	DIO_Writepin(FIRST_OUT_Pin , HIGH);
	DIO_Writepin(FIRST_OUT_Pin + 1  , HIGH);
	DIO_Writepin(FIRST_OUT_Pin + 2  , HIGH);
	DIO_Writepin(FIRST_OUT_Pin + 3  , HIGH);
	
	for(r = 0; r < ROW; r++)
	{
		DIO_Writepin(FIRST_OUT_Pin + r  , LOW);		// set one output pin to Low
		for(c = 0; c < COLUMN; c++)
		{
			if(!DIO_Readpin(FIRST_INP_Pin + c))		// if you press the button --> reverse the signal and when row x column = Low
			{
				key = key_array[r][c];				
				while(!DIO_Readpin(FIRST_INP_Pin + c));		// keep same signal as you still pressing the button
			}
		}
		DIO_Writepin(FIRST_OUT_Pin + r  , HIGH);	// reset one output pin to High again
	}
	return key;
}
