/*
 * To_Start.h
 *
 * Created: 1/26/2024 4:28:37 PM
 *  Author: Ali Reda
 */ 


#ifndef TO_START_H_
#define TO_START_H_

#include "../HAL/Servo.h"
#include "../Services/UART_services.h"
#include "../Sensors/Ultrasonic_Sensor.h"
#include "../MCAL/DIO.h"
#include "../HAL/Buzzer.h"
#include "../HAL/LCD.h"
#include "../MCAL/Timer0.h"
#include "../HAL/LCD.h"
#include "string.h"

#define  Relay  PINB0
#define  start  PINB1

void Start(void);


#endif /* TO_START_H_ */