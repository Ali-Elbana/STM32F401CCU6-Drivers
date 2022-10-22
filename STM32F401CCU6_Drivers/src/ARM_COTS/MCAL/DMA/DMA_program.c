/* FILENAME: DMA_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Fri 10/14/2022
*/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBITMATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"



/******************************************************************/
/******************************************************************/

void MDMA_vInit( void )
{

	CLR_BIT( DMA2->S[0].CR_REG, 0 ) ; // make sure that the enable bit is disabled before configuration

	DMA2->S[0].CR_REG |= (1<<14) | (1<<12) | (1<<10) | (1<<9) | (1<<8) | (1<<7) | (1<<4) ;

	DMA2->S[0].FCR_REG |= (1<<0) | (1<<1) | (1<<2)  ;

}

/******************************************************************/
/******************************************************************/

void MDMA_vSetStream( u32 *A_pu32SrcAddress,
					  u32 *A_pu32DestAddress, u32 A_u32DataSize,
					  u32 A_u32BlockSize, u8 A_u8StreamID )
{

	DMA2->S[A_u8StreamID].PAR_REG  = *A_pu32SrcAddress ;

	DMA2->S[A_u8StreamID].M0AR_REG = *A_pu32DestAddress ;

	DMA2->S[A_u8StreamID].NDTR_REG = A_u32BlockSize ;
	// A_u32DataSize: (0b00 , 0b01 , 0b10) -> PSIZE and MSIZE

}

/******************************************************************/
/******************************************************************/

void MDMA_vEnableStream( u8 A_u8StreamID )
{

	DMA2->LIFCR_REG |= ( (1<<0) | (1<<2) | (1<<3) | (1<<4) | (1<<5) ) ;

	SET_BIT( DMA2->S[0].CR_REG, 0 ) ; // set enable bit to start transfer

}

/******************************************************************/
/******************************************************************/

void MDMA_vSetStreamCallback( u8 A_u8StreamID, void (*fptr) (void) )
{




}

/******************************************************************/
/******************************************************************/





