

/********************** includes   *********************************************/
#include "UART_Services.h"

/********************** Helper Functions Declaration "prototype"   *************/

static void Send_str(void) ;


static void Receive_str(void) ;


static void ReceiveDockLight_str(void)  ;

/*********************  Global Variable Defination    **************************/

volatile  u8 finishedRx_f = 0 ;

/*********************  static Variable Defination    **************************/

static volatile u8* tx_str   ;
static volatile u8* rx_str;
static volatile  u8 finishedTx_f =1 ;
static volatile u8 flag_sendStr=1 ;

/*********************  APIs Defination          *******************************/


/*  Synchronous function */

void UART_SendString_BusyW8(u8* str) {
	
	
	u8 i;
	
	for(i=0; str[i];i++) {
		
		
		UART_SendDatau8_BusyW8(str[i]) ;
	}
	//UART_SendDatau8_BusyW8(0x0d) ;
}


//0x0d -> enter (hex)



void UART_ReceiveString_BusyW8(u8* str)  {
	
	u8 i=0;
	str[i] = UART_ReceiveDatau8_BusyW8() ;
	for(; str[i]!=0x0d;) {
		i++ ;
		str[i] = UART_ReceiveDatau8_BusyW8() ;
	}
	str[i]=0 ;
	
}

void UART_ReceiveStringDockLight(u8* str) {
	static u8 first_use = 0 ;
	s8 i=0;
	if(first_use==0) {
		
		
		
		str[i] = UART_ReceiveDatau8_BusyW8() ;
		for(; str[i]!=13;) {
			i++ ;
			str[i] = UART_ReceiveDatau8_BusyW8() ;
		}
		str[i]=0 ;
		first_use=1 ;
	}
	else
	
	{
		str[i] = UART_ReceiveDatau8_BusyW8() ;
		i=-1;
		for(; str[i]!=13;) {
			i++ ;
			str[i] = UART_ReceiveDatau8_BusyW8() ;
		}
		str[i]=0 ;
	}
	
}



void UART_SendNum(u32 num) {
	
	UART_SendDatau8_BusyW8((u8)num);
	UART_SendDatau8_BusyW8((u8)(num>>8)) ;
	UART_SendDatau8_BusyW8((u8)(num>>16)) ;
	UART_SendDatau8_BusyW8((u8)(num>>24)) ;
	
	
	/*u8* p =&num ;
	
	
	UART_SendDatau8(*p) ;
	UART_SendDatau8(*(p+1)) ;
	UART_SendDatau8(*(p+2)) ;
	UART_SendDatau8(*(p+3)) ; */
}

u32 UART_ReceiveNum(void) {
	
	u32 num=0 ;
	
	u8 p1 = UART_ReceiveDatau8_BusyW8() ;
	u8 p2 = UART_ReceiveDatau8_BusyW8() ;
	u8 p3 = UART_ReceiveDatau8_BusyW8() ;
	u8 p4 = UART_ReceiveDatau8_BusyW8() ;
	num = p1|p2<<8|(u32)p3<<16|(u32)p4<<24 ;
	
	
	/*u8* p =&num ;
	
	p[0] = UART_ReceiveDatau8_BusyW8();
	p[1] = UART_ReceiveDatau8_BusyW8();
	p[2] = UART_ReceiveDatau8_BusyW8();
	p[3] = UART_ReceiveDatau8_BusyW8();*/
	return num ;
}




u8 check_endian(void){

	
	u32 num =1 ;
	
	
	u8 *p =&num ;
	
	if(*p==1){
		
		return TRUE ; // little  ;
		
		
	}
	else {
		
		return FALSE ;   //big
	}



}



u32 endian_convert_u32(u32 x) {


	return (x>>24) |(x<<24) | ((x<<8)&(0x00ff0000))|((x>>8)&(0x0000ff00)) ;

}



