/*
 * initTSI.h
 *
 *  Created on: Nov 8, 2012
 *      Author: ulab
 */

#include "Derivative.h"
#ifndef INITTSI_H_
#define INITTSI_H_


//#define GPIO_PIN(x)    ((1) &lt;&lt; (x))   // Macro to manipulate a specific pin

#define RED_LED 18
#define GREEN_LED 19
#define BLUE_LED 1



void InitLEDsGPIO(void);
void CalibrateTSI(void);


#endif /* INITTSI_H_ */
