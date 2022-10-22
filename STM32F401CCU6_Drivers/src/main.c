
#include "ARM_COTS/LIB/LSTD_TYPES.h"
#include "ARM_COTS/LIB/LBITMATH.h"

#include "ARM_COTS/MCAL/RCC/MRCC_interface.h"
#include "ARM_COTS/MCAL/GPIO/GPIO_interface.h"
#include "ARM_COTS/MCAL/GPIO/GPIO_private.h"
#include "ARM_COTS/MCAL/NVIC/NVIC_interface.h"
#include "ARM_COTS/MCAL/EXTI/EXTI_interface.h"
#include "ARM_COTS/MCAL/SysTick/SysTick_interface.h"
#include "ARM_COTS/MCAL/SPI/SPI_interface.h"
#include "ARM_COTS/MCAL/UART/UART_interface.h"
#include "ARM_COTS/MCAL/DMA/DMA_interface.h"
#include "ARM_COTS/MCAL/Flash_Driver/Flash_Driver_interface.h"

#include "ARM_COTS/HAL/LED_Matrix/LED_Matrix_interface.h"
#include "ARM_COTS/HAL/TFT/TFT_interface.h"

#include "ARM_COTS/RTOS/RTOS_interface.h"

#include "QusadEiny.h"
#include "MyImage.h"

#define  GPIO 	 	STOP
#define  EXTI  		STOP
#define  SysTick	STOP
#define  LED_Matrix	STOP
#define  RTOS		STOP
#define	 DAC		STOP
#define	 IR			STOP
#define	 SPI		STOP
#define  TFT		STOP
#define  UART		STOP
#define  DMA		STOP
#define FLASH_APP	STOP
#define BOOT0		RUN




#if BOOT0 == RUN

int main(void)
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1LPENR, AHB1LPENR_FLITFLPEN ) ;

	u8 L_u8Record[] = ":1080000007B5FFF75FFF0F210520FFF77FFF064B71" ;

	AHexParser_vParseData( L_u8Record ) ;

	while( TRUE )
	{

	}

}


#endif



#if FLASH_APP == RUN

int main(void)
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1LPENR, AHB1LPENR_FLITFLPEN ) ;

	u16 L_u16Data[3] = { 0x30, 0x31, 0x32 } ;

	MFlash_vWrite( 0x08008000, L_u16Data, 3 ) ;

	while( TRUE )
	{

	}

}


#endif


#if DMA == RUN

int main(void)
{
	/* call init */
	/* call setStream */

	/* used by DMA */
	u32 arr1[500];
	u32 arr2[500];

	/* used by CPU */
	u32 arr3[500];
	u32 arr4[500];

	/* fill arr1 and arr3 with data */

	/* demo starts here   */

	while(1)
	{

	}
}


#endif



#if UART == RUN

int main(void)
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;
	MRCC_vEnablePeriphralCLK( RCC_APB2, APB2ENR_USART1EN  ) ;

	MGPIOx_ConfigType TX =
	{

		.Port 			= GPIO_PORTA 			,

		.Pin 			= GPIOx_PIN9 			,

		.Mode 			= GPIOx_MODE_AF 		,

		.OutputType 	= GPIOx_PUSHPULL 		,

		.OutputSpeed 	= GPIOx_MediumSpeed 	,

		.InputType 		= GPIOx_PUSHPULL		,

		.AF_Type 		= GPIOx_AF7

	} ;

	MGPIOx_ConfigType RX =
	{

		.Port 			= GPIO_PORTA 			,

		.Pin 			= GPIOx_PIN10 			,

		.Mode 			= GPIOx_MODE_AF 		,

		.OutputType 	= GPIOx_PUSHPULL 		,

		.OutputSpeed 	= GPIOx_MediumSpeed 	,

		.InputType 		= GPIOx_PUSHPULL		,

		.AF_Type 		= GPIOx_AF7

	} ;

	MGPIOx_vInit( &TX ) ;
	MGPIOx_vInit( &RX ) ;

	USART_InitType MyUART1 =
	{

		.BaudRate  				= 9600 			,

		.DataWidth 				= MODE_8BIT 	,

		.StopBits  				= STOP_BIT_1 	,

		.Parity_Enable 			= DISABLE 		,

		.Parity_Selection 		= EVEN_PARITY 	,

		.TransferDirection 		= TX_RX			,

		.HardwareFlowControl 	= DISABLE 		,

		.Oversampling 			= OVER_SAMPLING_16

	} ;

	USART_ClockInitTypeDef MyUARTCLK = { DISABLE, 0, 0, 0 } ;

	// Initialization of USART1
	MUSART_vInit( &MyUART1, &MyUARTCLK, USART1_REG ) ;

	// Enable USART1
	MUSART_vEnable( USART1_REG ) ;

	// Transmit String
	MUSART_vTransmitByte( USART1_REG, 'A' ) ;

	while( TRUE )
	{


	}

}


