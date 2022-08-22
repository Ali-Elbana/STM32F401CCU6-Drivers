

#include "ARM_COTS/LIB/LSTD_TYPES.h"
#include "ARM_COTS/LIB/LBITMATH.h"

#include "ARM_COTS/MCAL/RCC/MRCC_interface.h"
#include "ARM_COTS/MCAL/GPIO/GPIO_interface.h"


int main( void )
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;

	MGPIOx_vSetPinMode( GPIO_PORTA, GPIOx_PIN0, GPIOx_MODE_OUTPUT ) ;

	MGPIOx_vSetPinOutputSpeed( GPIO_PORTA, GPIOx_PIN0, GPIOx_LOW ) ;

	MGPIOx_vSetPinOutputType( GPIO_PORTA, GPIOx_PIN0, GPIOx_PUSHPULL ) ;

	MGPIOx_vSetPinValue( GPIO_PORTA, GPIOx_PIN0, GPIOx_HIGH ) ;

	while( TRUE )
	{




	}



}
