
//CTRL + K + D  => FORMAT CODE


/************************** orginal project   ***************************************/

#define F_CPU 8000000
#include <util/delay.h>

#include "MemMaph.h"
#include "StdTypes.h"
#include "Utils.h"
#include "SEGMENT_interface.h"
#include "DIO_interface.h"
#include "MOTOR_Interface.h"
#include "LCD_Interface.h"
#include "STEPPER_Interface.h"
#include "ADC_interface.h"
#include "KeyPad_interface.h"
#include "SENSORS_interface.h"
#include "EX_INTERRUPT_interface.h"
#include "KIT.h"
#include "FireSystem_interface.h"
#include "Timers_interface.h"
#include "RGB_LED_interface.h"
#include "Timer_Services.h"
#include "ULTRASONIC_interface.h"
#include "MultiUltra_interafce.h"
#include "SERVO_interface.h"
#include "UART_interface.h"
#include "UART_Services.h"
#include "SmartHome_interface.h"
#include "FireSytemSmart_interface.h"
#include "AdditionalFun.h"
#include "UART_STACK.h"
#include "SPI_interface.h"
#include "I2C_interface.h"
#include "WDT.h"
#include "MOVE_interface.h"


#include "I2C_cfg.h"
#include "I2C_interface.h"
#include "I2C_Services.h"


int main(void)
{
	
// 	/* DIO Initialization */
// 	DIO_Init() ;
// 	/* LCD Initialization  */
// 	LCD_Init()  ;
// 	/* Global Interrupt enable */
// 	GLOBAL_INTERRUPT_E ;
// 	/*EX interrupt Initialization */
// 	
// 	//PWM_Init_Timer0()  ;
// 	//PWM_Freq_HZ_Timer0(50000) ; 
// 	


u8 x  =10   , y =20 ; 

DIO_Init() ; 
DIO_TogglePin(PINA0) ; 

u16 z  = x+ y ; 


	while(1) {
		
		/*************** Start While ********************/
			LCD_WriteNumber4D(z) ; 
		
		/*************** End While ********************/
	}
	
		
		return   0 ; 	
		
	/*************** End Main ********************/
	
	
}
