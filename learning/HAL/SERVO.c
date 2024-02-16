#include "SERVO_interface.h"



void SERVO_init(void)  {
	
	Timer1_Init(TIMER1_FASTPWM_OCRA_TOP_MODE,TIMER1_SCALER_8) ;
	
	OCR1A=19999 ;
	
	Timer1_OCRB1Mode(OCRB_NON_INVERTING) ;
}

void SERVO_SetAngle(u8 angle) {
	
	OCR1B=((u32)(angle*(u32)1000)/180)+999 ;

}


void SERVO_SG90_SetAngle(u8 angle) {

	OCR1B=((u32)(angle*(u32)2000)/180)+499 ; 

}



