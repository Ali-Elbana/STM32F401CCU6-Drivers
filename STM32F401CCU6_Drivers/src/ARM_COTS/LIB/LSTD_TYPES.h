/************************************************************/
/**********   Author      : Ali El_bana           **********/
/**********   Date        : 5/4/2022             **********/
/**********   Description : STD_TYPES library   **********/
/**********   Version     : 1.0 V              **********/
/*******************************************************/




/*******************************************************************/
/****   Guard file that will be called one time in file.c      ****/
/*****************************************************************/


#ifndef STD_TYPES_H
#define STD_TYPES_H



#ifndef NULL

	#define NULL ( (void*) 0 )

#endif


typedef char        		c8	;

typedef unsigned char       u8	;
typedef signed   char       s8	;

typedef unsigned long int   u64	;
typedef signed   long int   s64	;

typedef unsigned int        u32	;
typedef signed   int        s32	;

typedef unsigned short int  u16	;
typedef signed   short int  s16	;

typedef float               f32	;
typedef double              f64	;



#define TRUE  1

// Is a macro for defining the initialized value of the variables.
#define Initialized_by_Zero  0


#define RUN  1

#define STOP 0


#define Flag_is_Set 	1

#define Flag_is_Cleared 0




#endif