#endif




#if TFT == RUN

int main(void)
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;
	MRCC_vEnablePeriphralCLK( RCC_APB2, APB2ENR_SPI1EN  ) ;

	HTFT_vInit( ) ;

	HTFT_vShowImage( Image, sizeof(Image)/sizeof(Image[0]) ) ;

	while( TRUE )
	{


	}



}


#endif


#if SPI == RUN


int main( void )
{

	u16 L_u8Mychar = 0 ;

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;

	MRCC_vEnablePeriphralCLK( RCC_APB2, APB2ENR_SPI1EN  ) ;

	MGPIOx_ConfigType LED =
	{

		.Port 			= GPIO_PORTA 			,

		.Pin 			= GPIOx_PIN1 			,

		.Mode 			= GPIOx_MODE_OUTPUT 	,

		.OutputType 	= GPIOx_PUSHPULL 		,

		.OutputSpeed 	= GPIOx_LowSpeed 		,

		.InputType 		= GPIOx_NoPull

	} ;

	MGPIOx_vInit( &LED ) ;

	MSPI_vInit( ) ;

	//MGPIOx_vSetPinValue( LED.Port, LED.Pin, GPIOx_HIGH ) ;

	L_u8Mychar = MSPI_u16Transcieve( 'A' ) ;

	if( L_u8Mychar == 'A' )
	{
		MGPIOx_vSetPinValue( LED.Port, LED.Pin, GPIOx_LOW ) ;
	}

	else
	{
		MGPIOx_vSetPinValue( LED.Port, LED.Pin, GPIOx_HIGH ) ;
	}


	while( TRUE )
	{


	}

}

#endif







#if IR == RUN


MGPIOx_ConfigType IR_PIN =
{

	.Port 			= GPIO_PORTA ,

	.Pin 			= GPIOx_PIN0 ,

	.Mode 			= GPIOx_MODE_INPUT ,

	.OutputType 	= GPIOx_NoPull ,

	.OutputSpeed 	= GPIOx_LowSpeed ,

	.InputType 		= GPIOx_NoPull
};


MGPIOx_ConfigType RGB_PINS[3] =
{

	{

		.Port 			= GPIO_PORTA 		,

		.Pin 			= GPIOx_PIN1 		,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_NoPull

	}, // RED

	{

		.Port 			= GPIO_PORTA 		,

		.Pin 			= GPIOx_PIN2 		,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_NoPull

	}, // GREEN

	{

		.Port 			= GPIO_PORTA 		,

		.Pin 			= GPIOx_PIN3 		,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_NoPull

	}// BLUE

};



u8  G_u8StartFlag = 0 ;

u32 FrameData[50] ;

u32 EdgeCounter = 0 ;

u8  IR_Data = 0 ;

void GetFrame( void ) ;

void ParseFrame( void ) ;

void RGB( void ) ;

int main( void )
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;
	MRCC_vEnablePeriphralCLK( RCC_APB2, APB2ENR_SYSCFGEN ) ;


	MGPIOx_vInit( &IR_PIN ) ;

	for( u8 i = 0; i < 3; i++ )
	{
		MGPIOx_vInit( &RGB_PINS[i] ) ;
	}

	MEXTI_vInit( ) ;

	EXTI_vSetCallback( EXTI_LINE0, GetFrame ) ;

	MNVIC_vEnablePeriphral( EXTI0 ) ;

	MSysTick_vInit( ) ;

	while( TRUE )
	{



	}

}


void RGB( void )
{

	switch( IR_Data )
	{

		case 70: MGPIOx_vSetPinValue( RGB_PINS[0].Port, RGB_PINS[0].Pin, GPIOx_HIGH ) ;
		break;

		case 80: MGPIOx_vSetPinValue( RGB_PINS[1].Port, RGB_PINS[0].Pin, GPIOx_HIGH ) ;
		break;

		case 90: MGPIOx_vSetPinValue( RGB_PINS[1].Port, RGB_PINS[0].Pin, GPIOx_HIGH ) ;
		break;

	}

}


void ParseFrame( void )
{

	for( u8 i = 0; i < 8; i++ )
	{

		if( FrameData[17+i] >= 2000 && FrameData[17+i] <= 2500 )
		{
			SET_BIT( IR_Data, i ) ;
		}

		else
		{
			CLR_BIT( IR_Data, i ) ;
		}

	}

	G_u8StartFlag = 0 ;

	EdgeCounter = 0 ;

	RGB( ) ;

}


