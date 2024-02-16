#include "UART_STACK.h"


static volatile u8* UART_STACK_arr[UART_STACK_SIZE] ;

void UART_STACK_Init(void){

STACK_SetStack(UART_STACK_arr , UART_STACK_SIZE) ; 
}



static stack_status_type stack_s_ff,   stack_s_f1;

static void uart_stack_rx(void) {
	u8 data   =  UART_ReceiveData_NoBlock() ;
	STACK_push(data) ; 
	
	
}

uartstack_status_type UART_STACK_pushReciveData(void) {
	
	UART_RX_SetCallBack(uart_stack_rx) ; 
	UART_RX_InterruptEnable() ; 
	
}

uartstack_status_type UART_STACK_popReciveData(u8* pdata) {
	
	 STACK_pop(&pdata) ; 
	
}

u8 UART_STACK_isEmpty(void) {
	
	if(STACK_isEmpty()){
		
		
		return TRUE ; 
	}
	else {
		
		return FALSE ; 
	}
	
}

u8 UART_STACK_isFull(void) {
	if(STACK_isFull()){
		
		
		return TRUE ;
	}
	else {
		
		return FALSE ;
	}
	
	
}