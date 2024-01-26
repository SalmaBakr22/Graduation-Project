/*
 * LCD.c
 *
 * Created: 9/21/2023 11:23:07 PM
 *  Author: Ali Reda
 */ 

/*----------------- Libraries and Definitions ------------*/

#include "LCD.h"
#include "../MCAL/DIO.h"

	
/*------------------------- Function Definitions Of  -----------------------------*/


		/*---------------- Specialized Functions ------------------*/

void LCD_lcd_kick(){
	DIO_Writepin(EN,LOW);
	_delay_ms(50);
	DIO_Writepin(EN,HIGH);
}

void LCD_check_lcd_isbusy(){
	DDRA &= ~(0xFF<<4);  // output pins
	DIO_Writepin(RW,LOW); // L: Write Operation
	DIO_Writepin(RS,HIGH); //  Data Code
	LCD_lcd_kick();
	DDRA |= (0xFF<<4);  // input pins
	DIO_Writepin(RW,HIGH); // R : read Operation
	
}

/*---------- Function used to initialize LCD--------------*/

void LCD_Init()
{
	#ifdef LCD_8_BIT_MODE 
	
	_delay_ms(30);	
	LCD_WriteCmd(0x38);           // (Function Set) Enable  8-bit, 2 Line, 5x7 Dots
	_delay_ms(1);
	LCD_WriteCmd(0x0F);           // (Display ON/OFF Control) Display on, Cursor blinking
	_delay_ms(1);
	LCD_WriteCmd(0x01);           // Clear Display (also clear DDRAM content)
	_delay_ms(2);
	LCD_WriteCmd(0x06);           // (Entry Mode Set) shift cursor to right (increment cursor)
	_delay_ms(1);
	LCD_WriteCmd(0x80);           // beginning of 1st line
	
	#endif
	
	#ifdef LCD_4_BIT_MODE
	
	_delay_ms(20);
	
	LCD_WriteCmd(0x02);
	_delay_ms(1);
	LCD_WriteCmd(0x28);           // (Function Set) Enable  4-bit, 2 Line, 5x7 Dots
	_delay_ms(1);
	LCD_WriteCmd(0x0C);           // (Display ON/OFF Control) Display on, Cursor blinking
	_delay_ms(1);
	LCD_WriteCmd(0x01);           // Clear Display (also clear DDRAM content)
	_delay_ms(2);
	LCD_WriteCmd(0x06);           // (Entry Mode Set) shift cursor to right (increment cursor)
	_delay_ms(1);
	LCD_WriteCmd(0x80);           // beginning of 1st line
	
	#endif
	
}

/*--------------------------- Function used to write Commend (Instruction) to LCD ---------------------------*/

void LCD_WriteCmd(uint8_t cmd)
{
	#ifdef LCD_8_BIT_MODE 
	
	DIO_Writepin(RS, LOW);		//  Instruction Code
	DIO_Writepin(RW, LOW);		//  L: Write Operation
	DIO_Writeport(DATA, cmd);   // write command
	DIO_Writepin(EN, HIGH);		// Enable Signal
	_delay_ms(1);				// delay required to allow LCD to read
	DIO_Writepin(EN, LOW);
	_delay_ms(1);
	
	#endif
	
	#ifdef LCD_4_BIT_MODE 

	// send last 4 bits
	DIO_Writepin(D4, READ_BIT(cmd,4));
	DIO_Writepin(D5, READ_BIT(cmd,5));
	DIO_Writepin(D6, READ_BIT(cmd,6));
	DIO_Writepin(D7, READ_BIT(cmd,7));
	
	DIO_Writepin(RS, LOW);		//  Instruction Code
	DIO_Writepin(RW, LOW);		//  L: Write Operation
	DIO_Writepin(EN, HIGH);		// Enable Signal
	_delay_ms(1);				// delay required to allow LCD to read
	DIO_Writepin(EN, LOW);
	
	// send first 4 bits
	DIO_Writepin(D4, READ_BIT(cmd,0));
	DIO_Writepin(D5, READ_BIT(cmd,1));
	DIO_Writepin(D6, READ_BIT(cmd,2));
	DIO_Writepin(D7, READ_BIT(cmd,3));
	
	DIO_Writepin(RS, LOW);		//  Instruction Code
	DIO_Writepin(RW, LOW);		//  L: Write Operation
	DIO_Writepin(EN, HIGH);		// Enable Signal
	_delay_ms(1);				// delay required to allow LCD to read
	DIO_Writepin(EN, LOW);
	_delay_ms(5);
	
	#endif
}

/*--------------------------- Function used to write Data to LCD ----------------------------------*/

