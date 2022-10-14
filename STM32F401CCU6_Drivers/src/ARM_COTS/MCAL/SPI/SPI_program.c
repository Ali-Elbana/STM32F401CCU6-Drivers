/* FILENAME: SPI_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Wed 10/12/2022
*/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBITMATH.h"

#include "../GPIO/GPIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"




/******************************************************************/
/******************************************************************/

void MSPI_vInit( void )
{

	// CPHA, CPOL.
	SET_BIT( SPI1->CR1, CPHA ) ;
	SET_BIT( SPI1->CR1, CPOL ) ;

	// MASTER/SLAVE Mode.
	SET_BIT( SPI1->CR1, MSTR ) ;

	// BUAD RATE.
	SPI1->CR1 = (SPI1->CR1 & ( ~(0b111U) << 3 )) | ( BR_MODE << 3 )  ;

	// MSB/LSB first.
	CLR_BIT( SPI1->CR1, LSBFIRST ) ;

	// Select SW slave management.
	SET_BIT( SPI1->CR1, SSI ) ;
	SET_BIT( SPI1->CR1, SSM ) ;

	// Data format.
	CLR_BIT( SPI1->CR1, DFF ) ;

	// PINs configurations.
	MGPIOx_ConfigType MOSI1 =
	{
		.Port 			= GPIO_PORTA 			,

		.Pin 			= GPIOx_PIN7 			,

		.Mode 			= GPIOx_MODE_AF 		,

		.OutputType 	= GPIOx_PUSHPULL 		,

		.OutputSpeed 	= GPIOx_VeryHighSpeed 	,

		.InputType 		= GPIOx_NoPull			,

		.AF_Type 		= GPIOx_AF5
	} ;

	MGPIOx_ConfigType MISO1 =
	{
		.Port 			= GPIO_PORTA 			,

		.Pin 			= GPIOx_PIN6 			,

		.Mode 			= GPIOx_MODE_AF 		,

		.OutputType 	= GPIOx_NoPull 			,

		.OutputSpeed 	= GPIOx_VeryHighSpeed 	,

		.InputType 		= GPIOx_NoPull			,

		.AF_Type 		= GPIOx_AF5
	} ;

	MGPIOx_ConfigType SCK1 =
	{
		.Port 			= GPIO_PORTA 			,

		.Pin 			= GPIOx_PIN5 			,

		.Mode 			= GPIOx_MODE_AF			,

		.OutputType 	= GPIOx_NoPull 			,

		.OutputSpeed 	= GPIOx_VeryHighSpeed 	,

		.InputType 		= GPIOx_NoPull 			,

		.AF_Type 		= GPIOx_AF5
	} ;

	MGPIOx_vInit( &MOSI1 ) ;
	MGPIOx_vInit( &MISO1 ) ;
	MGPIOx_vInit( &SCK1  ) ;

	// EN/DIS SPI.
	SET_BIT( SPI1->CR1, SPE ) ;

}

/******************************************************************/
/******************************************************************/

u16 MSPI_u16Transcieve( u16 A_u16Data )
{

	SPI1->DR = A_u16Data ;

	while( GET_BIT( SPI1->SR, BSY ) == Flag_is_Set )
	{
		asm("NOP") ;
	}

	return SPI1->DR ;

}

/******************************************************************/
/******************************************************************/














