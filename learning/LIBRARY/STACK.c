#include "STACK.h"




static u8* stack  , STACK_SIZE; 

static volatile u8 sp=0;


void STACK_SetStack(u8* stacklocation,u8 size) {
	
	stack= stacklocation ; 
	STACK_SIZE =  size ; 
}

stack_status_type STACK_push(u8 data) {
	
	if(sp==STACK_SIZE) {
		
		
		return STACK_FULL ;
	}
	else {
		stack[sp++]= data  ;
		return DONE ;
	}
	
}

stack_status_type STACK_pop(u8* pdata) {
	
	
	
	if (sp==0)
	{
		return STACK_EMPTY ;
	}
	else {
		
		*pdata = stack[--sp] ;
		return DONE ;
	}
}

u8 STACK_isEmpty(void) {
	
	
	if (sp==0)
	{
		return TRUE ;
	}
	else {
		return FALSE ;
	}
}

u8 STACK_isFull(void) {
	if (sp==STACK_SIZE)
	{
		return TRUE ;
	}
	else {
		return FALSE ;
	}
	
}