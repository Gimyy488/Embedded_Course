/*
 * LoginSystem_prog.c
 *
 *  Created on: Oct 2, 2023
 *      Author: Omar Gamal El-Kady
 */

// public
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"
#include "util/delay.h"

//lower
#include "../../HAL/HexaDecoder/HexaDecoder_int.h"
#include "../../HAL/Led/Led_int.h"
#include "../../HAL/Switch/Switch_int.h"
#include "../../HAL/Lcd/Lcd_int.h"
#include "../../HAL/Buzzer/Buzzer_int.h"
#include "../../HAL/Keypad/Keypad_int.h"
#include "../../MCAL/ADC/ADC_int.h"
#include "../../MCAL/DIO/DIO_int.h"

// owm
#include "LoginSystem_config.h"
#include "LoginSystem_priv.h"

ES_t LoginSystem_enuInit(void){

	ES_t Local_enuErrorState = ES_NOK;

	Lcd_enuInit();
	Led_enuInit();
	Keypad_enuInit();
	Buzzer_enuInit();
	ADC_enuInit();
	Lcd_enuSendCommand(LCD_CURSOR_OFF);

	DIO_enuSetPinDirection(DIO_GROUP_A,DIO_PIN_1,DIO_INPUT);
	DIO_enuSetPinValue(DIO_GROUP_A,DIO_PIN_1,DIO_FLOAT);

	ADCChannels_t Local_u8ADCChannels = ADC1;

	ADC_enuSetADCChannel(ADC1);
	ADC_enuClearTriggerSource();
	ADC_enuSetTriggerSource(ADC_SINGLE_CONVERSION);
	ADC_enuSetIterruptMode(ADC1,ADC_POLLING);


	//enuSendDataAtCursorLocation("Omar",1,1);

	return Local_enuErrorState;
}

ES_t LoginSystem_enuWelcomePage(void){


	ES_t Local_enuErrorState = ES_NOK;

	Lcd_enuSendCommand(LCD_CURSOR_OFF);

	enuSendDataAtCursorLocation("Welcome :)",LCD_ROW_1,LCD_COLUMN_4);

	//Lcd_enuSetCursor(LCD_ROW_1,LCD_COLUMN_4);
	//Lcd_enuSendString("Welcome :)");

	enuSendDataAtCursorLocation("Loading......",LCD_ROW_2,LCD_COLUMN_4);

	//Lcd_enuSetCursor(LCD_ROW_2,LCD_COLUMN_4);
	//Lcd_enuSendString("Loading......");

	_delay_ms(1000);

	Lcd_enuSendCommand(LCD_CLEAR_DISPLAY);


	return Local_enuErrorState;
}

