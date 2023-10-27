/*
 * LoginSystem_priv.h
 *
 *  Created on: Oct 2, 2023
 *      Author: Omar Gamal El-Kady
 */

#ifndef APP_LOGINSYSTEM_LOGINSYSTEM_PRIV_H_
#define APP_LOGINSYSTEM_LOGINSYSTEM_PRIV_H_

#define LOGINSYSTEM_NUM_OF_TRIALS      3
#define LOGINSYSTEM_LENGTH_OF_PASSWORD  10
#define LOGINSYSTEM_ENTER_KEY                'E'

static ES_t enuOptionPage(const u8 * Copy_au8Options[],u8 Copy_u8NumOfOptions);

static ES_t enuSendDataAtCursorLocation(const char * Copy_pcString,u8 Copy_u8RowNum , u8 Copy_u8ColNum);

static ES_t enuDisplayTemprature(void);

#endif /* APP_LOGINSYSTEM_LOGINSYSTEM_PRIV_H_ */
