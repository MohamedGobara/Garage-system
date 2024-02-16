
#define F_CPU 8000000
#include <util/delay.h>

#include "STEPPER_Interface.h"
#include "STEPPER_cfg.h"
#include "STEPPER_private.h"
#include "StdTypes.h"
#include "DIO_interface.h"



void STEPPER_BiPoler_CW(void){
	
	
	DIO_WritePin(COIL1A,HIGH) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(DELAY_STEPPER);
	
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,HIGH) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(DELAY_STEPPER);
	
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,HIGH) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(DELAY_STEPPER);
	
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,HIGH) ;
	_delay_ms(DELAY_STEPPER);

	
	
}


void STEPPER_BiPoler_CCW(void) {
	


	//4
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,HIGH) ;
	_delay_ms(DELAY_STEPPER);

	//3
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,HIGH) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(DELAY_STEPPER);
	
	
	//2
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,HIGH) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(DELAY_STEPPER);
	
	
	//1
	DIO_WritePin(COIL1A,HIGH) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(DELAY_STEPPER);
}


void STEPPER_UniPoler_CW(void){
	
	
	DIO_WritePin(COIL1A,HIGH) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(DELAY_STEPPER);
	
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,HIGH) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(DELAY_STEPPER);
	
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,HIGH) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(DELAY_STEPPER);
	
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,HIGH) ;
	_delay_ms(DELAY_STEPPER);

	
	
	
}


void STEPPER_UniPoler_CCW(void){



	//4
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,HIGH) ;
	_delay_ms(DELAY_STEPPER);
	//3
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,HIGH) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(DELAY_STEPPER);

	//2
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,HIGH) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(DELAY_STEPPER);

	
	//1
	DIO_WritePin(COIL1A,HIGH) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(DELAY_STEPPER);
}


void STEPPER_UniPoler_CW_HS(void){
	
	
	DIO_WritePin(COIL1A,HIGH) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(DELAY_STEPPER);
	
	DIO_WritePin(COIL1A,HIGH) ;
	DIO_WritePin(COIL1B,HIGH) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(DELAY_STEPPER);
	
	
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,HIGH) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(DELAY_STEPPER);
	
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,HIGH) ;
	DIO_WritePin(COIL2A,HIGH) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(DELAY_STEPPER);
	
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,HIGH) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(DELAY_STEPPER);
	
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,HIGH) ;
	DIO_WritePin(COIL2B,HIGH) ;
	_delay_ms(DELAY_STEPPER);
	
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,HIGH) ;
	_delay_ms(DELAY_STEPPER);
	
	
	DIO_WritePin(COIL1A,HIGH) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,HIGH) ;
	_delay_ms(DELAY_STEPPER);

	
	
	
}


void STEPPER_UniPoler_ByAngle(u32 angle ,STEPPER_DIRECTION direct){
	
	/* 
	
	512 for one full cycle 
	
	512/365=1.422222
	
	1.42*100=142
	
	( 142 * angle )and division it on 100
	 
	 
	
	*/
	
	if(direct==CW)
	{
		
		for(u32 i=0 ; i <((u32)142*angle)/100 ;i++)
		{
			STEPPER_UniPoler_CW() ;
		}
		
		
	}
	
	
	else if(direct==CCW) {
		
		for(u32 i=0 ; i <((u32)142*angle)/100 ;i++)
		{
			STEPPER_UniPoler_CCW() ;
		}
		
		
	}
	
}
void STEPPER_UniPoler_ByRotate(u8 n_rotate ,STEPPER_DIRECTION direct ){

	
	if(direct==CW)
	{
		for(u32 i=0 ; i <n_rotate*FULL_CYCLE_FUN4 ;i++)
		{
			STEPPER_UniPoler_CW() ;
		}
		
		
		
	}
	
	
	else if(direct==CCW) {
		
		for(u32 i=0 ; i <n_rotate*FULL_CYCLE_FUN4 ;i++)
		{
			STEPPER_UniPoler_CCW() ;
		}
		
		
	}


}
void STEPPER_UniPoler_OFF(void) {
	
	
	
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	
	
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;

	
	
}





