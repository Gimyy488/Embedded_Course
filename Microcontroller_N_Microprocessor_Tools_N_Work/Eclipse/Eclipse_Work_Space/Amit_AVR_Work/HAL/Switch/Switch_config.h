/*
 * Switch_config.h
 *
 *  Created on: Sep 26, 2023
 *      Author: LENOVO
 */

#ifndef HAL_SWITCH_SWITCH_CONFIG_H_
#define HAL_SWITCH_SWITCH_CONFIG_H_


//#define SWTICH_OFF             0
//#define SWITCH_ON              1

#define SWITCH_MAX_NUM         3

typedef struct {

	u8 Sw_Grp;
	u8 Sw_Pin;
	u8 Sw_Status;
} Switch_t;

#endif /* HAL_SWITCH_SWITCH_CONFIG_H_ */
