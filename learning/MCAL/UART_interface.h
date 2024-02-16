
#ifndef UART_H_
#define UART_H_


#include "StdTypes.h"
#include "MemMaph.h"
#include "Utils.h"
#include "UART_cfg.h"

void UART_init(void) ; 

void UART_SendDatau8_BusyW8(u8 data) ;

u8 UART_ReceiveDatau8_BusyW8(void) ;

u8 UART_ReceiveDatau8_periodic(u8* data) ;


void UART_RX_InterruptEnable(void) ; 

void UART_RX_InterruptDisable(void) ;


void UART_TX_InterruptEnable(void) ;

void UART_TX_InterruptDisable(void) ;

void UART_TX_SetCallBack(void (*local_ptr)(void)) ; 


void UART_RX_SetCallBack(void (*local_ptr)(void)) ;


void UART_SendData_NoBlock(u8 data) ;


u8 UART_ReceiveData_NoBlock(void) ;

#endif /* UART_H_ */