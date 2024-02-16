
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_


#include "StdTypes.h"

#include "DIO_interface.h"
#include "Timers_interface.h"

#define F_CPU 8000000
#include <util/delay.h>



#define  US1   PIND0
#define  US2   PIND7
#define  US3   PIND3
#define  US4   PIND4


typedef enum{
	ULTRASONIC_1=PINC0,
	ULTRASONIC_2=PIND1,
	ULTRASONIC_3=PIND2,
	ULTRASONIC_4=PIND3,
}ULTRASONIC_type2;



typedef   DIO_Pin_type ULTRASONIC_type;



void ULTRASONIC_Init(void);


u8 ULTRASONIC_GetDistance(ULTRASONIC_type2 us,u16* pdistance );

#endif /* ULTRASONIC_H_ */