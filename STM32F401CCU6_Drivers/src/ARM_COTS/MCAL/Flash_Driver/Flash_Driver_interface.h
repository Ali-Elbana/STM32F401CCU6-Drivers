/* FILENAME: Flash_Driver_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Thu 10/20/2022
*/
#ifndef _Flash_Driver_interface_H
#define _Flash_Driver_interface_H


#define SECTOR1	1
#define SECTOR2	2
#define SECTOR3	3
#define SECTOR4	4
#define SECTOR5	5
#define SECTOR6	6
#define SECTOR7	7





void MFlash_vEraseAppArea( void ) ;

void MFlash_vEraseSector( u8 A_u8Sector ) ;

void MFlash_vWrite( u32 A_u32Address, u16* A_pu16Data,
					u16 A_u16Length ) ;



#endif //_Flash_Driver_interface_H
