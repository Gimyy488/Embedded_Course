/*
 * EXTI_prog.c]
 *
 *  Created on: Oct 6, 2023
 *      Author: Omar Gamal El-Kady
 */


// public lib
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

// lower lib
//#include "../GIE/GIE_int.h"
#include "../DIO/DIO_int.h"

// own lib
#include "EXTI_priv.h"
#include "EXTI_config.h"

extern u8 EXTI_u8EXTIPinNum;

extern EXTI_t EXTI_astrEXTIConfig[];

static pfuncISRFunc_t LOC_apISRFunc[EXTI_NUM_PINS] = {NULL,NULL,NULL};

static vidptr_t LOC_apISRFuncParameters[EXTI_NUM_PINS] = {NULL,NULL,NULL};

// enable GIE , PIE by setting mode to interrupt
ES_t EXTI_enuInit(void){

	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Iter;

	for(Local_u8Iter = 0 ; Local_u8Iter < EXTI_u8EXTIPinNum ; Local_u8Iter++){

		enuSetSenseLevel(EXTI_astrEXTIConfig[Local_u8Iter].intPin,
				EXTI_astrEXTIConfig[Local_u8Iter].senselevel);

		enuSetIntMode(EXTI_astrEXTIConfig[Local_u8Iter].intPin,
				EXTI_astrEXTIConfig[Local_u8Iter].intMode);
	}


	return Local_enuErrorState;
}

// to set sense level to enable PIF if sense what specify
ES_t EXTI_enuSetSenseLevel(u8 Copy_u8IntPin , u8 Copy_u8SenseLevel){

	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = enuSetSenseLevel(Copy_u8IntPin,Copy_u8SenseLevel);

	return Local_enuErrorState;
}

// to enable PIE
ES_t EXTI_enuEnableInterrupt(u8 Copy_IntPin){

	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = enuSetSenseLevel(Copy_IntPin,EXTI_INTERRUPT_MODE);

	return Local_enuErrorState;
}

//to disable PIE
ES_t EXTI_enuDisableInterrupt(u8 Copy_IntPin){

	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = enuSetSenseLevel(Copy_IntPin,EXTI_POOLING_MODE);

	return Local_enuErrorState;
}

