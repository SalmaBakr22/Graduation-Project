/*
 * SPI.h
 *
 * Created: 12/8/2023 3:03:36 PM
 *  Author: Ali Reda
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "stdint.h"

typedef enum{
	f_dividedby4,
	f_dividedby16,
	f_dividedby64,
	f_dividedby128,
	f_dividedby2,
	f_dividedby8,
	f_dividedby32
	}clock_rate;


void SPI_master_init(clock_rate r);
void SPI_slave_init();
uint8_t SPI_send_recieve(uint8_t data);  // most used to send (master)
void SPI_send_noblock(uint8_t data);
void SPI_recieve_noblock(uint8_t *data); // most used to receive (slave) inside interrupt
uint8_t SPI_send_PC(uint8_t data);
uint8_t SPI_recieve_PC(uint8_t *data);
void SPI_recieve_setcallback(uint8_t *data);
void SPI_interrupt_enable();
void SPI_interrupt_disable();

#endif /* SPI_H_ */