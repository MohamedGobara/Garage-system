
#include "MemMaph.h"
#include "Utils.h"
#include "I2C_cfg.h"
#include "I2C_interface.h"


static void (*I2C_Report_Write_Collision_InterruptHandler)(void) = NULL;
static void (*I2C_DefaultInterruptHandle)(void) = NULL;
static void (*I2C_Report_Receive_Overflow_InterruptHandle)(void) = NULL;


Error_type I2C_Init(const I2C_Type* I2c_CopyObject) {
	
	
}

Error_type I2C_DeInit(const I2C_Type* I2c_CopyObject) {
	
	
	if(I2c_CopyObject!=NULL) {
		
		
		
		return OK ; 
	}
	else {
		
		
		return NOK ; 	
	}
	
}

Error_type I2C_Master_Send_Start(const I2C_Type* I2c_CopyObject) {
	
	if(I2c_CopyObject!=NULL) {
		
		
		
		return OK ;
	}
	else {
		
		
		return NOK ;
	}

}

Error_type I2C_Master_Send_RepStart(const I2C_Type* I2c_CopyObject) {
	
	
	if(I2c_CopyObject!=NULL) {
		
		
		
		return OK ;
	}
	else {
		
		
		return NOK ;
	}
	
}

Error_type I2C_Master_Send_Stop(const I2C_Type* I2c_CopyObject) {
	
	if(I2c_CopyObject!=NULL) {
		
		
		
		return OK ;
	}
	else {
		
		
		return NOK ;
	}
	
	
}

Error_type I2C_Master_SendData(const I2C_Type* I2c_CopyObject, u8 copu_u8Data ) {
	
	if(I2c_CopyObject!=NULL) {
		
		
		
		return OK ;
	}
	else {
		
		
		return NOK ;
	}
	
	
}

Error_type I2C_Master_ReceiveData(const I2C_Type* I2c_CopyObject,u8  copy_u8Ack ,  u8* copu_Ptru8Data ) {
	
	
	if(I2c_CopyObject!=NULL) {
		
		
		
		return OK ;
	}
	else {
		
		
		return NOK ;
	}
	
	
}