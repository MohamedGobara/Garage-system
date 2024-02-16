  
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "StdTypes.h"
#include "MemMaph.h"
#include "Utils.h"


typedef enum
{
	SPI_MASTER , 
	SPI_SLAVE
}SPI_MODE_status;


void SPI_Init(SPI_MODE_status mode ) ; 

u8 SPI_SendReceiveData_Busyw8(u8 data); 

void SPI_SendDataNoBlock(u8 data) ; 

u8 SPI_ReceiveDataNoBlock(void)  ;

u8 SPI_SLave_RecvivePeriodic(u8* pdata) ; 



void SPI_Interrupt_Enable(void) ;
void SPI_Interrupt_Disable(void) ;
void Spi_Set_callBack(void(*localfptr)(void)) ;

#endif /* SPI_INTERFACE_H_ */