void GetFrame( void )
{

	if( G_u8StartFlag == Flag_is_Cleared )
	{
		MSysTick_vSetSingleInterval( 1000000, ParseFrame ) ;

		G_u8StartFlag = Flag_is_Set ;
	}

	else
	{
		FrameData[EdgeCounter] = MSysTick_u32GetElapsedTime( ) ;

		MSysTick_vSetSingleInterval( 1000000, ParseFrame ) ;

		EdgeCounter++ ;
	}

}



#endif














#if DAC == RUN


void DAC_ISR(void)
{

	static u32 song_iterator = 0 ;

	GPIOA->ODRx &= ~( 0xff ) ;

	GPIOA->ODRx |= ( (u16)QusadEiny_raw[song_iterator] & (0x00ff) ) ;

	if( song_iterator < QusadEiny_raw_len )
	{
		song_iterator++ ;
	}
	else
	{
		song_iterator = 0 ;
	}

}


int main( void )
{

	u8 L_u8Iterator1 = Initialized_by_Zero ;

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;


	MGPIOx_ConfigType DAC_PINs[ 8 ] =
	{

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN0 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		}, // BIT0

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN1 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		}, // BIT1

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN2 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		}, // BIT2

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN3 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		},// BIT3


		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN4 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		},// BIT4

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN5 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		},// BIT5

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN6 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		},// BIT6

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN7 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		}// BIT7

	};


	for( L_u8Iterator1 = 0; L_u8Iterator1 < 8; L_u8Iterator1++ )
	{

		MGPIOx_vInit( &DAC_PINs[L_u8Iterator1] ) ;

	}

	MSysTick_vInit( ) ;

	MSysTick_vSetPeriodicInterval( TICK_TIME, DAC_ISR ) ;

	while( TRUE )
	{


	}



}



#endif






#if RTOS == RUN


void LED1(void) ;
void LED2(void)	;

int main(void)
{


	(void)RTOS_u8CreateTask( LED1, 50, 0, 0 ) ;
	(void)RTOS_u8CreateTask( LED2, 50, 0, 0 ) ;

	RTOS_vStartOS(  ) ;



	while(TRUE)
	{


	}



}




void LED1(void)
{

	MGPIOx_vTogglePinValue( GPIO_PORTA, GPIOx_PIN8 ) ;

}

void LED2(void)
{

	MGPIOx_vTogglePinValue( GPIO_PORTA, GPIOx_PIN9 ) ;

}



#endif




#if LED_Matrix == RUN


int main( void )
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN ) ;

	MLED_Matrix_vInit( ) ;

	u8 L_u8SmileyFace[8] = {128, 0, 0, 0, 0, 0, 0, 0} ;

	while( TRUE )
	{

		MLEDMatrix_vDisplayFrame( L_u8SmileyFace, 5 ) ;

	}

}


#endif



#if SysTick == RUN


int main( void )
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;

	MGPIOx_vSetPinMode( GPIO_PORTA, GPIOx_PIN2, GPIOx_MODE_OUTPUT ) ;

	MGPIOx_vSetPinOutputSpeed( GPIO_PORTA, GPIOx_PIN2, GPIOx_LOW ) ;

	MGPIOx_vSetPinOutputType( GPIO_PORTA, GPIOx_PIN2, GPIOx_PUSHPULL ) ;

	while( TRUE )
	{

		MGPIOx_vSetPinValue( GPIO_PORTA, GPIOx_PIN2, GPIOx_HIGH ) ;

		MSysTick_vSetBusyWait( 300 ) ; // 1ms

		MGPIOx_vSetPinValue( GPIO_PORTA, GPIOx_PIN2, GPIOx_LOW ) ;

		MSysTick_vSetBusyWait( 300 ) ; // 1ms

	}



}


#endif





#if EXTI == RUN


void APP_vTurnOnnLED( void ) ;


int main( void )
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;

	MRCC_vEnablePeriphralCLK( RCC_APB2, APB2ENR_SYSCFGEN ) ;

	MGPIOx_ConfigType LED =
	{

		.Port 			= GPIO_PORTA ,

		.Pin 			= GPIOx_PIN1 ,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL ,

		.OutputSpeed 	= GPIOx_LowSpeed ,

		.InputType 		= GPIOx_NoPull

	};


	MGPIOx_ConfigType IRQ =
	{

		.Port 			= GPIO_PORTA ,

		.Pin 			= GPIOx_PIN0 ,

		.Mode 			= GPIOx_MODE_INPUT ,

		.OutputType 	= GPIOx_NoPull ,

		.OutputSpeed 	= GPIOx_LowSpeed ,

		.InputType 		= GPIOx_PullUp
	};


	MGPIOx_vInit( &LED ) ;

	MGPIOx_vInit( &IRQ ) ;

	EXTI_vSetCallback( EXTI_LINE0, &APP_vTurnOnnLED ) ;

	 MSYSCFG_vSetEXTIPort( EXTI0, GPIO_PORTA ) ;

	MEXTI_vInit( ) ;

	MNVIC_vEnablePeriphral( EXTI0 ) ;

	MEXTI_vSWITrigger( EXTI_LINE0 ) ;


	while( TRUE )
	{




	}


}


