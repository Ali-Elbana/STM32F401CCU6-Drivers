/* FILENAME: EXTI_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Fri 09/02/2022
*/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBITMATH.h"


#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"





/*******************************************************************************************************************/
/******************************************************************************************************************/

void MEXTI_vInit( void )
{

	u8 L_u8ShiftedOffset = Initialized_by_Zero ;


	#if EXTI_LINE0_EN == ENABLE

		L_u8ShiftedOffset = 0 ;

	#elif EXTI_LINE1_EN == ENABLE

		L_u8ShiftedOffset = 1 ;

	#elif EXTI_LINE2_EN == ENABLE

		L_u8ShiftedOffset = 2 ;

	#elif EXTI_LINE3_EN == ENABLE

		L_u8ShiftedOffset = 3 ;

	#elif EXTI_LINE4_EN == ENABLE

		L_u8ShiftedOffset = 4 ;

	#elif EXTI_LINE5_EN == ENABLE

		L_u8ShiftedOffset = 5 ;

	#elif EXTI_LINE6_EN == ENABLE

		L_u8ShiftedOffset = 6 ;

	#elif EXTI_LINE7_EN == ENABLE

		L_u8ShiftedOffset = 7 ;

	#elif EXTI_LINE8_EN == ENABLE

		L_u8ShiftedOffset = 8 ;

	#elif EXTI_LINE9_EN == ENABLE

		L_u8ShiftedOffset = 9 ;

	#elif EXTI_LINE10_EN == ENABLE

		L_u8ShiftedOffset = 10 ;

	#elif EXTI_LINE11_EN == ENABLE

		L_u8ShiftedOffset = 11 ;

	#elif EXTI_LINE12_EN == ENABLE

		L_u8ShiftedOffset = 12 ;

	#elif EXTI_LINE13_EN == ENABLE

		L_u8ShiftedOffset = 13 ;

	#elif EXTI_LINE14_EN == ENABLE

		L_u8ShiftedOffset = 14 ;


	#elif EXTI_LINE15_EN == ENABLE

		L_u8ShiftedOffset = 15 ;


	#endif

	// Clear all flags.
	MEXTI->PR = 0xffffffff ;

	// Enable EXTI on a line.
	MEXTI->IMR = 0 ;

	MEXTI->IMR = ( ENABLE << L_u8ShiftedOffset ) ;

	// Set EXTI Triggered status on a line.
	#if EXTI_LINE0_TRIGGER == EXTI_RisingEdge

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE0_TRIGGER == EXTI_FallingEdge

				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE0_TRIGGER == EXTI_OnChange

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;
				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

///////////////////////////////////////////////////////////
	#elif EXTI_LINE1_TRIGGER == EXTI_RisingEdge

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE1_TRIGGER == EXTI_FallingEdge

				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE1_TRIGGER == EXTI_OnChange

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;
				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

///////////////////////////////////////////////////////////
	#elif EXTI_LINE2_TRIGGER == EXTI_RisingEdge

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE2_TRIGGER == EXTI_FallingEdge

				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE2_TRIGGER == EXTI_OnChange

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;
				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

///////////////////////////////////////////////////////////
	#elif EXTI_LINE3_TRIGGER == EXTI_RisingEdge

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE3_TRIGGER == EXTI_FallingEdge

				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE3_TRIGGER == EXTI_OnChange

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;
				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

///////////////////////////////////////////////////////////
	#elif EXTI_LINE4_TRIGGER == EXTI_RisingEdge

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE4_TRIGGER == EXTI_FallingEdge

				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE4_TRIGGER == EXTI_OnChange

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;
				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

///////////////////////////////////////////////////////////
	#elif EXTI_LINE5_TRIGGER == EXTI_RisingEdge

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE5_TRIGGER == EXTI_FallingEdge

				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE5_TRIGGER == EXTI_OnChange

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;
				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

//////////////////////////////////////////////////////////
	#elif EXTI_LINE6_TRIGGER == EXTI_RisingEdge

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE6_TRIGGER == EXTI_FallingEdge

				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE6_TRIGGER == EXTI_OnChange

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;
				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

//////////////////////////////////////////////////////////
	#elif EXTI_LINE7_TRIGGER == EXTI_RisingEdge

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE7_TRIGGER == EXTI_FallingEdge

				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE7_TRIGGER == EXTI_OnChange

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;
				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

//////////////////////////////////////////////////////////
	#elif EXTI_LINE8_TRIGGER == EXTI_RisingEdge

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE8_TRIGGER == EXTI_FallingEdge

				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE8_TRIGGER == EXTI_OnChange

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;
				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

/////////////////////////////////////////////////////////
	#elif EXTI_LINE9_TRIGGER == EXTI_RisingEdge

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE9_TRIGGER == EXTI_FallingEdge

				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE9_TRIGGER == EXTI_OnChange

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;
				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

/////////////////////////////////////////////////////////
	#elif EXTI_LINE10_TRIGGER == EXTI_RisingEdge

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE10_TRIGGER == EXTI_FallingEdge

				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE10_TRIGGER == EXTI_OnChange

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;
				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

/////////////////////////////////////////////////////////
	#elif EXTI_LINE11_TRIGGER == EXTI_RisingEdge

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE11_TRIGGER == EXTI_FallingEdge

				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE11_TRIGGER == EXTI_OnChange

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;
				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

////////////////////////////////////////////////////////
	#elif EXTI_LINE12_TRIGGER == EXTI_RisingEdge

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE12_TRIGGER == EXTI_FallingEdge

				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE12_TRIGGER == EXTI_OnChange

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;
				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

///////////////////////////////////////////////////////
	#elif EXTI_LINE13_TRIGGER == EXTI_RisingEdge

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE13_TRIGGER == EXTI_FallingEdge

				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE13_TRIGGER == EXTI_OnChange

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;
				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

///////////////////////////////////////////////////////
	#elif EXTI_LINE14_TRIGGER == EXTI_RisingEdge

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE14_TRIGGER == EXTI_FallingEdge

				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE14_TRIGGER == EXTI_OnChange

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;
				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

///////////////////////////////////////////////////////
	#elif EXTI_LINE15_TRIGGER == EXTI_RisingEdge

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE15_TRIGGER == EXTI_FallingEdge

				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;

	#elif EXTI_LINE15_TRIGGER == EXTI_OnChange

				SET_BIT( MEXTI->RTSR, L_u8ShiftedOffset ) ;
				SET_BIT( MEXTI->FTSR, L_u8ShiftedOffset ) ;


#endif



}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MEXTI_vEnableLine( u8 A_u8LineID,  u8 A_u8TriggerStatus )
{

	if( A_u8LineID <= 23 )
	{

		SET_BIT( MEXTI->IMR, A_u8LineID ) ;

		switch( A_u8TriggerStatus )
		{

			case EXTI_RisingEdge	: 	SET_BIT( MEXTI->RTSR, A_u8LineID ) ;

										CLR_BIT( MEXTI->FTSR, A_u8LineID ) ; break;

			case EXTI_FallingEdge	: 	SET_BIT( MEXTI->FTSR, A_u8LineID ) ;

										CLR_BIT( MEXTI->RTSR, A_u8LineID ) ; break;

			case EXTI_OnChange		: 	SET_BIT( MEXTI->RTSR, A_u8LineID ) ;

									  	SET_BIT( MEXTI->FTSR, A_u8LineID ) ; break;

		}


	}


}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MEXTI_vDisableLine( u8 A_u8LineID )
{

	if( A_u8LineID <= 23 )
	{

		CLR_BIT( MEXTI->IMR, A_u8LineID ) ;

	}

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MEXTI_vSWITrigger( u8 A_u8LineID )
{

	if( A_u8LineID <= 23 )
	{

		SET_BIT( MEXTI->SWIER, A_u8LineID ) ;

	}

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MEXTI_vSetTrigger( u8 A_u8LineID,  u8 A_u8TriggerStatus )
{

	if( A_u8LineID <= 23 )
	{

		SET_BIT( MEXTI->IMR, A_u8LineID ) ;

		switch( A_u8TriggerStatus )
		{

			case EXTI_RisingEdge	: 	SET_BIT( MEXTI->RTSR, A_u8LineID ) ;

										CLR_BIT( MEXTI->FTSR, A_u8LineID ) ; break;

			case EXTI_FallingEdge	: 	SET_BIT( MEXTI->FTSR, A_u8LineID ) ;

										CLR_BIT( MEXTI->RTSR, A_u8LineID ) ; break;

			case EXTI_OnChange		: 	SET_BIT( MEXTI->RTSR, A_u8LineID ) ;

									  	SET_BIT( MEXTI->FTSR, A_u8LineID ) ; break;

		}


	}

}

/*******************************************************************************************************************/
/******************************************************************************************************************/



















