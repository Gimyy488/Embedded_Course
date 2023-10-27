/*
 * TIMER_config.c
 *
 *  Created on: Oct 15, 2023
 *      Author: Omar Gamal El-Kady
 */

// public lib
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"


// own lib
#include "TIMER_config.h"
#include "TIMER_priv.h"

u8 TIMER_u8PinNum = TIMER_NUM_PINS;

TIMER_t TIMER_astrTimerConfig[TIMER_NUM_PINS] = {

		{TIMER_INT0,TIMER0_WAVEFORM_GEN_MODE_CTC,
				TIMER0_COMP_OUTPUT_NON_PWM_NORMAL,TIMER0_PRESCALER_1024,TIMER_OCINT}
};

