/* FILENAME: SysTick_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Sun 09/04/2022
*/
#ifndef _SysTick_interface_H
#define _SysTick_interface_H



void MSysTick_vInit( void ) ;

void MSysTick_vSetBusyWait( u32 A_u32Ticks ) ;

void MSysTick_vSetSingleInterval( u32 A_u32Ticks, void (*A_Fptr) (void) ) ;

void MSysTick_vSetPeriodicInterval( u32 A_u32Ticks, void (*A_Fptr) (void) ) ;

void MSysTick_vStopInterval( void ) ;

u32 MSysTick_u32GetElapsedTime( void ) ;

u32 MSysTick_u32GetRemainingTime( void ) ;

void MSysTick_vEnable( void ) ;

void MSysTick_vDisable( void ) ;


#define TICK_TIME	3125


#endif //_SysTick_interface_H
