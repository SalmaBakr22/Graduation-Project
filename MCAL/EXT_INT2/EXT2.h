#ifndef EXT2_H
#define EXT2_H

#define EXT2_FALLING    0
#define EXT2_RISING     1


void EXT2_vidInit(void);

void EXT2_vidEnable(void);
void EXT2_vidDisable(void);
void EXT2_vidSetCallBack(pf pfCpy);
void EXT2_vidChgMod(uint8 u8ModeCpy);

#endif 