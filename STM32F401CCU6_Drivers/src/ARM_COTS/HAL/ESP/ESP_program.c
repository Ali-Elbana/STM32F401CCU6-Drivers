/* FILENAME: ESP_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Mon 10/17/2022
*/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBITMATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/UART/UART_interface.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"




/*******************************************************************************************************************/
/******************************************************************************************************************/

u8 u8ESPValidateCMD( void )
{

	u8 L_u8Response[100] = {0} ;

	u8 i = 0 ;

	u8 dummy = 0 ;

	u8 result = 0 ;

	while( dummy != 255 )
	{

		dummy = MUSART_u8ReceiveByteSynchNonBlocking(USART1_REG) ;

		 L_u8Response[i] = dummy ;

		i++ ;

	}

	// check if ok
	if( L_u8Response[0] == 'O' && L_u8Response[1] == 'K' )
	{
		result = 1 ;
	}

	return result ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MESP_vInit(void)
{

	u8 L_u8uResult = Initialized_by_Zero ;

	USART_InitType MyUART1 =
	{

		.BaudRate  				= 115200 		,

		.DataWidth 				= MODE_8BIT 	,

		.StopBits  				= STOP_BIT_1 	,

		.Parity_Enable 			= DISABLE 		,

		.Parity_Selection 		= EVEN_PARITY 	,

		.TransferDirection 		= TX_RX			,

		.HardwareFlowControl 	= DISABLE 		,

		.Oversampling 			= OVER_SAMPLING_16

	} ;

	USART_ClockInitTypeDef MyUARTCLK = { DISABLE, 0, 0, 0 } ;

	// Initialization of USART1
	MUSART_vInit( &MyUART1, &MyUARTCLK, USART1_REG ) ;


	while( L_u8uResult == 0 )
	{
		// Stop the ECHO:
		MUSART_vTransmitString( USART1_REG, "ATE0\r\n" ) ;

		L_u8uResult = u8ESPValidateCMD(  ) ;
	}

	L_u8uResult = 0 ;

	while( L_u8uResult == 0 )
	{
		//Select the mode:
		MUSART_vTransmitString( USART1_REG, "AT+CWMODE=1\r\n" ) ;

		L_u8uResult = u8ESPValidateCMD(  ) ;
	}

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MESP_vConnectToAccessPoint( c8* ssid, c8* password )
{

	MUSART_vTransmitString( USART1_REG, "AT+CWJAP_CUR=\"" ) ;
	MUSART_vTransmitString( USART1_REG, ssid ) ;
	MUSART_vTransmitString( USART1_REG, "\",\"" ) ;
	MUSART_vTransmitString( USART1_REG, password ) ;
	MUSART_vTransmitString( USART1_REG, "\"\r\n" ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MESP_vOpenServerTCPConnection( c8* serverip, c8* portnum )
{

	MUSART_vTransmitString( USART1_REG, "AT+CIPSTART=\"TCP\",\"" ) ;
	MUSART_vTransmitString( USART1_REG, serverip ) ;
	MUSART_vTransmitString( USART1_REG, "\"," ) ;
	MUSART_vTransmitString( USART1_REG, portnum ) ;
	MUSART_vTransmitString( USART1_REG, "\r\n" ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MESP_vSendHttpRequest( c8* url, c8* length )
{

	MUSART_vTransmitString( USART1_REG, "AT+CIPSEND=" ) ;
	MUSART_vTransmitString( USART1_REG, length ) ;
	MUSART_vTransmitString( USART1_REG, "\r\n" ) ;

	// Delay 1 or 2 seconds.

	MUSART_vTransmitString( USART1_REG, url ) ;
	MUSART_vTransmitString( USART1_REG, "\r\n" ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/



















