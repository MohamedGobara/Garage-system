#include "Utils.h"
#include "MemMaph.h"
#include "StdTypes.h"
#include "EX_INTERRUPT_interface.h"

/**********************Pointer to function to be assigned to ISR *******************/

static void (*INT0_fptr) (void) = NULL_PTR ;
static void (*INT1_fptr) (void) = NULL_PTR ;
static void (*INT2_fptr) (void) = NULL_PTR ;


void EX_INTERRUPT_PinState(INTERRUPT_ExInterrupt_pin pin  ,INTERRUPT_ExInterrupt_senceControl senceControl )  {
	
	/*  pin is disable */
	
	if(senceControl==DISABLE_I) {
		
		switch(pin) {
			case INT0_PIN :
			CLR_BIT(GICR,INT0) ;
			break;
			case INT1_PIN :
			CLR_BIT(GICR,INT1) ;
			break;
			case INT2_PIN :
			CLR_BIT(GICR,INT2) ;
			break;
		}
		
	}
	/* pin is enable */
	else  {
		switch(pin) {
			case INT0_PIN :
			SET_BIT(GICR,INT0) ;
			break;
			case INT1_PIN :
			SET_BIT(GICR,INT1) ;
			break;
			case INT2_PIN :
			SET_BIT(GICR,INT2) ;
			break;
		}
		
		if(pin==INT1_PIN) {
			switch (senceControl) {
				
				case LOW_LEVEL :
				CLR_BIT(MCUCR,ISC11) ;
				CLR_BIT(MCUCR,ISC10) ;
				break ;

				case CHANGE :
				CLR_BIT(MCUCR,ISC11) ;
				SET_BIT(MCUCR,ISC10) ;
				break ;

				case FALLING :
				SET_BIT(MCUCR,ISC11) ;
				CLR_BIT(MCUCR,ISC10) ;
				break ;

				case RISING :
				SET_BIT(MCUCR,ISC11) ;
				SET_BIT(MCUCR,ISC10) ;
				break 	 ;
			}
		}
		
		else if(pin==INT0_PIN) {
			switch (senceControl) {
				
				case LOW_LEVEL :
				CLR_BIT(MCUCR,ISC01) ;
				CLR_BIT(MCUCR,ISC00) ;
				break ;
				case CHANGE :
				CLR_BIT(MCUCR,ISC01) ;
				SET_BIT(MCUCR,ISC00) ;
				break ;

				case FALLING :
				SET_BIT(MCUCR,ISC01) ;
				CLR_BIT(MCUCR,ISC00) ;
				break ;

				case RISING :
				SET_BIT(MCUCR,ISC01) ;
				SET_BIT(MCUCR,ISC00) ;
				break ;
				
			}
		}
	}
	
}


/*****************************call back function***************************/

void EX_INTERRUPT_SetCallBack(INTERRUPT_ExInterrupt_pin pin  , void (*local_ptr) (void)){

	switch(pin) {
		case INT0_PIN :
		INT0_fptr= local_ptr ;
		break;
		case INT1_PIN :
		INT1_fptr= local_ptr ;
		break;
		case INT2_PIN :
		INT2_fptr= local_ptr ;
		break;
	}

}


/*****************************ISR With call back function***************************/

ISR(INT0_vect){
	
	
	if(INT0_fptr!=NULL_PTR) {
		
		INT0_fptr() ;
	}
	
}



ISR(INT1_vect){
	
	
	if(INT1_fptr!=NULL_PTR) {
		
		INT1_fptr() ;
	}
	
}




ISR(INT2_vect){
	
	
	if(INT2_fptr!=NULL_PTR) {
		
		INT2_fptr() ;
	}
	
}

/*****************************ISR With call out function ***************************/


/*
ISR(INT0_vect){

INT0_F() ;

}



ISR(INT1_vect){


INT1_F() ;

}




ISR(INT2_vect){


INT2_F() ;

}


*/