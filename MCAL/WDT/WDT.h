 #ifndef WDT_H
 #define WDT_H
 
#define PRE16_3MS       0
#define PRE32_5MS       1
#define PRE65MS         2
#define PRE0_13S        3
#define PRE0_26S        4
#define PRE0_52S        5
#define PRE1S           6
#define PRE2_1S         7

#define WDTCR   *((volatile uint8 * ) 0x41 )


 void WDT_vidRefresh(void);
 void WDT_vidWDTPrescalar(uint8 u8PrescalarCpy);
 void WDT_vidOFF(void);
 
 #endif