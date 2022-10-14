/* FILENAME: SysTick_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Sun 09/04/2022
*/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBITMATH.h"

#include "SysTick_interface.h"
#include "SysTick_private.h"
#include "SysTick_config.h"


static void (*GS_vCallbackFunc) ( void ) = NULL ;

static u8 GS_u8MyIntervalMode = Initialized_by_Zero ;

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MSysTick_vInit( void )
{

	// Choose the input CLK source.
	#if CLK_SOURCE == AHB_DividedBy8

		CLR_BIT( SysTick->CTRL, CLKSOURCE ) ;

	#elif CLK_SOURCE == AHB

		SET_BIT( SysTick->CTRL, CLKSOURCE ) ;

	#endif

	// SysTick exception request enable.
	#if Exception_Request == Dont_AssertRequest

			CLR_BIT( SysTick->CTRL, TICKINT ) ;

	#elif Exception_Request == AssertRequest

			SET_BIT( SysTick->CTRL, TICKINT ) ;

	#endif


	// Enable the peripheral interrupt.
	SET_BIT( SysTick->CTRL, COUNTER_ENABLE ) ;


}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MSysTick_vSetBusyWait( u32 A_u32Ticks )
{

	// Load Ticks to the load register.
	SysTick->LOAD = A_u32Ticks ;

	// Start Timer.
	SET_BIT( SysTick->CTRL, COUNTER_ENABLE ) ;

	// Wait till the flag is raised.
	while( GET_BIT( SysTick->CTRL, COUNTFLAG ) != Flag_is_Set ) ;

	// Stop the timer.
	CLR_BIT( SysTick->CTRL, COUNTER_ENABLE ) ;

	// Clear the LOAD and VAL registers
	SysTick->LOAD = Initialized_by_Zero ;
	SysTick->VAL  = Initialized_by_Zero ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MSysTick_vSetSingleInterval( u32 A_u32Ticks, void (*A_Fptr) (void) )
{

	// Save the callback.
	GS_vCallbackFunc = A_Fptr ;

	// Load Ticks to the load register.
	SysTick->LOAD = A_u32Ticks ;

	// Start Timer.
	SET_BIT( SysTick->CTRL, COUNTER_ENABLE ) ;

	// Set interval mode to single.
	GS_u8MyIntervalMode = SINGLE_INTERVAL_MODE ;

	// Enable the IRQ.
	SET_BIT( SysTick->CTRL, TICKINT ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MSysTick_vSetPeriodicInterval( u32 A_u32Ticks, void (*A_Fptr) (void) )
{

	// Save the callback.
	GS_vCallbackFunc = A_Fptr ;

	// Load Ticks to the load register.
	SysTick->LOAD = A_u32Ticks ;

	// Start Timer.
	SET_BIT( SysTick->CTRL, COUNTER_ENABLE ) ;

	// Set interval mode to single.
	GS_u8MyIntervalMode = PERIODIC_INTERVAL_MODE ;

	// Enable the IRQ.
	SET_BIT( SysTick->CTRL, TICKINT ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MSysTick_vStopInterval( void )
{

	// Disable the IRQ.
	CLR_BIT( SysTick->CTRL, TICKINT ) ;

	// Stop the timer.
	CLR_BIT( SysTick->CTRL, COUNTER_ENABLE ) ;

	// Clear the LOAD and VAL registers
	SysTick->LOAD = Initialized_by_Zero ;
	SysTick->VAL  = Initialized_by_Zero ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

u32 MSysTick_u32GetElapsedTime( void )
{

	u32 L_u32ElapsedTime = Initialized_by_Zero ;

	L_u32ElapsedTime = (SysTick->LOAD - SysTick->VAL) ;

	return L_u32ElapsedTime ;
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

u32 MSysTick_u32GetRemainingTime( void )
{

	u32 L_u32RemainingTime = Initialized_by_Zero ;

	L_u32RemainingTime = SysTick->VAL ;

	return L_u32RemainingTime ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MSysTick_vEnable( void )
{

	// Enable the peripheral interrupt.
	SET_BIT( SysTick->CTRL, COUNTER_ENABLE ) ;

	// Start Timer.
	SET_BIT( SysTick->CTRL, COUNTER_ENABLE ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MSysTick_vDisable( void )
{

	// Disable the peripheral interrupt.
	CLR_BIT( SysTick->CTRL, COUNTER_ENABLE ) ;

	// Stop the timer.
	CLR_BIT( SysTick->CTRL, COUNTER_ENABLE ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void SysTick_Handler( void )
{

	volatile u8 L_u8ReadFlag = Initialized_by_Zero ;


	if( GS_vCallbackFunc != NULL )
	{

		// Callback notification.
		GS_vCallbackFunc( ) ;

	}

	if( GS_u8MyIntervalMode == SINGLE_INTERVAL_MODE )
	{

		// Disable the IRQ.
		CLR_BIT( SysTick->CTRL, TICKINT ) ;

		// Stop the timer.
		CLR_BIT( SysTick->CTRL, COUNTER_ENABLE ) ;

		// Clear the LOAD and VAL registers
		SysTick->LOAD = Initialized_by_Zero ;
		SysTick->VAL  = Initialized_by_Zero ;

		GS_u8MyIntervalMode = PERIODIC_INTERVAL_MODE ;

	}

	// Clear IRQ flag.
	L_u8ReadFlag = GET_BIT( SysTick->CTRL, COUNTFLAG ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/


