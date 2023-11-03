#ifndef EXT0_H
#define EXT0_H

#define EXT0_RISING     3
#define EXT0_FALLING    2
#define EXT0_IOC        1
#define EXT0_LOW_LEVEL  0

void EXT0_vidInit(void);

void EXT0_vidEnable(void);
void EXT0_vidDisable(void);
void EXT0_vidSetCallBack(pf pfCpy);
void EXT0_vidChgMod(uint8 u8ModeCpy);

#endif 