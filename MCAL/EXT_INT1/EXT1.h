#ifndef EXT1_H
#define EXT1_H

#define EXT1_LOW_LEVEL  0
#define EXT1_IOC        1
#define EXT1_FALLING    2
#define EXT1_RISING     3


void EXT1_vidInit(void);

void EXT1_vidEnable(void);
void EXT1_vidDisable(void);
void EXT1_vidSetCallBack(pf pfCpy);
void EXT1_vidChgMod(uint8 u8ModeCpy);

#endif 