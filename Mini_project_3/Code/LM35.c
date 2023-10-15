/*
 * LM35.c
 *
 *  Created on: Oct 14, 2023
 *      Author: dell
 */


#include "LM35.h"
#include "adc.h" /*to get its reading*/

/*
 * Description:
 * read ADC value and calculate the real temperature
 * */
uint8 LM35_getTemperature(void){
uint8 temp;
uint16 adcValue;
adcValue=ADC_readChannel(SENSOR_CHANNEL_ID);
temp=(uint8)(((uint32)adcValue*MAX_TEMP*VREF)/(MAX_VOLT_SENSOR*ADC_N));
return temp;
}
