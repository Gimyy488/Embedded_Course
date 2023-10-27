/*
 * TIMER_int.h
 *
 *  Created on: Oct 15, 2023
 *      Author: Omar Gamal El-Kady
 */

#ifndef MCAL_TIMER_TIMER_INT_H_
#define MCAL_TIMER_TIMER_INT_H_

#define TIMER_INT0      0
#define TIMER_INT1      1
#define TIMER_INT2      2

#define TIMER0_WAVEFORM_GEN_MODE_NORMAL         0
#define TIMER0_WAFEFORM_GEN_MODE_PWM            1
#define TIMER0_WAFEFORM_GEN_MODE_CTC            2
#define TIMER0_WAFEFORM_GEN_MODE_FASTPWM        3

#define TIMER0_COMP_OUTPUT_NON_PWM_NORMAL       0
#define TIMER0_COMP_OUTPUT_NON_PWM_TOGGLE_OC2   1
#define TIMER0_COMP_OUTPUT_NON_PWM_CLEAR_OC2    2
#define TIMER0_COMP_OUTPUT_NON_PWM_SET_OC2      3

#define TIMER0_COMP_OUTPUT_PWM_NORMAL           0
#define TIMER0_COMP_OUTPUT_PWM_RESERVED         1
#define TIMER0_COMP_OUTPUT_PWM_CLEAR_OC2        2
#define TIMER0_COMP_OUTPUT_PWM_SET_OC2          3

#define TIMER0_COMP_OUTPUT_FASTPWM_NORMAL       0
#define TIMER0_COMP_OUTPUT_FASTPWM_RESERVED     1
#define TIMER0_COMP_OUTPUT_FASTPWM_CLEAR_OC2    2
#define TIMER0_COMP_OUTPUT_FASTPWM_SET_OC2      3

#define TIMER0_NO_CLK_SOURCE                    0
#define TIMER0_PRESCALER_1                      1
#define TIMER0_PRESCALER_8                      2
#define TIMER0_PRESCALER_64                     3
#define TIMER0_PRESCALER_256                    4
#define TIMER0_PRESCALER_1024                   5
#define TIMER0_EXT_CLK_FALLING                  6
#define TIMER0_EXT_CLK_RISING                   7

#define TIMER_POLLING     90
#define TIMER_OVFINT      91
#define TIMER_OCINT       92

ES_t TIMER_enuInit(void);

ES_t TIMER_enuSetWaveGenMode(u8 Copy_u8IntPin , u8 Copy_u8WaveForm);

ES_t TIMER_enuSetPrescaler(u8 Copy_u8IntPin , u8 Copy_u8Prescaler);

ES_t TIMER_enuSetCompNonPWMMode(u8 Copy_u8IntPin , u8 Copy_u8Mode);

ES_t TIMER_enuSyncDelayms(u8 Copy_u8IntPin , u16 Copy_u16DelayTime);

ES_t TIMER_enuAsyncDelayms(u8 Copy_u8IntPin , u16 Copy_u16DelayTime);

ES_t TIMER_enuSetOCRValue(u8 Copy_u8IntPin , u16 Copy_u16Cycles);

ES_t TIMER_enuGetTimerCounts(u8 Copy_u8IntPin , u8 * Copy_pu8Counts);

ES_t TIEMR_enuInterruptEnable(u8 Copy_u8IntPin);

ES_t TIEMR_enuInterruptDisable(u8 Copy_u8IntPin);

ES_t TIMER_enuOCEnable(u8 Copy_u8IntPin);

ES_t TIMER_enuOCDisable(u8 Copy_u8IntPin);

ES_t TIMER_enuOVFEnable(u8 Copy_u8IntPin);

ES_t TIMER_enuOVFDisable(u8 Copy_u8IntPin);

//ES_t TIMER_enuEnable(u8 Copy_IntPin);

ES_t TIMER_enuDisable(u8 Copy_u8Intpin);

ES_t TIMER_enuSetCallBack(void(* Copy_pfuncAppFunc)(void*),void * Copy_pvidParameter);

#endif /* MCAL_TIMER_TIMER_INT_H_ */
