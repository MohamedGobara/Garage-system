/*
File: DIO_private.C
Version: 1.0
Date: 08-07-2023
Author: Mohamed Hussein
Description: This file contains declaration of private functions related to DIO
*/


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status) ;  

extern DIO_PinStatus_type PinsStatusArray[TOTAL_PINS]  ;


#endif /* DIO_PRIVATE_H_ */