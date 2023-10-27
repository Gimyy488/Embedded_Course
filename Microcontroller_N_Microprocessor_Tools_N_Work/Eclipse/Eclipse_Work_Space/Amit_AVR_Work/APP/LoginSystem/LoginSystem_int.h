/*
 * LoginSystem_int.h
 *
 *  Created on: Oct 2, 2023
 *      Author: Omar Gamal El-Kady
 */

#ifndef APP_LOGINSYSTEM_LOGINSYSTEM_INT_H_
#define APP_LOGINSYSTEM_LOGINSYSTEM_INT_H_

ES_t LoginSystem_enuInit(void);

ES_t LoginSystem_enuWelcomePage(void);

ES_t LoginSystem_enuEnterPassPage(BOOL * Copy_bPasswordCheck);

ES_t LoginSystem_enuMainDashBoard(void);

#endif /* APP_LOGINSYSTEM_LOGINSYSTEM_INT_H_ */
