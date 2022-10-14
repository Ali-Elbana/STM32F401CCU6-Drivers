/*
 * LED_Matrix_Config.c
 *
 *  Created on: Sep 8, 2022
 *      Author: Ali El Bana
 */

#include "../../LIB/LSTD_TYPES.h"

#include "../../MCAL/GPIO/GPIO_interface.h"

#include "LED_Matrix_config.h"



/*******************************************************************************************************************/
/******************************************************************************************************************/


// Set GPIO PINS Configurations.

MGPIOx_ConfigType LED_MATRIX_ROWS[ ROWS_NUMs ] =
{

	{

		.Port 			= ROWS_PORT 		,

		.Pin 			= GPIOx_PIN0 		,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_NoPull

	}, //ROW0

	{

		.Port 			= ROWS_PORT 		,

		.Pin 			= GPIOx_PIN1 		,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_NoPull

	}, //ROW1

	{

		.Port 			= ROWS_PORT 		,

		.Pin 			= GPIOx_PIN2 		,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_NoPull

	}, //ROW2

	{

		.Port 			= ROWS_PORT 		,

		.Pin 			= GPIOx_PIN3 		,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_NoPull

	},//ROW3


	{

		.Port 			= ROWS_PORT 		,

		.Pin 			= GPIOx_PIN4 		,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_NoPull

	},//ROW4

	{

		.Port 			= ROWS_PORT 		,

		.Pin 			= GPIOx_PIN5 		,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_NoPull

	},//ROW5

	{

		.Port 			= ROWS_PORT 		,

		.Pin 			= GPIOx_PIN6 		,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_NoPull

	},//ROW6

	{

		.Port 			= ROWS_PORT 		,

		.Pin 			= GPIOx_PIN7 		,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_NoPull

	}//ROW7

};


MGPIOx_ConfigType LED_MATRIX_COLUMNS[ COLUMNS_NUMs ] =
{

	{

		.Port 			= COLUMNS_PORT 		,

		.Pin 			= GPIOx_PIN5 		,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_NoPull

	},//COLUMN0

	{

		.Port 			= COLUMNS_PORT 		,

		.Pin 			= GPIOx_PIN6 		,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_NoPull

	},//COLUMN1

	{

		.Port 			= COLUMNS_PORT 		,

		.Pin 			= GPIOx_PIN7 		,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_NoPull

	},//COLUMN2

	{

		.Port 			= COLUMNS_PORT 		,

		.Pin 			= GPIOx_PIN8 		,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_NoPull

	},//COLUMN3

	{

		.Port 			= COLUMNS_PORT 		,

		.Pin 			= GPIOx_PIN9 		,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_NoPull

	},//COLUMN4

	{

		.Port 			= COLUMNS_PORT 		,

		.Pin 			= GPIOx_PIN10 		,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_NoPull

	},//COLUMN5

	{

		.Port 			= COLUMNS_PORT 		,

		.Pin 			= GPIOx_PIN12 		,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_NoPull

	},//COLUMN6

	{

		.Port 			= COLUMNS_PORT 		,

		.Pin 			= GPIOx_PIN13 		,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_NoPull

	} //COLUMN7

};


/*******************************************************************************************************************/
/******************************************************************************************************************/

















