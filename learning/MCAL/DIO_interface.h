
/*
File: DIO.h
Version: 1.0
Date: 08-07-2023
Author: Mohamed Hussein
Description: This file contains declaration functions of DIO 

*/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/********************** includes   *********************************************/

#include "StdTypes.h"

/********************** Macro Declarations   ***********************************/

/*********************  Macro Fucnction Declarations  **************************/

/*********************  Data Type Declarations   *******************************/

typedef enum {

	OUTPUT,

	INFREE ,

	INPULL

}DIO_PinStatus_type ;

typedef enum {
	
	PA,
	PB,
	PC,
	PD
	
}DIO_Port_type ;


typedef enum {
	
	LOW=0,
	HIGH
	
}DIO_PinVoltage_type ;


typedef enum {
	
	PINA0 ,
	PINA1 ,
	PINA2 ,
	PINA3 ,
	PINA4 ,
	PINA5 ,
	PINA6 ,
	PINA7 ,
	PINB0 ,
	PINB1 ,
	PINB2 ,
	PINB3 ,
	PINB4 ,
	PINB5 ,
	PINB6 ,
	PINB7 ,
	PINC0 ,
	PINC1 ,
	PINC2 ,
	PINC3 ,
	PINC4 ,
	PINC5 ,
	PINC6 ,
	PINC7 ,
	PIND0 ,
	PIND1 ,
	PIND2 ,
	PIND3 ,
	PIND4 ,
	PIND5 ,
	PIND6 ,
	PIND7 ,
	TOTAL_PINS
	
}DIO_Pin_type ;


/*********************  Software Interfaces Declarations "APIs"    *************/

/* THis function  set the default mode pin according to your configuration in file "Dio_cfg.c" */  
void DIO_Init(void) ;

/* THis function reads any pin by passing any pin from DIO_Pin_type enum */ 
DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin) ;

/* This function writes on any pin by passing any pin from DIO_Pin_type enum */ 
void DIO_WritePin (DIO_Pin_type pin,DIO_PinVoltage_type volt) ;

/* THis function TOOGLES any pin by passing any pin from DIO_Pin_type enum */ 
void DIO_TogglePin (DIO_Pin_type pin) ;

/* This function writes on any port by passing from DIO_Port_type enum */ 
void DIO_WritePort(DIO_Port_type port , u8 value) ;


#endif /* DIO_INTERFACE_H_ */