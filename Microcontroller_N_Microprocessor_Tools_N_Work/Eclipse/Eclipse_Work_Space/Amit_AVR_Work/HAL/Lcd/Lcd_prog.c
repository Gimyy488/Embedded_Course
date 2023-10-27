/*
 * Lcd_prog.c
 *
 *  Created on: Sep 27, 2023
 *      Author: LENOVO
 */

#include <stdio.h>
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"
#include <util/delay.h>
// lower
#include "../../MCAL/DIO/DIO_int.h"

//my own lib
#include "Lcd_priv.h"
#include "Lcd_config.h"


ES_t Lcd_enuInit(void){

	ES_t Local_enuErrorState = ES_NOK;

	_delay_ms(35);

	DIO_enuSetPinDirection(LCD_RS_GRP,LCD_RS_PIN,DIO_OUTPUT);
	DIO_enuSetPinDirection(LCD_RW_GRP,LCD_RW_PIN,DIO_OUTPUT);
	DIO_enuSetPinDirection(LCD_EN_GRP,LCD_EN_PIN,DIO_OUTPUT);

	DIO_enuSetPinDirection(LCD_D7_GRP,LCD_D7_PIN,DIO_OUTPUT);
	DIO_enuSetPinDirection(LCD_D6_GRP,LCD_D6_PIN,DIO_OUTPUT);
	DIO_enuSetPinDirection(LCD_D5_GRP,LCD_D5_PIN,DIO_OUTPUT);
	DIO_enuSetPinDirection(LCD_D4_GRP,LCD_D4_PIN,DIO_OUTPUT);

    #if LCD_MODE == EIGHT_BIT

	    DIO_enuSetPinDirection(LCD_D3_GRP,LCD_D3_PIN,DIO_OUTPUT);
	    DIO_enuSetPinDirection(LCD_D2_GRP,LCD_D2_PIN,DIO_OUTPUT);
		DIO_enuSetPinDirection(LCD_D1_GRP,LCD_D1_PIN,DIO_OUTPUT);
		DIO_enuSetPinDirection(LCD_D0_GRP,LCD_D0_PIN,DIO_OUTPUT);

		// Function Set
		DIO_enuSetPinValue(LCD_RS_GRP,LCD_RS_PIN,DIO_LOW);
		enuWriteNLatch(0x38);
		//_delay_ms(45);

    #elif LCD_MODE == FOUR_BIT

		  //DIO_enuSetPinDirection(LCD_RS_GRP,LCD_RS_PIN,DIO_LOW);

		  DIO_enuSetPinValue(LCD_D7_GRP,LCD_D7_PIN,DIO_LOW);
		  DIO_enuSetPinValue(LCD_D6_GRP,LCD_D6_PIN,DIO_LOW);
		  DIO_enuSetPinValue(LCD_D5_GRP,LCD_D5_PIN,DIO_HIGH);
	      DIO_enuSetPinValue(LCD_D4_GRP,LCD_D4_PIN,DIO_LOW);

		  DIO_enuSetPinValue(LCD_EN_GRP,LCD_EN_PIN,DIO_HIGH);
		  _delay_ms(1);
		  DIO_enuSetPinValue(LCD_EN_GRP,LCD_EN_PIN,DIO_LOW);


		  DIO_enuSetPinValue(LCD_RS_GRP,LCD_RS_PIN,DIO_LOW);
		  enuWriteNLatch(0x28);

    #else
        #error LCD Mode MUST BE EIGHT_BIT OR FOUR_BIT

    #endif

	// Display ON/OFF Control
	DIO_enuSetPinValue(LCD_RS_GRP,LCD_RS_PIN,DIO_LOW);
	enuWriteNLatch(0x0F);


	// Display Clear
	DIO_enuSetPinValue(LCD_RS_GRP,LCD_RS_PIN,DIO_LOW);
	enuWriteNLatch(0x01);

	// Entry Mode Set
	DIO_enuSetPinValue(LCD_RS_GRP,LCD_RS_PIN,DIO_LOW);
	enuWriteNLatch(0x06);

	return Local_enuErrorState;
}

ES_t Lcd_enuSendCommand(u8 Copy_u8Command){

	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = DIO_enuSetPinValue(LCD_RS_GRP,LCD_RS_PIN,DIO_LOW);

	if( Local_enuErrorState == ES_OK ){

		Local_enuErrorState = enuWriteNLatch(Copy_u8Command);
	}

	return Local_enuErrorState;
}

