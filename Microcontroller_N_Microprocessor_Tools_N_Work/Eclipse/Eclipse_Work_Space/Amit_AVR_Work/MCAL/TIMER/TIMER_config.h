/*
 * TIMER_config.h
 *
 *  Created on: Oct 15, 2023
 *      Author: Omar Gamal El-Kady
 */

#ifndef MCAL_TIMER_TIMER_CONFIG_H_
#define MCAL_TIMER_TIMER_CONFIG_H_

//#define TIMER0_CLOCK_SELECTOR
//#define TIMER0_COMP_OUTPUT_MODE
//#define TIMER0_MODE_SELECTOR

#define TIMER_NUM_PINS    1

typedef struct {

	u8 timerpin;
	u8 timerwaveformmode;
	u8 timercompoutputmode;
	u8 timerclockspeed;
	u8 timerintmode;
} TIMER_t;

#endif /* MCAL_TIMER_TIMER_CONFIG_H_ */
