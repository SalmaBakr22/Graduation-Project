/*
 * UART.c
 *
 * Created: 10/21/2023 9:44:49 PM
 *  Author: Ali Reda
 */ 

#include "UART.h"
#include "../MCAL/DIO.h"
#include "../MemoryMap.h"
#include "../Utils.h"


void uart_init(Character_Size s, Stop_Bits x, Parity_Mode m, Mode y)
{
	// The frame format
	switch(s)
	{
		case bits_5:
		CLEAR_BIT(UCSRC,UCSZ0);
		CLEAR_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
		break;
		case bits_6:
		SET_BIT(UCSRC,UCSZ0);
		CLEAR_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
		break;
		case bits_7:
		CLEAR_BIT(UCSRC,UCSZ0);
		SET_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
		break;
		case bits_8:
		SET_BIT(UCSRC,UCSZ0);
		SET_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
		break;
		case bits_9:
		SET_BIT(UCSRC,UCSZ0);
		SET_BIT(UCSRC,UCSZ1);
		SET_BIT(UCSRB,UCSZ2);
		break;
	}
	// Stop Bit Select
	switch (x)
	{
		case bit_1:
		CLEAR_BIT(UCSRC,USBS);
		break;
		case bit_2:
		SET_BIT(UCSRC,USBS);
		break;
	}
	// Parity Mode
	switch (m)
	{
		case Disabled:
		CLEAR_BIT(UCSRC,UPM0);
		CLEAR_BIT(UCSRC,UPM1);
		break;
		case Even_Parity:
		CLEAR_BIT(UCSRC,UPM0);
		SET_BIT(UCSRC,UPM1);
		break;
		case Odd_Parity:
		SET_BIT(UCSRC,UPM0);
		SET_BIT(UCSRC,UPM1);
		break;
	}
	// Mode
	switch (y)
	{
		case Asynchronous:
		CLEAR_BIT(UCSRC,UMSEL);
		CLEAR_BIT(UCSRA,U2X);
		break;
		case synchronous:
		SET_BIT(UCSRC,UMSEL);
		break;
	}
	//  Baud Rate = 9600
	UBRRL=51;
	// Receiver Enable
	SET_BIT(UCSRB,RXEN);
	//  Transmitter Enable
	SET_BIT(UCSRB,TXEN);
}

void uart_send(uint8_t data)
{
	// check if the buffer is empty 
	while(!READ_BIT(UCSRA,UDRE));
	UDR=data;
}

uint8_t uart_recieve()
{
	// check when there are unread data in the receive buffer
	while(!READ_BIT(UCSRA,RXC));
	return UDR;
}

uint8_t uart_send_PC(uint8_t c) // periodic check
{
	if (READ_BIT(UCSRA,TXC)) // This flag bit is set when the entire frame in the transmit Shift Register has been shifted out
	{
		UDR=c;
		return 1;
	}
	else
	{
		return 0;
	}
}

uint8_t uart_recieve_PC(uint8_t *c)
{
	if (READ_BIT(UCSRA,RXC)) // This flag bit is set when there are unread data in the receive buffer
	{
		*c=UDR;
		return 1;
	}	
	else
	{
		return 0;
	}
	
}

void uart_send_noblock(uint8_t c)
{
	UDR=c;
}

uint8_t uart_recieve_noblock()
{
	return UDR;
}

void RX_Complete_Interrupt_Enable()
{
	SET_BIT(UCSRB,RXCIE);
}

void RX_Complete_Interrupt_Disable()
{
	CLEAR_BIT(UCSRB,RXCIE);
}

void TX_Complete_Interrupt_Enable()
{
	SET_BIT(UCSRB,TXCIE);
}
void TX_Complete_Interrupt_Disable()
{
	CLEAR_BIT(UCSRB,TXCIE);
}

