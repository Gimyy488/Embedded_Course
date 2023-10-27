/*
 * Keypad_prog.c
 *
 *  Created on: Oct 2, 2023
 *      Author: Omar Gamal El-Kady
 */
// public
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"


//lower
#include "../../MCAL/DIO/DIO_int.h"

//my own
#include <util/delay.h>
#include "../Keypad/Keypad_config.h"
#include "../Keypad/Keypad_priv.h"

#if KEYPAD_NUM_OF_ROWS > 0 && KEYPAD_NUM_OF_ROWS <= 4 && KEYPAD_NUM_OF_COLUMNS > 0 && KEYPAD_NUM_OF_COLUMNS <= 4

#else
    #error keypad col & row is not valid
#endif

ES_t Keypad_enuInit(void){

	u8 Local_u8ErrorState = ES_NOK;

	u8 Local_au8RowGrp[] = {KEYPAD_ROW_1_GRP,KEYPAD_ROW_2_GRP,KEYPAD_ROW_3_GRP,KEYPAD_ROW_4_GRP};
	u8 Local_au8RowPin[] = {KEYPAD_ROW_1_PIN,KEYPAD_ROW_2_PIN,KEYPAD_ROW_3_PIN,KEYPAD_ROW_4_PIN};

	u8 Local_au8ColumnGrp[] = {KEYPAD_COLUMN_1_GRP,KEYPAD_COLUMN_2_GRP,KEYPAD_COLUMN_3_GRP,KEYPAD_COLUMN_4_GRP};
	u8 Local_au8ColumnPin[] = {KEYPAD_COLUMN_1_PIN,KEYPAD_COLUMN_2_PIN,KEYPAD_COLUMN_3_PIN,KEYPAD_COLUMN_4_PIN};

	for(u8 Local_u8RowIterator = 0 ; Local_u8RowIterator < KEYPAD_NUM_OF_ROWS ; Local_u8RowIterator++){

		DIO_enuSetPinDirection(Local_au8RowGrp[Local_u8RowIterator],Local_au8RowPin[Local_u8RowIterator],DIO_INPUT);
		DIO_enuSetPinValue(Local_au8RowGrp[Local_u8RowIterator],Local_au8RowPin[Local_u8RowIterator],DIO_PULL_UP);

	}

	for(u8 Local_u8ColumnIterator = 0 ; Local_u8ColumnIterator < KEYPAD_NUM_OF_COLUMNS ; Local_u8ColumnIterator++){

		DIO_enuSetPinDirection(Local_au8ColumnGrp[Local_u8ColumnIterator],Local_au8ColumnPin[Local_u8ColumnIterator],DIO_OUTPUT);
		DIO_enuSetPinValue(Local_au8ColumnGrp[Local_u8ColumnIterator],Local_au8ColumnPin[Local_u8ColumnIterator],DIO_HIGH);

	}

	return Local_u8ErrorState;

}
