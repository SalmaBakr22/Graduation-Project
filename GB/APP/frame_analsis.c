/*
 * frame_analisis.c
 *
 * Created: 12/20/2023 6:53:29 PM
 *  Author: Ali Reda
 */ 

#include "frame_analsis.h"

void UART_frame_analsis(uint8_t *arr, uint8_t *str1, uint8_t *str2)
{
	char name[10];
	char state[4];
	int i,j=0,flag=0;

	for(i=0;arr[i]!='.'; i++)
	{
		if(arr[i]==',' && flag==0)
		{
			name[i]='\0';
			flag=1;
		}
		else if(arr[i]!=',' && flag==0)
		{
			name[i]=arr[i];
		}
		else if(arr[i]!='.' && flag==1)
		{
			state[j]=arr[i];
			j++;
		}
	}
	state[j]='\0';

	str1=name;
	str2=state;
	
}
