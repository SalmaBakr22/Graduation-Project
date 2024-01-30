/*
 * I2C.c
 *
 * Created: 12/18/2023 11:54:07 PM
 *  Author: Ali Reda
 */ 

#include "I2C.h"

#define Prescaler 1

void I2C_init(uint32_t SCL_freq)
{
	// bit rate
	TWBR=(uint8_t)(((F_CPU / SCL_freq)-16)/(2*Prescaler));
	//  Prescaler Value 1
	if (Prescaler==1)
	{
		CLEAR_BIT(TWSR,TWPS0);
		CLEAR_BIT(TWSR,TWPS1);
	}
	else if (Prescaler==4)
	{
		SET_BIT(TWSR,TWPS0);
		CLEAR_BIT(TWSR,TWPS1);
	}
	else if (Prescaler==16)
	{
		CLEAR_BIT(TWSR,TWPS0);
		SET_BIT(TWSR,TWPS1);
	}
	else if (Prescaler==64)
	{
		SET_BIT(TWSR,TWPS0);
		SET_BIT(TWSR,TWPS1);
	}
		
	// TW Interrupt : off
	CLEAR_BIT(TWCR,TWIE);
	// General Call Recognition : off
	CLEAR_BIT(TWAR,TWGCE);
}

void I2C_start()
{
	// Send START condition
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	// Wait for TWINT Flag set by hardware
	while (!(TWCR & (1<<TWINT)));
}
void I2C_stop()
{
	// Transmit STOP condition
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

uint8_t I2C_get_status()
{
	uint8_t status;
	status= TWSR & 0xF8;
	return status;
}

void I2C_write(uint8_t data)
{
	TWCR = (1<<TWINT) | (1<<TWEN);
	// Load DATA into TWDR Register	TWDR = data;	// Wait for TWINT Flag set	while (!(TWCR & (1<<TWINT)));
}
uint8_t I2C_Read_ACK()
{
	TWCR = (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
	// Wait for TWINT Flag set	while (!(TWCR & (1<<TWINT)));
	if (I2C_get_status()!=TW_SR_SLA_ACK)
	return 0;
	TWCR = (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
	// Wait for TWINT Flag set	while (!(TWCR & (1<<TWINT)));
	if (I2C_get_status()!=TW_SR_DATA_ACK)
	return 0;
	// read data
	return TWDR;
}

uint8_t I2C_Read_NACK()
{
	TWCR = (1<<TWINT) | (1<<TWEN);
	// Wait for TWINT Flag set	while (!(TWCR & (1<<TWINT)));
	TWCR = (1<<TWINT) | (1<<TWEN);
	// Wait for TWINT Flag set	while (!(TWCR & (1<<TWINT)));
	// read data
	return TWDR;
}

uint8_t I2C_write_data(uint8_t data, uint8_t address)
{
	I2C_start();
	// Check value of TWI Status Register
	while (I2C_get_status() != TW_START);	I2C_write((address<<1)|0);	// Check value of TWI Status Register	while (I2C_get_status() != TW_MT_SLA_ACK);	I2C_write(data);	// Check value of TWI Status Register	while (I2C_get_status() != TW_MT_DATA_ACK);	I2C_stop();	
	return 1;
}

void I2C_set_address(uint8_t add_WR)
{
	TWAR= add_WR;
}

