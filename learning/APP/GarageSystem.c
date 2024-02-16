
#define F_CPU 8000000
#include <util/delay.h>


#include "MemMaph.h"
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_interface.h"
#include "LCD_Interface.h"
#include "STEPPER_Interface.h"
#include "KeyPad_interface.h"
#include "KIT.h"
#include "GarageSystem.h"
#include "NVM_interface.h"

/* var for get password */

static u8 password   ;

static u8 intial_screen_f  = 0 , pass_page_f =1 , passed_f=1  , chang_f =1 ,new_pass_f=1 ;

static u8 temp =0    ,c_wrong_pass = 0 ,count_wrong_pass = 0;


/* get password first in initialization */
void GarageSystem_Init(void) {
	
	intial_screen() ;
	password =  NVM_Raed8(0) ;
	count_wrong_pass=NVM_Raed8(1) ;
	
	
	if(count_wrong_pass>=4){
		
		u8 i = count_wrong_pass;
		LCD_Clear() ;
		LCD_GoTo(0,0) ;
		LCD_WriteString("locked for while") ;
		while(i--) {
			LCD_GoTo(1,0) ;
			LCD_WriteNumber(i) ;
			_delay_ms(1000) ;
			pass_page_f=0 ;	
		}
		NVM_Write8(1,0) ;
		LCD_Clear() ;
		LCD_GoTo(0,0) ;
		LCD_WriteString("Enter Password") ;
		LCD_GoTo(1,0) ;
		
		
	}

	
}


