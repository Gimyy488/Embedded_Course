/*
 * Switch_prog.c
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
#include "Switch_priv.h"
#include "Switch_config.h"

extern u8 Switch_u8MaxSwitchNum;

extern Switch_t Switch_astrSwitchConfig[];

ES_t Switch_enuInit(void){

	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Iter;

	for(Local_u8Iter = 0 ; Local_u8Iter < Switch_u8MaxSwitchNum ; Local_u8Iter++){

		Local_enuErrorState = DIO_enuSetPinDirection(Switch_astrSwitchConfig[Local_u8Iter].Sw_Grp,
				Switch_astrSwitchConfig[Local_u8Iter].Sw_Pin,DIO_INPUT);

		if( Local_enuErrorState != ES_OK){

			break;

		}
	}

	return Local_enuErrorState;

}

ES_t Switch_enuGetSwitchState(u8 Copy_u8SwitchID , u8 * Copy_pu8SwitchState){

	ES_t Local_enuErrorState = ES_NOK;

	if( Copy_pu8SwitchState != NULL){

		if( Copy_u8SwitchID < Switch_u8MaxSwitchNum ){

			Local_enuErrorState = DIO_enuGetPinValue(Switch_astrSwitchConfig[Copy_u8SwitchID].Sw_Grp,
					Switch_astrSwitchConfig[Copy_u8SwitchID].Sw_Pin,Copy_pu8SwitchState);

		}
		else{

			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else{

		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

