

#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

#include "StdTypes.h"
#include "Timers_interface.h"


void SERVO_init(void) ;


void SERVO_SetAngle(u8 angle) ; 


void SERVO_SG90_SetAngle(u8 angle) ;



#endif /* SERVO_INTERFACE_H_ */