/*
 * LCD.h
 *
 * Created: 9/21/2023 11:22:54 PM
 *  Author: Ali Reda
 */ 


#ifndef LCD_H_
#define LCD_H_

/*----------------- Libraries and Definitions ------------*/

#include "stdint.h"
#include "../MCAL/DIO.h"

/********************************** LCD modes ***********************/

  #define    LCD_4_BIT_MODE      
 //#define    LCD_8_BIT_MODE          

/*************** LCD config 8 Bit mode (OUTPUT IN DIO_CONFIG) **********/
#define    DATA             PA

/*************** LCD config 4 Bit mode (OUTPUT IN DIO_CONFIG)*********/
#define   D4              PINA4
#define   D5              PINA5
#define   D6              PINA6
#define   D7              PINA7

/************ define control pins (OUTPUT IN DIO_CONFIG)    *************/

#define RS               PINB0
#define RW               PINB1
#define EN               PINB2

/* ============= LCD Commands ================== */
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)

/*--------------------- Functions Prototypes ---------------------------*/
void LCD_check_lcd_isbusy();
void LCD_lcd_kick();
void LCD_Init();
void LCD_WriteCmd(uint8_t cmd);
void LCD_WriteData(uint8_t data);
void LCD_GOTO(uint8_t pos_x , uint8_t pos_y);
void LCD_WriteChar(uint8_t character);
void LCD_WriteString(char *str);
void LCD_WriteSpaces(uint8_t n);
void LCD_WriteNumber(float Number);
void LCD_WriteNumber5D(int32_t Number);
void LCD_WriteNumber3D(int16_t Number);
void LCD_WriteNumber2D(int8_t Number);
void LCD_WriteBinary(uint8_t num);
void LCD_Create_Character(uint8_t *Pattern,uint8_t Location);
void LCD_Clear(void);

#endif /* LCD_H_ */