/* FILENAME: DMA_private  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Fri 10/14/2022
*/
#ifndef _DMA_private_H
#define _DMA_private_H


#define DMA1_BASE_ADDRESS	0x40026000
#define DMA2_BASE_ADDRESS	0x40026400

typedef struct
{

	volatile u32 CR_REG   ;

	volatile u32 NDTR_REG ;

	volatile u32 PAR_REG  ;

	volatile u32 M0AR_REG ;

	volatile u32 M1AR_REG ;

	volatile u32 FCR_REG  ;

} DMA_StreamType ;


typedef struct
{

	volatile u32 LISR_REG 	;

	volatile u32 HISR_REG 	;

	volatile u32 LIFCR_REG 	;

	volatile u32 HIFCR_REG 	;

	DMA_StreamType S[8] ;

} DMA_MemoryMapType ;


#define DMA1 ( (volatile DMA_MemoryMapType*) DMA1_BASE_ADDRESS )
#define DMA2 ( (volatile DMA_MemoryMapType*) DMA2_BASE_ADDRESS )




#endif //_DMA_private_H
