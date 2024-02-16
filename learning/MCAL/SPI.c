#include "SPI_interface.h"


static void (*Spi_Fptr) (void)= NULL_PTR ;


void SPI_Init(SPI_MODE_status mode ) {
	
	
	if(mode==SPI_MASTER) {
		
		// Clock 2MHZ
		SET_BIT(SPCR,MSTR) ;
	}
	else if(mode==SPI_SLAVE) {
		
		
		CLR_BIT(SPCR,MSTR) ;
	}
	
	// SPI ENABLE
	SET_BIT(SPCR, SPE)  ;
	
}

u8 SPI_SendReceiveData_Busyw8(u8 data) {
	SPDR=data ;
	while(!READ_BIT(SPSR,SPIF)) ;
	return SPDR ;
	
	
}


u8 SPI_SLave_RecvivePeriodic(u8* pdata) {
	if(READ_BIT(SPSR,SPIF)){
		*pdata =  SPDR ;
		return TRUE ;
	}
	else {
		return FALSE ;
	}
	
	
}


void SPI_SendDataNoBlock(u8 data) {
	
	SPDR = data  ;
	
	
}

u8 SPI_ReceiveDataNoBlock(void)  {
	
	
	return SPDR ;
}



void SPI_Interrupt_Enable(void){
	SET_BIT(SPCR,SPIE);
}
void SPI_Interrupt_Disable(void){
	CLR_BIT(SPCR,SPIE);
}
void Spi_Set_callBack(void(*localfptr)(void)){
	Spi_Fptr=localfptr;
	
}
ISR(SPI_STC_vect){
	if(Spi_Fptr!=NULL_PTR){
		Spi_Fptr();
	}
}