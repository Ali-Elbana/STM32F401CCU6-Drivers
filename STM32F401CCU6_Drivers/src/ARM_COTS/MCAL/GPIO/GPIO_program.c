/* FILENAME: GPIO_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Mon 08/22/2022
*/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBITMATH.h"


#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"



/**************************************************************************************/
/**************************************************************************************/

void MGPIOx_vSetPinMode( u8 A_u8PortID, u8 A_u8PinID, u8 A_u8Mode )
{

	switch( A_u8PortID )
	{

		case GPIO_PORTA:

			CLR_BITs( GPIOA->MODERx, 0b11, A_u8PinID, 2 ) ;
			SET_BITs( GPIOA->MODERx, A_u8Mode, A_u8PinID, 2 ) ;

		break ;


		case GPIO_PORTB:

			CLR_BITs( GPIOB->MODERx, 0b11, A_u8PinID, 2 ) ;
			SET_BITs( GPIOB->MODERx, A_u8Mode, A_u8PinID, 2 ) ;

		break ;


		case GPIO_PORTC:

			CLR_BITs( GPIOC->MODERx, 0b11, A_u8PinID, 2 ) ;
			SET_BITs( GPIOC->MODERx, A_u8Mode, A_u8PinID, 2 ) ;

		break ;

	}


}

/**************************************************************************************/
/**************************************************************************************/

void MGPIOx_vSetPinOutputType( u8 A_u8PortID, u8 A_u8PinID, u8 A_u8OutputType )
{

	switch( A_u8OutputType )
	{

		case GPIOx_OPENDRAIN:

			switch( A_u8PortID )
			{

				case GPIO_PORTA:

					SET_BIT( GPIOA->OTYPERx, A_u8PinID ) ;

				break ;


				case GPIO_PORTB:

					SET_BIT( GPIOB->OTYPERx, A_u8PinID ) ;

				break ;


				case GPIO_PORTC:

					SET_BIT( GPIOC->OTYPERx, A_u8PinID ) ;

				break ;

			}

		break;


			case GPIOx_PUSHPULL:

				switch( A_u8PortID )
				{

					case GPIO_PORTA:

						CLR_BIT( GPIOA->OTYPERx, A_u8PinID ) ;

					break ;


					case GPIO_PORTB:

						CLR_BIT( GPIOB->OTYPERx, A_u8PinID ) ;

					break ;


					case GPIO_PORTC:

						CLR_BIT( GPIOC->OTYPERx, A_u8PinID ) ;

					break ;

				}

			break;

	}

}

/**************************************************************************************/
/**************************************************************************************/

void MGPIOx_vSetPinOutputSpeed( u8 A_u8PortID, u8 A_u8PinID, u8 A_u8OutputSpeed )
{

	switch( A_u8PortID )
	{

		case GPIO_PORTA:

			CLR_BITs( GPIOA->OSPEEDRx, 0b11, A_u8PinID, 2 ) ;
			SET_BITs( GPIOA->OSPEEDRx, A_u8OutputSpeed, A_u8PinID, 2 ) ;

		break ;


		case GPIO_PORTB:

			CLR_BITs( GPIOB->OSPEEDRx, 0b11, A_u8PinID, 2 ) ;
			SET_BITs( GPIOB->OSPEEDRx, A_u8OutputSpeed, A_u8PinID, 2 ) ;

		break ;


		case GPIO_PORTC:

			CLR_BITs( GPIOC->OSPEEDRx, 0b11, A_u8PinID, 2 ) ;
			SET_BITs( GPIOC->OSPEEDRx, A_u8OutputSpeed, A_u8PinID, 2 ) ;

		break ;

	}


}

/**************************************************************************************/
/**************************************************************************************/

