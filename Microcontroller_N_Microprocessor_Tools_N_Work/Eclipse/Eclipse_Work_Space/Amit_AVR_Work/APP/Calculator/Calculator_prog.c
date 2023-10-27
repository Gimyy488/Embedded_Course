/*
 * Calculator_prog.c
 *
 *  Created on: Oct 3, 2023
 *      Author: Omar Gamal El-Kady
 */
// public
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"
#include "util/delay.h"
//#include <stdlib.h>


//lower
#include "../../HAL/HexaDecoder/HexaDecoder_int.h"
#include "../../HAL/Led/Led_int.h"
#include "../../HAL/Switch/Switch_int.h"
#include "../../HAL/Lcd/Lcd_int.h"
#include "../../HAL/Buzzer/Buzzer_int.h"
#include "../../HAL/Keypad/Keypad_int.h"

// owm
#include "Calculator_priv.h"

ES_t Calculator_enuInit(void){

	ES_t Local_enuErrorState = ES_NOK;

	Lcd_enuInit();

	Lcd_enuSendCommand(LCD_CURSOR_OFF);
	Lcd_enuSetCursor(LCD_ROW_1,LCD_COLUMN_5);
	Lcd_enuSendString("Calculator");

	Keypad_enuInit();

	_delay_ms(1000);

	Lcd_enuSendCommand(LCD_CLEAR_DISPLAY);

	return Local_enuErrorState;
}

