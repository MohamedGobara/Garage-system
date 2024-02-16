
#ifndef RGB_INTERFACE_H_
#define RGB_INTERFACE_H_

#include "StdTypes.h"
#include "Timers_interface.h"
#include "RGB_LED_cfg.h"
#include "DIO_interface.h"
#include "RGB_LED_private.h"

typedef struct RGB_LED_ColorsStruct{
u8 RED ;
u8 GREEN ; 
u8 BLUE  ; 
}RGB_LED_Contains ; 


void RGB_LED_init(RGB_LED_ColorsNames color) ; 


void RGB_LED_SetColorByColor(RGB_LED_ColorsNames color) ;


void RGB_LED_SetColorByRGB(u8 r , u8 g , u8 b) ;


void RGB_LED_Off(void) ; 


void RGB_LED_MoveByShowRoom(RGB_LED_ColorsNames from  , RGB_LED_ColorsNames to) ;




#endif /* RGB_INTERFACE_H_ */