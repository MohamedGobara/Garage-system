

#ifndef LCD_INTERFACING_H_
#define LCD_INTERFACING_H_


#define F_CPU 8000000
#include <util/delay.h>

#include "DIO_interface.h"


void LCD_Init(void) ; 

void LCD_WriteNumber(s32 num) ;

void LCD_WriteChar(u8 ch) ;

void LCD_WriteString(u8* str ) ;

void LCD_Clear(void) ;   

void LCD_WriteBinary(u8 num) ; 

void LCD_WriteHex(u8 num) ;

void LCD_ReturnHome(void) ; 

void LCD_GoTo(u8 line , u8 cell) ; 

void LCD_WriteNumber4D(u32 num) ;

void LCD_GoToClear(u8 line , u8 cell , u8 numOfCells) ; 

void LCD_CreateCharacter(u8* pattern , u8 location) ; 

#endif /* LCD_INTERFACING_H_ */