/*
 * ADC_int.h
 *
 *  Created on: Oct 11, 2023
 *      Author: Omar Gamal El-Kady
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_


ES_t ADC_enuInit(void);

ES_t ADC_enuReadPolling(u8 Copy_u8Channel , u16 * Copy_pu16ADCRead);

ES_t ADC_enuStartConversion(void);

ES_t ADC_enuSetADCChannel(u8 Copy_u8Channel);

ES_t ADC_enuReadInterrupt(u16 * Copy_pu16ADCRead);

ES_t ADC_enuReadInterruptHigh(u8 * Copy_pu8ADCRead);

ES_t ADC_enuSetTriggerSource(u8 Copy_u8TriggerSource);

ES_t ADC_enuClearTriggerSource(void);

ES_t ADC_enuSetPrescaler(u8 Copy_u8Channel , u8 Copy_u8Prescaler);

ES_t ADC_enuSetIterruptMode(u8 Copy_u8Channel , u8 Copy_u8InterruptMode);

ES_t ADC_enuInterruptEnable(void);

ES_t ADC_enuInterruptDisable(void);

ES_t ADC_enuADCEnable(void);

ES_t ADC_enuADCDisable(void);

ES_t ADC_enuSetCallBack(void(* Copy_pfuncAppFunc)(void*),void * Copy_pvidParameter);


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

#define ADC_POLLING        0
#define ADC_INTERRUPT      1

typedef enum{

	ADC0 = 0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7,
	ADC0_ADC0_10X,
	ADC1_ADC0_10X,
	ADC0_ADC0_200X,
	ADC1_ADC0_200X,
	ADC2_ADC2_10X,
	ADC3_ADC2_10X,
	ADC2_ADC2_200X,
	ADC3_ADC2_200X,
	ADC0_ADC1_1X,
	ADC1_ADC1_1X,
	ADC2_ADC1_1X,
	ADC3_ADC1_1X,
	ADC4_ADC1_1X,
	ADC5_ADC1_1X,
	ADC6_ADC1_1X,
	ADC7_ADC1_1X,
	ADC0_ADC2_1X,
	ADC1_ADC2_1X,
	ADC2_ADC2_1X,
	ADC3_ADC2_1X,
	ADC4_ADC2_1X,
	ADC5_ADC2_1X,
	VBG,
	GND
} ADCChannels_t;

#endif /* MCAL_ADC_ADC_INT_H_ */
