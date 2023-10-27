/*
 * ADC_prog.c
 *
 *  Created on: Oct 11, 2023
 *      Author: Omar Gamal El-Kady
 */

// public lib
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

// lower lib

// my own lib
#include "ADC_priv.h"
#include "ADC_config.h"

static pfuncISRFunc_t LOC_pISRFunc;

static vidptr_t LOC_pISRFuncParameters;

ES_t ADC_enuInit(void){

	ES_t Local_enuErrorState = ES_OK;

	ADC_ADCSRA &= ~(ADC_MASK_BIT<<7);

	ADC_ADMUX &= 0x3F;
    #if ADC_VOLATAGE_REFRENCE == ADC_V_AREF
	     //ADC_ADMUX &= (0x3F);
	     ADC_ADMUX |= (ADC_V_AREF<<ADC_BIT_6);
    #elif ADC_VOLATAGE_REFRENCE == ADC_V_AVCC
	     ADC_ADMUX |= (ADC_V_AVCC<<ADC_BIT_6);
    #elif ADC_VOLATAGE_REFRENCE == ADC_V_INTERNAL
	     ADC_ADMUX |= (ADC_V_INTERNAL<<ADC_BIT_6);
    #else
	    //#error ADC Voltage Reference Configuration is Invalid
    #endif

	ADC_ADMUX &= 0xDF;
    #if ADC_ADJUSTMENT == ACC_RIGHT_ADJUSTMENT
	     ADC_ADMUX |= (ACC_RIGHT_ADJUSTMENT<<ADC_BIT_5);
    #elif ADC_ADJUSTMENT == ACC_LEFT_ADJUSTMENT
	     ADC_ADMUX |= (ACC_LEFT_ADJUSTMENT<<ADC_BIT_5);
    #else
        #error ADC Adjustment Configuration is Invalid
    #endif

	ADC_ADMUX &= 0xE0;
    #if ADC_INIT_CHANNEL >= ADC_MIN_NUM_CHANNELS && ADC_INIT_CHANNEL <= ADC_MAX_NUM_CHANNELS
	     ADC_ADMUX |= ADC_INIT_CHANNEL;
    #else
        #error ADC Init Channel Number is Invalid
    #endif

	ADC_ADCSRA &= 0xF8;
    #if ADC_PRESCALER >= ADC_PRESCALER_RESERVED && ADC_PRESCALER <= ADC_PRESCALER_128
	     ADC_ADCSRA |= ADC_PRESCALER;
    #else
         #error ADC Prescaler Configuration is Invalid
    #endif

	ADC_ADCSRA &= 0xF7;
    #if ADC_INTERRUPT_MODE == ADC_INTERRUPT
	     ADC_ADCSRA |= (ADC_INTERRUPT<<ADC_BIT_3);
    #elif ADC_INTERRUPT_MODE == ADC_POOLING
	     //ADC_ADCSRA &= ~(ADC_MASK_BIT<<ADC_BIT_3);
	     ADC_ADCSRA |= (ADC_POLLING<<ADC_BIT_3);
    #else
        #error ADC Interrupt Mode Configuration is Invalid
    #endif

	ADC_SFIOR &= 0x1F;
    #if ADC_TRIGGER_SOURCE == ADC_SINGLE_CONVERSION
	     ADC_ADCSRA &= ~(ADC_MASK_BIT<<ADC_BIT_5);
    #elif ADC_TRIGGER_SOURCE >= ADC_FREE_RUNNING_TIGGER && ADC_TRIGGER_SOURCE <= ADC_TIM1_COMP_CAPTURE_EVENT_TRIGGER
	     ADC_ADCSRA &= ~(ADC_MASK_BIT<<ADC_BIT_5);
	     ADC_SFIOR |= (ADC_TRIGGER_SOURCE<<ADC_BIT_5);
	     ADC_ADCSRA |= (ADC_MASK_BIT<<ADC_BIT_5);
    #else
        #error ADC Auto Trigger Mode Configuration is Invalid
    #endif

	ADC_ADCSRA |= (ADC_MASK_BIT<<ADC_BIT_7);
	Local_enuErrorState = ES_OK;


	return Local_enuErrorState;
}

