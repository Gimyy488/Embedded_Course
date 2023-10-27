/*
 * GIE_prog.c
 *
 *  Created on: Oct 6, 2023
 *      Author: Omar Gamal El-Kady
 */

// public lib
#include "../../LIB/stdTypes.h"

// own lib
#include "GIE_priv.h"

void GIE_vidEnable(void){

	GIE_SREG |= (1<<7);
	//asm("SEI");
	//__asm("SEI");
	//__asm__("SEI");
}

void GIE_vidDisable(void){

	GIE_SREG &= ~(1<<7);
	//asm("CLI");
	//__asm("CLI");
	//__asm__("CLI");
}
