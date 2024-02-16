

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "DIO_interface.h"
#include "KIT.h"

#define _4_BIT  1
#define _8_BIT  2

#define LCD_MODE  _4_BIT

/* main pins in any mode */
#define LCD_RS      PINA1
#define LCD_E       PINA2

/* is use 4 BIT MODE */

#define D7  PINA6
#define D6  PINA5
#define D5  PINA4
#define D4  PINA3

/* is use 8 BIT MODE */

#define LCD_PORT    PD


#endif /* LCD_CFG_H_ */