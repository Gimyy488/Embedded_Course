/*
 * EXTI_int.h
 *
 *  Created on: Oct 6, 2023
 *      Author: Omar Gamal El-Kady
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

#define EXTI_INT0           0
#define EXTI_INT1           1
#define EXTI_INT2           2

// enable GIE , PIE by setting mode to interrupt
ES_t EXTI_enuInit(void);

// to set sense level to enable PIF if sense what specify
ES_t EXTI_enuSetSenseLevel(u8 Copy_u8IntPin , u8 Copy_u8SenseLevel);

ES_t EXTI_enuEnableInterrupt(u8 Copy_IntPin); // to enable PIE

ES_t EXTI_enuDisableInterrupt(u8 Copy_IntPin); //to disable PIE

ES_t EXTI_enuSetCallBack(u8 Copy_u8IntPin , void(*Copy_pFuncAppFunc)(void),void * Copy_pvidParameter);

#endif /* MCAL_EXTI_EXTI_INT_H_ */