ES_t LoginSystem_enuEnterPassPage(BOOL * Copy_bPasswordCheck){

	ES_t Local_enuErrorState = ES_NOK;

	enuSendDataAtCursorLocation("Enter Password : ",LCD_ROW_1,LCD_COLUMN_1);
	//Lcd_enuSetCursor(LCD_ROW_1,LCD_COLUMN_1);
	//Lcd_enuSendString("Password : ");
	Lcd_enuSetCursor(LCD_ROW_2,LCD_COLUMN_1);

	u8 Local_au8EnteredPassword[10] = {'\0'};
	u8 Local_u8Iter = 0;
	u8 Local_u8TrialCounter = 0;
	u8 Local_u8KeypadValue;

	if( Copy_bPasswordCheck != NULL){

		while(1){

			if(Local_u8TrialCounter < LOGINSYSTEM_NUM_OF_TRIALS){


				Keypad_enuGetPressedKey(&Local_u8KeypadValue);

				if(Local_u8KeypadValue != KEYPAD_NOT_PRESSED){

					if(Local_u8Iter < LOGINSYSTEM_LENGTH_OF_PASSWORD){

						if(Local_u8KeypadValue == LOGINSYSTEM_ENTER_KEY){

							u8 Local_u8SystemPassword[]= LOGINSTSYTEM_PASSWORD;
							BOOL Local_bCorrectPass;
							Local_u8Iter = 0;

							while( //(Local_au8EnteredPassword[Local_u8Iter] != '\0') &&
									(Local_u8SystemPassword[Local_u8Iter] != '\0') ){

								if( Local_au8EnteredPassword[Local_u8Iter] == Local_u8SystemPassword[Local_u8Iter]){

									Local_bCorrectPass = true;
									Local_u8Iter++;
								}
								else{

									Local_bCorrectPass = false;
									break;
								}
							}

							if( Local_bCorrectPass == true ){

								Buzzer_enuAlertActivator();

								enuSendDataAtCursorLocation("Correct Password",LCD_ROW_1,LCD_COLUMN_1);
								//Lcd_enuSetCursor(LCD_ROW_1,LCD_COLUMN_1);
								//Lcd_enuSendString("Correct Password");

								_delay_ms(500);
								Buzzer_enuSilenceDeactivation();

								Lcd_enuSendCommand(LCD_CLEAR_DISPLAY);

								*Copy_bPasswordCheck = true;
								Local_u8Iter = 0;

								break;
							}
							else{

								Local_u8TrialCounter++;

								Buzzer_enuAlertActivator();

								Lcd_enuSendCommand(LCD_CLEAR_DISPLAY);
								enuSendDataAtCursorLocation("InCorrect Password",LCD_ROW_1,LCD_COLUMN_1);
								//Lcd_enuSetCursor(LCD_ROW_1,LCD_COLUMN_1);
							    //Lcd_enuSendString("InCorrect Password");

								_delay_ms(500);
								Buzzer_enuSilenceDeactivation();

								if(Local_u8TrialCounter < LOGINSYSTEM_NUM_OF_TRIALS){

									Lcd_enuSendCommand(LCD_CLEAR_DISPLAY);
									enuSendDataAtCursorLocation("Enter Password : ",LCD_ROW_1,LCD_COLUMN_1);
									Lcd_enuSetCursor(LCD_ROW_2,LCD_COLUMN_1);
								}

								Local_u8Iter = 0;

								//break;
							}

						}

						else{

							Lcd_enuSendData('*');
							Local_au8EnteredPassword[Local_u8Iter] = Local_u8KeypadValue;
							Local_u8Iter++;
						}

					}

					else{
						Local_u8TrialCounter++;

						Buzzer_enuAlertActivator();

						Lcd_enuSendCommand(LCD_CLEAR_DISPLAY);

						enuSendDataAtCursorLocation("Incorrect Password",LCD_ROW_1,LCD_COLUMN_1);
						//Lcd_enuSetCursor(LCD_ROW_1,LCD_COLUMN_1);
						//Lcd_enuSendString("Incorrect Password");

						enuSendDataAtCursorLocation("0<Pass should<",LCD_ROW_2,LCD_COLUMN_1);
						Lcd_enuWriteIntegarNum(LOGINSYSTEM_LENGTH_OF_PASSWORD);
						//Lcd_enuSetCursor(LCD_ROW_2,LCD_COLUMN_1);
						//Lcd_enuSendString("0<Pass should<30");

						_delay_ms(500);
						Buzzer_enuSilenceDeactivation();

						Lcd_enuSendCommand(LCD_CLEAR_DISPLAY);

						if(Local_u8TrialCounter < LOGINSYSTEM_NUM_OF_TRIALS){

							Lcd_enuSendCommand(LCD_CLEAR_DISPLAY);
							enuSendDataAtCursorLocation("Enter Password : ",LCD_ROW_1,LCD_COLUMN_1);
							Lcd_enuSetCursor(LCD_ROW_2,LCD_COLUMN_1);
						}

						Local_u8Iter = 0;

						//break;
					}
				}
				else{}

			}

			else{

				Buzzer_enuAlertActivator();
				Lcd_enuSendCommand(LCD_CLEAR_DISPLAY);
				enuSendDataAtCursorLocation("Theif.......",LCD_ROW_1,LCD_COLUMN_1);
				Buzzer_enuSilenceDeactivation();
				_delay_ms(5000);
				Lcd_enuSendCommand(LCD_CLEAR_DISPLAY);

				*Copy_bPasswordCheck = false;

				break;
			}
		}
	}
	else{

		Local_enuErrorState = ES_NULL_POINTER;
	}



	return Local_enuErrorState;

}

