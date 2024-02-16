
#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_


typedef enum {
	
    M1 , 
	M2 ,
	M3 , 
	M4
	
	
	}MOTOR_Type;
	
	

void MOTOR_Stop(MOTOR_Type motor) ; 

void MOTOR_CW(MOTOR_Type motor) ;

void MOTOR_CCW(MOTOR_Type motor) ;






#endif /* MOTOR_INTERFACE_H_ */