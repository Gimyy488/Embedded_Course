/*
 * DIO_prog.c
 *
 *  Created on: Sep 24, 2023
 *      Author: LENOVO
 */

// public lib
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

// lower lib

// my own lib
#include "DIO_priv.h"
#include "DIO_config.h"


ES_t DIO_enuInit(void){

	ES_t Local_enuErrorState = ES_NOK;


	return Local_enuErrorState;
}


ES_t DIO_enuSetPinDirection(u8 Copy_u8GroupID , u8 Copy_u8PinID , u8 Copy_u8Direction){

	ES_t Local_enuErrorState = ES_NOK;

	if( (Copy_u8GroupID <= DIO_GROUP_D) && (Copy_u8PinID <= DIO_PIN_7) && (Copy_u8Direction <= DIO_OUTPUT) ){

		switch (Copy_u8GroupID){

		    case DIO_GROUP_A :
		    	DIO_DDRA_REG &= ~(DIO_BIT_MASK << Copy_u8PinID);
		    	DIO_DDRA_REG |= (Copy_u8Direction << Copy_u8PinID);
			break;
		    case DIO_GROUP_B :
		    	DIO_DDRB_REG &= ~(DIO_BIT_MASK << Copy_u8PinID);
		    	DIO_DDRB_REG |= (Copy_u8Direction << Copy_u8PinID);
		    break;
		    case DIO_GROUP_C :
		    	DIO_DDRC_REG &= ~(DIO_BIT_MASK << Copy_u8PinID );
		    	DIO_DDRC_REG |= (Copy_u8Direction << Copy_u8PinID);
		    break;
		    case DIO_GROUP_D :
		    	DIO_DDRD_REG &= ~(DIO_BIT_MASK << Copy_u8PinID);
		    	DIO_DDRD_REG |= (Copy_u8Direction << Copy_u8PinID);
		    break;
		    default:
		    break;
		}

		Local_enuErrorState = ES_OK;

	}

	else {

		Local_enuErrorState = ES_OUT_OF_RANGE;

	}



	return Local_enuErrorState;
}


ES_t DIO_enuSetPinValue(u8 Copy_u8GroupID , u8 Copy_u8PinID , u8 Copy_u8Value){

	ES_t Local_enuErrorState = ES_NOK;

	if( (Copy_u8GroupID <= DIO_GROUP_D) && (Copy_u8PinID <= DIO_PIN_7) && (Copy_u8Value <= DIO_HIGH) ){

		switch (Copy_u8GroupID){

			case DIO_GROUP_A :
			    if( Copy_u8Value == DIO_HIGH ){
			    	DIO_PORTA_REG |= (DIO_BIT_MASK << Copy_u8PinID);
			    }
			    else{
			    	DIO_PORTA_REG &= ~(DIO_BIT_MASK << Copy_u8PinID);
			    }
			break;
			case DIO_GROUP_B :
				if( Copy_u8Value == DIO_HIGH ){
					DIO_PORTB_REG |= (DIO_BIT_MASK << Copy_u8PinID);
				}
				else{
					DIO_PORTB_REG &= ~(DIO_BIT_MASK << Copy_u8PinID);
				}
			break;
			case DIO_GROUP_C :
				if( Copy_u8Value == DIO_HIGH ){
					DIO_PORTC_REG |= (DIO_BIT_MASK << Copy_u8PinID);
				}
				else{
					DIO_PORTC_REG &= ~(DIO_BIT_MASK << Copy_u8PinID);
				}
			break;
			case DIO_GROUP_D :
				if( Copy_u8Value == DIO_HIGH ){
					DIO_PORTD_REG |= (DIO_BIT_MASK << Copy_u8PinID);
				}
				else{
					DIO_PORTD_REG &= ~(DIO_BIT_MASK << Copy_u8PinID);
			    }
			break;
			default:
			break;
		}

		Local_enuErrorState = ES_OK;
	}

	else {

		Local_enuErrorState = ES_OUT_OF_RANGE;

	}

	return Local_enuErrorState;

}


ES_t DIO_enuTogglePinValue(u8 Copy_u8GroupID , u8 Copy_u8PinID){

	ES_t Local_enuErrorState = ES_NOK;

	if( (Copy_u8GroupID <= DIO_GROUP_D) && (Copy_u8PinID <= DIO_PIN_7) ){

		switch (Copy_u8GroupID){

			case DIO_GROUP_A :
				DIO_PORTA_REG ^= (DIO_BIT_MASK << Copy_u8PinID);
			break;

			case DIO_GROUP_B :
				DIO_PORTB_REG ^= (DIO_BIT_MASK << Copy_u8PinID);
			break;

			case DIO_GROUP_C :
				DIO_PORTC_REG ^= (DIO_BIT_MASK << Copy_u8PinID);
			break;

			case DIO_GROUP_D :
				DIO_PORTD_REG ^= (DIO_BIT_MASK << Copy_u8PinID);
			break;

			default:
			break;
		}

		Local_enuErrorState = ES_OK;

	}

	else {

		Local_enuErrorState = ES_OUT_OF_RANGE;

	}

	return Local_enuErrorState;
}


ES_t DIO_enuGetPinValue(u8 Copy_u8GroupID , u8 Copy_u8PinID , u8 * Copy_pu8Value){

	ES_t Local_enuErrorState = ES_NOK;

	if( Copy_pu8Value != NULL ){

		if( (Copy_u8GroupID <= DIO_GROUP_D) && (Copy_u8PinID <= DIO_PIN_7) ){

			switch (Copy_u8GroupID){

			   case DIO_GROUP_A :
				   *Copy_pu8Value = ( (DIO_PINA_REG >> Copy_u8PinID) & DIO_BIT_MASK );
			   break;

			   case DIO_GROUP_B :
			   		*Copy_pu8Value = ( (DIO_PINB_REG >> Copy_u8PinID) & DIO_BIT_MASK );
			   break;

			   case DIO_GROUP_C :
			   		*Copy_pu8Value = ( (DIO_PINC_REG >> Copy_u8PinID) & DIO_BIT_MASK );
			   break;

			   case DIO_GROUP_D :
			   		*Copy_pu8Value = ( (DIO_PIND_REG >> Copy_u8PinID) & DIO_BIT_MASK );
			   break;

			   default:
			   break;

			}

			Local_enuErrorState = ES_OK;
		}
		else{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}
