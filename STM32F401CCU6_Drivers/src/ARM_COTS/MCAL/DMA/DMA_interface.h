/* FILENAME: DMA_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Fri 10/14/2022
*/
#ifndef _DMA_interface_H
#define _DMA_interface_H

void MDMA_vInit( void ) ;

void MDMA_vSetStream( u32 *A_pu32SrcAddress,
					  u32 *A_pu32DestAddress, u32 A_u32DataSize,
					  u32 A_u32BlockSize, u8 A_u8StreamID ) ;

void MDMA_vEnableStream( u8 A_u8StreamID ) ;

void MDMA_vSetStreamCallback( u8 A_u8StreamID, void (*fptr) (void) ) ;


#endif //_DMA_interface_H