ES_t Lcd_enuSendData(u8 Copy_u8Data){

	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = DIO_enuSetPinValue(LCD_RS_GRP,LCD_RS_PIN,DIO_HIGH);

	if( Local_enuErrorState == ES_OK ){

		Local_enuErrorState = enuWriteNLatch(Copy_u8Data);
	}

	return Local_enuErrorState;
}

ES_t Lcd_enuSendString(const char * Copy_pcString){

	ES_t Local_enuErrorState = ES_NOK;

	ES_t Local_aenuErrorState[LCD_SEND_STRING_ERROR_STATE_COND] = {0};

	while(*Copy_pcString){

		Local_aenuErrorState[0] = DIO_enuSetPinValue(LCD_RS_GRP,LCD_RS_PIN,DIO_HIGH);
		Local_aenuErrorState[1] = enuWriteNLatch(*Copy_pcString++);

	}

	return Local_enuErrorState;


}

ES_t Lcd_enuSetCursor(u8 Copy_u8RowNum , u8 Copy_u8ColNum){

	ES_t Local_enuErrorState = ES_NOK;

	if( ((Copy_u8RowNum >= LCD_MIN_NUM_ROWS) && (Copy_u8RowNum <= LCD_MAX_NUM_ROWS)) &&
			((Copy_u8ColNum >= LCD_MIN_NUM_COLS) && (Copy_u8ColNum <= LCD_MAX_NUM_COLS))){

		DIO_enuSetPinValue(LCD_RS_GRP,LCD_RS_PIN,DIO_LOW);
		enuWriteNLatch((LCD_ROW_1_COL_1_BASE_ADDRESS + ( (LCD_NUM_TO_ROW_2_COL_1_SHIFT) * (Copy_u8RowNum - 1))) +  (Copy_u8ColNum - 1));

	}
	else{

		Local_enuErrorState = ES_OUT_OF_RANGE;
	}


	return Local_enuErrorState;
}

