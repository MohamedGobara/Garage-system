#include "DIO_interface.h"
#include "MOTOR_cfg.h"
#include "MOTOR_Interface.h"
#include "StdTypes.h"
#include "MOTOR_private.h"




void MOTOR_Stop(MOTOR_Type motor) {
	
	DIO_WritePin(MotorPinsArray[motor][IN1] , LOW) ; 
	DIO_WritePin(MotorPinsArray[motor][IN2] , LOW) ;


	
}
  
void MOTOR_CW(MOTOR_Type motor){
	
		
		DIO_WritePin(MotorPinsArray[motor][IN1] , HIGH) ;
		DIO_WritePin(MotorPinsArray[motor][IN2] , LOW) ;


		
	
}  

void MOTOR_CCW(MOTOR_Type motor) {
	
	
	
	DIO_WritePin(MotorPinsArray[motor][IN1] , LOW) ;
	DIO_WritePin(MotorPinsArray[motor][IN2] , HIGH) ;


		
}

