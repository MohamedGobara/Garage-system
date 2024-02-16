#include "RGB_LED_interface.h"
#include "RGB_LED_cfg.h"
#include "MemMaph.h"
#include "LCD_Interface.h"


extern  RGB_LED_Contains RGB_LED_ColorsArray[];


static RGB_LED_Contains *color_ptr;

void RGB_LED_init(RGB_LED_ColorsNames color) {
	
	color_ptr=&RGB_LED_ColorsArray[color] ;
	/* timer0 - red */
	TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_8) ;
	TIMER0_OC0Mode(OC0_INVERTING) ;
	RGB_R_reg =255-color_ptr->RED;
	
	/* timer1 -  green and blue */
	Timer1_Init(TIMER1_FASTPWM_8bit_MODE,TIMER1_SCALER_8) ;
	Timer1_OCRA1Mode(OCRA_INVERTING) ;
	Timer1_OCRB1Mode(OCRB_INVERTING) ;

	RGB_G_reg =255-color_ptr->GREEN;
	RGB_B_reg =255-color_ptr->BLUE;
	
}


void RGB_LED_Off(void) {
	
	RGB_R_reg=255 ;
	RGB_G_reg =255;
	RGB_B_reg =255;
	
}

void RGB_LED_SetColorByColor(RGB_LED_ColorsNames color) {
	
	color_ptr=&RGB_LED_ColorsArray[color] ;
	RGB_R_reg =255-color_ptr->RED;
	RGB_G_reg =255-color_ptr->GREEN;
	RGB_B_reg =255-color_ptr->BLUE;
	
}


void RGB_LED_SetColorByRGB(u8 r , u8 g , u8 b)  {
	
	RGB_R_reg =255-r;
	RGB_G_reg =255-g;
	RGB_B_reg =255-b;
	
}

static volatile u8 c_rgb=0  ;


static void ShowRoom(void){
	
	TCNT2=6 ;
	c_rgb++ ;
	if(c_rgb==70) {
		/* red */
		
		if(RGB_R_reg >255-color_ptr->RED ) {
			
			RGB_R_reg-- ;
		}
		
		else if( RGB_R_reg<255-color_ptr->RED) {
			
			
			RGB_R_reg++ ;
		}
		else if(RGB_R_reg == 255-color_ptr->RED) {
			
			
			//no thing
		}
		
		
		/*green*/
		if(RGB_G_reg >255-color_ptr->GREEN) {
			
			
			RGB_G_reg-- ;
			
		}
		else if(RGB_G_reg < 255-color_ptr->GREEN) {
			
			
			RGB_G_reg++ ;
			
			
		}
		
		else if(RGB_G_reg == 255-color_ptr->GREEN) {
			
			
			//no thing
		}
		
		
		/* blue */
		
		if(RGB_B_reg >255-color_ptr->BLUE) {
			
			
			RGB_B_reg-- ;
		}
		else if( RGB_B_reg < 255-color_ptr->BLUE) {
			
			
			RGB_B_reg++ ;
			
		}
		else if(RGB_B_reg== 255-color_ptr->BLUE) {
			
			
			//no thing
		}
			
		
		c_rgb=0 ;
	}

}


void RGB_LED_MoveByShowRoom(RGB_LED_ColorsNames from  , RGB_LED_ColorsNames to) {
	
	RGB_LED_SetColorByColor(from) ;
	color_ptr=&RGB_LED_ColorsArray[to] ;
	TCNT2=6 ;
	TIMER2_OVF_SetCallBack(ShowRoom) ;
	TIMER2_OV_InterruptEnable() ;
	TIMER2_Init(TIMER2_NORMAL_MODE,TIMER2_SCALER_8) ;
	_delay_ms(5000) ;
	TIMER2_Init(TIMER2_NORMAL_MODE,TIMER2_STOP) ;

}