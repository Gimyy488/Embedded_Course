/*
 * Buzzer_prog.c
 *
 *  Created on: Sep 28, 2023
 *      Author: LENOVO
 */

// public
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

// lower
#include "../../MCAL/DIO/DIO_int.h"

//my own lib
#include "Buzzer_priv.h"
#include "Buzzer_config.h"


ES_t Buzzer_enuInit(void){

	return DIO_enuSetPinDirection(BUZZER_GRP,BUZZER_PIN,DIO_OUTPUT);
}

ES_t Buzzer_enuAlertActivator(void){

	return DIO_enuSetPinValue(BUZZER_GRP,BUZZER_PIN,DIO_HIGH);
}

ES_t Buzzer_enuSilenceDeactivation(void){

	return DIO_enuSetPinValue(BUZZER_GRP,BUZZER_PIN,DIO_LOW);
}

