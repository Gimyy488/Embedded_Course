/*
 * Calculator_priv.h
 *
 *  Created on: Oct 3, 2023
 *      Author: Omar Gamal El-Kady
 */

#ifndef APP_CALCULATOR_CALCULATOR_PRIV_H_
#define APP_CALCULATOR_CALCULATOR_PRIV_H_

#define CALCULATOR_CLEAR_BUTTON         'C'
#define CALCULATOR_EQUAL_OPERATOR       '='
#define CALCULATOR_ADDITION             '+'
#define CALCULATOR_SUBTRACTION          '-'
#define CALCULATOR_MULTIPLICATION       '*'
#define CALCULATOR_DEVISION             '/'
#define CALCULATOR_DOT                  '.'
#define CALCULATOR_MIN_NUM              '0'
#define CALCULATOR_MAX_NUM              '9'

static ES_t enuArraytoInteger(const s8 * Copy_ps8String,s32 * Copy_s32IntValue);

#endif /* APP_CALCULATOR_CALCULATOR_PRIV_H_ */
