#include "ULTRASONIC_interface.h"
#include "ULTRASONIC_cfg.h"

static volatile u16 t1,t2;
static volatile u8 flag=0,counter_ovf=0,start_pulse=0;

static void f1(void);

static void f2(void);

void ULTRASONIC_Init(void){
	
	Timer1_ICU_SetCallBack(f1);
	Timer1_ICU_InterruptEnable();
	Timer1_OVF_SetCallBack(f2) ; 
	Timer1_OVF_InterruptEnable();
}


u8 ULTRASONIC_GetDistance( ULTRASONIC_type2 us, u16* pdistance ){
	//TCNT1=0 ;
	u16 t,d;
	flag=0;
	u16 c=0;
	Timer1_InputCaptureEdge(TIMERICU_RISING);
	DIO_WritePin(us,HIGH);
	_delay_us(10);
	DIO_WritePin(us,LOW);
	while((flag<2)&&(c<50000))  // w8 50000 us 
	{
		c++;
		_delay_us(1);
	}
	if (flag==2)
	{
		t=t2-t1+(counter_ovf*ULTRASONIC_TOP_TIMER);
		d=t/58;
		*pdistance=d;
		counter_ovf=0 ;
		return TRUE;
	}
	counter_ovf=0 ;
	return FALSE;

}



static void f1(void)
{
	if (flag==0)
	{
		t1=ICR1;
		Timer1_InputCaptureEdge(TIMERICU_FALLING);
		flag=1;
		start_pulse=1 ;
		 
	}
	else if (flag==1)
	{
		t2=ICR1;
		flag=2;
		start_pulse= 0;

	}
}

static void f2(void)
{
	
	if(start_pulse){
		counter_ovf++ ; 
		
	}
}