ES_t LoginSystem_enuMainDashBoard(void){

	ES_t Local_enuErrorState = ES_NOK;

	u8 * Local_pau8PageOneOptions[] = {"1-LED","2-AC","3-TEMP","4-EXIT"};
	enuOptionPage(Local_pau8PageOneOptions,4);

	u8 Local_u8KeypadValue;

	while(1){

		Keypad_enuGetPressedKey(&Local_u8KeypadValue);

		if(Local_u8KeypadValue != KEYPAD_NOT_PRESSED){

			//Keypad_enuGetPressedKey(&Local_u8KeypadValue);

			if(Local_u8KeypadValue == '1'){

				u8 * Local_pau8LedsOptions[] = {"1-LED1","2-LED2","3-LED3","4-BACK"};
				enuOptionPage(Local_pau8LedsOptions,4);

				while(1){
					_delay_ms(50);
					Keypad_enuGetPressedKey(&Local_u8KeypadValue);

					if(Local_u8KeypadValue != KEYPAD_NOT_PRESSED){

						u8 * Local_pau8LedStateOptions[] = {"1-LED ON","2-LED OFF","3-BACK"};
						//enuOptionPage(Local_pau8LedStateOptions,3);

						if(Local_u8KeypadValue == '1'){

							enuOptionPage(Local_pau8LedStateOptions,3);
							while(1){
								_delay_ms(50);

								Keypad_enuGetPressedKey(&Local_u8KeypadValue);

								if(Local_u8KeypadValue != KEYPAD_NOT_PRESSED){

									if(Local_u8KeypadValue == '1'){

										Led_enuLedTurnON(LED_GREEN_ID);
									}

									else if(Local_u8KeypadValue == '2'){

										Led_enuLedTurnOFF(LED_GREEN_ID);
									}
									else if(Local_u8KeypadValue == '3'){

										enuOptionPage(Local_pau8LedsOptions,4);
										break;
									}
									else{}

								}
							}

						}

						else if(Local_u8KeypadValue == '2'){
							enuOptionPage(Local_pau8LedStateOptions,3);

							while(1){
								_delay_ms(50);

								Keypad_enuGetPressedKey(&Local_u8KeypadValue);

								if(Local_u8KeypadValue != KEYPAD_NOT_PRESSED){

									if(Local_u8KeypadValue == '1'){

										Led_enuLedTurnON(LED_RED_ID);
									}
									else if(Local_u8KeypadValue == '2'){

										Led_enuLedTurnOFF(LED_RED_ID);

									}
									else if(Local_u8KeypadValue == '3'){
										enuOptionPage(Local_pau8LedsOptions,4);
										break;
									}
									else{}
								}

							}

						}
						else if(Local_u8KeypadValue == '3'){
							enuOptionPage(Local_pau8LedStateOptions,3);


							while(1){
								_delay_ms(50);

								Keypad_enuGetPressedKey(&Local_u8KeypadValue);

							    if(Local_u8KeypadValue != KEYPAD_NOT_PRESSED){

							    	if(Local_u8KeypadValue == '1'){

							    		Led_enuLedTurnON(LED_YELLOW_ID);
							    	}
							    	else if(Local_u8KeypadValue == '2'){

							    		Led_enuLedTurnOFF(LED_YELLOW_ID);

							        }
							    	else if(Local_u8KeypadValue == '3'){

							    		enuOptionPage(Local_pau8LedsOptions,4);
							    		break;
							    	}
							    	else{}
							    }

							}

						}
						else if(Local_u8KeypadValue == '4'){

							enuOptionPage(Local_pau8PageOneOptions,4);

							break;
						}
						else{}


					}
					else{}
				}


			}
			else if(Local_u8KeypadValue == '2'){

				u8 * Local_pau8ACOptions[] = {"1-AC ON","2-AC OFF","3-BACK"};
				enuOptionPage(Local_pau8ACOptions,3);

				while(1){
					_delay_ms(50);

					Keypad_enuGetPressedKey(&Local_u8KeypadValue);

					if(Local_u8KeypadValue != KEYPAD_NOT_PRESSED){

						if(Local_u8KeypadValue == '1'){

							Buzzer_enuAlertActivator();
							//on
						}
						else if(Local_u8KeypadValue == '2'){

							Buzzer_enuSilenceDeactivation();
							//off
						}
						else if(Local_u8KeypadValue == '3'){

							//back
							enuOptionPage(Local_pau8PageOneOptions,4);

							break;
						}
						else{}

					}
					else{}
				}
			}
			else if(Local_u8KeypadValue == '3'){

				u8 * Local_pau8TempOptions[] = {NULL,NULL,"1-BACK"};
				enuOptionPage(Local_pau8TempOptions,3);


				while(1){

					enuDisplayTemprature();

					Keypad_enuGetPressedKey(&Local_u8KeypadValue);

					if(Local_u8KeypadValue != KEYPAD_NOT_PRESSED){

						if(Local_u8KeypadValue == '1'){

							enuOptionPage(Local_pau8PageOneOptions,4);
							break;
						}

						else{}

					}
					else{}

					_delay_ms(500);

				}

			}
			else if(Local_u8KeypadValue == '4'){

				break;
			}
			else{}
		}
		else{}

	}

	Led_enuLedTurnOFF(LED_GREEN_ID);
	Led_enuLedTurnOFF(LED_RED_ID);
	Led_enuLedTurnOFF(LED_YELLOW_ID);

	Lcd_enuSendCommand(LCD_CLEAR_DISPLAY);
	Lcd_enuSetCursor(LCD_ROW_1,LCD_COLUMN_6);
	Lcd_enuSendString("Good Bye");
	_delay_ms(400);
	Lcd_enuSendCommand(LCD_CLEAR_DISPLAY);

	return Local_enuErrorState;
}

