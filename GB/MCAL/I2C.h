/*
 * I2C.h
 *
 * Created: 12/18/2023 11:54:20 PM
 *  Author: Ali Reda
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "stdint.h"
#include "../Utils.h"
#include "../MemoryMap.h"

#define 	TW_START   0x08

#define 	TW_REP_START   0x10

#define 	TW_MT_SLA_ACK   0x18

#define 	TW_MT_SLA_NACK   0x20

#define 	TW_MT_DATA_ACK   0x28

#define 	TW_MT_DATA_NACK   0x30

#define 	TW_MT_ARB_LOST   0x38

#define 	TW_MR_ARB_LOST   0x38

#define 	TW_MR_SLA_ACK   0x40

#define 	TW_MR_SLA_NACK   0x48

#define 	TW_MR_DATA_ACK   0x50

#define 	TW_MR_DATA_NACK   0x58

#define 	TW_ST_SLA_ACK   0xA8

#define 	TW_ST_ARB_LOST_SLA_ACK   0xB0

#define 	TW_ST_DATA_ACK   0xB8

#define 	TW_ST_DATA_NACK   0xC0

#define 	TW_ST_LAST_DATA   0xC8

#define 	TW_SR_SLA_ACK   0x60

#define 	TW_SR_ARB_LOST_SLA_ACK   0x68

#define 	TW_SR_GCALL_ACK   0x70

#define 	TW_SR_ARB_LOST_GCALL_ACK   0x78

#define 	TW_SR_DATA_ACK   0x80

#define 	TW_SR_DATA_NACK   0x88

#define 	TW_SR_GCALL_DATA_ACK   0x90

#define 	TW_SR_GCALL_DATA_NACK   0x98

#define 	TW_SR_STOP   0xA0

#define 	TW_NO_INFO   0xF8

#define 	TW_BUS_ERROR   0x00

#define 	TW_STATUS_MASK

#define 	TW_STATUS   (TWSR & TW_STATUS_MASK)

// R/~W bit in SLA+R/W address field.

#define 	TW_READ   1

#define 	TW_WRITE   0



void I2C_start();
void I2C_stop();
void I2C_write(uint8_t data);
uint8_t I2C_Read_ACK();
uint8_t I2C_Read_NACK();
uint8_t I2C_get_status();

void I2C_init(uint32_t SCL_freq);
uint8_t I2C_write_data(uint8_t data, uint8_t address);
void I2C_set_address(uint8_t add_WR);
uint8_t I2C_read_data(uint8_t add_WR);

#endif /* I2C_H_ */