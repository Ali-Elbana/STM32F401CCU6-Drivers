/* FILENAME: LED_Matrix_config  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Mon 09/05/2022
*/
#ifndef _LED_Matrix_config_H
#define _LED_Matrix_config_H


#define COLUMNS_PORT 	GPIO_PORTB

#define ROWS_PORT 		GPIO_PORTA

#define COLUMNS_NUMs	8

#define ROWS_NUMs		8

#define SCAN_TIME		1250


/*option:
 * ROW_CONTROLLED_METHOD
 * COLUMN_CONTROLLED_METHOD
 */
#define CONTROLLED_METHOD COLUMN_CONTROLLED_METHOD


extern MGPIOx_ConfigType LED_MATRIX_ROWS[ ROWS_NUMs ] 			;

extern MGPIOx_ConfigType LED_MATRIX_COLUMNS[ COLUMNS_NUMs ] 	;


#endif //_LED_Matrix_config_H