void GarageSystem_Runnable(void) {
	
	
	u8 k  =  NO_KEY ;
	
	k = KeyPad_GetKey() ;
	
	
	if(intial_screen_f==0) {
		
		intial_screen() ;
		
	}
	
	
	if (k!=NO_KEY) {
		
		DIO_WritePin(BUZZER_KIT,HIGH) ;
		_delay_ms(200) ;
		DIO_WritePin(BUZZER_KIT,LOW) ;

		
		/* Login  */
		
		
		if(intial_screen_f==0)
		{
			
			
			/* set flag login */
			if(k=='1') {
				
				pass_page_f = 0 ;
				intial_screen_f = 1 ;
				LCD_Clear();
				
				
				LCD_GoTo(0,0) ;
				LCD_WriteString("Enter Password") ;
				LCD_GoTo(1,0) ;
				
			}
			
			/* set flag change password */
			else if(k=='2') {
				intial_screen_f =1 ;
				chang_f= 0 ;
				LCD_Clear();
				LCD_GoTo(0,0) ;
				LCD_WriteString("Enter old pass..") ;
				LCD_GoTo(1,0) ;
				
			}
			
			

			
		}
		/* check change password flag */
		else if(chang_f==0){
			if(k>='0'&&k<='9') {
				LCD_WriteChar('*') ;
				temp = (temp*10)+ (k-'0') ;
				
			}
			
			/* check old password */
			else  if (k=='=')
			{
				/* correct password */
				if(temp==password) {
					temp=0  ;
					LCD_Clear() ;
					LCD_GoTo(0,0) ;
					LCD_WriteString("New password") ;
					LCD_GoTo(1,0) ;
					chang_f=1 ;
					new_pass_f=0 ;
					
					
					
				}
				
				/* wrong password */
				else{
					temp=0 ;
					LCD_Clear() ;
					LCD_GoTo(0,0) ;
					LCD_WriteString("wrong password") ;
					_delay_ms(2500)  ;
					LCD_Clear() ;
					chang_f=1 ;
					new_pass_f=1 ;
					intial_screen_f=0 ;
					
					
				}
				
			}
			
			
		}
		/* enter new password */
		else if(new_pass_f==0) {
			
			
			if(k>='0'&&k<='9') {
				LCD_WriteChar('*') ;
				temp = (temp*10)+ (k-'0') ;
				
			}
			
			
			else  if (k=='=')
			{
				NVM_Write8(0,temp) ;
				password=temp ;
				temp=0 ;
				
				LCD_Clear() ;
				LCD_GoTo(0,0) ;
				LCD_WriteString("Changed !") ;
				_delay_ms(2500) ;
				LCD_Clear() ; 
				
				new_pass_f= 1 ;
				intial_screen_f=0 ;
				
			}
			
			
			
		}
		
		/* login*/
		
		else if (pass_page_f==0)
		{
			
			if(k>='0'&&k<='9') {
				LCD_WriteChar('*') ;
				temp = (temp*10)+ (k-'0') ;
				//LCD_WriteNumber(k-'0') ;
			}
			
			
			else  if (k=='=')
			{
				
				/* correct password */
				if(temp==password)
				{
					c_wrong_pass = 0  ;
					pass_page_f=1;
					DIO_WritePin(LED_GREEN_KIT ,HIGH) ;
					LCD_Clear() ;
					LCD_WriteString("Crusher ON") ;
					//DIO_WritePin(PINB0,HIGH) ;
					STEPPER_UniPoler_ByAngle(90,CCW);
					_delay_ms(5000) ;
					//DIO_WritePin(PINB0,LOW) ;
					STEPPER_UniPoler_ByAngle(90,CW);
					DIO_WritePin(LED_GREEN_KIT ,LOW) ;

					LCD_Clear() ;
					LCD_GoTo(0,0) ;
					
					intial_screen_f = 0 ;
					temp=0 ; 
					
				}
				else {
					
					/* wrong password */
					temp= 0 ;
					/* count ENTER WRONG PASSWORD */
					c_wrong_pass++ ;
					if(c_wrong_pass<9)  {
						
						
						
						LCD_Clear() ;
						LCD_GoTo(0,0) ;
						LCD_WriteString("Wrong Password") ;
						
						DIO_WritePin(LED_RED_KIT,HIGH) ;
						DIO_WritePin(BUZZER_KIT,HIGH) ;

						_delay_ms(100) ;
						DIO_WritePin(LED_RED_KIT,LOW) ;
						DIO_WritePin(BUZZER_KIT,LOW) ;
						_delay_ms(100) ;
						
						DIO_WritePin(LED_RED_KIT,HIGH) ;
						DIO_WritePin(BUZZER_KIT,HIGH) ;

						_delay_ms(100) ;
						DIO_WritePin(LED_RED_KIT,LOW) ;
						DIO_WritePin(BUZZER_KIT,LOW) ;
						_delay_ms(100) ;
						
						DIO_WritePin(LED_RED_KIT,HIGH) ;
						DIO_WritePin(BUZZER_KIT,HIGH) ;

						_delay_ms(100) ;
						DIO_WritePin(LED_RED_KIT,LOW) ;
						DIO_WritePin(BUZZER_KIT,LOW) ;
						_delay_ms(100) ;
						
						DIO_WritePin(LED_RED_KIT,HIGH) ;
						DIO_WritePin(BUZZER_KIT,HIGH) ;

						_delay_ms(100) ;
						
						
						DIO_WritePin(LED_RED_KIT,LOW) ;
						DIO_WritePin(BUZZER_KIT,LOW) ;
						_delay_ms(800) ;
						LCD_Clear() ;
						pass_page_f = 0 ;
						
						LCD_GoTo(0,0) ;
						LCD_WriteString("Enter Password") ;
						LCD_GoTo(1,0) ;
						
						
					}
					
					if(c_wrong_pass==3) {
						
						u8 i = 8 ;
						NVM_Write8(1,8) ; 
						LCD_Clear() ;
						LCD_GoTo(0,0) ;
						LCD_WriteString("locked for while") ;
						while(i--) {
							if(i==4){
								NVM_Write8(1,4) ;
								
							}
							LCD_GoTo(1,0) ;
							LCD_WriteNumber(i) ;
							_delay_ms(1000) ;
							pass_page_f=0 ;
							
							
						}
						NVM_Write8(1,0) ;
						LCD_Clear() ;
						LCD_GoTo(0,0) ;
						LCD_WriteString("Enter Password") ;
						LCD_GoTo(1,0) ;
					}
					
					if(c_wrong_pass==6) {
						
						u8 i = 15 ;
						NVM_Write8(1,15) ; 
						LCD_Clear() ;
						LCD_GoTo(0,0) ;
						LCD_WriteString("locked for while") ;
						while(i--) {
							if(i==7){
								NVM_Write8(1,7) ;
								
							}
							LCD_GoTo(1,0) ;
							LCD_WriteNumber(i) ;
							_delay_ms(1000) ;
							pass_page_f=0 ;
							
						}
						NVM_Write8(1,0) ;
						LCD_Clear() ;
						LCD_GoTo(0,0) ;
						LCD_WriteString("Enter Password") ;
						LCD_GoTo(1,0) ;
						
					}
					
					
					if(c_wrong_pass==9) {
						
						LCD_Clear() ;
						LCD_GoTo(0,0)  ;
						LCD_WriteString("Alarm....") ;
						while (1){
							
							DIO_WritePin(BUZZER_KIT,HIGH) ;
							DIO_WritePin(LED_RED_KIT,HIGH) ;
							_delay_ms(250) ;
							DIO_WritePin(BUZZER_KIT,LOW) ;
							DIO_WritePin(LED_RED_KIT,LOW) ;
							_delay_ms(250) ;
							
						}
						
					}
					
					
				}
				
			}
			
			
		}
		
		
		
		
		
	}
}









void intial_screen(void) {
	LCD_GoTo(0,0) ;
	LCD_WriteString("Garage system") ;
	LCD_GoTo(1,0) ;
	LCD_WriteString("1.Login 2.Change") ;
	
	
	
	/*
	
	
	u8 str[]="Lock System Project";
	u8 size  = sizeof(str)/sizeof(str[0]) ;
	u8 j = size-1 ;
	LCD_GoTo(0,0) ;
	LCD_WriteChar(str[j]) ;
	
	
	for (u8 i = 0 ; i<size ;i++)
	{
	j = j-i ;
	//LCD_GoTo(0,0) ;
	//LCD_WriteString("                       ") ;
	LCD_GoTo(0,0) ;

	for(j ; j<size-1 ; j++)
	{
	
	
	LCD_WriteChar(str[j]) ;
	
	}
	_delay_ms(300) ;

	
	}
	LCD_GoToClear(0,11,8) ;
	LCD_GoTo(1,0) ;
	LCD_WriteString("Project") ;
	_delay_ms(2500) ;

	LCD_Clear() ;
	
	*/
}