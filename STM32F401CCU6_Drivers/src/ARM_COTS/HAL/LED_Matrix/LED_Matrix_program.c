/* FILENAME: LED_Matrix_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Mon 09/05/2022
*/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBITMATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/SysTick/SysTick_interface.h"

#include "LED_Matrix_private.h"
#include "LED_Matrix_config.h"
#include "LED_Matrix_interface.h"




void MLED_Matrix_vInit( void )
{

	u8 L_u8Iterator1 = Initialized_by_Zero ;
	u8 L_u8Iterator2 = Initialized_by_Zero ;

	for( L_u8Iterator1 = 0; L_u8Iterator1 < ROWS_NUMs; L_u8Iterator1++ )
	{

		MGPIOx_vInit( &LED_MATRIX_ROWS[L_u8Iterator1] ) ;

	}



	for( L_u8Iterator2 = 0; L_u8Iterator2 < COLUMNS_NUMs; L_u8Iterator2++ )
	{

		MGPIOx_vInit( &LED_MATRIX_COLUMNS[L_u8Iterator2] ) ;

	}


	MSysTick_vInit( ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

#if CONTROLLED_METHOD == COLUMN_CONTROLLED_METHOD


static void LED_Matrix_vDisableAllColumns( void )
{

	u8 L_u8Iterator = Initialized_by_Zero ;

	for( L_u8Iterator = 0; L_u8Iterator < COLUMNS_NUMs ; L_u8Iterator++ )
	{

		MGPIOx_vSetPinValue( LED_MATRIX_COLUMNS[L_u8Iterator].Port,
							 LED_MATRIX_COLUMNS[L_u8Iterator].Pin , GPIOx_LOW ) ;

	}

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

static void LED_Matrix_vSetRowValues( u8 A_u8RowValues )
{

	u8 L_u8Iterator = Initialized_by_Zero ;

	for( L_u8Iterator = 0; L_u8Iterator < ROWS_NUMs; L_u8Iterator++ )
	{

		MGPIOx_vSetPinValue( LED_MATRIX_ROWS[L_u8Iterator].Port,
							 LED_MATRIX_ROWS[L_u8Iterator].Pin ,
							 GET_BIT(A_u8RowValues, L_u8Iterator) ) ;

	}

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

static void LED_Matrix_vSetColumnValue( u8 A_u8ColumnNUM )
{

	MGPIOx_vSetPinValue( LED_MATRIX_COLUMNS[A_u8ColumnNUM].Port,
						 LED_MATRIX_COLUMNS[A_u8ColumnNUM].Pin , GPIOx_HIGH ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MLEDMatrix_vDisplayFrame( u8 A_ARRu8Frame[], u32 A_u32FrameRepetition )
{

	u8 L_u8Iterator1 = Initialized_by_Zero ;
	u8 L_u8Iterator2 = Initialized_by_Zero ;

	for( L_u8Iterator1 = 0; L_u8Iterator1 < A_u32FrameRepetition; L_u8Iterator1++ )
	{

		for( L_u8Iterator2 = 0; L_u8Iterator2 < COLUMNS_NUMs; L_u8Iterator2++ )
		{

			// Disable all columns.
			LED_Matrix_vDisableAllColumns( ) ;

			// Set rows values.
			LED_Matrix_vSetRowValues( A_ARRu8Frame[L_u8Iterator2] ) ;

			// Set column value.
			LED_Matrix_vSetColumnValue( L_u8Iterator2 ) ;

			// Delay with suitable FPS.
			MSysTick_vSetBusyWait( SCAN_TIME ) ; // 2.5ms

		}

	}

}

#endif

/*******************************************************************************************************************/
/******************************************************************************************************************/

#if CONTROLLED_METHOD == ROW_CONTROLLED_METHOD

static void LED_Matrix_vDisableAllRows( void )
{

	u8 L_u8Iterator = Initialized_by_Zero ;

	for( L_u8Iterator = 0; L_u8Iterator < ROWS_NUMs; L_u8Iterator++ )
	{

		MGPIOx_vSetPinValue( LED_MATRIX_ROWS[L_u8Iterator].Port,
							 LED_MATRIX_ROWS[L_u8Iterator].Pin , GPIOx_LOW ) ;

	}

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

static void LED_Matrix_vSetColumnValues( u8 A_u8ColumnValues )
{

	u8 L_u8Iterator = Initialized_by_Zero ;

	for( L_u8Iterator = 0; L_u8Iterator < COLUMNS_NUMs; L_u8Iterator++ )
	{

		MGPIOx_vSetPinValue( LED_MATRIX_COLUMNS[L_u8Iterator].Port,
							 LED_MATRIX_COLUMNS[L_u8Iterator].Pin , GET_BIT( A_u8ColumnValues , L_u8Iterator ) ) ;

	}

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

static void LED_Matrix_vSetRowValue( u8 A_u8RowNUM )
{

		MGPIOx_vSetPinValue( LED_MATRIX_ROWS[A_u8RowNUM].Port,
							 LED_MATRIX_ROWS[A_u8RowNUM].Pin , GPIOx_HIGH ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MLEDMatrix_vDisplayFrame2( u8 A_ARRu8Frame[], u32 A_u32FrameRepetition )
{

	u8 L_u8Iterator1 = Initialized_by_Zero ;
	u8 L_u8Iterator2 = Initialized_by_Zero ;

	for( L_u8Iterator1 = 0; L_u8Iterator1 < A_u32FrameRepetition; L_u8Iterator1++ )
	{

		for( L_u8Iterator2 = 0; L_u8Iterator2 < ROWS_NUMs; L_u8Iterator2++ )
		{

			// Disable all rows.
			LED_Matrix_vDisableAllRows( ) ;

			// Set columns values.
			LED_Matrix_vSetColumnValues( A_ARRu8Frame[L_u8Iterator2] ) ;

			// Set row value.
			LED_Matrix_vSetRowValue( L_u8Iterator2 ) ;

			// Delay with suitable FPS.
			MSysTick_vSetBusyWait( SCAN_TIME ) ; // 2.5ms

		}

	}

}

#endif

/*******************************************************************************************************************/
/******************************************************************************************************************/

//void MLED_Matrix_vDisplayMatrix( u8 A_ARRu8Matrix[][COLUMNS_NUMs], u32 A_u32MatrixDelay )
//{
//
//
//
//
//}

/*******************************************************************************************************************/
/******************************************************************************************************************/






