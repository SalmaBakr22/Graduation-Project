/******************************************/
/* Desc    : Standard types header file   */
/* Author  : Salma Bakr 			      */
/* Date    : 4 Aug 2023 				  */
/* Version : 1.0v                         */
/******************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef void (*pf)(void);

typedef signed char              sint8  ;
typedef unsigned char            uint8  ;
typedef signed short int         sint16 ;
typedef unsigned short int       uint16 ;
typedef signed long int          sint32 ;
typedef unsigned long int        uint32 ;
typedef float                    float32;
typedef double                   float64;

typedef enum 
{
	E_OK,
	E_NOK,
	PARM_POT_OF_RANGE,
	PTR_IS_NULL
}tenuErrorStatus;

#endif   /*End Guard*/