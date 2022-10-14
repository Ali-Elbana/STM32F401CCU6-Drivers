/* FILENAME: SysTick_config  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Sun 09/04/2022
*/
#ifndef _SysTick_config_H
#define _SysTick_config_H



/**********************************************************************************/
							// SysTick Configurations //
/**********************************************************************************/

/*options:
 *AHB_DividedBy8
 *AHB
 */
#define CLK_SOURCE AHB_DividedBy8

/**********************************************************************************/

/**
 * Options:
 * Dont_AssertRequest
 * AssertRequest
 */
#define Exception_Request AssertRequest

/**********************************************************************************/

#define SINGLE_INTERVAL_MODE 	1
#define PERIODIC_INTERVAL_MODE	2














#endif //_SysTick_config_H
