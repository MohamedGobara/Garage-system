

#ifndef UART_STACK_H_
#define UART_STACK_H_
#include "StdTypes.h"
#include "STACK.h"

#define  UART_STACK_SIZE  5 
typedef enum {
	
	UART_STACK_FULL ,
	UART_STACK_EMPTY ,
	UART_STACK_DONE
	
	}uartstack_status_type;

void UART_STACK_Init();

uartstack_status_type UART_STACK_pushReciveData(void) ; 

uartstack_status_type UART_STACK_popReciveData(u8* pdata) ;

u8 UART_STACK_isEmpty(void) ;

u8 UART_STACK_isFull(void) ;

#endif /* UART_STACK_H_ */