void UART_SendStringCheckSum(u8* str) {
	
	u8 l   ;
	u16 sum=0;
	for(l=0 ; str[l];l++)  ; // get length of string
	UART_SendDatau8_BusyW8(l)   ;
	for (l=0;str[l] ; l++)
	{
		
		UART_SendDatau8_BusyW8(str[l]) ;
		sum+=str[l]  ; // sum of data
		
	}
	UART_SendDatau8_BusyW8((u8)sum) ;
	UART_SendDatau8_BusyW8((u8)(sum>>8)) ;

}

void UART_ReceiveStringCheckSum(u8* str) {
	
	
	
	
	u8 l,i, p1,p2 ;
	u16 sumdata=0 , sum  =0  ;
	l = UART_ReceiveDatau8_BusyW8() ; //receive length
	
	
	//receive data
	for(i= 0; i< l ; i++ ) {
		
		str[i] ; UART_ReceiveDatau8_BusyW8() ;
		sum+=str[i] ;
	}
	str[i]= 0 ;
	
	//get sum of data
	p1=UART_ReceiveDatau8_BusyW8() ;
	p2=UART_ReceiveDatau8_BusyW8() ;
	
	sumdata=(u16)p1|(u16)p2<<8 ;
	
	// compare real data with sum of data
	if(sum==sumdata){
		
		return TRUE ;
	}
	else
	return FALSE ;
}

void UART_SendString_Asynch(u8* str) {
	finishedTx_f=0  ;
	UART_TX_SetCallBack(Send_str) ;
	tx_str= str  ;
	UART_SendData_NoBlock(str[0]) ;
	UART_TX_InterruptEnable() ;
}


void UART_SendString_NoBlock(u8* str) {
	
	static u8 i=0 ;
	
	if(flag_sendStr==1){
		
		if(str[i]!=0){
			
			UART_SendString_NoBlock(str[i++]) ;
			
		}
		flag_sendStr =0 ;
		
	}
	
}



void UART_ReceiveString_Asynch(u8* str) {
	rx_str= str ;
	UART_RX_SetCallBack(Receive_str) ;
	UART_RX_InterruptEnable() ;
	
}


u8  UART_ReceiveString_AsynchFinshedCheck(void) {
	
	
	
	if (finishedRx_f==1)
	{
		return TRUE ;
	}
	else {
		
		return FALSE ;
	}
}


void UART_ReceiveStringDockLight_Asynch(u8* str)  {
	rx_str= str ;
	UART_RX_SetCallBack(ReceiveDockLight_str) ;
	UART_RX_InterruptEnable() ;

}

/*********************  ISRs Defination          *******************************/

/*********************  Helper Function Defination    **************************/

/* Asynchronous function */



static void Send_str(void){

	static u8 i = 1 ;
	if(finishedTx_f==0)
	{
		if(tx_str[i]!=0){
			
			UART_SendData_NoBlock(tx_str[i++]) ;
		}
		else {
			//UART_SendData_NoBlock(0x0d) ;
			finishedTx_f=1 ;
			i=1 ;
		}
	}
}











static void Receive_str(void) {
	
	static u8 i=0 ;
	
	rx_str[i]=UART_ReceiveData_NoBlock() ;
	if(rx_str[i]!=0x0d){
		i++ ;
	}
	else {
		rx_str[i]= 0;
		finishedRx_f=1 ;
		i=0 ;
	}
	
	
	
	
}




static void ReceiveDockLight_str(void){

	static u8 first_use = 0 ;
	s8 i=0;
	if(first_use==0) {
		
		rx_str[i] = UART_ReceiveData_NoBlock() ;
		
		
		if(rx_str[i]!=13){
			
			i++ ;
		}
		else {
			
			rx_str[i] = 0 ;
			finishedRx_f=1 ;
			first_use= 1 ;
		}
		
	}
	else
	
	{
		
		rx_str[i] = UART_ReceiveData_NoBlock() ;
		
		i=-1 ;
		
		if(rx_str[i]!=13){
			
			i++ ;
		}
		else {
			
			rx_str[i] = 0 ;
			finishedRx_f=1 ;
		}
		
		
	}
	

}
