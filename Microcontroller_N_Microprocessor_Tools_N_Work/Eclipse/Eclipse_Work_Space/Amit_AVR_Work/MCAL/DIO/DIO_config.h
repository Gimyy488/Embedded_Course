/*
 * DIO_config.h
 *
 *  Created on: Sep 24, 2023
 *      Author: LENOVO
 */

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_


// Helper macros for configuring DIO pins
#define DIO_PIN_OUTPUT(pin)  (DIO_PORTA_DIR |= (1 << (pin)))
#define DIO_PIN_INPUT(pin)   (DIO_PORTA_DIR &= ~(1 << (pin)))
#define DIO_SET_HIGH(pin)    (DIO_PORTA_DATA |= (1 << (pin)))
#define DIO_SET_LOW(pin)     (DIO_PORTA_DATA &= ~(1 << (pin)))

#endif /* DIO_CONFIG_H_ */
