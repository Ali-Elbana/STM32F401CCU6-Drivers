/* FILENAME: DAC_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Sat 09/24/2022
*/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBITMATH.h"


#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"

#include "../../MCAL/GPIO/GPIO_interface.h"

extern MGPIOx_ConfigType DAC_PINs[ DAC_RESOLUTION ] ;

void HDAC_vInit(void)
{

	for( u8 i = 0; i < DAC_RESOLUTION; i++ )
	{

		MGPIOx_vInit( &DAC_PINs[ i ] ) ;

	}

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HDAC_vAnalogWrite( u8 A_u8Signal )
{

	for( u8 i = 0; i < DAC_RESOLUTION; i++ )
	{

		MGPIOx_vSetPinValue( DAC_PINs[i].Port, DAC_PINs[i].Pin,
							 GET_BIT( A_u8Signal, i ) ) ;

	}

}

/*******************************************************************************************************************/
/******************************************************************************************************************/












