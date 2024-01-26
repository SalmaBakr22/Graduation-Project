/*
 * UART.h
 *
 * Created: 10/21/2023 9:45:06 PM
 *  Author: Ali Reda
 */ 


#ifndef UART_H_
#define UART_H_

#include "stdint.h"

typedef enum
{
	bits_5=0,
	bits_6,
	bits_7,
	bits_8,
	bits_9
	}Character_Size;

typedef enum
{
	Disabled=0,
	Even_Parity,
	Odd_Parity
	} Parity_Mode;

typedef enum
{
	bit_1=0,
	bit_2
	} Stop_Bits;

typedef enum
{
	Asynchronous=0,
	synchronous
	}Mode;
	
void uart_init(Character_Size s, Stop_Bits x, Parity_Mode m, Mode y);
void uart_send(uint8_t data);
uint8_t uart_recieve();
uint8_t uart_send_PC(uint8_t c);
uint8_t uart_recieve_PC(uint8_t *c); 
void uart_send_noblock(uint8_t c);
uint8_t uart_recieve_noblock();
void RX_Complete_Interrupt_Enable();
void RX_Complete_Interrupt_Disable();
void TX_Complete_Interrupt_Enable();
void TX_Complete_Interrupt_Disable();



#endif /* UART_H_ */