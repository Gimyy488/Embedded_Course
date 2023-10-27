/*
 * Switch_int.h
 *
 *  Created on: Sep 26, 2023
 *      Author: LENOVO
 */

#ifndef HAL_SWITCH_SWITCH_INT_H_
#define HAL_SWITCH_SWITCH_INT_H_


#define SWITCH_OFF             0
#define SWITCH_ON              1


#define SWITCH_BUTTON_0     0
#define SWITCH_BUTTON_1     1
#define SWITHC_BUTTON_2     2

ES_t Switch_enuInit(void);

ES_t Switch_enuGetSwitchState(u8 Copy_u8SwitchID , u8 * Copy_pu8SwitchState);

#endif /* HAL_SWITCH_SWITCH_INT_H_ */