ES_t enuOptionPage(const u8 * Copy_au8Options[],u8 Copy_u8NumOfOptions){

	ES_t Local_enuErrorState = ES_NOK;
	Lcd_enuSendCommand(LCD_CLEAR_DISPLAY);

	u8 Local_u8OptionRow[] = {LCD_ROW_1,LCD_ROW_1,LCD_ROW_2,LCD_ROW_2};
	u8 Local_u8OptionCol[] = {LCD_COLUMN_1,LCD_COLUMN_9,LCD_COLUMN_1,LCD_COLUMN_9};

	for(u8 Local_u8Iter = 0 ; Local_u8Iter < Copy_u8NumOfOptions ; Local_u8Iter++){

		Lcd_enuSetCursor(Local_u8OptionRow[Local_u8Iter],Local_u8OptionCol[Local_u8Iter]);
		Lcd_enuSendString(Copy_au8Options[Local_u8Iter]);

		_delay_ms(200);

	}

	return Local_enuErrorState;
}

ES_t enuSendDataAtCursorLocation(const char * Copy_pcString,u8 Copy_u8RowNum , u8 Copy_u8ColNum){

	ES_t Local_enuErrorState = ES_NOK;

	Lcd_enuSetCursor(Copy_u8RowNum,Copy_u8ColNum);
	Lcd_enuSendString(Copy_pcString);
	return Local_enuErrorState;

}

ES_t enuDisplayTemprature(void){

	ES_t Local_enuErrorState = ES_NOK;


	Lcd_enuSetCursor(LCD_ROW_1,LCD_COLUMN_1);
	Lcd_enuSendString("Temp = ");
	Lcd_enuSetCursor(LCD_ROW_1,LCD_COLUMN_10);
	Lcd_enuSendString(" C");

	ADCChannels_t Local_u8ADCChannels = ADC1;
	u16 Local_u16ADCReading;
	u16 Local_u16TempValue;


	ADC_enuReadPolling(ADC1,&Local_u16ADCReading);
	Local_u16TempValue = (Local_u16ADCReading * 5000LLU) / 1024;
	Local_u16TempValue = Local_u16TempValue / 100;
	Lcd_enuSetCursor(LCD_ROW_1,LCD_COLUMN_8);
	Lcd_enuSendString("   ");
	Lcd_enuSetCursor(LCD_ROW_1,LCD_COLUMN_8);
	Lcd_enuWriteIntegarNum(Local_u16TempValue);
	//_delay_ms(500);

	return Local_enuErrorState;
}

