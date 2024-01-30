/*
 * UART_services.c
 *
 * Created: 10/22/2023 9:16:12 PM
 *  Author: Ali Reda
 */ 


#include "UART_services.h"

uint8_t *pdata=0;


void uart_send_int(uint32_t Num)
{
	/*
	uart_send((uint8_t)(Num));
	uart_send((uint8_t)(Num>>8));
	uart_send((uint8_t)(Num>>16));
	uart_send((uint8_t)(Num>>32));
	*/
	uint32_t y=Num;
	uint8_t *x= &y;
	uint8_t i;
	for (i=0; i<4; i++)
	{
		uart_send(x[i]);
	}
	
}

uint32_t uart_recieve_int()
{
	/*
	uint32_t num;
	uint8_t b1= uart_recieve();
	uint8_t b2= uart_recieve();
	uint8_t b3= uart_recieve();
	uint8_t b4= uart_recieve();
	num= b1|b2<<8|b3<16|b4<<24;
	*/
	uint32_t y=0;
	uint8_t *x= &y;
	uint8_t i;
	for (i=0; i<4; i++)
	{
		x[i]= uart_recieve();
	}
	return y;
}

void uart_send_string(uint8_t *str)
{
	uint8_t i;
	for (i=0; str[i]; i++)
	{
		uart_send(str[i]);
	}
	uart_send('\0');
}

void uart_recieve_string(uint8_t *str)
{
	uint8_t i=0;
	str[i]=uart_recieve();
	while(str[i]!=0x0d)
	{
		i++;
		str[i]=uart_recieve();
	}
}

void uart_send_str_cs(uint8_t *str)
{
	uint16_t sum=0;
	uint8_t i;
	for (i=0; str[i]; i++)
	{
		sum += str[i];
	}
	uart_send(i);
	for (i=0; str[i]; i++)
	{
		uart_send(str[i]);
	}
	uart_send(sum);
	uart_send(sum>>8);
}

uint8_t uart_recieve_str_cs(uint8_t *str)
{
	uint8_t l,byte1,byte2;
	uint16_t sum_rec=0,sum=0;
	l=uart_recieve();
	for (uint8_t i=0; i<l; i++)
	{
		sum +=uart_recieve();
		str[i]=uart_recieve();
	}
	byte1=uart_recieve();
	byte2=uart_recieve();
	sum_rec= byte1|byte2<<8;
	if (sum_rec==sum)
	{
		return 1;
	} 
	else
	{
		return 0;
	}
}

void uart_send_Asynch(uint8_t *str)
{
	pdata=str;
	TX_Complete_Interrupt_Enable();
	uart_send_noblock(str[0]);
}

void uart_recieve_Asynch(uint8_t *str)
{
		
}

ISR(USART_TXC_vect)
{
	static uint8_t i=1;
	if (pdata[i]!=0)
	{
		uart_send_noblock(pdata[i]);
		i++;
	}
	else
	{
		i=1;	
	}
}