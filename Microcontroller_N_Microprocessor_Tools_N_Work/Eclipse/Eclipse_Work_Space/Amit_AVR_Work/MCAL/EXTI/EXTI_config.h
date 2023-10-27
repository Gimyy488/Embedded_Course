/*
 * EXTI_config.h
 *
 *  Created on: Oct 6, 2023
 *      Author: Omar Gamal El-Kady
 */

#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_

#define EXTI_NUM_PINS    3

typedef struct {

	u8 intPin;
	u8 senselevel;
	u8 intMode;
} EXTI_t;


#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
