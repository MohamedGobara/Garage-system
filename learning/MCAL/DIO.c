
/*
File: DIO.C
Version: 1.0
Date: 8-7-2032
Author: Mohamed Hussein
Description: This file contains the code for DIO.
*/

/********************** includes   *********************************************/
#include "MemMaph.h"
#include "StdTypes.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "Utils.h"
/********************** Helper Functions Declaration "prototype"   *************/

static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status) ; 


/*********************  Global Variable Defination    **************************/

/*********************  APIs Defination          *******************************/


void DIO_Init(void) {
	
	for (DIO_Pin_type pin = PINA0 ; pin<TOTAL_PINS ; pin++  )
	{
		DIO_InitPin(pin , PinsStatusArray[pin]) ;
	}
	
}

void DIO_TogglePin(DIO_Pin_type pin)  {
	
	switch(pin/8){
		case 0:
		TOG_BIT(PORTA,(pin%8));
		break;
		case 1:
		TOG_BIT(PORTB,(pin%8));
		break;
		case 2:
		TOG_BIT(PORTC,(pin%8));
		break;
		case 3:
		TOG_BIT(PORTD,(pin%8));
		break;
	}
	
	
}


void DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volt){
	switch(pin/8){
		case 0:
		SET_BIT(DDRA,(pin%8));
		WRITE_BIT(PORTA,(pin%8),volt);
		break;
		case 1:
		SET_BIT(DDRB,(pin%8));
		WRITE_BIT(PORTB,(pin%8),volt);
		break;
		case 2:
		SET_BIT(DDRC,(pin%8));
		WRITE_BIT(PORTC,(pin%8),volt);
		break;
		case 3:
		SET_BIT(DDRD,(pin%8));
		WRITE_BIT(PORTD,(pin%8),volt);
		break;
	}
}



DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin){
	switch(pin/8){
		case 0:
		if ( READ_BIT(PINA,(pin%8)))
		{
			return HIGH  ;
		}
		else {
			return LOW ;
		}
		break;
		
		case 1:
		if ( READ_BIT(PINB,(pin%8)))
		{
			return HIGH  ;
		}
		else {
			return LOW ;
		}
		break;
		
		case 2:
		if ( READ_BIT(PINC,(pin%8)))
		{
			return HIGH  ;
		}
		else {
			return LOW ;
		}
		break;
		
		case 3:
		if ( READ_BIT(PIND,(pin%8)))
		{
			return HIGH  ;
		}
		else {
			return LOW ;
		}
		break;
		
		
	}
	return LOW ;
}



void DIO_WritePort(DIO_Port_type port , u8 value) {
	
	switch(port) {
		
		case PA :
		PORTA = value ;
		break;
		
		case PB :
		PORTB = value ;
		break;
		
		case PC :
		PORTC = value ;
		break;
		
		case PD :
		PORTD = value ;
		break;
		
		
	}
	
	
}

/*********************  ISRs Defination          *******************************/

/*********************  Helper Function Defination    **************************/

static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status)
{
	switch(status){
		case INFREE:
		switch(pin/8){
			/* PORTA */
			 /* NO bit not value in register
			    0%8 => 0 1%8 => 1 2%8  => 2 
				8%8 => 0 9%8 => 1 10%8 => 2
				....etc
			 */
			
			case 0:
			CLR_BIT(PORTA,(pin%8));
			CLR_BIT(DDRA,(pin%8));
			break;
			/* PORTB */
			case 1:
			CLR_BIT(PORTB,(pin%8));
			CLR_BIT(DDRB,(pin%8));
			break;
			/* PORTC */
			case 2:
			CLR_BIT(PORTC,(pin%8));
			CLR_BIT(DDRC,(pin%8));
			break;
			/* PORTD */
			case 3:
			CLR_BIT(PORTD,(pin%8));
			CLR_BIT(DDRD,(pin%8));
			break;
		}
		break;
		case INPULL:
		switch(pin/8){
			case 0:
			CLR_BIT(DDRA,(pin%8));
			SET_BIT(PORTA,(pin%8));
			
			break;
			case 1:
			CLR_BIT(DDRB,(pin%8));
			SET_BIT(PORTB,(pin%8));
			
			break;
			case 2:
			CLR_BIT(DDRC,(pin%8));
			SET_BIT(PORTC,(pin%8));
			
			break;
			case 3:
			CLR_BIT(DDRD,(pin%8));
			SET_BIT(PORTD,(pin%8));
			
			break;
		}
		
		break;
		case  OUTPUT:
		switch(pin/8){
			case 0:
			SET_BIT(DDRA,(pin%8));
			CLR_BIT(PORTA,(pin%8));
			break;
			case 1:
			SET_BIT(DDRB,(pin%8));
			CLR_BIT(PORTB,(pin%8));
			break;
			case 2:
			SET_BIT(DDRC,(pin%8));
			CLR_BIT(PORTC,(pin%8));
			break;
			case 3:
			SET_BIT(DDRD,(pin%8));
			CLR_BIT(PORTD,(pin%8));
			break;
		}
		break;
		
	}
	
}




