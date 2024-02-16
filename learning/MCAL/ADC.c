/********************** includes   *********************************************/

#include "ADC_cfg.h"
#include "ADC_interface.h"




#define F_CPU 8000000
#include <util/delay.h>
/********************** Helper Functions Declaration "prototype"   *************/

/*********************  Global Variable Defination    **************************/

u16  volt_ref ;
static u8 adc_flag= 1 ;

/*********************  APIs Defination          *******************************/

void ADC_Init(ADC_Vref_type ref , ADC_Prescaler_type prescaler) {
	
	
	/* Clock */
	
	
	
	ADCSRA = ADCSRA & 0xf8 ;
	ADCSRA = ADCSRA | prescaler ;
	
	
	
	
	
	/* volt ref */
	
	switch(ref){
		
		case VREF_AREF :
		CLR_BIT(ADMUX,REFS1) ;
		CLR_BIT(ADMUX,REFS0) ;
		volt_ref=AREF ;
		break;
		
		case VREF_AVCC :
		CLR_BIT(ADMUX,REFS1) ;
		SET_BIT(ADMUX,REFS0) ;
		volt_ref=5000 ;
		break;
		
		case VREF_256 :
		SET_BIT(ADMUX,REFS1) ;
		SET_BIT(ADMUX,REFS0) ;
		volt_ref=2560 ;
		break;
		
		default:
		break;
		
		
		
		
	}
	
	
	
	/* READ ADC Mode */
	CLR_BIT(ADCH,ADLAR) ;
	
	/* ADC Enable */
	SET_BIT(ADCSRA,ADEN) ;
	
	
}

u16 ADC_Read(ADC_Channel_type ch){
	
	/* select channel  */
	ch&=0x07  ;
	ADMUX = ADMUX & 0xE0 ;
	ADMUX = ADMUX | ch ;

	/* start conversion */

	SET_BIT(ADCSRA,ADSC) ;

	/* w8 until finish */

	while (READ_BIT(ADCSRA,ADSC));
	
	/* get read */
	
	u16 res  ;


	//res = ADC  ;

	u8 low , high;
	low = ADCL ;
	high = ADCH ;
	res =  (u16) (high<<8 )|low;

	return res;

}


u16 ADC_ReadToMiliVolt(ADC_Channel_type ch  ) {
	
	u16 res  = ADC_Read(ch) ;

	res = (res*(u32)volt_ref)/1024 ;
	return res;
}



void ADC_StartConverstion(ADC_Channel_type ch)   {
	
	
	
	if(adc_flag==1 ) {
		/* select channel  */
		ch&=0x07  ;
		ADMUX = ADMUX & 0xE0 ;
		ADMUX = ADMUX | ch ;

		/* start conversion */

		SET_BIT(ADCSRA,ADSC) ;
		adc_flag=  0  ;
		
	}
	
}
u16  ADC_GetRead(void)  {
	
	while (READ_BIT(ADCSRA,ADSC));
	
	/* get read */
	
	u16 res  ;

	res=ADC ;

	return res;

	
	
}
u8 ADC_GetReadPeriodic(u16 *pdata) {
	
	
	
	if(!READ_BIT(ADCSRA,ADSC)) {
		*pdata = ADC ;
		adc_flag = 1  ;
		return 1  ;
	}
	else
	{
		return 0 ;
	}
}

u16 ADC_GetReadNoBlock() {
	
	return ADC ;
	
}

/*********************  ISRs Defination          *******************************/

/*********************  Helper Function Defination    **************************/









