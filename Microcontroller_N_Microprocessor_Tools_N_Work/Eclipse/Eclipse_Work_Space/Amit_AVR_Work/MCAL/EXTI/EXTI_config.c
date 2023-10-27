/*
 * EXTI_config.c
 *
 *  Created on: Oct 6, 2023
 *      Author: Omar Gamal El-Kady
 */

// public lib
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"


// own lib
#include "EXTI_config.h"
#include "EXTI_priv.h"

u8 EXTI_u8EXTIPinNum = EXTI_NUM_PINS;

EXTI_t EXTI_astrEXTIConfig [EXTI_NUM_PINS] = {

		{EXTI_INT0,EXTI_ANY_CHANGE,EXTI_INTERRUPT_MODE},
		{EXTI_INT1,EXTI_ANY_CHANGE,EXTI_INTERRUPT_MODE},
		{EXTI_INT2,EXTI_LOW_LEVEL,EXTI_INTERRUPT_MODE}
};
