/*
 * Led_int.h
 *
 *  Created on: Sep 26, 2023
 *      Author: LENOVO
 */

#ifndef HAL_LED_LED_INT_H_
#define HAL_LED_LED_INT_H_

#define LED_GREEN_ID   0
#define LED_RED_ID     1
#define LED_YELLOW_ID  2



ES_t Led_enuInit(void);

ES_t Led_enuLedTurnON(u8 Copy_u8LedID);

ES_t Led_enuLedTurnOFF(u8 Copy_u8LedID);

ES_t Led_enuLedToggle(u8 Copy_u8LedID);

#endif /* HAL_LED_LED_INT_H_ */
