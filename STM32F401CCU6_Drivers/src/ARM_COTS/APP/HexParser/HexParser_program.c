/* FILENAME: HexParser_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Sat 10/22/2022
*/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBITMATH.h"

#include "../../MCAL/Flash_Driver/Flash_Driver_interface.h"

#include "HexParser_interface.h"
#include "HexParser_private.h"
#include "HexParser_config.h"


u16 G_u16DataBuffer[100] ;



/******************************************************************/
/******************************************************************/

static u8 AHexparser_u8ASCIItoHex( u8 A_u8ASCII )
{

	u8 L_u8HexValue = 0 ;

	if( A_u8ASCII >= '0' && A_u8ASCII <= '9' )
	{
		L_u8HexValue = A_u8ASCII - '0' ;
	}

	else if( A_u8ASCII >= 'A' && A_u8ASCII <= 'F' )
	{
		L_u8HexValue = A_u8ASCII - 55 ;
	}

	return L_u8HexValue ;
}

/******************************************************************/
/******************************************************************/

void AHexParser_vParseData( u8 A_u8Data[] )
{

	// Char count variables:
	u8 L_u8CC_High, L_u8CC_Low, L_u8CC ;

	// Address variables:
	u32 L_u32Address = 0 ;

	// 4 digits for conversion:
	u8 L_u8Digit0, L_u8Digit1, L_u8Digit2, L_u8Digit3 ;

	// Convert Char count:
	L_u8CC_High = AHexparser_u8ASCIItoHex( A_u8Data[1] ) ;
	L_u8CC_Low  = AHexparser_u8ASCIItoHex( A_u8Data[2] ) ;
	L_u8CC = ( L_u8CC_High << 4 ) | L_u8CC_Low ;

	// Convert address:
	L_u8Digit0 = AHexparser_u8ASCIItoHex( A_u8Data[3] ) ;
	L_u8Digit1 = AHexparser_u8ASCIItoHex( A_u8Data[4] ) ;
	L_u8Digit2 = AHexparser_u8ASCIItoHex( A_u8Data[5] ) ;
	L_u8Digit3 = AHexparser_u8ASCIItoHex( A_u8Data[6] ) ;

	L_u32Address = FLASH_BASE_ADDRESS | (L_u8Digit0 << 12) |
				   (L_u8Digit1 << 8)  | (L_u8Digit2 << 4)  |
				   (L_u8Digit3) ;

	for( u8 i = 0; i < (L_u8CC / 2); i++ )
	{

		L_u8Digit0 = AHexparser_u8ASCIItoHex( A_u8Data[(4 * i) + 9 ] ) ;
		L_u8Digit1 = AHexparser_u8ASCIItoHex( A_u8Data[(4 * i) + 10] ) ;
		L_u8Digit2 = AHexparser_u8ASCIItoHex( A_u8Data[(4 * i) + 11] ) ;
		L_u8Digit3 = AHexparser_u8ASCIItoHex( A_u8Data[(4 * i) + 12] ) ;

		G_u16DataBuffer[i] = (L_u8Digit0 << 12) | (L_u8Digit1 << 8) |
					   	     (L_u8Digit2 << 4)  | (L_u8Digit3) ;

	}

	MFlash_vWrite( L_u32Address, G_u16DataBuffer, L_u8CC / 2 ) ;

}

/******************************************************************/
/******************************************************************/





/******************************************************************/
/******************************************************************/





