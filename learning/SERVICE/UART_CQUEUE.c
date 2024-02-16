#include "UART_CQUEUE.h"


static u8 CQUEUE_arr[CQUEUE_SIZE] ;

static u8 front =-1  , rear=-1 ;


u8 UART_CQUEUE_IsEmpty(void) {
	
	if (front == -1) {
		
		return TRUE;
	}
	else
	return FALSE;
	
}



u8 UART_CQUEUE_IsFull(void) {
	
	if ((front == rear + 1) || (front == 0 && rear == CQUEUE_SIZE - 1))
	return TRUE;
	else
	return FALSE ;
	
}


Cir_queue_status UART_CQUEUE_DeQueue(u8 data) {
	
	
	if (UART_CQUEUE_IsFull())
	{
		return  CQUEUE_FULL ;
	}
	else {
		if (front == -1) front = 0;
		rear = (rear + 1) % CQUEUE_SIZE;
		CQUEUE_arr[rear] = data;
		return  CQUEUE_DONE ;
	}
}




Cir_queue_status UART_CQUEUE_EnQueue(u8* data) {
	
	
	if (UART_CQUEUE_IsEmpty()) {
		
		return CQUEUE_EMPTY;
	}
	else {
		data = CQUEUE_arr[front];
		if (front == rear) {
			front = -1;
			rear = -1;
		}
		// Q has only one element, so we reset the
		// queue after dequeing it. ?
		else {
			front = (front + 1) % CQUEUE_SIZE;
		}
		return CQUEUE_DONE;
	}
}


