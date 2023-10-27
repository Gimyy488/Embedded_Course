/*
 * DIO_priv.h
 *
 *  Created on: Sep 24, 2023
 *      Author: LENOVO
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

#define DIO_PORTA_REG *((volatile u8 *)0x3B)
#define DIO_DDRA_REG *((volatile u8 *)0x3A)
#define DIO_PINA_REG *((volatile u8 *)0x39)

#define DIO_PORTB_REG *((volatile u8 *)0x38)
#define DIO_DDRB_REG *((volatile u8 *)0x37)
#define DIO_PINB_REG *((volatile u8 *)0x36)

#define DIO_PORTC_REG *((volatile u8 *)0x35)
#define DIO_DDRC_REG *((volatile u8 *)0x34)
#define DIO_PINC_REG *((volatile u8 *)0x33)

#define DIO_PORTD_REG *((volatile u8 *)0x32)
#define DIO_DDRD_REG *((volatile u8 *)0x31)
#define DIO_PIND_REG *((volatile u8 *)0x30)

#define DIO_GROUP_A     0
#define DIO_GROUP_B     1
#define DIO_GROUP_C     2
#define DIO_GROUP_D     3

#define DIO_PIN_0       0
#define DIO_PIN_1       1
#define DIO_PIN_2       2
#define DIO_PIN_3       3
#define DIO_PIN_4       4
#define DIO_PIN_5       5
#define DIO_PIN_6       6
#define DIO_PIN_7       7

#define DIO_LOW         0
#define DIO_HIGH        1

#define DIO_FLOAT       0
#define DIO_PULL_UP     1

#define DIO_INPUT       0
#define DIO_OUTPUT      1

#define DIO_BIT_MASK    1



#endif /* DIO_PRIV_H_ */
