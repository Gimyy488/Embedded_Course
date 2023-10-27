/*
 * POV_prog.c
 *
 *  Created on: Sep 24, 2023
 *      Author: LENOVO
 */

// public
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"
#include "util/delay.h"

//lower
#include "../../HAL/HexaDecoder/HexaDecoder_int.h"
//my own
#include "POV_priv.h"
#include "POV_config.h"


ES_t POV_enuInit(void){

	return HexaDecoder_enuInit();
}

ES_t POV_enuDisplayNum(u8 Copy_u8Num){

	ES_t Local_enuErrorState = ES_NOK;

	if( Copy_u8Num < 100 ){

		HexaDecoder_enuDisableSSG(HEX_DEC_SSG_LEFT);
		HexaDecoder_enuDisableSSG(HEX_DEC_SSG_RIGHT);

		HexaDecoder_enuDisplayNum(Copy_u8Num / 10);
		HexaDecoder_enuEnableSSG(HEX_DEC_SSG_LEFT);
		_delay_ms(10);

		HexaDecoder_enuDisableSSG(HEX_DEC_SSG_LEFT);
		HexaDecoder_enuDisplayNum(Copy_u8Num % 10);
		HexaDecoder_enuEnableSSG(HEX_DEC_SSG_RIGHT);
		_delay_ms(10);

		HexaDecoder_enuStopDisplay();

		Local_enuErrorState = ES_OK;

	}
	else{

		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