ES_t Calculator_enuPowerCalculator(void){

	ES_t Local_enuErrorState = ES_NOK;


	u8 Local_u8KeypadValue;
	BOOL Local_bFillNextOperand = false;
	BOOL Local_bOperatorFlag = false;
	u8 Local_au8EnteredOperand[33] = {'\0'};
	f32 Local_f32OperationResult = 0;
	u8 Local_u8Operator;
	u8 Local_u8Iter = 0;

	while(1){

		Keypad_enuGetPressedKey(&Local_u8KeypadValue);
		if(Local_u8KeypadValue != KEYPAD_NOT_PRESSED){

			s32 Local_s32EnteredOperand;
			if(Local_u8KeypadValue == CALCULATOR_CLEAR_BUTTON){

				Lcd_enuSendCommand(LCD_CLEAR_DISPLAY);
				//_delay_ms(2000);
				Lcd_enuSetCursor(LCD_ROW_1,LCD_COLUMN_1);
				Lcd_enuSendString("Make New Operation");
				Local_u8Iter = 0;
				Local_f32OperationResult = 0;
				Local_bFillNextOperand = false;
				Local_bOperatorFlag = false;
				_delay_ms(1000);
				Lcd_enuSendCommand(LCD_CLEAR_DISPLAY);
			}
			else if(Local_u8KeypadValue == CALCULATOR_EQUAL_OPERATOR){

				Lcd_enuSendData(Local_u8KeypadValue);


				if(Local_u8Operator == CALCULATOR_ADDITION){

					enuArraytoInteger(Local_au8EnteredOperand,&Local_s32EnteredOperand);
					Local_f32OperationResult = Local_f32OperationResult +  Local_s32EnteredOperand;
					Lcd_enuWriteIntegarNum((s32)Local_f32OperationResult);
				}
				else if(Local_u8Operator == CALCULATOR_SUBTRACTION){

					enuArraytoInteger(Local_au8EnteredOperand,&Local_s32EnteredOperand);
					Local_f32OperationResult = Local_f32OperationResult - Local_s32EnteredOperand;
					Lcd_enuWriteIntegarNum((s32)Local_f32OperationResult);
				}
				else if(Local_u8Operator == CALCULATOR_MULTIPLICATION){

					enuArraytoInteger(Local_au8EnteredOperand,&Local_s32EnteredOperand);
					Local_f32OperationResult = Local_f32OperationResult *  Local_s32EnteredOperand;
					Lcd_enuWriteIntegarNum((s32)Local_f32OperationResult);

				}
				else if(Local_u8Operator == CALCULATOR_DEVISION){

					enuArraytoInteger(Local_au8EnteredOperand,&Local_s32EnteredOperand);
					Local_f32OperationResult = Local_f32OperationResult /  Local_s32EnteredOperand;
					Lcd_enuWriteFloatNum(Local_f32OperationResult);
				}
				else{

					enuArraytoInteger(Local_au8EnteredOperand,&Local_s32EnteredOperand);
					Local_f32OperationResult = Local_f32OperationResult +  Local_s32EnteredOperand;
					Lcd_enuWriteIntegarNum((s32)Local_f32OperationResult);
				}


			}
			else if( ((Local_u8KeypadValue >= CALCULATOR_MIN_NUM) && (Local_u8KeypadValue <= CALCULATOR_MAX_NUM))
					|| ( ((Local_u8KeypadValue == CALCULATOR_ADDITION) || (Local_u8KeypadValue == CALCULATOR_SUBTRACTION))
							&& (Local_bOperatorFlag == false)) || (Local_u8KeypadValue == CALCULATOR_DOT)){

				Lcd_enuSendData(Local_u8KeypadValue);

				Local_au8EnteredOperand[Local_u8Iter] = Local_u8KeypadValue;
				Local_u8Iter++;
				Local_au8EnteredOperand[Local_u8Iter] = '\0';
				Local_bOperatorFlag = true;

			}
			else if((Local_u8KeypadValue == CALCULATOR_ADDITION) && (Local_bOperatorFlag == true)){

				Lcd_enuSendData(Local_u8KeypadValue);

				Local_u8Operator = CALCULATOR_ADDITION;
				Local_bFillNextOperand = true;
				Local_bOperatorFlag = false;
				Local_u8Iter = 0;

				enuArraytoInteger(Local_au8EnteredOperand,&Local_s32EnteredOperand);
				Local_f32OperationResult = Local_f32OperationResult + Local_s32EnteredOperand;

			}
			else if((Local_u8KeypadValue == CALCULATOR_SUBTRACTION) && (Local_bOperatorFlag == true)){

				enuArraytoInteger(Local_au8EnteredOperand,&Local_s32EnteredOperand);
				if(Local_f32OperationResult == 0 ){

					Local_f32OperationResult = Local_s32EnteredOperand;
					Local_s32EnteredOperand = 0;
				}
				Lcd_enuSendData(Local_u8KeypadValue);

				Local_u8Operator = CALCULATOR_SUBTRACTION;
				Local_bFillNextOperand = true;
				Local_bOperatorFlag = false;
				Local_u8Iter = 0;

				Local_f32OperationResult = Local_f32OperationResult - Local_s32EnteredOperand;

			}
			else if((Local_u8KeypadValue == CALCULATOR_MULTIPLICATION) && (Local_bOperatorFlag == true)){

				if(Local_f32OperationResult == 0){

					Local_f32OperationResult = 1;
				}
				Lcd_enuSendData(Local_u8KeypadValue);

				Local_u8Operator = CALCULATOR_MULTIPLICATION;
				Local_bFillNextOperand = true;
				Local_bOperatorFlag = false;
				Local_u8Iter = 0;

				enuArraytoInteger(Local_au8EnteredOperand,&Local_s32EnteredOperand);
				Local_f32OperationResult = Local_f32OperationResult * Local_s32EnteredOperand;
			}
			else if((Local_u8KeypadValue == CALCULATOR_DEVISION) && (Local_bOperatorFlag == true)){

				enuArraytoInteger(Local_au8EnteredOperand,&Local_s32EnteredOperand);

				if(Local_f32OperationResult == 0){

					Local_f32OperationResult = Local_s32EnteredOperand;
					Local_s32EnteredOperand = 1;
				}

				Lcd_enuSendData(Local_u8KeypadValue);

				Local_u8Operator = CALCULATOR_DEVISION;
				Local_bFillNextOperand = true;
				Local_bOperatorFlag = false;
				Local_u8Iter = 0;

				Local_f32OperationResult = Local_f32OperationResult / Local_s32EnteredOperand;
			}
			else{}
		}
		else{}
	}


	return Local_enuErrorState;

}

ES_t enuArraytoInteger(const s8 * Copy_ps8String,s32 * Copy_s32IntValue){

	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8StringIter = 0;
	s16 Local_s8IntSign = 0;
	s32 Local_s32OperationResult = 0;

	if((Copy_ps8String != NULL) && (Copy_s32IntValue != NULL)){

		if(Copy_ps8String[Local_u8StringIter] == '-'){

			Local_s8IntSign  = -1;
			Local_u8StringIter++;
		}
		else if(Copy_ps8String[Local_u8StringIter] == '+'){

			Local_s8IntSign = 1;
			Local_u8StringIter++;
		}
		else{

			Local_s8IntSign = 1;
		}

		while(Copy_ps8String[Local_u8StringIter] != '\0'){

			Local_s32OperationResult = Local_s32OperationResult * 10 + (Copy_ps8String[Local_u8StringIter] - '0');
			Local_u8StringIter++;

		}

		*Copy_s32IntValue = Local_s32OperationResult * Local_s8IntSign;
	}
	else{

		Local_enuErrorState = ES_NULL_POINTER;
	}


	return Local_enuErrorState;
}

