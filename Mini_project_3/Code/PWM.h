/*
 * PWM.h
 *
 *  Created on: Oct 14, 2023
 *      Author: dell
 */

#ifndef PWM_H_
#define PWM_H_

/**********************************Definitions*****************************************/

#define MAX_COMP_VALUE 255
/***********************************Functions Prototype********************************/


/*
 * Description:
 * Generate a PWM form with specific duty cycle
 *
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
