/*
 * TFT_Config.c
 *
 *  Created on: Oct 13, 2022
 *      Author: Ali El Bana
 */

#include "../../LIB/LSTD_TYPES.h"

#include "../../MCAL/GPIO/GPIO_interface.h"

#include "TFT_config.h"

MGPIOx_ConfigType TFT_A0 =
{

	.Port 			= A0_PORT 				,

	.Pin 			= GPIOx_PIN1 			,

	.Mode 			= GPIOx_MODE_OUTPUT 	,

	.OutputType 	= GPIOx_PUSHPULL 		,

	.OutputSpeed 	= GPIOx_VeryHighSpeed 	,

} ;


MGPIOx_ConfigType TFT_RST =
{

	.Port 			= RST_PORT 				,

	.Pin 			= GPIOx_PIN0 			,

	.Mode 			= GPIOx_MODE_OUTPUT 	,

	.OutputType 	= GPIOx_PUSHPULL 		,

	.OutputSpeed 	= GPIOx_VeryHighSpeed 	,

} ;



















