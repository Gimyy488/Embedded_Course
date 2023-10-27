/*
 * Led_config.c
 *
 *  Created on: Sep 26, 2023
 *      Author: LENOVO
 */


// public
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

// lower
#include "../../MCAL/DIO/DIO_int.h"

// my own
#include "Led_priv.h"
#include "Led_config.h"

u8 Led_u8MaxLedNum = LED_MAX_NUM;

Led_t Led_astrLedConfig[LED_MAX_NUM] = {

		{DIO_GROUP_B,DIO_PIN_5,DIO_LOW},
		{DIO_GROUP_B,DIO_PIN_6,DIO_LOW},
		{DIO_GROUP_B,DIO_PIN_7,DIO_LOW}

};