ES_t EXTI_enuSetCallBack(u8 Copy_u8IntPin , void(*Copy_pFuncAppFunc)(void),void * Copy_pvidParameter){

	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_pFuncAppFunc != NULL) && (Copy_pvidParameter != NULL)){

		if((Copy_u8IntPin >= EXTI_INT0) && (Copy_u8IntPin <= EXTI_INT2)){

			LOC_apISRFunc[Copy_u8IntPin] = Copy_pFuncAppFunc;
			LOC_apISRFuncParameters[Copy_u8IntPin]= Copy_pvidParameter;
		}
		else{

			Local_enuErrorState =  ES_OUT_OF_RANGE;
		}
	}
	else{

		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_t enuSetSenseLevel(u8 Copy_u8IntPin , u8 Copy_u8SenseLevel){

	ES_t Local_enuErrorState = ES_NOK;

	switch(Copy_u8IntPin){

	    case EXTI_INT0 :
	    	if(Copy_u8SenseLevel == EXTI_LOW_LEVEL){
	    		MCUCR &= ~(3<<0);
	    		Local_enuErrorState = ES_OK;
	    	}
	    	else if(Copy_u8SenseLevel == EXTI_ANY_CHANGE){
	    		MCUCR &= ~(3<<0);
	    		MCUCR |= (1<<0);
	    		Local_enuErrorState = ES_OK;
	    	}
	    	else if(Copy_u8SenseLevel == EXTI_FALLING_EDGE){
	    		MCUCR &= ~(3<<0);
	    		MCUCR |= (1<<1);
	    		Local_enuErrorState = ES_OK;
	    	}
	    	else if(Copy_u8SenseLevel == EXTI_RISING_EDGE){
	    		MCUCR |= (3<<0);
	    		Local_enuErrorState = ES_OK;
	    	}
	    	else{}
	    	break;
	    case EXTI_INT1 :
	    	if(Copy_u8SenseLevel == EXTI_LOW_LEVEL){
	    		MCUCR &= ~(3<<2);
	    		Local_enuErrorState = ES_OK;
	    	}
	        else if(Copy_u8SenseLevel == EXTI_ANY_CHANGE){
	        	MCUCR &= ~(3<<2);
	        	MCUCR |= (1<<2);
	    		Local_enuErrorState = ES_OK;
	        }
	        else if(Copy_u8SenseLevel == EXTI_FALLING_EDGE){
	        	MCUCR &= ~(3<<2);
	        	MCUCR |= (1<<3);
	    		Local_enuErrorState = ES_OK;
	        }
	    	else if(Copy_u8SenseLevel == EXTI_RISING_EDGE){
	    		MCUCR |= (3<<2);
	    		Local_enuErrorState = ES_OK;
	    	}
	    	else{}
	    	break;
	    case EXTI_INT2 :
	    	if(Copy_u8SenseLevel == EXTI_FALLING_EDGE){
	    		MCUCSR &= ~(1<<6);
	    		Local_enuErrorState = ES_OK;
	    	}
	        else if(Copy_u8SenseLevel == EXTI_RISING_EDGE){
	    		MCUCSR |= (1<<6);
	    		Local_enuErrorState = ES_OK;
	        }
	    	else{}
	    	break;
	    default :
	    	break;


	}

	return Local_enuErrorState;
}

ES_t enuSetIntMode(u8 Copy_u8IntPin , u8 Copy_u8IntMode){

	ES_t Local_enuErrorState = ES_NOK;

	switch(Copy_u8IntPin){

	    case EXTI_INT0 :
	    	if(Copy_u8IntMode == EXTI_INTERRUPT_MODE){
	    		GICR |= (1<<6);
	    		Local_enuErrorState = ES_OK;
	    	}
	    	else if(Copy_u8IntMode == EXTI_POOLING_MODE){
	    		GICR &= ~(1<<6);
	    		Local_enuErrorState = ES_OK;
	    	}
	    	else{}
	    	break;
	    case EXTI_INT1 :
	    	if(Copy_u8IntMode == EXTI_INTERRUPT_MODE){
	    		GICR |= (1<<7);
	    		Local_enuErrorState = ES_OK;
	    	}
	    	else if(Copy_u8IntMode == EXTI_POOLING_MODE){
	    		GICR &= ~(1<<7);
	    		Local_enuErrorState = ES_OK;
	    	}
	    	else{}
	    	break;
	    case EXTI_INT2 :
	    	if(Copy_u8IntMode == EXTI_INTERRUPT_MODE){
	    		GICR |= (1<<5);
	    		Local_enuErrorState = ES_OK;
	    	}
	    	else if(Copy_u8IntMode == EXTI_POOLING_MODE){
	    		GICR &= ~(1<<5);
	    		Local_enuErrorState = ES_OK;
	    	}
	    	else{}
	    	break;
	    default :
	    	break;

	}

	return Local_enuErrorState;


}


void __vector_1 (void)__attribute__((signal));
void __vector_2 (void)__attribute__((signal));
void __vector_3 (void)__attribute__((signal));

void __vector_1(void){

	if(LOC_apISRFunc[EXTI_INT0] != NULL){

		LOC_apISRFunc[EXTI_INT0](LOC_apISRFuncParameters[EXTI_INT0]);
	}
	else{}
}

void __vector_2(void){

	if(LOC_apISRFunc[EXTI_INT1] != NULL){

		LOC_apISRFunc[EXTI_INT1](LOC_apISRFuncParameters[EXTI_INT1]);
	}
	else{}

}

void __vector_3(void){

	if(LOC_apISRFunc[EXTI_INT2] != NULL){

		LOC_apISRFunc[EXTI_INT2](LOC_apISRFuncParameters[EXTI_INT2]);
	}
	else{}
}