ES_t Lcd_enuDrawSpecialChar(u8 * Copy_pu8Pattern , u8 Copy_u8PatternNum, u8 Copy_StartPattern , u8 Copy_u8RowNum , u8 Copy_u8ColNum , u8 Copy_u8PrintDirection){

	ES_t Local_enuErrorState = ES_NOK;

	if( Copy_pu8Pattern != NULL ){

		if( (Copy_u8PatternNum < LCD_MAX_PATTERN_NUM) &&
				((Copy_StartPattern <= LCD_PATTERN_7_BASE_ADDRESS) && (Copy_StartPattern >= LCD_PATTERN_0_BASE_ADDRESS)) &&
				(Copy_u8RowNum >= LCD_MIN_NUM_ROWS) && (Copy_u8RowNum <= LCD_MAX_NUM_ROWS) &&
				(Copy_u8ColNum >= LCD_MIN_NUM_COLS) && (Copy_u8ColNum <= LCD_MAX_NUM_COLS) &&
				((Copy_u8PrintDirection == LCD_DISPLAY_RIGHT) || (Copy_u8PrintDirection == LCD_DISPLAY_LEFT)) ){


			DIO_enuSetPinValue(LCD_RS_GRP,LCD_RS_PIN,DIO_LOW);
			enuWriteNLatch(Copy_StartPattern); //shift CGRAM

			for(u8 iter = 0 ; iter < LCD_NUM_OF_BYTES_PER_CHART ; iter++){

				DIO_enuSetPinValue(LCD_RS_GRP,LCD_RS_PIN,DIO_HIGH);
				enuWriteNLatch(*Copy_pu8Pattern++);
			}


			DIO_enuSetPinValue(LCD_RS_GRP,LCD_RS_PIN,DIO_LOW);
			enuWriteNLatch((LCD_ROW_1_COL_1_BASE_ADDRESS + ( (LCD_NUM_TO_ROW_2_COL_1_SHIFT) * (Copy_u8RowNum - 1))) +  (Copy_u8ColNum - 1)); // shift DDRAM

			DIO_enuSetPinValue(LCD_RS_GRP,LCD_RS_PIN,DIO_LOW);
			enuWriteNLatch(Copy_u8PrintDirection);

			DIO_enuSetPinValue(LCD_RS_GRP,LCD_RS_PIN,DIO_HIGH);
			enuWriteNLatch(Copy_u8PatternNum);


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

ES_t Lcd_enuWriteIntegarNum(s32 Copy_s32Num){

	return enuDisplayNum(Copy_s32Num);
}

ES_t Lcd_enuWriteFloatNum(f32 Copy_f32Num){

	ES_t Local_enuErrorState = ES_NOK;

	f32 Local_f32DecimalPart;
	Local_f32DecimalPart = Copy_f32Num - (s32)Copy_f32Num;
	enuDisplayNum((s32)Copy_f32Num);

	if( LCD_LENGTH_OF_DECIMAL != 0){

		//Lcd_enuSendData('.');

		if( Local_f32DecimalPart == 0.0 ){

			//enuDisplayNum(0);
		}
		else{
			Lcd_enuSendData('.');

			u8 Copy_u8LengthOfDecimalPart = LCD_LENGTH_OF_DECIMAL;

			while(Copy_u8LengthOfDecimalPart != 0){

				/*if(Local_f32DecimalPart - (s32)Local_f32DecimalPart == 0.0){
					break;
				}*/
				Local_f32DecimalPart *= 10;
				//enuDisplayNum((u8)Local_f32DecimalPart);
				Copy_u8LengthOfDecimalPart--;
			}

			enuDisplayNum( (s32)Local_f32DecimalPart );
		}
	}
	else{

	}

	return Local_enuErrorState;

}

static ES_t enuDisplayNum(s32 Copy_s32Num){

	ES_t Local_enuErrorState = ES_NOK;

	char Local_acIntNumString[33] = {0};
	u8 Local_u8ArrayIter = 0;
	Local_enuErrorState = enuIntToString(Copy_s32Num,Local_acIntNumString);

	if( Local_enuErrorState == ES_OK ){

		while(Local_acIntNumString[Local_u8ArrayIter]){

			Local_enuErrorState = DIO_enuSetPinValue(LCD_RS_GRP,LCD_RS_PIN,DIO_HIGH);

			if( Local_enuErrorState == ES_OK ){

				Local_enuErrorState = enuWriteNLatch(Local_acIntNumString[Local_u8ArrayIter++]);

			}
			else{

				break;
			}
		}

	}

	return Local_enuErrorState;
}

ES_t enuIntToString(s32 Copy_s32Num, char* Copy_pcIntNumString) {

	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pcIntNumString != NULL){

		u8 Local_u8ArrayIter = 0;
		u8 Local_u8IsNegative = 0;

		// Handle negative numbers
		if (Copy_s32Num < 0) {

			Local_u8IsNegative = 1;
			Copy_s32Num = -Copy_s32Num;

		}

		// Handle special case of 0
		if (Copy_s32Num == 0) {

			Copy_pcIntNumString[Local_u8ArrayIter++] = '0';
		}

		// Process digits in reverse order
		while (Copy_s32Num != 0) {

			Copy_pcIntNumString[Local_u8ArrayIter++] = (char)(Copy_s32Num % 10 + '0');
			Copy_s32Num /= 10;
		}

		// Add negative sign if necessary
		if (Local_u8IsNegative) {
			Copy_pcIntNumString[Local_u8ArrayIter++] = '-';
		}

		Copy_pcIntNumString[Local_u8ArrayIter] = '\0';

		// Reverse the string
		u8 Local_u8ArrayStart = 0;
		u8 Local_u8ArrayEnd = Local_u8ArrayIter - 1;

		while (Local_u8ArrayStart < Local_u8ArrayEnd) {

			char temp = Copy_pcIntNumString[Local_u8ArrayStart];
		    Copy_pcIntNumString[Local_u8ArrayStart] = Copy_pcIntNumString[Local_u8ArrayEnd];
		    Copy_pcIntNumString[Local_u8ArrayEnd] = temp;
		    Local_u8ArrayStart++;
		    Local_u8ArrayEnd--;
		}

		Local_enuErrorState = ES_OK;

	}
	else{

		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;

}



ES_t enuWriteNLatch(u8 Copy_u8Byte){

	ES_t Local_enuErrorState = ES_NOK;

	ES_t Local_aenuErrorState[LCD_WRITENLATCH_ERROR_STATE_COND] = {0};

	Local_aenuErrorState[0] = DIO_enuSetPinValue(LCD_RW_GRP,LCD_RW_PIN,DIO_LOW);
	Local_aenuErrorState[1] = DIO_enuSetPinValue(LCD_EN_GRP,LCD_EN_PIN,DIO_LOW);



    #if LCD_MODE == EIGHT_BIT

	    DIO_enuSetPinValue(LCD_D7_GRP,LCD_D7_PIN,(Copy_u8Byte>>LCD_BYTE_7)&LCD_BIT_MASK);
 	    DIO_enuSetPinValue(LCD_D6_GRP,LCD_D6_PIN,(Copy_u8Byte>>LCD_BYTE_6)&LCD_BIT_MASK);
	    DIO_enuSetPinValue(LCD_D5_GRP,LCD_D5_PIN,(Copy_u8Byte>>LCD_BYTE_5)&LCD_BIT_MASK);
	    DIO_enuSetPinValue(LCD_D4_GRP,LCD_D4_PIN,(Copy_u8Byte>>LCD_BYTE_4)&LCD_BIT_MASK);

	    DIO_enuSetPinValue(LCD_D3_GRP,LCD_D3_PIN,(Copy_u8Byte>>LCD_BYTE_3)&LCD_BIT_MASK);
	    DIO_enuSetPinValue(LCD_D2_GRP,LCD_D2_PIN,(Copy_u8Byte>>LCD_BYTE_2)&LCD_BIT_MASK);
	    DIO_enuSetPinValue(LCD_D1_GRP,LCD_D1_PIN,(Copy_u8Byte>>LCD_BYTE_1)&LCD_BIT_MASK);
	    DIO_enuSetPinValue(LCD_D0_GRP,LCD_D0_PIN,(Copy_u8Byte>>LCD_BYTE_0)&LCD_BIT_MASK);

	    DIO_enuSetPinValue(LCD_EN_GRP,LCD_EN_PIN,DIO_HIGH);
	    _delay_ms(2);
	    DIO_enuSetPinValue(LCD_EN_GRP,LCD_EN_PIN,DIO_LOW);

	    _delay_ms(2);

    #elif LCD_MODE == FOUR_BIT

	      DIO_enuSetPinValue(LCD_D7_GRP,LCD_D7_PIN,((Copy_u8Byte>>LCD_BYTE_7)&LCD_BIT_MASK));
	      DIO_enuSetPinValue(LCD_D6_GRP,LCD_D6_PIN,((Copy_u8Byte>>LCD_BYTE_6)&LCD_BIT_MASK));
	      DIO_enuSetPinValue(LCD_D5_GRP,LCD_D5_PIN,((Copy_u8Byte>>LCD_BYTE_5)&LCD_BIT_MASK));
	      DIO_enuSetPinValue(LCD_D4_GRP,LCD_D4_PIN,((Copy_u8Byte>>LCD_BYTE_4)&LCD_BIT_MASK));

	      DIO_enuSetPinValue(LCD_EN_GRP,LCD_EN_PIN,DIO_HIGH);
	      _delay_ms(1);
	      DIO_enuSetPinValue(LCD_EN_GRP,LCD_EN_PIN,DIO_LOW);

	      DIO_enuSetPinValue(LCD_D7_GRP,LCD_D7_PIN,((Copy_u8Byte>>LCD_BYTE_3)&LCD_BIT_MASK));
	      DIO_enuSetPinValue(LCD_D6_GRP,LCD_D6_PIN,((Copy_u8Byte>>LCD_BYTE_2)&LCD_BIT_MASK));
	      DIO_enuSetPinValue(LCD_D5_GRP,LCD_D5_PIN,((Copy_u8Byte>>LCD_BYTE_1)&LCD_BIT_MASK));
	      DIO_enuSetPinValue(LCD_D4_GRP,LCD_D4_PIN,((Copy_u8Byte>>LCD_BYTE_0)&LCD_BIT_MASK));

	      DIO_enuSetPinValue(LCD_EN_GRP,LCD_EN_PIN,DIO_HIGH);
	      _delay_ms(1);
	      DIO_enuSetPinValue(LCD_EN_GRP,LCD_EN_PIN,DIO_LOW);

	     _delay_ms(2);

    #else
	    #error LCD Mode MUST BE EIGHT_BIT OR FOUR_BIT

    #endif

	return Local_enuErrorState;
}
