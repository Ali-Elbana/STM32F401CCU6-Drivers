/* FILENAME: RTOS_private  
*  Author:  Ali El-Bana
*  Version:  V1.0
*  DATE:   Wed 09/07/2022
*  Description: Private file for OS module
*/
#ifndef _RTOS_private_H
#define _RTOS_private_H


typedef enum
{

	Suspended,

	Running

} RunState;



typedef struct
{

	void (*TaskHandler)( void ) ;

	u8 periodicity 				;

	u8 FirstDelay 				;

	RunState TaskRunstate		;

}Task ;













#endif //_RTOS_private_H
