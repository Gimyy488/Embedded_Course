/*
 * EXTI_priv.h
 *
 *  Created on: Oct 6, 2023
 *      Author: Omar Gamal El-Kady
 */

#ifndef MCAL_EXTI_EXTI_PRIV_H_
#define MCAL_EXTI_EXTI_PRIV_H_


static ES_t enuSetSenseLevel(u8 Copy_u8IntPin , u8 Copy_u8SenseLevel);
static ES_t enuSetIntMode(u8 Copy_u8IntPin , u8 Copy_u8IntMode);


// Interrupt Sense Level control for INT0 ,INT1 which generate PIF
// when sense what we specified
#define MCUCR      *((volatile u8 *)0x55)
// Interrupt Sense Level control for INT2 which generate PIF when sense what we specified
#define MCUCSR     *((volatile u8 *)0x54)
#define GICR       *((volatile u8 *)0x5B)  // PIE for INT0 , INT1 , INT2
#define GIFR       *((volatile u8 *)0x5A)  // PIF for INT0 , INT1 , INT2

#define EXTI_INT0             0
#define EXTI_INT1             1
#define EXTI_INT2             2

#define EXTI_LOW_LEVEL        10
#define EXTI_ANY_CHANGE       11
#define EXTI_FALLING_EDGE     12
#define EXTI_RISING_EDGE      13

#define EXTI_INTERRUPT_MODE   80
#define EXTI_POOLING_MODE     90

#define EXTI_NUM_PINS         3

typedef void(*pfuncISRFunc_t)(void*);
typedef void* vidptr_t;

#endif /* MCAL_EXTI_EXTI_PRIV_H_ */
