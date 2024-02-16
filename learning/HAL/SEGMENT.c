
#define F_CPU 8000000
#include <util/delay.h>

#include "MemMaph.h"
#include "SEGMENT_interface.h"


void SEGMENT_Decimal (u8 n) {
	
	DIO_WritePin(ONE,HIGH) ;
	DIO_WritePin(TWO,LOW) ;
	u8 arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	
	SEGMENT_PORT = arr[n]<<1 ;
	
}



void SEGMENT_Hex(u8 n){
	
	DIO_WritePin(ONE,HIGH) ;
	DIO_WritePin(TWO,LOW) ;

	SEGMENT_PORT = n<<1 ;

}


void SEGMENT_Mlx(u8 n){
	
	u8 arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	u8 p1=n%10 ;
	u8 p2= n/10  ;
	DIO_WritePin(ONE,HIGH) ; 
	SEGMENT_PORT=arr[p1]<<1  ;
	DIO_WritePin(TWO,LOW);
	_delay_ms(10) ;
	DIO_WritePin(TWO,HIGH) ;
	SEGMENT_PORT=arr[p2]<<1  ;
	DIO_WritePin(ONE,LOW) ;
	_delay_ms(10) ;
	

}



