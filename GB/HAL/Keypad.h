/*
 * Keypad.h
 *
 * Created: 9/27/2023 6:20:54 PM
 *  Author: Ali Reda
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

/*----------------- Libraries and Definitions ------------*/
#include "stdint.h"

/******** All 4-pins in the same Port and another 4 in another port **********/
/*************** (OUTPUT IN DIO_CONFIG) **********/
#define FIRST_OUT_Pin        PINC0

/*************** (INPUT_PULL_UP IN DIO_CONFIG) **********/
#define FIRST_INP_Pin        PINC4

#define ROW              4
#define COLUMN           4

#define DEFAULT_KEY       '.'

/*--------------------- Functions Prototypes ---------------------------*/

uint8_t keypad_Data(void);



#endif /* KEYPAD_H_ */