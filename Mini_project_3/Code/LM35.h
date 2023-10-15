/*
 * LM35.h
 *
 *  Created on: Oct 14, 2023
 *      Author: dell
 */

#ifndef LM35_H_
#define LM35_H_

#include "std_types.h"

/***********************************Definitions**********************/

#define MAX_VOLT_SENSOR 1.5
#define MAX_TEMP 150
#define SENSOR_CHANNEL_ID 2

/**********************************Functions Prototype*****************/


/*
 * Description:
 * read ADC value and calculate the real temperature
 * */
uint8 LM35_getTemperature(void);


#endif /* LM35_H_ */
