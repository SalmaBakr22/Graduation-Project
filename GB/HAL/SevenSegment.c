/*
 * SevenSegment.c
 *
 * Created: 9/21/2023 12:55:50 AM
 *  Author: Ali Reda
 */ 

/*----------------- Libraries and Definitions ------------*/

#include "stdint.h"
#include "SevenSegment.h"

unsigned char segmentnum[]={0x3f,0x06,0x5b,0x4F,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	
	/*------------------------- Function Definitions -----------------------------*/

void SEVEN_SEGMENT1(uint8_t num){
	// enable pin
	DIO_Writepin(PINC2,HIGH);
	// output on port C
	segmentport=segmentnum[num];
}
