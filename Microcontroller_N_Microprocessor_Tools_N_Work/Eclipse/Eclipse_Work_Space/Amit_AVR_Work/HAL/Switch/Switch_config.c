/*
 * Switch_config.c
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
#include "Switch_priv.h"
#include "Switch_config.h"


u8 Switch_u8MaxSwitchNum = SWITCH_MAX_NUM;

Switch_t Switch_astrSwitchConfig[SWITCH_MAX_NUM] = {

		{DIO_GROUP_B,DIO_PIN_0,DIO_FLOAT},
		{DIO_GROUP_D,DIO_PIN_6,DIO_FLOAT},
		{DIO_GROUP_D,DIO_PIN_2,DIO_FLOAT}
};

