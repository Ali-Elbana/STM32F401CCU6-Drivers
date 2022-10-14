/*
 * DAC_config.c
 *
 *  Created on: Sep 30, 2022
 *      Author: Ali El Bana
 */


#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBITMATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"

#include "DAC_config.h"
#include "DAC_interface.h"



	MGPIOx_ConfigType DAC_PINs[ DAC_RESOLUTION ] =
	{

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN0 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		}, // BIT0

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN1 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		}, // BIT1

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN2 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		}, // BIT2

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN3 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		},// BIT3


		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN4 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		},// BIT4

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN5 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		},// BIT5

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN6 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		},// BIT6

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN7 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		}// BIT7

	};

























