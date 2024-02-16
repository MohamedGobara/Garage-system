#include "NVM_interface.h"


void NVM_Write8(u16 address , u8 data)  {
	
	/* wait previous write , wait EEWE */
	while(READ_BIT(EECR,1))   ;
	
	/* Set up address and data registers */
	
	EEAR = address ;
	EEDR = data ;
	
	/* Write logical one to EEMWE */
	SET_BIT(EECR ,2  ) ;
	
	
	/* Start  write by write one to  EEWE */
	SET_BIT(EECR ,1  ) ;
	
}




void NVM_Write16(u16 address , u16 data)  {
	
	NVM_Write8(address,data) ;
	NVM_Write8(address+1,data>>8) ;
}



void NVM_Write32(u16 address , u32 data)  {
	
	NVM_Write8(address,data) ;
	NVM_Write8(address+1,data>>8) ;
	NVM_Write8(address+2,data>>16) ;
	NVM_Write8(address+3,data>>24) ;
}




u8 NVM_Raed8(u16 address )  {
	
	
	/* wait previous write , wait EEWE */
	while(READ_BIT(EECR,1)) ;
	
	
	/* Set up address and data registers */
	
	EEAR = address ;
	
	/* Start  read by write one to  EERE */
	SET_BIT(EECR ,0 ) ;
	
	return  EEDR ;
}


u16 NVM_Raed16(u16 address )  {
	
	u16 data   = 0  , temp =0  ;
	
	temp  = NVM_Raed8(address)  ;
	data = temp ;
	temp =  NVM_Raed8(address+1) ;
	data =  (temp<<8 ) | data  ;
	return data  ;
}


u32 NVM_Raed32(u16 address )  {
	
	u32 data   = 0  , temp = 0  ;
	temp  = NVM_Raed8(address)  ;
	data = temp ;
	temp =  NVM_Raed8(address+1) ;
	data =  (temp<<8 ) | data ;
	temp =  NVM_Raed8(address+2) ;
	data =  (temp<<16 ) | data ;
	temp =  NVM_Raed8(address+3) ;
	data =  (temp<<24 ) | data ;
	
	return data ;
	}