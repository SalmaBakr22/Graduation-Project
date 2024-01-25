/**************************************************/
/*Desc   : interface file for DIO                 */
/*Author :Ahmed abo elnour                        */
/*Date   : 25 Aug 2023                            */
/*Version: 1.0V                                   */
/**************************************************/

#ifndef DIO_H
#define DIO_H
#include "../../Lib/STD_Types.h"

void DIO_vidInit(void);

tenuErrorStatus DIO_enuSetPinDir   (uint8 u8PinNumCpy ,uint8  u8PinDirCpy);
tenuErrorStatus DIO_enuSetPinValue (uint8 u8PinNumCpy ,uint8  u8PinStatusCpy);
tenuErrorStatus DIO_enuReadPinValue(uint8 u8PinNumCpy ,uint8* pu8PinValueCpy);
tenuErrorStatus DIO_enuSetPinPullUp(uint8 u8PinNumCpy ,uint8  u8PullupStatusCpy);
void DIO_vidTogglePin(uint8 u8PinNumCpy);


#endif /*Gaurd*/