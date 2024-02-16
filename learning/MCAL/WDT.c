#include "WDT.h"


void WDT_start(WDT_TIMEOUT timeOut) {
	
	/* watchdog timer enable */
	
	u8 temp =0x08;
	/* set time out */
	temp |= timeOut ; 
	/* start watchdog */
	WDTCR|=(1<<WDTOE)|(1<<WDE) ;
	/* put time out with enable bit in register */
	WDTCR=temp;
}

void WDT_stop(void) {
	/* start watchdog */
	WDTCR|=(1<<WDTOE)|(1<<WDE) ;
	/* stop watchdog */
	WDTCR=0 ; 

}


