/* FILENAME: RTOS_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Wed 09/07/2022
*/
#ifndef _RTOS_interface_H
#define _RTOS_interface_H


u8 RTOS_u8CreateTask( void A_fptrHandler(void), u8 A_u8Periodicity,

		u8 A_u8Priority, u8 A_u8FirstDelay ) ;


void Scheduler(void) ;

void RTOS_vStartOS(void) ;

u8 RTOS_u8DeleteTask( u8 A_u8Priority ) 	;

u8 RTOS_u8SuspendTask( u8 A_u8Priority ) 	;

u8 RTOS_u8ResumeTask( u8 A_u8Priority )  	;


#endif //_RTOS_interface_H
