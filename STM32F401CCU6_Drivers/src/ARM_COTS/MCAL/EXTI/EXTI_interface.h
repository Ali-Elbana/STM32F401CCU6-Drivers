/* FILENAME: EXTI_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Fri 09/02/2022
*/
#ifndef _EXTI_interface_H
#define _EXTI_interface_H



typedef struct
{

	u8 LineNum 			;

	u8 TriggerStatus 	;

} EXTI_ConfigType ;


void MEXTI_vInit( void ) ;

void MEXTI_vEnableLine( u8 A_u8LineID,  u8 A_u8TriggerStatus ) ;

void MEXTI_vDisableLine( u8 A_u8LineID ) ;

void MEXTI_vSWITrigger( u8 A_u8LineID ) ;

void MEXTI_vSetTrigger( u8 A_u8LineID,  u8 A_u8TriggerStatus ) ;

void EXTI_vSetCallback( u8 A_u8LineID, void (*A_vFptr) (void) ) ;

void MEXTI_vInit_WithStruct( EXTI_ConfigType* A_xConfig ) ;

void MSYSCFG_vSetEXTIPort( u8 A_u8LineID, u8 A_u8PortID ) ;



#define EXTI_LINE0 	0
#define EXTI_LINE1  1
#define EXTI_LINE2  2
#define EXTI_LINE3  3
#define EXTI_LINE4  4
#define EXTI_LINE5  5
#define EXTI_LINE6  6
#define EXTI_LINE7  7
#define EXTI_LINE8  8
#define EXTI_LINE9  9
#define EXTI_LINE10 10
#define EXTI_LINE11 11
#define EXTI_LINE12 12
#define EXTI_LINE13 13
#define EXTI_LINE14 14
#define EXTI_LINE15 15


#define EXTI_FallingEdge	1
#define EXTI_RisingEdge		2
#define EXTI_OnChange   	3











#endif //_EXTI_interface_H
