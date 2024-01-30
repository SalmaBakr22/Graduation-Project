/*
 * To_Start.h
 *
 * Created: 1/26/2024 4:28:37 PM
 *  Author: Ali Reda
 */ 


#ifndef TO_START_H_
#define TO_START_H_

#include "../HAL/Servo.h"
#include "../HAL/Buzzer.h"
#include "../HAL/LCD.h"
#include "../HAL/Limit Switch.h"
#include "../HAL/Stepper_H.h"
#include "../HAL/Stepper_V.h"
#include "../Services/UART_services.h"
#include "../Sensors/Ultrasonic_Sensor.h"
#include "../Sensors/IR Sensor.h"
#include "../MCAL/DIO.h"
#include "../MCAL/Timer0.h"
#include "../MCAL/Timer1.h"
#include "../MCAL/Timer2.h"
#include "string.h"

#define  Relay  PINB0
#define  start  PINB1
#define  IR1    PINB2
#define  IR2    PINB3
#define  IR3    PINB4
#define  IR4    PINB5
#define  LS1    PINB6
#define  LS2    PINB7
#define  LS3    PINC0

void Start(uint8_t *state, uint8_t *WC);
void Park(uint8_t pos);
void Take_out(uint8_t pos);
void safety(void);

#endif /* TO_START_H_ */