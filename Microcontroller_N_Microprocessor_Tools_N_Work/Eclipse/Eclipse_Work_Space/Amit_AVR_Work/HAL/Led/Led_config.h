/*
 * Led_config.h
 *
 *  Created on: Sep 26, 2023
 *      Author: LENOVO
 */

#ifndef HAL_LED_LED_CONFIG_H_
#define HAL_LED_LED_CONFIG_H_

//#define LED_RED_ID     0
//#define LED_YELLOW_ID  1
//#define LED_GREEN_ID   2

#define LED_MAX_NUM     3

typedef struct {

	u8 Led_Grp;
	u8 Led_Pin;
	u8 Led_Status;
} Led_t;


#endif /* HAL_LED_LED_CONFIG_H_ */
