/*
 * Utils.h
 *
 * Created: 9/21/2023 12:54:07 AM
 *  Author: Ali Reda
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define F_CPU 8000000UL
#include <util/delay.h>

#define SET_BIT(reg,bit) (reg |=(1<<bit))
#define CLEAR_BIT(reg,bit) (reg &=(~(1<<bit)))
#define READ_BIT(reg,bit) ((reg>>bit) & 0x01)
#define TOGGLE_BIT(reg,bit)  (reg ^=(1<<bit))
#define WRITE_BIT(reg,bit,value)  (reg=(reg & (~(1<<bit)))|(value<<bit))




#endif /* UTILS_H_ */