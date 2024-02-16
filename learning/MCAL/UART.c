#include "UART_interface.h"


static void (*fptr_TX)(void) = NULL_PTR ;

static void (*fptr_RX)(void) = NULL_PTR ;

void UART_init(void) {
	
	/* baud rate */
	UBRRL=51  ;  // 9600 baud rate , 8MHz  Oscillator Frequencies
	
	/*frame */
	//data bit , no parity , 1 stop
	
	/* double speed clear */
	CLR_BIT(UCSRA,U2X) ;
	
	/*enable*/
	SET_BIT(UCSRB,RXEN) ; // RECEIVER ENABLE
	SET_BIT(UCSRB,TXEN) ; // TRANSMITTER ENABLE
	
}


void UART_SendDatau8_BusyW8(u8 data) {
	while (!READ_BIT(UCSRA,UDRE)) ;
	UDR=data ;
}



u8 UART_ReceiveDatau8_BusyW8(void) { //busy w8
	while (!READ_BIT(UCSRA,RXC)) ;
	return UDR ;
}



u8 UART_ReceiveDatau8_periodic(u8* Pdata) {
	if (READ_BIT(UCSRA,RXC))  {
		*Pdata= UDR ;
		return TRUE ;
	}
	return FALSE ;
}



u8 UART_reciveCheckSum(u8* str){

	u16 result =0 , sum=0;
	
	u16 p1 =0,p2=0 ;
	
	result =UART_ReceiveDatau8_BusyW8() ;


	
	for(u8 i=0  ; str[i]!='#';i++){
		str[i] =UART_ReceiveDatau8_BusyW8() ;
		sum+=str[i] ;
	}
	
}




void UART_SendData_NoBlock(u8 data) {
	
	UDR= data ; 
}


u8 UART_ReceiveData_NoBlock(void) {


return UDR  ; 
}



void UART_RX_InterruptEnable(void) {
	
	SET_BIT(UCSRB,RXCIE) ;
}

void UART_RX_InterruptDisable(void) {
	
	CLR_BIT(UCSRB,RXCIE) ;
}


void UART_TX_InterruptEnable(void) {
	
	SET_BIT(UCSRB,TXCIE) ;
}

void UART_TX_InterruptDisable(void) {
	CLR_BIT(UCSRB,TXCIE) ;
	
}



void UART_TX_SetCallBack(void (*local_ptr)(void)) {
	
	fptr_TX=local_ptr ;
	
}


void UART_RX_SetCallBack(void (*local_ptr)(void)) {
	fptr_RX=local_ptr ;
}



ISR(UART_TX_vect){

	if(fptr_TX!=NULL_PTR){
		
		fptr_TX() ;
	}
}



ISR(UART_RX_vect){

	if(fptr_RX!=NULL_PTR){
		
		fptr_RX() ;
	}
}



