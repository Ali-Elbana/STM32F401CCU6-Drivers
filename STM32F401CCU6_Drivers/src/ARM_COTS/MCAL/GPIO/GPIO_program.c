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



void MGPIOx_vSetPinMode( u8 A_u8PortID, u8 A_u8PinID, u8 A_u8Mode )
{

	switch( A_u8PortID )
	{

		case GPIO_PORTA:

			CLR_BITs( GPIOA->MODER, 0b11, A_u8PinID, 2 ) ;
			SET_BITs( GPIOA->MODER, A_u8Mode, A_u8PinID, 2 ) ;

		break ;


		case GPIO_PORTB:

			CLR_BITs( GPIOB->MODER, 0b11, A_u8PinID, 2 ) ;
			SET_BITs( GPIOB->MODER, A_u8Mode, A_u8PinID, 2 ) ;

		break ;


		case GPIO_PORTC:

			CLR_BITs( GPIOC->MODER, 0b11, A_u8PinID, 2 ) ;
			SET_BITs( GPIOC->MODER, A_u8Mode, A_u8PinID, 2 ) ;

		break ;

	}


}

/******************************************************************/
/******************************************************************/

void MGPIOx_vSetPinOutputType( u8 A_u8PortID, u8 A_u8PinID, u8 A_u8OutputType )
{

	switch( A_u8OutputType )
	{

		case GPIOx_OPENDRAIN:

			switch( A_u8PortID )
			{

				case GPIO_PORTA:

					SET_BIT( GPIOA->OTYPER, A_u8PinID ) ;

				break ;


				case GPIO_PORTB:

					SET_BIT( GPIOB->OTYPER, A_u8PinID ) ;

				break ;


				case GPIO_PORTC:

					SET_BIT( GPIOC->OTYPER, A_u8PinID ) ;

				break ;

			}

		break;


			case GPIOx_PUSHPULL:

				switch( A_u8PortID )
				{

					case GPIO_PORTA:

						CLR_BIT( GPIOA->OTYPER, A_u8PinID ) ;

					break ;


					case GPIO_PORTB:

						CLR_BIT( GPIOB->OTYPER, A_u8PinID ) ;

					break ;


					case GPIO_PORTC:

						CLR_BIT( GPIOC->OTYPER, A_u8PinID ) ;

					break ;

				}

			break;

	}

}

/******************************************************************/
/******************************************************************/

void MGPIOx_vSetPinOutputSpeed( u8 A_u8PortID, u8 A_u8PinID, u8 A_u8OutputSpeed )
{

	switch( A_u8PortID )
	{

		case GPIO_PORTA:

			CLR_BITs( GPIOA->OSPEEDR, 0b11, A_u8PinID, 2 ) ;
			SET_BITs( GPIOA->OSPEEDR, A_u8OutputSpeed, A_u8PinID, 2 ) ;

		break ;


		case GPIO_PORTB:

			CLR_BITs( GPIOB->OSPEEDR, 0b11, A_u8PinID, 2 ) ;
			SET_BITs( GPIOB->OSPEEDR, A_u8OutputSpeed, A_u8PinID, 2 ) ;

		break ;


		case GPIO_PORTC:

			CLR_BITs( GPIOC->OSPEEDR, 0b11, A_u8PinID, 2 ) ;
			SET_BITs( GPIOC->OSPEEDR, A_u8OutputSpeed, A_u8PinID, 2 ) ;

		break ;

	}


}

/******************************************************************/
/******************************************************************/

void MGPIOx_vSetPinInputPullType( u8 A_u8PortID, u8 A_u8PinID, u8 A_u8InputPullType )
{

	switch( A_u8PortID )
	{

		case GPIO_PORTA:

			CLR_BITs( GPIOA->PUPDR, 0b11, A_u8PinID, 2 ) ;
			SET_BITs( GPIOA->PUPDR, A_u8InputPullType, A_u8PinID, 2 ) ;

		break ;


		case GPIO_PORTB:

			CLR_BITs( GPIOB->PUPDR, 0b11, A_u8PinID, 2 ) ;
			SET_BITs( GPIOB->PUPDR, A_u8InputPullType, A_u8PinID, 2 ) ;

		break ;


		case GPIO_PORTC:

			CLR_BITs( GPIOC->PUPDR, 0b11, A_u8PinID, 2 ) ;
			SET_BITs( GPIOC->PUPDR, A_u8InputPullType, A_u8PinID, 2 ) ;

		break ;

	}


}

/******************************************************************/
/******************************************************************/

u8 MGPIOx_u8GetPinValue( u8 A_u8PortID, u8 A_u8PinID )
{

	u8 L_u8PinValue = Initialized_by_Zero ;

	switch( A_u8PortID )
	{

		case GPIO_PORTA:

			L_u8PinValue = GET_BIT( GPIOA->IDR, A_u8PinID ) ;

		break ;


		case GPIO_PORTB:

			L_u8PinValue = GET_BIT( GPIOB->IDR, A_u8PinID ) ;

		break ;


		case GPIO_PORTC:

			L_u8PinValue = GET_BIT( GPIOC->IDR, A_u8PinID ) ;

		break ;

	}

	return L_u8PinValue ;

}

/******************************************************************/
/******************************************************************/

void MGPIOx_vSetPinValue( u8 A_u8PortID, u8 A_u8PinID, u8 A_u8PinValue )
{

	switch( A_u8PinValue )
	{

		case GPIOx_HIGH:

			switch( A_u8PortID )
			{

				case GPIO_PORTA:

					SET_BIT( GPIOA->ODR, A_u8PinID ) ;

				break ;


				case GPIO_PORTB:

					SET_BIT( GPIOB->ODR, A_u8PinID ) ;

				break ;


				case GPIO_PORTC:

					SET_BIT( GPIOC->ODR, A_u8PinID ) ;

				break ;

			}

		break;


			case GPIOx_LOW:

				switch( A_u8PortID )
				{

					case GPIO_PORTA:

						CLR_BIT( GPIOA->ODR, A_u8PinID ) ;

					break ;


					case GPIO_PORTB:

						CLR_BIT( GPIOB->ODR, A_u8PinID ) ;

					break ;


					case GPIO_PORTC:

						CLR_BIT( GPIOC->ODR, A_u8PinID ) ;

					break ;

				}

			break;

	}


}

/******************************************************************/
/******************************************************************/

void MGPIOx_vSetResetPinValue( u8 A_u8PortID, u8 A_u8PinID, u8 A_u8SetResetPinValue )
{




}

/******************************************************************/
/******************************************************************/

void MGPIOx_vSetAlternateFunctionON( u8 A_u8PortID, u8 A_u8PinID, u8 A_u8AFID )
{





}

/******************************************************************/
/******************************************************************/




























