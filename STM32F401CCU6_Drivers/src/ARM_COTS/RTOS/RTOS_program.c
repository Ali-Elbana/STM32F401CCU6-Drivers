/* FILENAME: RTOS_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Wed 09/07/2022
*/

#include"../LIB/LSTD_TYPES.h"
#include"../LIB/LBITMATH.h"

#include"../MCAL/SysTick/SysTick_interface.h"

#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_config.h"


// Creating array of Tasks structures(System container).
Task SystemTasks[MAX_NUM_OF_TASKS] 	= {Initialized_by_Zero} ;

u8   TaskTiming[MAX_NUM_OF_TASKS]  	= {Initialized_by_Zero} ;

Task Empty 							= {Initialized_by_Zero} ;

/*******************************************************************************************************************/
/******************************************************************************************************************/

u8 RTOS_u8CreateTask( void A_fptrHandler(void), u8 A_u8Periodicity,
					u8 A_u8Priority, u8 A_u8FirstDelay )
{

	u8 L_u8ErrorState = Initialized_by_Zero ;


	// Verify that the priority index within the correct range.
	if( A_u8Priority < MAX_NUM_OF_TASKS )
	{

		// Verify that the required priority is free.
		if( SystemTasks[A_u8Priority].TaskHandler == 0 )
		{

			SystemTasks[A_u8Priority].TaskHandler  = A_fptrHandler   ;

			SystemTasks[A_u8Priority].periodicity  = A_u8Periodicity ;

			TaskTiming [A_u8Priority] 			   = A_u8FirstDelay  ;

			SystemTasks[A_u8Priority].TaskRunstate = Running 		 ;

		}

		else
		{

			// The required priority is already reserved.
			L_u8ErrorState = 2 ;

		}

	}

	else
	{
		// Wrong priority.
		L_u8ErrorState = 1 ;

	}


	return L_u8ErrorState ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void Scheduler(void)
{

	u8 	L_u8Counter = Initialized_by_Zero ;

	// Loop on all tasks.
	for( L_u8Counter = 0; L_u8Counter < MAX_NUM_OF_TASKS; L_u8Counter++ )
	{

		if( SystemTasks[L_u8Counter].TaskRunstate == Running )
		{

			// Verify that the required priority is registered.
			if( SystemTasks[L_u8Counter].TaskHandler != 0 )
			{

				// Verify that it is the time to execute it.
				if( TaskTiming[L_u8Counter] == 0 )
				{

					// Run the task.
					SystemTasks[L_u8Counter].TaskHandler() ;

					// Reload the periodicity.
					TaskTiming[L_u8Counter] = SystemTasks[L_u8Counter].periodicity ;

				}

				else
				{

					TaskTiming[L_u8Counter]-- ;

				}

			}

		}
	}

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

u8 RTOS_u8DeleteTask( u8 A_u8Priority )
{

	u8 L_u8ErrorState = Initialized_by_Zero ;

	// Verify that the required priority is registered.
	if( SystemTasks[A_u8Priority].TaskHandler != 0 )
	{

		// Task exist, execute the removal.
		SystemTasks[A_u8Priority] = Empty ;

	}

	else
	{

		// Task not exist.
		L_u8ErrorState = 1 ;

	}

	return L_u8ErrorState ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

u8 RTOS_u8SuspendTask( u8 A_u8Priority )
{

	u8 L_u8ErrorState = Initialized_by_Zero ;

	// Verify that the required priority is registered.
	if( SystemTasks[A_u8Priority].TaskHandler != 0 )
	{

		// Task exist, execute the removal.
		SystemTasks[A_u8Priority].TaskRunstate = Suspended ;

	}

	else
	{

		// Task not exist.
		L_u8ErrorState = 1 ;

	}

	return L_u8ErrorState ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

u8 RTOS_u8ResumeTask( u8 A_u8Priority )
{

	u8 L_u8ErrorState = Initialized_by_Zero ;

	// Verify that the required priority is registered.
	if( SystemTasks[A_u8Priority].TaskHandler != 0 )
	{

		// Task exist, execute the removal.
		SystemTasks[A_u8Priority].TaskRunstate = Running ;

	}

	else
	{

		// Task not exist.
		L_u8ErrorState = 1 ;

	}

	return L_u8ErrorState ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void RTOS_vStartOS(void)
{

	MSysTick_vSetPeriodicInterval( TICK_TIME, Scheduler ) ;

	while(TRUE) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/





















