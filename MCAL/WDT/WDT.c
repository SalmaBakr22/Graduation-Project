#include "STD_Types.h"
#include "WDT.h"

 void WDT_vidRefresh(void)
 {
	 WDTCR = 0x08;
 }
 
void WDT_vidWDTPrescalar(uint8 u8PrescalarCpy)
 {
	 WDTCR = 0b00001000;
	 WDTCR |= (u8PrescalarCpy & 0x07 ); 
 }
 
 void WDT_vidTurnOFF(void)
 {
	 WDTCR = 0X18;
	 WDTCR = 0 ; 
 }