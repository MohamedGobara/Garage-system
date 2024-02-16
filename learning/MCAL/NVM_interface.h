
#ifndef NVM_H_
#define NVM_H_

#include "StdTypes.h"
#include "MemMaph.h"
#include "Utils.h"
#include "MemMaph.h"

void NVM_Write8(u16 address , u8 data) ;

void NVM_Write16(u16 address , u16 data)   ;

void NVM_Write32(u16 address , u32 data)  ; 

u8 NVM_Raed8(u16 address ) ;

u16 NVM_Raed16(u16 address ) ;

u32 NVM_Raed32(u16 address ) ;

#endif /* NVM_H_ */