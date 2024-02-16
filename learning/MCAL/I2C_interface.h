#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include "StdTypes.h"

/*************** Status Codes for Master Transmitter Mode ****************/

/* A START condition has been transmitted */
#define TWI_MT_STARTED 0x08
/* A repeated START condition has been transmitted */
#define TWI_MT_REPEATED 0x10
/* SLA+W has been transmitted ACK has been received */
#define TWI_MT_WDATA_ACK 0x18
/* SLA+W has been transmitted NOT ACK has been received */
#define TWI_MT_WDATA_NACK 0x20
/* Data byte has been transmitted ACK has been received */
#define TWI_MT_DATA_TRANS_ACK 0x28
/* Data byte has been transmitted NOT ACK has been received */
#define TWI_MT_DATA_TRANS_NACK 0x30
/* Arbitration lost in SLA+W or data bytes */
#define TWI_MT_ARB_LOST 0x38

/***************  Status Codes for Master Receiver Mode ****************/
/* SLA+R has been transmitted ACK has been received */
#define TWI_MR_RDATA_ACK 0x40
/* SLA+W has been transmitted NOT ACK has been received */
#define TWI_MR_RDATA_NACK 0x48
/* Data byte has been received ACK has been returned */
#define TWI_MR_DATA_RECEIVED_ACK 0x50
/* Data byte has been received NOT ACK has been returned */
#define TWI_MR_DATA_RECEIVED_NACK 0x58



/* ----------------- Macro Declarations -----------------*/
/* Stop Condition Indication */
#define I2C_STOP_BIT_DETECTED     1
#define I2C_STOP_BIT_NOT_DETECTED 0
/* Start Condition Indication */
#define I2C_START_BIT_DETECTED     1
#define I2C_START_BIT_NOT_DETECTED 0
/* I2C : Master or Slave Mode */
#define I2C_MSSP_MASTER_MODE 1
#define I2C_MSSP_SLAVE_MODE  0
/* General Call Enable */
#define I2C_GENERAL_CALL_ENABLE   1
#define I2C_GENERAL_CALL_DISABLE  0
/* Master Mode Receive Enable */
#define I2C_MASTER_RECEIVE_ENABLE   1
#define I2C_MASTER_RECEIVE_DISABLE  0
/* Acknowledge Status bit (Master Transmit mode only) */
#define I2C_ACK_RECEIVED_FROM_SLAVE     0
#define I2C_ACK_NOT_RECEIVED_FROM_SLAVE 1
/* Acknowledge Data bit (Master Receive mode only) */
#define I2C_MASTER_SEND_ACK  0
#define I2C_MASTER_SEND_NACK 1


/* ----------------- Macro Functions Declarations -----------------*/



typedef struct {

	u8 I2C_Mode:1 ;				/* I2C : Master or Slave Mode */
	u8 I2C_GCall:1 ;
	u8 I2C_Master_Receive_Mode:1 ;
	u8 I2C_Reserved:5 ;
			
}I2C_Config_T;



typedef struct {
	
	u8 I2C_clock ;									/* Master Clock Frequency */
	void (*I2C_Report_Write_Collision) (void) ; 	/* Write Collision Indicator */
	void (*I2C_Report_Receive_Overflow) (void) ;	/* Default Interrupt Handler */
	void (*I2C_DefaultInterruptHandler) (void) ;	/* Receive Overflow Indicator */
	I2C_Config_T  I2C_cfg  ;						 /* I2C Configurations */

}I2C_Type;


/******************  MASTER  ************************/

Error_type I2C_Init(const I2C_Type* I2c_CopyObject) ; 

Error_type I2C_DeInit(const I2C_Type* I2c_CopyObject) ; 

Error_type I2C_Master_Send_Start(const I2C_Type* I2c_CopyObject) ;

Error_type I2C_Master_Send_RepStart(const I2C_Type* I2c_CopyObject) ;

Error_type I2C_Master_Send_Stop(const I2C_Type* I2c_CopyObject) ;

Error_type I2C_Master_SendData(const I2C_Type* I2c_CopyObject, u8 copu_u8Data ) ;

Error_type I2C_Master_ReceiveData(const I2C_Type* I2c_CopyObject,u8  copy_u8Ack ,  u8* copu_Ptru8Data ) ;


/******************  SLAVE  ************************/

void I2C_Slave_SetAddress(u8  copy_u8Adderss) ;


u8 I2C_Slave_Receive_Data(void) ;

/******************* slave   ************************/
#endif /* I2C_INTERFACE_H_ */