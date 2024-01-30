/*
 * To_Park.c
 *
 * Created: 1/26/2024 4:27:24 PM
 *  Author: Ali Reda
 */ 


#include "APP.h"

void Park(uint8_t pos)
{
	switch(pos)
	{
		case 1:
		if (IR_Read(IR2)==1)
		{
			StepperV_off();
			StepperH_ON(right);
			if (LS_Read(LS3)==1)
			{
				StepperH_off();
				StepperV_ON(down);
			}
			if (IR_Read(IR1)==1)
			{
				StepperV_off();
				StepperH_ON(left);
			}
			if (LS_Read(LS2)==1)
			{
				StepperH_off();
				StepperV_ON(down);
			}
			if (LS_Read(LS1)==1)
			{
				StepperV_off();
			}
		}
		
		case 2:
		if (IR_Read(IR3)==1)
		{
			StepperV_off();
			StepperH_ON(right);
			if (LS_Read(LS3)==1)
			{
				StepperH_off();
				StepperV_ON(down);
			}
			if (IR_Read(IR2)==1)
			{
				StepperV_off();
				StepperH_ON(left);
			}
			if (LS_Read(LS2)==1)
			{
				StepperH_off();
				StepperV_ON(down);
			}
			if (LS_Read(LS1)==1)
			{
				StepperV_off();
			}
		}
		
		case 3:
		if (IR_Read(IR4)==1)
		{
			StepperV_off();
			StepperH_ON(right);
			if (LS_Read(LS3)==1)
			{
				StepperH_off();
				StepperV_ON(down);
			}
			if (IR_Read(IR3)==1)
			{
				StepperV_off();
				StepperH_ON(left);
			}
			if (LS_Read(LS2)==1)
			{
				StepperH_off();
				StepperV_ON(down);
			}
			if (LS_Read(LS1)==1)
			{
				StepperV_off();
			}
		}
		default:
		break;
	}
}
