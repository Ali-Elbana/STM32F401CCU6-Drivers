/* FILENAME: TFT_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Thu 10/13/2022
*/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBITMATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/SPI/SPI_interface.h"
#include "../../MCAL/SysTick/SysTick_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

extern MGPIOx_ConfigType TFT_A0  ;
extern MGPIOx_ConfigType TFT_RST ;

static u16 CurrentXStart 	= 0 ;
static u16 CurrentXEnd 		= 0 ;
static u16 CurrentYStart 	= 0 ;
static u16 CurrentYEnd 		= 0 ;

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HTFT_vWriteCMD( u16 A_u16CMD )
{

	MGPIOx_vSetPinValue( TFT_A0.Port, TFT_A0.Pin, GPIOx_LOW ) ;

	MSPI_u16Transcieve( A_u16CMD ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HTFT_vWriteData( u16 A_u16Data )
{

	MGPIOx_vSetPinValue( TFT_A0.Port, TFT_A0.Pin, GPIOx_HIGH ) ;

	MSPI_u16Transcieve( A_u16Data ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HTFT_vResetSequence( void )
{

	MGPIOx_vSetPinValue( TFT_RST.Port, TFT_RST.Pin, GPIOx_HIGH ) ;

	MSysTick_vSetBusyWait( 4 ) ; //100us

	MGPIOx_vSetPinValue( TFT_RST.Port, TFT_RST.Pin, GPIOx_LOW ) ;

	MSysTick_vSetBusyWait( 0.04 ) ; //1us

	MGPIOx_vSetPinValue( TFT_RST.Port, TFT_RST.Pin, GPIOx_HIGH ) ;

	MSysTick_vSetBusyWait( 4 ) ; //100us

	MGPIOx_vSetPinValue( TFT_RST.Port, TFT_RST.Pin, GPIOx_LOW ) ;

	MSysTick_vSetBusyWait( 0.04 ) ; //1us

	MGPIOx_vSetPinValue( TFT_RST.Port, TFT_RST.Pin, GPIOx_HIGH ) ;

	MSysTick_vSetBusyWait( 4800 ) ; //120ms

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HTFT_vInit( void )
{

	// Set pin directions:
	MGPIOx_vInit( &TFT_A0  ) ;
	MGPIOx_vInit( &TFT_RST ) ;

	MSPI_vInit( ) ;
	MSysTick_vInit( ) ;

	// Rest sequence:
	HTFT_vResetSequence( ) ;

	// Send SLPOUT CMD (0x11):
	HTFT_vWriteCMD( SLPOUT_CMD ) ;

	// Wait 15ms:
	MSysTick_vSetBusyWait( 600 ) ;

	// Send color mode CMD -> RGB565:
	HTFT_vWriteCMD( COLOR_MODE_CMD  ) ;
	HTFT_vWriteData( RGB565_CMD ) ;

	// DISPON CMD (0X29):
	HTFT_vWriteCMD( DISPON_CMD ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HTFT_vShowImage( u16 const *A_u16Image, u32 A_u32ImageSize )
{

	// Set X position:
	HTFT_vWriteCMD( XPOSITION_CMD ) ;
	// Xstart: 0, Xend: 127
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( 127 ) ;

	// Set Y position:
	HTFT_vWriteCMD( YPOSITION_CMD ) ;
	// Ystart: 0, Yend: 127
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( 159 ) ;

	// Send image data:
	HTFT_vWriteCMD( MEMORY_WRITE_CMD ) ;

	for( u8 PX = 0; PX < A_u32ImageSize; PX++ )
	{

		HTFT_vWriteData( A_u16Image[PX] >> 8 	) ; // MSB
		HTFT_vWriteData( A_u16Image[PX] & 0x00FF  ) ; // LSB

	}

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HTFT_vSetXPosition( u16 A_u16XStart, u16 A_u16XEnd )
{

	CurrentXStart 	= A_u16XStart ;
	CurrentXEnd 	= A_u16XEnd ;

	HTFT_vWriteCMD( XPOSITION_CMD ) ;
	// Xstart: 0, Xend: 127
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( A_u16XStart ) ;
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( A_u16XEnd ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HTFT_vSetYPosition( u16 A_u16YStart, u16 A_u16YEnd )
{

	CurrentYStart 	= A_u16YStart ;
	CurrentYEnd 	= A_u16YEnd ;

	HTFT_vWriteCMD( YPOSITION_CMD ) ;
	// Ystart: 0, Yend: 127
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( A_u16YStart ) ;
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( A_u16YEnd ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HTFT_vFillRectangle( u16 A_u16Color )
{

	u32 PXLS_Num = (CurrentXEnd-CurrentXStart) * (CurrentYEnd-CurrentYStart) ;

	HTFT_vWriteCMD( MEMORY_WRITE_CMD ) ;

	for( u8 PX = 0; PX < PXLS_Num ; PX++ )
	{

		HTFT_vWriteData( A_u16Color >> 8 	) ; // MSB
		HTFT_vWriteData( A_u16Color & 0x00FF  ) ; // LSB

	}

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HTFT_vFillBackground( u16 A_u16Color )
{

	// Set X position:
	HTFT_vWriteCMD( XPOSITION_CMD ) ;
	// Xstart: 0, Xend: 127
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( 127 ) ;

	// Set Y position:
	HTFT_vWriteCMD( YPOSITION_CMD ) ;
	// Ystart: 0, Yend: 127
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( 159 ) ;

	HTFT_vFillRectangle( A_u16Color ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/








