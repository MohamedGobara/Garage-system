
/*
File: DIO_cfg.c
Version: 1.0
Date: 8-7-2032
Author: Mohamed Hussein
Description: This file contains the code for DIO.
*/

#include "DIO_interface.h"

/* set here your pin configuration " OUTPUT, INPULL ,INFREE " */

DIO_PinStatus_type PinsStatusArray[TOTAL_PINS]={
	
	/********** PORT A  ***************/
	OUTPUT,     /* Port A Pin 0 ADC0 */
	OUTPUT,     /* Port A Pin 1 ADC2 */
	OUTPUT,     /* Port A Pin 2  */
	OUTPUT,     /* Port A Pin 3  */
	OUTPUT,     /* Port A Pin 4  */
	OUTPUT,     /* Port A Pin 5  */
	OUTPUT,     /* Port A Pin 6  */
	OUTPUT,     /* Port A Pin 7 ADC7  */
	/********** PORT B  ***************/
	OUTPUT,     /* Port B Pin 0  */
	OUTPUT,     /* Port B Pin 1  */
	OUTPUT,     /* Port B Pin 2 /INT2 */
	OUTPUT,     /* Port B Pin 3 /OC0 */
	OUTPUT,     /* Port B Pin 4 /SS */
	OUTPUT,     /* Port B Pin 5 /MOSI */
	OUTPUT,     /* Port B Pin 6 /MISO */
	OUTPUT,     /* Port B Pin 7 CLK */
	/********** PORT C  ***************/
	INPULL,     /* Port C Pin 0  */
	OUTPUT,     /* Port C Pin 1  */
	OUTPUT,     /* Port C Pin 2  */
	OUTPUT,     /* Port C Pin 3  */
	OUTPUT,     /* Port C Pin 4  */
	OUTPUT,     /* Port C Pin 5  */
	OUTPUT,     /* Port C Pin 6  */
	OUTPUT,     /* Port C Pin 7  */
	/********** PORT D  ***************/
	OUTPUT,     /* Port D Pin 0  / RX */
	OUTPUT,     /* Port D Pin 1  / TX */
	INPULL,     /* Port D Pin 2 /INT0 */
	INPULL,     /* Port D Pin 3 /INT1 */
	OUTPUT,     /* Port D Pin 4 /OC1B */
	OUTPUT,     /* Port D Pin 5 /OC1A */
	OUTPUT,     /* Port D Pin 6 /ICP */
	OUTPUT,     /* Port D Pin 7  */

	
} ;   