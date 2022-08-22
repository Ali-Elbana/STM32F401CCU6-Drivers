/* FILENAME: GPIO_private  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Mon 08/22/2022
*/
#ifndef _GPIO_private_H
#define _GPIO_private_H



#define GPIOA_BASE_ADDRESS	0x40020000
#define GPIOB_BASE_ADDRESS 	0x40020400
#define GPIOC_BASE_ADDRESS  0x40020800



typedef struct
{

	u32 MODER 	;

	u32 OTYPER 	;

	u32 OSPEEDR ;

	u32 PUPDR 	;

	u32 IDR		;

	u32 ODR		;

	u32 BSRR	;

	u32 LCKR	;

	u32 AFRL	;

	u32 AFRH	;


} GPIOx_MemoryMapType ;




#define GPIOA ( (volatile GPIOx_MemoryMapType*) (GPIOA_BASE_ADDRESS) )
#define GPIOB ( (volatile GPIOx_MemoryMapType*) (GPIOB_BASE_ADDRESS) )
#define GPIOC ( (volatile GPIOx_MemoryMapType*) (GPIOB_BASE_ADDRESS) )










#endif //_GPIO_private_H
