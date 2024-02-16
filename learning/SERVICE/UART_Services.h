
#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_


#include "StdTypes.h"
#include "UART_interface.h"
#include "Utils.h"




/*  Synchronous function */
void UART_SendString_BusyW8(u8* str) ;

void UART_ReceiveString_BusyW8(u8* str) ;

void UART_ReceiveStringDockLight(u8* str)  ; 

void UART_SendNum(u32 num) ;

u32 UART_ReceiveNum(void) ;

u8 check_endian(void) ; 

u32 endian_convert_u32(u32 x) ; 

void UART_SendStringCheckSum(u8* str) ;

void UART_ReceiveStringCheckSum(u8* str) ;

/* Asynchronous function */


void UART_SendString_Asynch(u8* str) ;


void UART_SendString_NoBlock(u8* str) ;

void UART_ReceiveString_Asynch(u8* str) ;

u8  UART_ReceiveString_AsynchFinshedCheck(void) ;

void UART_ReceiveStringDockLight_Asynch(u8* str)  ;

#endif /* UART_SERVICES_H_ */