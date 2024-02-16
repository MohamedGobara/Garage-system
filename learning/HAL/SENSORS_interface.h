


#ifndef SENSORS_H_
#define SENSORS_H_

#include "StdTypes.h"
#include "ADC_interface.h"
#include "SENSORS_cfg.h"



/************ return temp C*10  ******************/
u16 SENSORS_TempRead(void) ;

/************ MPX Sensor ***********************/
u16 SENSORS_MpxRead(void) ;

/************ GAS Sensor - MQ2 ***********************/
u16 SENSORS_SmokeRaed(void) ;


u8SENSORS_NTC10KGetTemp(void) ;


#endif /* SENSORS_H_ */