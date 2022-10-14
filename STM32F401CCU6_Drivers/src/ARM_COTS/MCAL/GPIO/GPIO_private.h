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

	u32 MODERx 		;

	u32 OTYPERx 	;

	u32 OSPEEDRx 	;

	u32 PUPDRx 		;

	u32 IDRx		;

	u32 ODRx		;

	u32 BSRRx		;

	u32 LCKRx		;

	u32 AFRLx		;

	u32 AFRHx		;


} GPIOx_MemoryMapType ;




#define GPIOA ( (volatile GPIOx_MemoryMapType*) (GPIOA_BASE_ADDRESS) )
#define GPIOB ( (volatile GPIOx_MemoryMapType*) (GPIOB_BASE_ADDRESS) )
#define GPIOC ( (volatile GPIOx_MemoryMapType*) (GPIOB_BASE_ADDRESS) )










#endif //_GPIO_private_H
