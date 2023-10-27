/*
 * TrafficLight_int.h
 *
 *  Created on: Sep 25, 2023
 *      Author: LENOVO
 */

#ifndef APP_TRAFFICLIGHT_TRAFFICLIGHT_INT_H_
#define APP_TRAFFICLIGHT_TRAFFICLIGHT_INT_H_

#define TRAFFIC_OFF   0
#define TRAFFIC_ON    1

ES_t TrafficLight_enuInit(void);

ES_t TrafficLight_enuTrafficON(void);

ES_t TrafficLight_enuTrafficOFF(void);

ES_t TrafficLight_enuTrafficStatus(u8 * Copy_pu8TrafficStatus);

#endif /* APP_TRAFFICLIGHT_TRAFFICLIGHT_INT_H_ */
