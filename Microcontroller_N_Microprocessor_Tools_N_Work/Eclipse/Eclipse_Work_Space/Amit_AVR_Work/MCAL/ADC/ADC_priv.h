/*
 * ADC_priv.h
 *
 *  Created on: Oct 11, 2023
 *      Author: Omar Gamal El-Kady
 */

#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_

// ADC Multiplexer Selection Register
// Bit 7:6 – REFS1:0: Reference Selection Bits
// Bit 5 – ADLAR: ADC Left Adjust Result
// Bits 4:0 – MUX4:0: Analog Channel and Gain Selection Bits
#define ADC_ADMUX          *((volatile u8 *)0x27)

// ADC Control and Status Register A
// Bit 7 – ADEN: ADC Enable
// Bit 6 – ADSC: ADC Start Conversion
// Bit 5 – ADATE: ADC Auto Trigger Enable
// Bit 4 – ADIF: ADC Interrupt Flag
// Bit 3 – ADIE: ADC Interrupt Enable , PIE of ADC
// Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits
#define ADC_ADCSRA         *((volatile u8 *)0x26)

// The ADC Data Register – ADCL and ADCH
#define ADC_ADCH           *((volatile u8 *)0x25)
#define ADC_ADCL           *((volatile u8 *)0x24)

// Special FunctionIO Register – SFIOR
#define ADC_SFIOR          *((volatile u8 *)0x50)

#define ACC_V_AREF      0
#define ACC_V_AVCC      1
#define ACC_V_Internal  3

#define ACC_RIGHT_ADJUSTMENT   0
#define ACC_LEFT_ADJUSTMENT    1

#define ADC_PRESCALER_RESERVED         0
#define ADC_PRESCALER_2                1
#define ADC_PRESCALER_4                2
#define ADC_PRESCALER_8                3
#define ADC_PRESCALER_16               4
#define ADC_PRESCALER_32               5
#define ADC_PRESCALER_64               6
#define ADC_PRESCALER_128              7

#define ADC_FREE_RUNNING_TIGGER                   0
#define ADC_ANALOG_COMP_TRIGGER                   1
#define ADC_EXTI0_TRIGGER                         2
#define ADC_TIM0_COM_MATCH_TRIGGER                3
#define ADC_TIM0_COMP_OVF_TRIGGER                 4
#define ADC_TIM_COMP_MATCH_B_TRIGGER              5
#define ADC_TIM1_COMP_OVF_TRIGGER                 6
#define ADC_TIM1_COMP_CAPTURE_EVENT_TRIGGER       7
#define ADC_SINGLE_CONVERSION                     8

#define ADC_MIN_NUM_CHANNELS                      0
#define ADC_MAX_NUM_CHANNELS                      31

#define ADC_POLLING        0
#define ADC_INTERRUPT      1

#define ADC0               0
#define	ADC1               1
#define	ADC2               2
#define	ADC3               3
#define	ADC4               4
#define	ADC5               5
#define	ADC6               6
#define	ADC7               7
#define	ADC0_ADC0_10X      8
#define	ADC1_ADC0_10X      9
#define	ADC0_ADC0_200X     10
#define	ADC1_ADC0_200X     11
#define	ADC2_ADC2_10X      12
#define	ADC3_ADC2_10X      13
#define	ADC2_ADC2_200X     14
#define	ADC3_ADC2_200X     15
#define	ADC0_ADC1_1X       16
#define	ADC1_ADC1_1X       17
#define	ADC2_ADC1_1X       18
#define	ADC3_ADC1_1X       19
#define	ADC4_ADC1_1X       20
#define	ADC5_ADC1_1X       21
#define	ADC6_ADC1_1X       22
#define	ADC7_ADC1_1X       23
#define	ADC0_ADC2_1X       24
#define	ADC1_ADC2_1X       25
#define	ADC2_ADC2_1X       26
#define	ADC3_ADC2_1X,      27
#define	ADC4_ADC2_1X       28
#define	ADC5_ADC2_1X       29
#define	VBG                30
#define	GND                31

#define ADC_MASK_BIT                       1
//#define ADC_V_REFERENCE_BIT_NUM            6
//#define ADC_ADJUSTMENT_BIT_NUM             5
//#define ADC_INTERRUPT_MODE_BIT_NUM         3
//#define ADC_AUTO_TRIGGER_ENABLE_BIT_NUM    5
//#define ADC_TRIGGER_SOURCE_BIT_NUM         5
//#define ADC_ENABLE_BIT_NUM                 7
//#define ADC_INTERRUPT_FLAG_BIT_NUM         4
//#define ADC_START_CONV_BIT_NUM             6
//#define ADC_INTERRUPT_ENABLE_BIT_NUM       3

#define ADC_BIT_0              0
#define ADC_BIT_1              1
#define ADC_BIT_2              2
#define ADC_BIT_3              3
#define ADC_BIT_4              4
#define ADC_BIT_5              5
#define ADC_BIT_6              6
#define ADC_BIT_7              7
#define ADC_BIT_8              8
#define ADC_BIT_9              9


typedef void(*pfuncISRFunc_t)(void*);
typedef void* vidptr_t;

#endif /* MCAL_ADC_ADC_PRIV_H_ */
