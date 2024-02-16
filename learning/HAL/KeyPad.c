
#include "StdTypes.h"
#include "DIO_interface.h"
#include "KeyPad_interface.h"
#include "KeyPad_cfg.h"
#include "KeyPad_private.h"




void KeyPad_Init(void) {
	
	DIO_WritePin(FIRST_OUTPUT,HIGH) ;
	DIO_WritePin(FIRST_OUTPUT+1,HIGH) ;
	DIO_WritePin(FIRST_OUTPUT+2,HIGH) ;
	DIO_WritePin(FIRST_OUTPUT+3,HIGH) ;

	
}

extern const u8 KeysArray[ROWS][COLUMNS] ;
u8 KeyPad_GetKey(void){
	
	u8 key =NO_KEY , r , c ;
	
	for( r=0 ; r<ROWS ; r++){
		
		DIO_WritePin(FIRST_OUTPUT+r,LOW) ;
		
		for ( c=0;  c <COLUMNS ; c++)
		{
			if (DIO_ReadPin(FIRST_INPUT+c)==LOW)
			{
				key = KeysArray[r][c] ;
				while(DIO_ReadPin(FIRST_INPUT+c)==LOW) ; 
			}
			
			
			
		}
		DIO_WritePin(FIRST_OUTPUT+r,HIGH) ;
		
	}
	
	return key ; 
	
	
	
	
}
