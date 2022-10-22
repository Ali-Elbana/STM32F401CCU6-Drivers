/* FILENAME: Flash_Driver_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Thu 10/20/2022
*/
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBITMATH.h"

#include "../GPIO/GPIO_interface.h"

#include "Flash_Driver_interface.h"
#include "Flash_Driver_private.h"
#include "Flash_Driver_config.h"




/******************************************************************/
/******************************************************************/

void MFlash_vEraseAppArea( void )
{


}

/******************************************************************/
/******************************************************************/

void MFlash_vEraseSector( u8 A_u8Sector )
{

	// Wait if flash is busy:
	while( GET_BIT( Flash->SR, BSY ) == Flag_is_Set ) ;

	// Unlock flash register:
	if( GET_BIT( Flash->CR, LOCK ) == 1 )
	{
		Flash->KEYR = KEY1 ;
		Flash->KEYR = KEY2 ;
	}

	// Select the sector:
	Flash->CR &= ~( (u32) (0b1111 << 3) ) ;
	Flash->CR |= (A_u8Sector << 3) ;

	// Select erase operation:
	SET_BIT( Flash->CR, SER ) ;

	// Start erase operation:
	SET_BIT( Flash->CR, STRT ) ;

	// Wait for busy flag:
	while( GET_BIT( Flash->SR, BSY ) == Flag_is_Set ) ;

	// Clear EOP flag:
	SET_BIT( Flash->CR, EOP ) ;

	// DeSelect erase operation:
	CLR_BIT( Flash->CR, SER ) ;

}

/******************************************************************/
/******************************************************************/

void MFlash_vWrite( u32 A_u32Address, u16* A_pu16Data,
					u16 A_u16Length )
{

	// Wait if flash is busy:
	while( GET_BIT( Flash->SR, BSY ) == Flag_is_Set ) ;

	// Unlock flash register:
	if( GET_BIT( Flash->CR, LOCK ) == 1 )
	{
		Flash->KEYR = KEY1 ;
		Flash->KEYR = KEY2 ;
	}

	// Select the element size:
	Flash->CR &= ~( (u32) 0b11 << 8 ) ;
	Flash->CR |= ( 0b01 << 8 ) ;

	// Activate Programming Mode:
	SET_BIT( Flash->CR, PG ) ;

	// Write data array on flash address:
	for( u16 i = 0; i < A_u16Length; i++ )
	{

		*(volatile u16*)A_u32Address = A_pu16Data[i] ;

		A_u32Address += 2 ;

		// Wait for busy flag:
		while( GET_BIT( Flash->SR, BSY ) == Flag_is_Set ) ;

		// Clear EOP flag:
		SET_BIT( Flash->CR, EOP ) ;

	}

	// Deactivate programming mode:
	CLR_BIT( Flash->CR, PG ) ;

}

/******************************************************************/
/******************************************************************/













