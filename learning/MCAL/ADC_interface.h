
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "StdTypes.h"
#include "MemMaph.h"
#include "Utils.h"

typedef enum{
	
	VREF_AREF ,
	VREF_AVCC,
	VREF_256
	
	
}ADC_Vref_type;


typedef enum{
	
	CH_0=0 ,
	CH_1 ,
	CH_2 ,
	CH_3 ,
	CH_4 ,
	CH_5 ,
	CH_6 ,
	CH_7
	
	
	
}ADC_Channel_type;

typedef enum{
	
	ADC_PRESCALER_2=1 ,
	ADC_PRESCALER_4 ,
	ADC_PRESCALER_8 ,
	ADC_PRESCALER_16,
	ADC_PRESCALER_32 ,
	ADC_PRESCALER_64 ,
	ADC_PRESCALER_128


	
	
}ADC_Prescaler_type;


void ADC_Init(ADC_Vref_type ref , ADC_Prescaler_type prescaler) ;

u16 ADC_Read(ADC_Channel_type ch) ;

u16 ADC_ReadToMiliVolt(ADC_Channel_type ch  ) ;

void ADC_StartConverstion(ADC_Channel_type ch)  ;

u16  ADC_GetRead(void) ;

u8 ADC_GetReadPeriodic(u16 *pdata) ;

u16 ADC_GetReadNoBlock() ;

#endif /* ADC_INTERFACE_H_ */