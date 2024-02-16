
#include "StdTypes.h"
#include "DIO_interface.h"
#include "LCD_Interface.h"
#include "LCD_cfg.h"
#include "LCD_private.h"
#include "Utils.h"



/* check mode is 4 bit or 8 bit */

#if LCD_MODE==_8_BIT


static void WriteInsterction(u8 ins) {
	
	
	DIO_WritePin(LCD_RS ,LOW );
	DIO_WritePort(LCD_PORT,ins) ;
	
	DIO_WritePin(LCD_E , HIGH) ;
	_delay_ms(1) ;
	DIO_WritePin(LCD_E , LOW) ;
	_delay_ms(1) ;
	
}


static void WriteData(u8 data) {
	
	
	DIO_WritePin(LCD_RS ,HIGH );
	DIO_WritePort(LCD_PORT,data) ;
	
	DIO_WritePin(LCD_E , HIGH) ;
	_delay_ms(1) ;
	DIO_WritePin(LCD_E , LOW) ;
	_delay_ms(1) ;
	
}


void LCD_Init(void) {
	
	_delay_ms(50) ;
	WriteInsterction(0x38)  ;//screen on 8 bit mode
	WriteInsterction(0x0f) ; //cursor off 0x0e ,0x0f
	WriteInsterction(0x01) ; //clear screen
	_delay_ms(1) ;
	WriteInsterction(0x06)  ; //increase DDRAM address no shift


}


/* check mode is 4 bit or 8 bit */

#elif LCD_MODE==_4_BIT

static void WriteInsterction(u8 ins) {
	
	
	DIO_WritePin(LCD_RS ,LOW );
	
	
	DIO_WritePin(D7,READ_BIT(ins,7))  ;
	DIO_WritePin(D6,READ_BIT(ins,6))  ;
	DIO_WritePin(D5,READ_BIT(ins,5))  ;
	DIO_WritePin(D4,READ_BIT(ins,4))  ;

	DIO_WritePin(LCD_E , HIGH) ;
	_delay_ms(1) ;
	DIO_WritePin(LCD_E , LOW) ;
	_delay_ms(1) ;
	
	DIO_WritePin(D7,READ_BIT(ins,3))  ;
	DIO_WritePin(D6,READ_BIT(ins,2))  ;
	DIO_WritePin(D5,READ_BIT(ins,1))  ;
	DIO_WritePin(D4,READ_BIT(ins,0))  ;

	DIO_WritePin(LCD_E , HIGH) ;
	_delay_ms(1) ;
	DIO_WritePin(LCD_E , LOW) ;
	_delay_ms(1) ;


	
}


static void WriteData(u8 data) {
	
	DIO_WritePin(LCD_RS ,HIGH );
	DIO_WritePin(D7,READ_BIT(data,7))  ;
	DIO_WritePin(D6,READ_BIT(data,6))  ;
	DIO_WritePin(D5,READ_BIT(data,5))  ;
	DIO_WritePin(D4,READ_BIT(data,4))  ;

	DIO_WritePin(LCD_E , HIGH) ;
	_delay_ms(1) ;
	DIO_WritePin(LCD_E , LOW) ;
	_delay_ms(1) ;
	
	DIO_WritePin(D7,READ_BIT(data,3))  ;
	DIO_WritePin(D6,READ_BIT(data,2))  ;
	DIO_WritePin(D5,READ_BIT(data,1))  ;
	DIO_WritePin(D4,READ_BIT(data,0))  ;
	
	DIO_WritePin(LCD_E , HIGH) ;
	_delay_ms(1) ;
	DIO_WritePin(LCD_E , LOW) ;
	_delay_ms(1) ;
	
}


void LCD_Init(void) {
	
	_delay_ms(50) ;
	WriteInsterction(0x02)  ;
	WriteInsterction(0x28)  ;//screen on 4 bit mode  with 2 line 5*7
	WriteInsterction(0x0c) ; //cursor off 0x0e ,0x0f
	WriteInsterction(0x01) ; //clear screen
	_delay_ms(1) ;
	WriteInsterction(0x06)  ; //increase DDRAM address no shift


}


#endif


void LCD_WriteChar(u8 ch) {

	WriteData(ch) ;

}



void LCD_Clear(void) {


	WriteInsterction(0x01) ;

}

void LCD_WriteNumber(s32 num)  {

	u8  i=0  , str[16]  , negative_flag = 0  ;

	s8 j ;


	//zero
	if(num==0) {
		
		
		LCD_WriteChar('0') ;
		
	}


	if (num<0)
	{
		negative_flag=1 ;
		num=num*-1 ;
	}


	//positive number
	while (num)
	{
		str[i]=(num%10)+'0' ;
		num=num/10 ;
		i++ ;
	}

	if (negative_flag==1)
	{
		LCD_WriteChar('-') ;
	}
	for (j=i;j>0 ; j--)
	{
		
		LCD_WriteChar(str[j-1]) ;
		
	}

}


void LCD_WriteString(u8* str ) {

	u8* ptr   = str;

	while(*ptr){
		
		LCD_WriteChar(*ptr) ;
		ptr++ ;
		
	}

}



void LCD_WriteBinary(u8 num) {
	
	for (s8 i=7 ; i>=0 ; i--)
	{
		if ((num>>i)&1==1)
		{
			LCD_WriteChar('1') ;
		}
		else {
			LCD_WriteChar('0') ;

		}
		
	}
	
	
	
	
	
}

void LCD_WriteHex(u8 num)  {
	
	
	u8 arr[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	struct temp{
		u8 left:4;
		u8 right:4;
	};
	struct temp s1;
	s1.right=num;
	s1.left=num>>4;

	LCD_WriteChar(arr[(s1.left)]);
	LCD_WriteChar(arr[(s1.right)]);
	



}

void LCD_ReturnHome(void) {
	
	WriteInsterction(0x02) ;
	
	
}


void LCD_GoTo(u8 line , u8 cell) {
	
	if(line==0) {
		
		WriteInsterction(0x80+cell) ;

		
	}
	else if (line==1)	{
		
		
		WriteInsterction((0x80+0x40)+cell) ;

	}
	
	
}

void LCD_WriteNumber4D(u32 num)  {
	
	LCD_WriteChar(((num%10000)/1000)+'0') ;
	LCD_WriteChar(((num%1000)/100)+'0') ;
	LCD_WriteChar(((num%100)/10)+'0') ;
	LCD_WriteChar(((num%10)/1)+'0') ;
}



void LCD_GoToClear(u8 line , u8 cell , u8 numOfCells) {
	
	u8 i;
	LCD_GoTo(line,cell) ;
	
	for(i=0 ;i <numOfCells; i++){
		
		LCD_WriteChar(' ') ;
		
	}
	
	
}


void LCD_CreateCharacter(u8* pattern , u8 location)  {
	
	u8 i = 0 ; 
	
	WriteInsterction(0x40+(location*8)) ; 
	for (i ; i<8 ; i++)
	{
		
		WriteData(pattern[i]) ; 
		
	}
	WriteInsterction(0x80) ; // return again to DDRAM	
	
}