ES_t ADC_enuReadPolling(u8 Copy_u8Channel , u16 * Copy_pu16ADCRead){

	ES_t Local_enuErrorState = ES_NOK;


	if(Copy_pu16ADCRead != NULL){

		if((Copy_u8Channel >= ADC_MIN_NUM_CHANNELS) && (Copy_u8Channel <= ADC_MAX_NUM_CHANNELS)){

			ADC_ADCSRA |= (ADC_MASK_BIT<<ADC_BIT_4); // CLEAR FLAG
			ADC_ADCSRA |= (ADC_MASK_BIT<<ADC_BIT_6); // START CONVERSION

			ADC_ADMUX &= 0xE0; // CLEAR CHANNEL
			ADC_ADMUX |= Copy_u8Channel; // SET CHANNEL

			while(((ADC_ADCSRA>>ADC_BIT_4)&ADC_MASK_BIT) == false);

            #if ADC_ADJUSTMENT == ACC_RIGHT_ADJUSTMENT

			    *Copy_pu16ADCRead = 0x00;
				*Copy_pu16ADCRead |= ADC_ADCL;
				*Copy_pu16ADCRead |= ((u16)ADC_ADCH<<ADC_BIT_8);
				Local_u8ErrorState = ES_OK;

            #else if(ADC_ADJUSTMENT == ACC_LEFT_ADJUSTMENT)

				*Copy_pu16ADCRead = 0x00;
				*Copy_pu16ADCRead |= (ADC_ADCL>>ADC_BIT_6);
				*Copy_pu16ADCRead |= ((u16)ADC_ADCH<<ADC_BIT_2);
				Local_enuErrorState = ES_OK;

            #endif

			ADC_ADCSRA |= (ADC_MASK_BIT<<ADC_BIT_4);

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

ES_t ADC_enuStartConversion(void){

	ES_t Local_enuErrorState = ES_NOK;

	ADC_ADCSRA &= 0xBF;
	ADC_ADCSRA |= 0x40;

	return Local_enuErrorState;
}

ES_t ADC_enuSetADCChannel(u8 Copy_u8Channel){

	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_u8Channel >= ADC_MIN_NUM_CHANNELS) && (Copy_u8Channel <= ADC_MAX_NUM_CHANNELS)){

		ADC_ADMUX &= 0xE0;
		ADC_ADMUX |= Copy_u8Channel;

		Local_enuErrorState = ES_OK;
	}
	else{

		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t ADC_enuReadInterrupt(u16 * Copy_pu16ADCRead){

	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pu16ADCRead != NULL){

        #if ADC_ADJUSTMENT == ACC_RIGHT_ADJUSTMENT

		    *Copy_pu16ADCRead = 0x00;
			*Copy_pu16ADCRead |= ADC_ADCL;
			*Copy_pu16ADCRead |= ((u16)ADC_ADCH<<ADC_BIT_8);
			Local_enuErrorState = ES_OK;

        #elif ADC_ADJUSTMENT == ACC_LEFT_ADJUSTMENT

			*Copy_pu16ADCRead = 0x00;
			*Copy_pu16ADCRead |= (ADC_ADCL>>ADC_BIT_6);
			*Copy_pu16ADCRead |= ((u16)ADC_ADCH<<ADC_BIT_2);
			Local_enuErrorState = ES_OK;
            #warning ADC_enuReadInterrupt is not working speedly in LEFT ADJUSTMENT

        #endif

	}
	else{

		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_t ADC_enuReadInterruptHigh(u8 * Copy_pu8ADCRead){

	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pu8ADCRead != NULL){

		#if ADC_ADJUSTMENT == ACC_RIGHT_ADJUSTMENT

		    *Copy_pu8ADCRead = 0x00;
		    *Copy_pu8ADCRead |= (ADC_ADCL>>ADC_BIT_2);
			*Copy_pu8ADCRead |= (ADC_ADCH<<ADC_BIT_6);
			Local_enuErrorState = ES_OK;
            #warning ADC_enuReadInterruptHigh is not working speedly in RIGHT ADJUSTMENT

	    #elif ADC_ADJUSTMENT == ACC_LEFT_ADJUSTMENT

			*Copy_pu8ADCRead = 0x00;
			*Copy_pu8ADCRead |= ADC_ADCH;
			Local_enuErrorState = ES_OK;

	    #endif

	}
	else{

		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_t ADC_enuSetTriggerSource(u8 Copy_u8TriggerSource){

	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_u8TriggerSource >= ADC_FREE_RUNNING_TIGGER) && (Copy_u8TriggerSource <= ADC_TIM1_COMP_CAPTURE_EVENT_TRIGGER)){

		ADC_ADCSRA &= 0xDF;


		ADC_SFIOR &= 0x1F;
		ADC_SFIOR |= (Copy_u8TriggerSource<<ADC_BIT_5);
		//ADC_ADCSRA |= 0x20;
		ADC_ADCSRA |= (1<<5);
		Local_enuErrorState = ES_OK;

	}
	else{

		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t ADC_enuClearTriggerSource(void){

	ES_t Local_enuErrorState = ES_NOK;

	ADC_ADCSRA &= 0xDF;

	return Local_enuErrorState;
}

ES_t ADC_enuSetPrescaler(u8 Copy_u8Channel , u8 Copy_u8Prescaler){

	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_u8Channel >= ADC_MIN_NUM_CHANNELS) && (Copy_u8Channel <= ADC_MAX_NUM_CHANNELS)){

		ADC_ADMUX &= 0xE0; // CLEAR CHANNEL
		ADC_ADMUX |= Copy_u8Channel; // SET CHANNEL

		if((Copy_u8Prescaler >= ADC_PRESCALER_RESERVED) && (Copy_u8Prescaler <= ADC_PRESCALER_64)){

			ADC_ADCSRA &= 0xF8; // CLEAR PRESCALER
			ADC_ADCSRA |= Copy_u8Prescaler; // SET PRESCALER
			Local_enuErrorState = ES_OK;
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

ES_t ADC_enuSetIterruptMode(u8 Copy_u8Channel , u8 Copy_u8InterruptMode){

	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_u8Channel >= ADC_MIN_NUM_CHANNELS) && (Copy_u8Channel <= ADC_MAX_NUM_CHANNELS)){

		ADC_ADMUX &= 0xE0;
		ADC_ADMUX |= Copy_u8Channel;

		if((Copy_u8InterruptMode == ADC_POLLING) || (Copy_u8InterruptMode == ADC_INTERRUPT)){

			ADC_ADCSRA &= 0xF7;
			ADC_ADCSRA |= (Copy_u8InterruptMode<<ADC_BIT_3);
			Local_enuErrorState = ES_OK;

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

ES_t ADC_enuInterruptEnable(void){

	ES_t Local_enuErrorState = ES_NOK;

	ADC_ADCSRA |= (ADC_MASK_BIT<<ADC_BIT_3);

	return Local_enuErrorState;
}

ES_t ADC_enuInterruptDisable(void){

	ES_t Local_enuErrorState = ES_NOK;

	ADC_ADCSRA &= ~(ADC_MASK_BIT<<ADC_BIT_3);

	return Local_enuErrorState;
}

ES_t ADC_enuADCEnable(void){

	ES_t Local_enuErrorState = ES_NOK;

	ADC_ADCSRA |= (ADC_MASK_BIT<<ADC_BIT_7);

	return Local_enuErrorState;

}

ES_t ADC_enuADCDisable(void){

	ES_t Local_enuErrorState = ES_NOK;

	ADC_ADCSRA &= ~(ADC_MASK_BIT<<ADC_BIT_7);

	return Local_enuErrorState;
}

ES_t ADC_enuSetCallBack(void(* Copy_pfuncAppFunc)(void*),void * Copy_pvidParameter){

	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_pfuncAppFunc != NULL) && (Copy_pvidParameter != NULL)){

		LOC_pISRFunc = Copy_pfuncAppFunc;
		LOC_pISRFuncParameters = Copy_pvidParameter;
	}
	else{

		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

void __vector_16 (void)__attribute__((signal));

void __vector_16(void){

	LOC_pISRFunc(LOC_pISRFuncParameters);
}
