/*
 * HexaDecoder_prog.c
 *
 *  Created on: Sep 24, 2023
 *      Author: LENOVO
 */

// public
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

// lower
#include "../../MCAL/DIO/DIO_int.h"

//my own lib
#include "HexaDecoder_priv.h"
#include "HexaDecoder_config.h"


ES_t HexaDecoder_enuInit(void){

	ES_t Local_enuErrorState = ES_NOK;

    #if HEX_DEC_A_GRP <= DIO_GROUP_D && HEX_DEC_B_GRP <= DIO_GROUP_D && HEX_DEC_C_GRP <= DIO_GROUP_D && HEX_DEC_D_GRP <= DIO_GROUP_D

      #if HEX_DEC_A_PIN <= DIO_PIN_7 && HEX_DEC_B_PIN <= DIO_PIN_7 && HEX_DEC_C_PIN <= DIO_PIN_7 && HEX_DEC_D_PIN <= DIO_PIN_7

	      ES_t Local_aenuErrorState[HEX_DEC_ERROR_STATE_INIT_COND] = {0};

	      Local_aenuErrorState[0] = DIO_enuSetPinDirection(HEX_DEC_A_GRP,HEX_DEC_A_PIN,DIO_OUTPUT);
	      Local_aenuErrorState[1] = DIO_enuSetPinDirection(HEX_DEC_B_GRP,HEX_DEC_B_PIN,DIO_OUTPUT);
	      Local_aenuErrorState[2] = DIO_enuSetPinDirection(HEX_DEC_C_GRP,HEX_DEC_C_PIN,DIO_OUTPUT);
	      Local_aenuErrorState[3] = DIO_enuSetPinDirection(HEX_DEC_D_GRP,HEX_DEC_D_PIN,DIO_OUTPUT);

	      Local_aenuErrorState[4] = DIO_enuSetPinDirection(HEX_DEC_EN1_GRP,HEX_DEC_EN1_PIN,DIO_OUTPUT);
	      Local_aenuErrorState[5] = DIO_enuSetPinDirection(HEX_DEC_EN2_GRP,HEX_DEC_EN2_PIN,DIO_OUTPUT);

	      for(u8 iter = 0 ; iter < HEX_DEC_ERROR_STATE_INIT_COND ; iter++){

	    	  if( Local_aenuErrorState[iter] != ES_OK){

	    		  Local_enuErrorState = Local_aenuErrorState[iter];
	    		  break;
	    	  }
	    	  else{
	    		  Local_enuErrorState = Local_aenuErrorState[iter];
	    	  }
	      }
      #else
        #error hexa pins config is out of range
      #endif

    #else
      #error hexa group config is out of range
    #endif
	return Local_enuErrorState;
}

ES_t HexaDecoder_enuDisplayNum(u8 Copy_u8Num){

	ES_t Local_enuErrorState = ES_NOK;

	if( Copy_u8Num <= 9 ){
		ES_t Local_aenuErrorState[HEX_DEC_ERROR_STATE_DISPLAY_COND] = {0};

	    Local_aenuErrorState[0] = DIO_enuSetPinValue(HEX_DEC_A_GRP,HEX_DEC_A_PIN,((Copy_u8Num>>HEX_DEC_NUM_BIT_0)&DIO_BIT_MASK));
	    Local_aenuErrorState[1] = DIO_enuSetPinValue(HEX_DEC_B_GRP,HEX_DEC_B_PIN,((Copy_u8Num>>HEX_DEC_NUM_BIT_1)&DIO_BIT_MASK));
	    Local_aenuErrorState[2] = DIO_enuSetPinValue(HEX_DEC_C_GRP,HEX_DEC_C_PIN,((Copy_u8Num>>HEX_DEC_NUM_BIT_2)&DIO_BIT_MASK));
	    Local_aenuErrorState[3] = DIO_enuSetPinValue(HEX_DEC_D_GRP,HEX_DEC_D_PIN,((Copy_u8Num>>HEX_DEC_NUM_BIT_3)&DIO_BIT_MASK));

	    for(u8 iter = 0 ; iter < HEX_DEC_ERROR_STATE_DISPLAY_COND ; iter++){

	    	if( Local_enuErrorState != ES_OK){

	    		Local_enuErrorState = Local_aenuErrorState[iter];
	    		break;
	    	}
	    	else{

	    	Local_enuErrorState = Local_aenuErrorState[iter];
		}
	}
	}

	return Local_enuErrorState;
}

ES_t HexaDecoder_enuEnableSSG(u8 Copy_u8SSGNum){

	ES_t Local_enuErrorState = ES_NOK;

	if( Copy_u8SSGNum == HEX_DEC_SSG_LEFT){

		Local_enuErrorState = DIO_enuSetPinValue(HEX_DEC_EN1_GRP,HEX_DEC_EN1_PIN,DIO_HIGH);
	}
	else if ( Copy_u8SSGNum ==  HEX_DEC_SSG_RIGHT){

		Local_enuErrorState = DIO_enuSetPinValue(HEX_DEC_EN2_GRP,HEX_DEC_EN2_PIN,DIO_HIGH);
	}

	else{

		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t HexaDecoder_enuDisableSSG(u8 Copy_u8SSGNum){

	ES_t Local_enuErrorState = ES_NOK;

	if( Copy_u8SSGNum == HEX_DEC_SSG_LEFT){

		Local_enuErrorState = DIO_enuSetPinValue(HEX_DEC_EN1_GRP,HEX_DEC_EN1_PIN,DIO_LOW);
	}
	else if ( Copy_u8SSGNum ==  HEX_DEC_SSG_RIGHT){

		Local_enuErrorState = DIO_enuSetPinValue(HEX_DEC_EN2_GRP,HEX_DEC_EN2_PIN,DIO_LOW);
	}

	else{

		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t HexaDecoder_enuStopDisplay(void){

	ES_t Local_enuErrorState = ES_NOK;

	ES_t Local_aenuErrorState[HEX_DEC_ERROR_STATE_STOP_DISPLAY_COND] = {0};

	Local_aenuErrorState[0] = DIO_enuSetPinValue(HEX_DEC_EN1_GRP,HEX_DEC_EN1_PIN,DIO_LOW);

	Local_aenuErrorState[1] = DIO_enuSetPinValue(HEX_DEC_EN2_GRP,HEX_DEC_EN2_PIN,DIO_LOW);

	for(u8 iter = 0 ; iter < HEX_DEC_ERROR_STATE_STOP_DISPLAY_COND ; iter++){

		if( Local_aenuErrorState[iter] != ES_NOK ){

			Local_enuErrorState = Local_aenuErrorState[iter];
			break;
		}
		else{
			Local_enuErrorState = Local_aenuErrorState[iter];
		}
	}

	return Local_enuErrorState;

}

