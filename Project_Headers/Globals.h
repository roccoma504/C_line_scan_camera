/*
 * Globals.h
 *
 *  Created on: Oct 13, 2012
 *      Author: Muneeb
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

typedef struct {
	volatile char ImageData[128];
} sLine;

extern volatile sLine Line;
#endif /* GLOBALS_H_ */
