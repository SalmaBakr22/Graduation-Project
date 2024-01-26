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

void Start(void);
void Park(void);
void Take_out(void);
void safety(void);

#endif /* TO_START_H_ */