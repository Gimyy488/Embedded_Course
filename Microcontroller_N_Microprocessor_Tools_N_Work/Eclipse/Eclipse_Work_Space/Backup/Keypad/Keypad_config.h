/*
 * Keypad_config.h
 *
 *  Created on: Oct 2, 2023
 *      Author: Omar Gamal El-Kady
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

// keypad row , column number
#define KEYPAD_NUM_OF_ROWS          4
#define KEYPAD_NUM_OF_COLUMNS       4

// keypad row config
#define KEYPAD_ROW_1_GRP            DIO_GROUP_C
#define KEYPAD_ROW_1_PIN            DIO_PIN_2

#define KEYPAD_ROW_2_GRP            DIO_GROUP_C
#define KEYPAD_ROW_2_PIN            DIO_PIN_3

#define KEYPAD_ROW_3_GRP            DIO_GROUP_C
#define KEYPAD_ROW_3_PIN            DIO_PIN_4

#define KEYPAD_ROW_4_GRP            DIO_GROUP_C
#define KEYPAD_ROW_4_PIN            DIO_PIN_5

// keypad column config
#define KEYPAD_COLUMN_1_GRP            DIO_GROUP_D
#define KEYPAD_COLUMN_1_PIN            DIO_PIN_1

#define KEYPAD_COLUMN_2_GRP            DIO_GROUP_D
#define KEYPAD_COLUMN_2_PIN            DIO_PIN_3

#define KEYPAD_COLUMN_3_GRP            DIO_GROUP_D
#define KEYPAD_COLUMN_3_PIN            DIO_PIN_2

#define KEYPAD_COLUMN_4_GRP            DIO_GROUP_D
#define KEYPAD_COLUMN_4_PIN            DIO_PIN_7

// keypad key values

#define KEYPAD_KEY_VALUES             {\
                                       {'7','8','9','/'},\
									   {'4','5','6','*'},\
									   {'1','2','3','-'},\
									   {LCD_CLEAR_DISPLAY,'0','=','+'}\
                                       }



#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
