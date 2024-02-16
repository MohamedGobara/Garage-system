/********************** includes ***********************************************/
#include "Timer_Services.h"

#include "Timer_Services.h"
/********************** Helper Functions Declaration "prototype" ************/
static void Func_ICU(void) ; 

static void ms_timer1(void) ;


static void Timer0_freq(void) ; 

/*********************  Global Variable Defination ****************************/
static volatile u16 t1,t2,t3 ;

static volatile u8 flag= 0;

static volatile u16 counter_ov_ms = 0 , ms_counter =0 , reminder_ms= 0 ,ms_value=0;

static volatile u8 time_in_TCNT ; 


static u8 overflow_need_flag  ; 

static void (*ms_fun) (void) ; 

/*********************  APIs Defination ***************************************/
/* initialization of Timer 0 in normal mode */
void PWM_Init_Timer0(void) {
	TIMER0_Init(TIMER0_NORMAL_MODE,TIMER0_STOP) ; 
	TIMER0_OV_SetCallBack(Timer0_freq) ; 
	TIMER0_OV_InterruptDisable() ; 
	
}
/*
set PWM frequency of Timer 0 normal mode
range : 2KHz ~ 100 KHz
*/
void PWM_Freq_HZ_Timer0(u32 freq) {
	u16 calc_freq = 0; 
	if(freq<1000) {
	/* we need over flow */
	overflow_need_flag=1 ; 		
	}	
	else if (freq>=2000&&freq<=100000)
	{
		/* don't need over flow */
		overflow_need_flag=0 ; 	
		calc_freq = ((u32)1000000/freq)  ; 
		time_in_TCNT =((u32)((u32)1/calc_freq) *1000000)/2 ; 
		TIMER0_Init(TIMER0_NORMAL_MODE,TIMER0_SCALER_8) ;
		TCNT0=256-time_in_TCNT; 
	}
}
/* set PWM frequency of Timer 0 normal mode*/
void PWM_Duty_Timer0(u8 Duty) {
	
	
}

/* Execute function after ....ms */
void Timer1_SetInterruptTime_ms (u16 time, void(*LocalFptr)(void) ) {
	Timer1_Init(TIMER1_CTC_OCRA_TOP_MODE,TIMER1_SCALER_8);
	
	if(time<=65) {
		ms_value = (time*1000)-1 ;
		OCR1A=ms_value;
		Timer1_OCA_SetCallBack(LocalFptr);
		Timer1_OCA_InterruptEnable();
	}
	else {
		ms_fun = LocalFptr ;
		ms_counter  =((u32)time*1000)/65000  ;
		reminder_ms=((u32)time*1000)%65000 ;
		OCR1A=65000-1 ;
		Timer1_OCA_SetCallBack(ms_timer1);
		Timer1_OCA_InterruptEnable();

	}
	
}

/* Execute function after ....us */
void Timer1_SetInterruptTime_us (u16 time,void(*LocalFptr)(void))
{
	Timer1_Init(TIMER1_CTC_OCRA_TOP_MODE,TIMER1_SCALER_8);
	OCR1A=(time)-1;
	Timer1_OCA_SetCallBack(LocalFptr);
	Timer1_OCA_InterruptEnable() ;
}

/* Measure PWM */
void PWM_Measure(u32* Pfreq,u8* Pduty)
{
	u16 Ton,Toff;
	
	TCNT1=0;
	Timer1_ICU_SetCallBack(Func_ICU);
	Timer1_InputCaptureEdge(TIMERICU_RISING);
	Timer1_ICU_InterruptEnable();
	flag=0;
	while(flag<3);//busy w8
	Ton=t2-t1;
	Toff=t3-t2;

	*Pduty=((u32)Ton*100)/((u32)Ton+Toff);
	*Pfreq=(u32)1000000/((u32)Toff+Ton);

}

/*********************  ISRs Defination **************************************/


/*********************  Helper Function Defination **************************/

static void ms_timer1(void) {
	static volatile flag =0 ;
	/* first time */
	if(flag==0)  {
		counter_ov_ms++ ;
		if(counter_ov_ms==ms_counter) {
			/* over flow counter passed */
			OCR1A = reminder_ms-1 ;
			counter_ov_ms=0 ;
			flag=1  ;
		}
	}
	else {
		
		/* call function */
		ms_fun() ;
		OCR1A =  65000-1 ;
		flag=0 ;
		
	}
	
	
}

static void Func_ICU(void)
{
	
	if (flag==0)
	{
		t1=ICR1;
		Timer1_InputCaptureEdge(TIMERICU_FALLING);
		flag=1;
	}
	else if (flag==1)
	{
		t2=ICR1;
		Timer1_InputCaptureEdge(TIMERICU_RISING);
		flag=2;
	}
	else if (flag==2)
	{
		t3=ICR1;
		Timer1_ICU_InterruptDisable();
		flag=3;
		
	}
}



static void Timer0_freq(void)
{
	
	if(overflow_need_flag) {
		/* make calculation of overflow */
		
		
	}
	else  {
		
		DIO_TogglePin(PWN_PIN_TIMER0) ; 
		TCNT0=256-time_in_TCNT ; 
		
	}

}