
#ifndef WDT_H_
#define WDT_H_

#include "StdTypes.h"
#include "MemMaph.h"
#include "Utils.h"


typedef enum WDT_time {
	WDT_TIMEOUT_16ms ,
	WDT_TIMEOUT_32ms ,
	WDT_TIMEOUT_65ms ,
	WDT_TIMEOUT_130ms ,
	WDT_TIMEOUT_260ms ,
	WDT_TIMEOUT_520ms ,
	WDT_TIMEOUT_1000ms ,
	WDT_TIMEOUT_2100ms
	
}WDT_TIMEOUT;


void WDT_start(WDT_TIMEOUT timeOut) ; 

void WDT_stop(void) ;


#endif /* WDT_H_ */