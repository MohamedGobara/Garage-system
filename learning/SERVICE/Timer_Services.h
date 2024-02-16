

#ifndef TIMER_SERVICES_H_
#define TIMER_SERVICES_H_

/********************** includes ***************************************************/
#include "Timers_interface.h"
#include "StdTypes.h"
#include "Timer_Services_cfg.h"
/********************** Macro Declarations ***************************************/

/*********************  Macro Fucnction Declarations ****************************/

/*********************  Data Type Declarations ***********************************/

/*********************  Software Interfaces Declarations "APIs" *****************/

/* initialization of Timer 0 in normal mode */
void PWM_Init_Timer0(void) ;
/* set PWM frequency of Timer 0 normal mode*/
void PWM_Freq_HZ_Timer0(u32 freq) ;
/*
set PWM frequency of Timer 0 normal mode
range : 2KHz ~ 100 KHz 
*/

void PWM_Duty_Timer0(u8 Duty) ;

/* initialization of Timer 1 in fast PWM */
void PWM_Init_Timer1(void) ;
/* set PWM frequency of Timer 1 normal mode*/
void PWM_Freq_HZ_Timer1(u32 freq) ;
/* set PWM frequency of Timer 1 normal mode*/
void PWM_Duty_Timer1(u8 Duty) ;


/* initialization of Timer 2 in fast PWM */
void PWM_Init_Timer2(void) ;
/* set PWM frequency of Timer 2 normal mode*/
void PWM_Freq_HZ_Timer1(u32 freq) ;
/* set PWM frequency of Timer 2 normal mode*/
void PWM_Duty_Timer2(u8 Duty) ;

/* set PWM duty cycle of Timer 1 in fast PWM */
void PWM_Duty(u8 duty) ;
/* Execute function after ....ms */
void Timer1_SetInterruptTime_ms(u16 time ,void(*local_fptr)(void)) ;
/* Execute function after ....us */
void Timer1_SetInterruptTime_us(u16 time ,void(*local_fptr)(void)) ;
/* Execute function after ....s */
void Timer1_SetInterruptTime_s(u16 time ,void(*local_fptr)(void)) ;
/* Measure PWM */
void PWM_Measure(u32* Pfreq,u8* Pduty) ;
/* Measure PWM */
void PWM_Measure2(u32* pfreq,u8* pduty) ;


#endif /* TIMER_SERVICES_H_ */