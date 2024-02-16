
#ifndef UART_CQUEUE_H_
#define UART_CQUEUE_H_

#include "StdTypes.h"

#define  CQUEUE_SIZE 5

typedef enum {
	
	CQUEUE_FULL ,
	CQUEUE_EMPTY,
	CQUEUE_DONE
	}Cir_queue_status;




Cir_queue_status UART_CQUEUE_DeQueue(u8 data) ;




Cir_queue_status UART_CQUEUE_EnQueue(u8* data) ;



u8 UART_CQUEUE_IsEmpty(void) ;



u8 UART_CQUEUE_IsFull(void) ;


#endif /* UART_CQUEUE_H_ */