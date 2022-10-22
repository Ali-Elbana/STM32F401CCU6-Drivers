/*
 * MRCC_program.c
 *
 *  Created on: Aug 16, 2022
 *      Author: Ali El Bana
 */



#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBITMATH.h"

#include "MRCC_private.h"
#include "MRCC_interface.h"
#include "MRCC_config.h"



/******************************************************************/
/******************************************************************/

void MRCC_vInit( void )
{

	// PLLI2S (ON/OFF).
	#if PLLI2S == ENABLE

		SET_BIT( RCC->CR, RCC_CR_PLLI2SON ) ;

	#elif PLLI2S == DISABLE

		CLR_BIT( RCC->CR, RCC_CR_PLLI2SON ) ;

	#endif


	// PLL (ON/OFF).
	#if PLL == ENABLE

		SET_BIT( RCC->CR, RCC_CR_PLLON ) ;

	#elif PLL == DISABLE

		CLR_BIT( RCC->CR, RCC_CR_PLLON ) ;

	#endif


	// CSS (ON/OFF).
	#if CSS == ENABLE

		SET_BIT( RCC->CR, RCC_CR_CSSON ) ;

	#elif CSS == DISABLE

		CLR_BIT( RCC->CR, RCC_CR_CSSON ) ;

	#endif


	// HSEBYP.
	#if HSEBYP == BYBASED

		SET_BIT( RCC->CR, RCC_CR_HSEBYP ) ;

	#elif HSEBYP == NOTBYBASED

		CLR_BIT( RCC->CR, RCC_CR_HSEBYP ) ;

	#endif


	// Select CLK switch (HSI/HSE/PLL).
	#if SW == HSI

		CLR_BIT( RCC->CFGR, RCC_CFGR_SW_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_SW_b1 ) ;

	#elif SW == HSE

		CLR_BIT( RCC->CFGR, RCC_CFGR_SW_b0 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_SW_b1 ) ;

	#elif SW == PLLCLK

		SET_BIT( RCC->CFGR, RCC_CFGR_SW_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_SW_b1 ) ;

	#endif



	// 4-Bus prescalers.

	// 5-PLL configurations.




	// Enable the selected CLK (HSI ON/HSE ON/PLL ON) //

	// HSE (ON/OFF).
	#if HSE_EN == ENABLE

		SET_BIT( RCC->CR, RCC_CR_HSEON ) ;

	#elif HSE_EN == DISABLE

		CLR_BIT( RCC->CR, RCC_CR_HSEON ) ;

	#endif


	// HSI (ON/OFF).
	#if HSI_EN == ENABLE

		SET_BIT( RCC->CR, RCC_CR_HSION ) ;

	#elif HSI_EN == DISABLE

		CLR_BIT( RCC->CR, RCC_CR_HSION ) ;

	#endif



}

/******************************************************************/
/******************************************************************/

void MRCC_vEnablePeriphralCLK( u32 A_u32BusID, u32 A_u32PeriphralID )
{

	switch( A_u32BusID )
	{

		case RCC_AHB1 :

			SET_BIT( RCC->AHB1ENR, A_u32PeriphralID ) ;

		break ;


		case RCC_AHB2 :

			SET_BIT( RCC->AHB2ENR, A_u32PeriphralID ) ;


		break ;


		case RCC_APB1 :

			SET_BIT( RCC->APB1ENR, A_u32PeriphralID ) ;

		break ;


		case RCC_APB2 :

			SET_BIT( RCC->APB2ENR, A_u32PeriphralID ) ;

		break ;

		case RCC_AHB1LPENR:

			SET_BIT( RCC->AHB1LPENR, A_u32PeriphralID ) ;

		break ;

		default:

			// Error wrong Bus ID

		break ;

	}

}

/******************************************************************/
/******************************************************************/

void MRCC_vDisablePeriphralCLK(  u32 A_u32BusID, u32 A_u32PeriphralID )
{

	switch( A_u32BusID )
	{

		case RCC_AHB1 :

			CLR_BIT( RCC->AHB1ENR, A_u32PeriphralID ) ;

		break ;


		case RCC_AHB2 :

			CLR_BIT( RCC->AHB2ENR, A_u32PeriphralID ) ;


		break ;


		case RCC_APB1 :

			CLR_BIT( RCC->APB1ENR, A_u32PeriphralID ) ;

		break ;


		case RCC_APB2 :

			CLR_BIT( RCC->APB2ENR, A_u32PeriphralID ) ;

		break ;


		default:

			// Error wrong Bus ID

		break ;

	}

}

/******************************************************************/
/******************************************************************/









