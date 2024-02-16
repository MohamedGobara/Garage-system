
#include "DIO_interface.h"
#include "MOTOR_cfg.h"
#include "MOTOR_Interface.h"
#include "MOTOR_private.h"

const DIO_Pin_type MotorPinsArray [NUMBER_OF_MOTOR][NUMBER_OF_PIN_PER_MOTOR]= {
					
							/* IN1  , IN2  */
     /* MOTOR 1 */			{PINB0  , PINB1 }, 
	 /* MOTOR 2 */			{PINB2  , PINB3 },
	 /* MOTOR 3 */			{PINB2  , PINB3 },
     /* MOTOR 4 */			{PINB2  , PINB2 },


} ; 
