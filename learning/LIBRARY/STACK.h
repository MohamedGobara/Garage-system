
#ifndef STACK_H_
#define STACK_H_
#include "StdTypes.h"


typedef enum {
	
	STACK_FULL ,
	STACK_EMPTY ,
	DONE
	
}stack_status_type;



void STACK_SetStack(u8* stacklocation,u8 size) ;


stack_status_type STACK_push(u8 data) ;

stack_status_type STACK_pop(u8* pdata) ;

u8 STACK_isEmpty(void) ;

u8 STACK_isFull(void) ;



#endif /* STACK_H_ */