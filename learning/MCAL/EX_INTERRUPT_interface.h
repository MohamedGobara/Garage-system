#ifndef INTERRUPT_INTERFACE_H_
#define INTERRUPT_INTERFACE_H_


typedef enum {
	
	INT0_PIN ,
	INT1_PIN ,
	INT2_PIN
	
}INTERRUPT_ExInterrupt_pin;

typedef enum {
	DISABLE_I ,
	LOW_LEVEL ,
	CHANGE ,
	FALLING,
	RISING
	
}INTERRUPT_ExInterrupt_senceControl;



void EX_INTERRUPT_PinState(INTERRUPT_ExInterrupt_pin pin  ,INTERRUPT_ExInterrupt_senceControl senceControl ) ;

void EX_INTERRUPT_SetCallBack(INTERRUPT_ExInterrupt_pin pin  , void (*local_ptr) (void)) ; 

#endif /* INTERRUPT_INTERFACE_H_ */