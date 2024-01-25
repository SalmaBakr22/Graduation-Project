/******************************************/
/* Desc    : BIT_Math Header file         */
/* Author  : Salma Bakr 			      */
/* Date    : 5 Aug 2023 				  */
/* Version : 1.0v                         */
/******************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(Reg , bitNO)            Reg |=  (1 << (bitNO))
#define CLR_BIT(Reg , bitNO)          Reg &= ~(1 << (bitNO))
#define TGL_BIT(Reg , bitNO)            Reg ^=  (1 << (bitNO))
#define GET_BIT(Reg , bitNO)            ((Reg) >> (bitNO)) & 1

#endif /*End guard*/