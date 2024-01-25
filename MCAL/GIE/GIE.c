#include"../../Lib/STD_TYPES.h"
#include"../../Lib/BIT_MATH.h"
#include"GIE.h"

#define SREG *((volatile uint8 *) 0x5F)

void GIE_vidEnable(void)
{
	Set_Bit(SREG , 7);
}
void GIE_vidDisableable(void)
{
	ClR_Bit(SREG , 7);
}