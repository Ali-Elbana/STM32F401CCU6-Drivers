/* FILENAME: SysTick_private  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Sun 09/04/2022
*/
#ifndef _SysTick_private_H
#define _SysTick_private_H


#define SysTick_BASE_ADDRESS	0xE000E010



typedef struct
{

	u32 CTRL	;

	u32 LOAD	;

	u32 VAL		;

	u32 CALIB	;

} SysTick_Type ;



#define SysTick ( (volatile SysTick_Type*) (SysTick_BASE_ADDRESS) )



#define COUNTFLAG 		16
#define CLKSOURCE		2
#define TICKINT			1
#define	COUNTER_ENABLE	0






#define  AHB_DividedBy8			1
#define  AHB           			2

#define  Dont_AssertRequest		1
#define  AssertRequest     		2






#endif //_SysTick_private_H
