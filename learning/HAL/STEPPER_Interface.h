
#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

#include "DIO_interface.h"
#include "StdTypes.h"


typedef enum {
	CW ,
	CCW
}STEPPER_DIRECTION;


void STEPPER_BiPoler_CW(void);
void STEPPER_BiPoler_CCW(void);


void STEPPER_UniPoler_OFF(void);

void STEPPER_UniPoler_CW(void);
void STEPPER_UniPoler_CCW(void);


void STEPPER_UniPoler_CW_HS(void);
void STEPPER_UniPoler_CCW_HS(void);



void STEPPER_UniPoler_ByAngle(u32 angle ,STEPPER_DIRECTION direct);

void STEPPER_UniPoler_ByRotate(u8 n_rotate ,STEPPER_DIRECTION direct) ;

#endif /* STEPPER_INTERFACE_H_ */