/*
 * ClickGlow_prog.c
 *
 *  Created on: Oct 13, 2023
 *      Author: Omar Gamal El-Kady
 */

// utilities
#include "util/delay.h"

// public
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

//lower
#include "../../HAL/Led/Led_int.h"
#include "../../HAL/Switch/Switch_int.h"
#include "../../HAL/Buzzer/Buzzer_int.h"

ES_t clickGlow_enuInit(void){

	ES_t Local_enuErrorState;

	Led_enuInit();
	Switch_enuInit();

	return Local_enuErrorState;
}