void LCD_WriteData(uint8_t data)
{
	#ifdef LCD_8_BIT_MODE 
	
	DIO_Writepin(RS, HIGH);		//  data Code
	DIO_Writepin(RW, LOW);		//  L:  Write Operation
	DIO_Writeport(DATA, data);   // write data
	DIO_Writepin(EN, HIGH);		// Enable Signal
	_delay_ms(1);				// delay required to allow LCD to read
	DIO_Writepin(EN, LOW);
	_delay_ms(1);
	
	#endif
	
	#ifdef LCD_4_BIT_MODE
	
	// send last 4 bits
	DIO_Writepin(D4, READ_BIT(data,4));
	DIO_Writepin(D5, READ_BIT(data,5));
	DIO_Writepin(D6, READ_BIT(data,6));
	DIO_Writepin(D7, READ_BIT(data,7));
	
	DIO_Writepin(RS, HIGH);		//  data Code
	DIO_Writepin(RW, LOW);		//  L: Write Operation
	DIO_Writepin(EN, HIGH);		// Enable Signal
	_delay_ms(1);				// delay required to allow LCD to read
	DIO_Writepin(EN, LOW);
	
	// send first 4 bits
	DIO_Writepin(D4, READ_BIT(data,0));
	DIO_Writepin(D5, READ_BIT(data,1));
	DIO_Writepin(D6, READ_BIT(data,2));
	DIO_Writepin(D7, READ_BIT(data,3));
	
	DIO_Writepin(RS, HIGH);		//  data Code
	DIO_Writepin(RW, LOW);		//  L: Write Operation
	DIO_Writepin(EN, HIGH);		// Enable Signal
	_delay_ms(1);				// delay required to allow LCD to read
	DIO_Writepin(EN, LOW);
	
	#endif
	
}

/*---------------------------------- Function used to clear Screen Of LCD -----------------------------------------*/

void LCD_Clear(void)
{
	LCD_WriteCmd(0x01);           // Clear Display (also clear DDRAM content)
	_delay_ms(1);
}

/*---------------- General Functions ------------------*/

/*----------------------------------- Function used to Move Cursor of LCD ----------------------------------------*/

void LCD_GOTO(uint8_t pos_x , uint8_t pos_y)
{
	int address = 0;
	
	if (pos_x == 0)
	address = 0x80;
	else if (pos_x == 1)
	address = 0xC0;
	
	if (pos_y <= 15)
	address += pos_y;
	
	LCD_WriteCmd(address);
}

/*----------------  Function used to Write Character  ------------------*/

void LCD_WriteChar(uint8_t character)
{
	LCD_WriteData(character);
	_delay_ms(1);
}

/*----------------  Function used to Write string  --------------------*/

void LCD_WriteString(char *str)
{
	uint8_t i;
	for (i=0 ; str[i] ; i++)
	{
		LCD_WriteData(str[i]);
		_delay_ms(1);
	}
}
void LCD_WriteSpaces(uint8_t n)
{
	for(uint8_t i =0; i < n ; i++)
	{
		LCD_WriteData(' ');
		_delay_ms(1);
	}
}

/*----------------  Function used to Write Real Number  --------------------*/

void LCD_WriteNumber(float Number)
{
	uint8_t i=0,arr[16];
	if(Number==0)
	LCD_WriteData('0');
	
	if (Number<0)
	{
		Number=Number*-1;
		LCD_WriteData('-');
	}
	int int_num=Number;	// integer part
	float fra_num=Number-int_num; // fraction part
	
		while(int_num)
		{
			arr[i]=int_num%10 +'0';
			int_num/=10;
			i++;
		}
		// write array content (Number ) --> start writing from the biggest digit
		for(;i>0;i--)
		{
			LCD_WriteData(arr[i-1]);
		}
		if (fra_num!=0)
		{
			LCD_WriteData('.');
			i=0;
			uint16_t int_num1;
			int_num1=fra_num*1000;
			while(int_num1)
			{
				arr[i]=int_num1%10 +'0';
				int_num1/=10;
				i++;
			}
			// write array content (Number ) --> start writing from the biggest digit
			for(;i>0;i--)
			{
				LCD_WriteData(arr[i-1]);
			}
		}	
}

/*----------------  Function used to Write Number of 5 digits  --------------------*/

void LCD_WriteNumber5D(int32_t Number)
{
	if (Number<0)
	{
		Number=Number*-1;
		LCD_WriteData('-');
	}
	LCD_WriteData(Number%100000/10000+'0');
	LCD_WriteData(Number%10000/1000+'0');
	LCD_WriteData(Number%1000/100+'0');
	LCD_WriteData(Number%100/10+'0');
	LCD_WriteData(Number%10/1+'0');
}

/*----------------  Function used to Write Number of 3 digits  --------------------*/

void LCD_WriteNumber3D(int16_t Number)
{
	if (Number<0)
	{
		Number=Number*-1;
		LCD_WriteData('-');
	}
	LCD_WriteData(Number%1000/100+'0');
	LCD_WriteData(Number%100/10+'0');
	LCD_WriteData(Number%10/1+'0');
}

/*----------------  Function used to Write Number of 2 digits  --------------------*/

void LCD_WriteNumber2D(int8_t Number)
{
	if (Number<0)
	{
		Number=Number*-1;
		LCD_WriteData('-');
	}
	LCD_WriteData(Number%100/10+'0');
	LCD_WriteData(Number%10/1+'0');
}
void LCD_WriteBinary(uint8_t num);

/*----------------  Function used to Create Character  --------------------*/
/*-------  Note that you have 16 memory locations for Characters and you can call them by numbers from 1 to 16 ------*/
/*------------- use LCD_GOTO(); fun before this fun -----------------------*/
void LCD_Create_Character(uint8_t *Pattern,uint8_t Location)
{
	uint8_t i;
	LCD_WriteCmd(0x40 + (8*Location));
	for (i=0; i<8; i++)
	{
		LCD_WriteData(Pattern[i]);
		_delay_ms(1);
	}
}



/*----------------------------------- Function used to display float on Screen -----------------------------*/
