/*
 * Led_prog.c
 *
 *  Created on: Sep 26, 2023
 *      Author: LENOVO
 */

// public
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

// lower
#include "../../MCAL/DIO/DIO_int.h"

// my own
#include "Led_priv.h"
#include "Led_config.h"

extern u8 Led_u8MaxLedNum;

extern Led_t Led_astrLedConfig[];

ES_t Led_enuInit(void){

	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Iter;
	for( Local_u8Iter = 0 ; Local_u8Iter < Led_u8MaxLedNum ; Local_u8Iter++){

		Local_enuErrorState = DIO_enuSetPinDirection(Led_astrLedConfig[Local_u8Iter].Led_Grp,
				Led_astrLedConfig[Local_u8Iter].Led_Pin,DIO_OUTPUT);

		if( Local_enuErrorState != ES_OK ){

			break;
		}

		Local_enuErrorState = DIO_enuSetPinValue(Led_astrLedConfig[Local_u8Iter].Led_Grp,
						Led_astrLedConfig[Local_u8Iter].Led_Pin,Led_astrLedConfig[Local_u8Iter].Led_Status);

		if (Local_enuErrorState != ES_OK ){

			break;
		}
	}

	return Local_enuErrorState;
}

ES_t Led_enuLedTurnON(u8 Copy_u8LedID){

	ES_t Local_enuErrorState = ES_NOK;

	if( Copy_u8LedID < Led_u8MaxLedNum){

		Local_enuErrorState = DIO_enuSetPinValue(Led_astrLedConfig[Copy_u8LedID].Led_Grp,
				Led_astrLedConfig[Copy_u8LedID].Led_Pin,DIO_HIGH);

	}
	else{

		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t Led_enuLedTurnOFF(u8 Copy_u8LedID){

	ES_t Local_enuErrorState = ES_NOK;

	if( Copy_u8LedID < Led_u8MaxLedNum){

		Local_enuErrorState = DIO_enuSetPinValue(Led_astrLedConfig[Copy_u8LedID].Led_Grp,
				Led_astrLedConfig[Copy_u8LedID].Led_Pin,DIO_LOW);

	}
	else{

		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;

}

ES_t Led_enuLedToggle(u8 Copy_u8LedID){

	ES_t Local_enuErrorState = ES_NOK;

	if( Copy_u8LedID < Led_u8MaxLedNum){

		Local_enuErrorState = DIO_enuTogglePinValue(Led_astrLedConfig[Copy_u8LedID].Led_Grp,
				Led_astrLedConfig[Copy_u8LedID].Led_Pin);

		}
		else{

			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

		return Local_enuErrorState;
}
