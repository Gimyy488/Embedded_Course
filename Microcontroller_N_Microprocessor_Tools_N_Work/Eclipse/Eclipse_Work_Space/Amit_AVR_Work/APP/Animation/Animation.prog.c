/*
 * Animation.prog.c
 *
 *  Created on: Sep 30, 2023
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
#include "../../HAL/Lcd/Lcd_int.h"
#include "../../HAL/Buzzer/Buzzer_int.h"

#include "Animation_priv.h"

ES_t Animation_enuInit(void){

	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = Lcd_enuInit();
	Buzzer_enuInit();

	u8 Local_au8AlivePerson[] = ANIMATION_SHOOTER;
	u8 Local_au8DeadPerson[] = ANIMATIN_VICTIM;
	u8 Local_au8Gun[] = ANIMATION_PISTOL;
	u8 Local_u8Bullet[] = ANIMATION_BULLET;

	Lcd_enuDrawSpecialChar(Local_au8AlivePerson,LCD_PATTERN_0,LCD_PATTERN_0_BASE_ADDRESS,
			LCD_ROW_1,LCD_COLUMN_1,LCD_DISPLAY_LEFT);

	Lcd_enuDrawSpecialChar(Local_au8AlivePerson,LCD_PATTERN_1,LCD_PATTERN_1_BASE_ADDRESS,
			LCD_ROW_1,LCD_COLUMN_16,LCD_DISPLAY_LEFT);

	Lcd_enuDrawSpecialChar(Local_au8Gun,LCD_PATTERN_2,LCD_PATTERN_2_BASE_ADDRESS,
			LCD_ROW_1,LCD_COLUMN_2,LCD_DISPLAY_LEFT);

	Lcd_enuDrawSpecialChar(Local_u8Bullet,LCD_PATTERN_3,LCD_PATTERN_3_BASE_ADDRESS,
			LCD_ROW_1,LCD_COLUMN_3,LCD_DISPLAY_LEFT);

	Lcd_enuSetCursor(LCD_ROW_1,LCD_COLUMN_1);
	Lcd_enuSendData(LCD_PATTERN_0);

	Lcd_enuSetCursor(LCD_ROW_1,LCD_COLUMN_16);
	Lcd_enuSendData(LCD_PATTERN_1);

	Lcd_enuSetCursor(LCD_ROW_1,LCD_COLUMN_2);
	Lcd_enuSendData(LCD_PATTERN_2);

	Lcd_enuSetCursor(LCD_ROW_1,LCD_COLUMN_3);
	Lcd_enuSendData(LCD_PATTERN_3);

	Lcd_enuSendCommand(LCD_CURSOR_OFF);


	return Local_enuErrorState;
}

ES_t Animation_enuBeginAnimat(void){

	ES_t Local_enuErrorState = ES_NOK;


	u8 Local_u8Iter;

	for(Local_u8Iter = 4 ; Local_u8Iter < 16 ; Local_u8Iter++){

		Lcd_enuSetCursor(LCD_ROW_1 , Local_u8Iter-1);
		Lcd_enuSendData(LCD_CLEAR_CELL);

		Lcd_enuSetCursor(LCD_ROW_1 , Local_u8Iter);
		Lcd_enuSendData(LCD_PATTERN_3);
		_delay_ms(50);

		if( Local_u8Iter == 15 ){

			Buzzer_enuAlertActivator();
			_delay_ms(200);
			Buzzer_enuSilenceDeactivation();

			Lcd_enuSendCommand(LCD_CLEAR_DISPLAY);

			Lcd_enuSetCursor(LCD_ROW_1,LCD_COLUMN_7);
			Lcd_enuSendString("Dead");

			Lcd_enuSetCursor(LCD_ROW_2,LCD_COLUMN_5);
			Lcd_enuSendString("Game Over");

		}
	}

	return Local_enuErrorState;

}
