
#ifndef RGB_LED_CFG_H_
#define RGB_LED_CFG_H_

#include "DIO_interface.h"


typedef enum {
		 BLACK,
		 WHITE,
		 GRAY,
		 RED,
		 GREEN,
		 BLUE,
		 YELLOW,
		 CYAN,
		 MAGENTA,
		 ORANGE,
		 PURPLE,
		 TEAL,
		 PINK,
		 LIME,
		 BROWN,
		 OLIVE,
		 NAVY,
		 MAROON,
		 AQUA,
		 LAVENDER,
		 TURQUOISE,
		 GOLD,
		 SALMON,
		 BEIGE,
		 CORAL,
		 INDIGO,
		 KHAKI,
		 PLUM,
		 SILVER , 
		TotalNumbers_COLOR
			
}RGB_LED_ColorsNames;



// red
#define RGB_R_reg OCR0

#define RGB_R_PIN PINB3

// green
#define RGB_G_reg OCR1A

#define RGB_G_PIN PIND5

// blue
#define RGB_B_reg OCR1B

#define RGB_B_PIN PIND4


#endif /* RGB_LED_CFG_H_ */