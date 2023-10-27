/*
 * TrafficLight_prog.c
 *
 *  Created on: Sep 25, 2023
 *      Author: LENOVO
 */

// public
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"
#include "util/delay.h"

//lower
#include "../../HAL/HexaDecoder/HexaDecoder_int.h"
#include "../../HAL/Led/Led_int.h"
#include "../../HAL/Switch/Switch_int.h"

//my own
#include "../POV/POV_int.h"
#include "TrafficLight_priv.h"

ES_t TrafficLight_enuInit(void){

	ES_t Local_enuErrorState = ES_NOK;

	POV_enuInit();
	Led_enuInit();
	Switch_enuInit();

	return Local_enuErrorState;
}

ES_t TrafficLight_enuTrafficON(void){

	ES_t Local_enuErrorState = ES_NOK;


	//static u8 SLocal_u8Time = 15 ;
	u8 SLocal_u8TrafficTime = SLocal_u8Time ;

	for(u8 Local_u8TimePassed = 0 ; Local_u8TimePassed <= SLocal_u8TrafficTime ; Local_u8TimePassed++){

		for(u8 Local_u8Wait = 0 ; Local_u8Wait < 100 ; Local_u8Wait++){

			POV_enuDisplayNum(Local_u8TimePassed);
		}

		Led_enuLedTurnON(LED_GREEN_ID);

		if( Local_u8TimePassed >= (u8)(SLocal_u8TrafficTime - (u8)3) ){

			Led_enuLedTurnON(LED_YELLOW_ID);
		}

		u8 Local_u8SwitchState;
		Switch_enuGetSwitchState(SWITCH_BUTTON_0,&Local_u8SwitchState);

		if( (SLocal_u8Time < TRAFFIC_LIGHT_MAX_TIME ) && (Local_u8SwitchState == SWITCH_ON) ){

			SLocal_u8Time++;
		}

		Switch_enuGetSwitchState(SWITCH_BUTTON_1,&Local_u8SwitchState);

		if( (SLocal_u8Time > TRAFFIC_LIGHT_MIN_TIME ) && (Local_u8SwitchState == SWITCH_ON) ){

			SLocal_u8Time--;
		}

	}

	Led_enuLedTurnOFF(LED_GREEN_ID);
	Led_enuLedTurnOFF(LED_YELLOW_ID);

	for(u8 Local_u8TimePassed = 0 ; Local_u8TimePassed <= SLocal_u8TrafficTime ; Local_u8TimePassed++){

		for(u8 Local_u8Wait = 0 ; Local_u8Wait < 100 ; Local_u8Wait++){

			POV_enuDisplayNum(Local_u8TimePassed);
		}

		Led_enuLedTurnON(LED_RED_ID);

		if( Local_u8TimePassed >= (u8)(SLocal_u8TrafficTime - (u8)3) ){

			Led_enuLedTurnON(LED_YELLOW_ID);
		}

		u8 Local_u8SwitchState;
		Switch_enuGetSwitchState(SWITCH_BUTTON_0,&Local_u8SwitchState);

		if( (SLocal_u8Time < TRAFFIC_LIGHT_MAX_TIME ) && (Local_u8SwitchState == SWITCH_ON) ){

			SLocal_u8Time++;
		}

		Switch_enuGetSwitchState(SWITCH_BUTTON_1,&Local_u8SwitchState);

		if( (SLocal_u8Time > TRAFFIC_LIGHT_MIN_TIME ) && (Local_u8SwitchState == SWITCH_ON) ){

			SLocal_u8Time--;
		}

	}

	Led_enuLedTurnOFF(LED_RED_ID);
	Led_enuLedTurnOFF(LED_YELLOW_ID);

	return Local_enuErrorState;

}

ES_t TrafficLight_enuTrafficOFF(void){

	ES_t Local_enuErrorState = ES_NOK;

	HexaDecoder_enuStopDisplay();

	return Local_enuErrorState;
}

ES_t TrafficLight_enuTrafficStatus(u8 * Copy_pu8TrafficStatus){

	ES_t Local_enuErrorState = ES_NOK;

	//u8 Local_u8TrafficSwitch = 2;

	if( Copy_pu8TrafficStatus != NULL){

		Switch_enuGetSwitchState(SWITHC_BUTTON_2,Copy_pu8TrafficStatus);

		Local_enuErrorState = ES_OK;

	}
	else{

		Local_enuErrorState = ES_NULL_POINTER;
	}
	return ES_NOK;
}
