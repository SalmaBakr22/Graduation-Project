#ifndef SPI_H
#define SPI_H

#define SPI_SLAVE        0
#define SPI_MASTER       1

void SPI_vidInit(void);

void SPI_vidEnable(void);
void SPI_vidDisable(void);

void SPI_vidEnableInt(void);
void SPI_vidDisableInt(void);

void SPI_vidSetCallBack(pf pfCallFuncCpy);

uint8 SPI_u8GetMode(void);
void SPI_vidChgMode(uint8 u8ModeCpy);

uint8 SPI_u8Transmit(uint8 u8DataCpy);

void SPI_vidSendData(uint8 u8DataCpy);
uint8 SPI_u8RecvData(void);



#endif
