/* FILENAME: LED_Matrix_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Mon 09/05/2022
*/
#ifndef _LED_Matrix_interface_H
#define _LED_Matrix_interface_H


void MLED_Matrix_vInit( void ) ;


#if CONTROLLED_METHOD == COLUMN_CONTROLLED_METHOD

void MLEDMatrix_vDisplayFrame( u8 A_ARRu8Frame[], u32 A_u32FrameRepetition ) ;

#endif

#if CONTROLLED_METHOD == ROW_CONTROLLED_METHOD

void MLEDMatrix_vDisplayFrame2( u8 A_ARRu8Frame[], u32 A_u32FrameRepetition ) ;

#endif
//void MLED_Matrix_vDisplayMatrix( u8 A_ARRu8Matrix[][COLUMNS_NUMs], u32 A_u32MatrixDelay ) ;

void MLED_Matrix_vClearShape( void ) ;


#endif //_LED_Matrix_interface_H