void APP_vTurnOnnLED( void )
{

	MGPIOx_vSetPinValue( GPIO_PORTA, GPIOx_PIN1, GPIOx_HIGH ) ;

}



#endif




#if GPIO == RUN

//
//int main( void )
//{
//
//	MRCC_vInit( ) ;
//
//	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;
//
//	MGPIOx_vSetPinMode( GPIO_PORTA, GPIOx_PIN1, GPIOx_MODE_OUTPUT ) ;
//
//	MGPIOx_vSetPinOutputSpeed( GPIO_PORTA, GPIOx_PIN1, GPIOx_LOW ) ;
//
//	MGPIOx_vSetPinOutputType( GPIO_PORTA, GPIOx_PIN1, GPIOx_PUSHPULL ) ;
//
//	MGPIOx_vSetPinValue( GPIO_PORTA, GPIOx_PIN1, GPIOx_HIGH ) ;
//
//	while( TRUE )
//	{
//
//
//
//
//	}
//
//
//
//}



int main( void )
{

	u8 L_u8Iterator1 = Initialized_by_Zero ;
	u8 L_u8Iterator2 = Initialized_by_Zero ;

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN ) ;


	MGPIOx_ConfigType LED_MATRIX_ROWS[ 8 ] =
	{

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN0 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		}, //ROW0

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN1 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		}, //ROW1

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN2 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		}, //ROW2

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN3 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		},//ROW3


		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN4 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		},//ROW4

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN5 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		},//ROW5

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN6 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		},//ROW6

		{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN7 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		}//ROW7

	};


	MGPIOx_ConfigType LED_MATRIX_COLUMNS[ 8 ] =
	{

		{

			.Port 			= GPIO_PORTB 		,

			.Pin 			= GPIOx_PIN5 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		},//COLUMN0

		{

			.Port 			= GPIO_PORTB 		,

			.Pin 			= GPIOx_PIN6 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		},//COLUMN1

		{

			.Port 			= GPIO_PORTB 		,

			.Pin 			= GPIOx_PIN7 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		},//COLUMN2

		{

			.Port 			= GPIO_PORTB 		,

			.Pin 			= GPIOx_PIN8 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		},//COLUMN3

		{

			.Port 			= GPIO_PORTB 		,

			.Pin 			= GPIOx_PIN9 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		},//COLUMN4

		{

			.Port 			= GPIO_PORTB 		,

			.Pin 			= GPIOx_PIN10 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		},//COLUMN5

		{

			.Port 			= GPIO_PORTB 		,

			.Pin 			= GPIOx_PIN12 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		},//COLUMN6

		{

			.Port 			= GPIO_PORTB 		,

			.Pin 			= GPIOx_PIN13 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

		} //COLUMN7

	};


	for( L_u8Iterator1 = 0; L_u8Iterator1 < 8; L_u8Iterator1++ )
	{

		MGPIOx_vInit( &LED_MATRIX_ROWS[L_u8Iterator1] ) ;

	}


	for( L_u8Iterator2 = 0; L_u8Iterator2 < 8; L_u8Iterator2++ )
	{

		MGPIOx_vInit( &LED_MATRIX_COLUMNS[L_u8Iterator2] ) ;

	}


	MSysTick_vInit( ) ;


	while( TRUE )
	{

//		MGPIOx_vSetPinValue( LED_MATRIX_ROWS[0].Port   , LED_MATRIX_ROWS[0].Pin   , GPIOx_HIGH ) ; //ROW0
//		MGPIOx_vSetPinValue( LED_MATRIX_COLUMNS[0].Port, LED_MATRIX_COLUMNS[0].Pin, GPIOx_LOW  ) ; //COLUMN0

		MGPIOx_vSetPinValue( GPIO_PORTA, GPIOx_PIN0, GPIOx_HIGH ) ; //ROW0
		MGPIOx_vSetPinValue( GPIO_PORTB, GPIOx_PIN5, GPIOx_LOW  ) ; //COLUMN0


	}



}



#endif








