/*
 * Keypad_int.h
 *
 *  Created on: Oct 2, 2023
 *      Author: Omar Gamal El-Kady
 */

#ifndef HAL_KEYPAD_KEYPAD_INT_H_
#define HAL_KEYPAD_KEYPAD_INT_H_

ES_t Keypad_enuInit(void);

ES_t Keypad_enuGetPressedKey(u8 * Copy_pu8KeyValue);

#endif /* HAL_KEYPAD_KEYPAD_INT_H_ */
