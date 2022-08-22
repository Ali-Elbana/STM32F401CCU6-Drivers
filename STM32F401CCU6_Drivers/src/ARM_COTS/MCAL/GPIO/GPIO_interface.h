/* FILENAME: GPIO_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Mon 08/22/2022
*/
#ifndef _GPIO_interface_H
#define _GPIO_interface_H


void MGPIOx_vSetPinMode( u8 A_u8PortID, u8 A_u8PinID,
						 u8 A_u8Mode ) ;

void MGPIOx_vSetPinOutputType( u8 A_u8PortID, u8 A_u8PinID,
							  u8 A_u8OutputType ) ;

void MGPIOx_vSetPinOutputSpeed( u8 A_u8PortID, u8 A_u8PinID,
							    u8 A_u8OutputSpeed ) ;

void MGPIOx_vSetPinInputPullType( u8 A_u8PortID, u8 A_u8PinID,
							      u8 A_u8InputPullType ) ;

u8 MGPIOx_u8GetPinValue( u8 A_u8PortID, u8 A_u8PinID ) ;

void MGPIOx_vSetPinValue( u8 A_u8PortID, u8 A_u8PinID,
						  u8 A_u8PinValue ) ;

void MGPIOx_vSetResetPinValue( u8 A_u8PortID, u8 A_u8PinID,
						  	   u8 A_u8SetResetPinValue ) ;

void MGPIOx_vSetAlternateFunctionON( u8 A_u8PortID, u8 A_u8PinID,
	  	   	   	   	   	   	   	   	 u8 A_u8AFID ) ;

void MGPIOx_vSetPortConfigLock( u8 A_u8PortID ) ;



#define GPIOx_MODE_INPUT 	0b00
#define GPIOx_MODE_OUTPUT	0b01
#define GPIOx_MODE_AF		0b10
#define GPIOx_MODE_ANALOG	0b11

#define GPIO_PORTA 1
#define GPIO_PORTB 2
#define GPIO_PORTC 3

#define GPIOx_OPENDRAIN 1
#define GPIOx_PUSHPULL  2

#define GPIOx_LowSpeed 		0b00
#define GPIOx_MediumSpeed 	0b01
#define GPIOx_HighSpeed 	0b10
#define GPIOx_VeryHighSpeed 0b11

#define GPIOx_NoPull 		0b00
#define GPIOx_PullUp 		0b01
#define GPIOx_PullDown 		0b10


#define GPIOx_HIGH 1
#define GPIOx_LOW  2




#define GPIOx_PIN0  0
#define GPIOx_PIN1  1
#define GPIOx_PIN2  2
#define GPIOx_PIN3  3
#define GPIOx_PIN4  4
#define GPIOx_PIN5  5
#define GPIOx_PIN6  6
#define GPIOx_PIN7  7
#define GPIOx_PIN8  8
#define GPIOx_PIN9  9
#define GPIOx_PIN10 10
#define GPIOx_PIN11 11
#define GPIOx_PIN12 12
#define GPIOx_PIN13 13
#define GPIOx_PIN14 14
#define GPIOx_PIN15 15


















#endif //_GPIO_interface_H