void MGPIOx_vSetPinInputPullType( u8 A_u8PortID, u8 A_u8PinID, u8 A_u8InputPullType )
{

	switch( A_u8PortID )
	{

		case GPIO_PORTA:

			CLR_BITs( GPIOA->PUPDRx, 0b11, A_u8PinID, 2 ) ;
			SET_BITs( GPIOA->PUPDRx, A_u8InputPullType, A_u8PinID, 2 ) ;

		break ;


		case GPIO_PORTB:

			CLR_BITs( GPIOB->PUPDRx, 0b11, A_u8PinID, 2 ) ;
			SET_BITs( GPIOB->PUPDRx, A_u8InputPullType, A_u8PinID, 2 ) ;

		break ;


		case GPIO_PORTC:

			CLR_BITs( GPIOC->PUPDRx, 0b11, A_u8PinID, 2 ) ;
			SET_BITs( GPIOC->PUPDRx, A_u8InputPullType, A_u8PinID, 2 ) ;

		break ;

	}


}

/**************************************************************************************/
/**************************************************************************************/

u8 MGPIOx_u8GetPinValue( u8 A_u8PortID, u8 A_u8PinID )
{

	u8 L_u8PinValue = Initialized_by_Zero ;

	switch( A_u8PortID )
	{

		case GPIO_PORTA:

			L_u8PinValue = GET_BIT( GPIOA->IDRx, A_u8PinID ) ;

		break ;


		case GPIO_PORTB:

			L_u8PinValue = GET_BIT( GPIOB->IDRx, A_u8PinID ) ;

		break ;


		case GPIO_PORTC:

			L_u8PinValue = GET_BIT( GPIOC->IDRx, A_u8PinID ) ;

		break ;

	}

	return L_u8PinValue ;

}

/**************************************************************************************/
/**************************************************************************************/

void MGPIOx_vSetPinValue( u8 A_u8PortID, u8 A_u8PinID, u8 A_u8PinValue )
{

	switch( A_u8PinValue )
	{

		case GPIOx_HIGH:

			switch( A_u8PortID )
			{

				case GPIO_PORTA:

					SET_BIT( GPIOA->ODRx, A_u8PinID ) ;

				break ;


				case GPIO_PORTB:

					SET_BIT( GPIOB->ODRx, A_u8PinID ) ;

				break ;


				case GPIO_PORTC:

					SET_BIT( GPIOC->ODRx, A_u8PinID ) ;

				break ;

			}

		break;


		case GPIOx_LOW:

			switch( A_u8PortID )
			{

				case GPIO_PORTA:

					CLR_BIT( GPIOA->ODRx, A_u8PinID ) ;

				break ;


				case GPIO_PORTB:

					CLR_BIT( GPIOB->ODRx, A_u8PinID ) ;

				break ;


				case GPIO_PORTC:

					CLR_BIT( GPIOC->ODRx, A_u8PinID ) ;

				break ;

			}

		break;

	}


}

/**************************************************************************************/
/**************************************************************************************/

void MGPIOx_vSetResetPinValue( u8 A_u8PortID, u8 A_u8PinID, u8 A_u8SetResetPinValue )
{




}

/**************************************************************************************/
/**************************************************************************************/

void MGPIOx_vSetAlternateFunctionON( u8 A_u8PortID, u8 A_u8PinID, u8 A_u8AFID )
{





}

/**************************************************************************************/
/**************************************************************************************/

void MGPIOx_vInit( MGPIOx_ConfigType* A_xPinConfig )
{

	MGPIOx_vSetPinMode			( A_xPinConfig->Port, A_xPinConfig->Pin, A_xPinConfig->Mode ) ;

	MGPIOx_vSetPinOutputType   	( A_xPinConfig->Port, A_xPinConfig->Pin, A_xPinConfig->OutputType ) ;

	MGPIOx_vSetPinOutputSpeed  	( A_xPinConfig->Port, A_xPinConfig->Pin, A_xPinConfig->OutputSpeed ) ;

	MGPIOx_vSetPinInputPullType	( A_xPinConfig->Port, A_xPinConfig->Pin, A_xPinConfig->InputType ) ;

	//MGPIOx_vSetAlternateFunctionON(  ) ;

}

/**************************************************************************************/
/**************************************************************************************/
























