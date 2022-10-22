/* FILENAME: Flash_Driver_private  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Thu 10/20/2022
*/
#ifndef _Flash_Driver_private_H
#define _Flash_Driver_private_H


#define Flash_BASE_ADDRESS	0x40023C00

#define KEY1	0x45670123
#define KEY2	0xCDEF89AB


typedef struct
{

	volatile u32 ACR 		;

	volatile u32 KEYR 		;

	volatile u32 OPTKEYR	;

	volatile u32 SR 		;

	volatile u32 CR 		;

	volatile u32 OPTCR 		;

} Flash_MemoryMapType ;


#define Flash ( (volatile Flash_MemoryMapType*) Flash_BASE_ADDRESS )


// ACR bits
#define DCRST 	12
#define ICRST	11
#define DCEN	10
#define ICEN	9
#define PRFTEN	8

// SR bits
#define BSY		16
#define RDERR	8
#define	PGSERR	7
#define	PGPERR	6
#define	PGAERR	5
#define	WRPERR	4
#define OPERR	1
#define EOP		0

// CR bits
#define LOCK	31
#define ERRIE	25
#define	EOPIE	24
#define	STRT	16
#define	MER		2
#define	SER		1
#define PG		0

// OPTCR bits
#define SPRMOD	31
#define OPTSTRT	1
#define	OPTLOCK	0


#define PROGRAM_SIZEx8	0
#define PROGRAM_SIZEx16	1
#define PROGRAM_SIZEx32	2
#define PROGRAM_SIZEx64	3








#endif //_Flash_Driver_private_H
