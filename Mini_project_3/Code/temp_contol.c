/*
 * main.c
 *
 *  Created on: Oct 14, 2023
 *      Author: dell
 */

#include "lcd.h"
#include "motor.h"
#include "LM35.h"
#include "adc.h"


int main(void){
	uint8 temp=0;
	LCD_init();
	ADC_ConfigType configure={Internal,F_CPU_8};
	ADC_init(&configure); /*Setup the ADC to work by internal voltage =2.56 and with clock Fcpu/8*/
	DcMotor_Init();
	LCD_displayStringRowColumn(0,4,"Fan is ");
	LCD_displayStringRowColumn(1,4,"Temp =    C");

	while(1)
	{
	temp=LM35_getTemperature();
	if(temp<30){
		LCD_displayStringRowColumn(0,11,"OFF");
		LCD_moveCursor(1,11);
		LCD_intgerToString(temp);
		LCD_displayCharacter(' ');
		DcMotor_Rotate(STOP,SPEED0); /*Zero speed by PWM signal with zero duty cycle*/
	}
	else if(temp>=30 && temp<60){
		LCD_displayStringRowColumn(0,11,"ON ");
		LCD_moveCursor(1,11);
		LCD_intgerToString(temp);
		LCD_displayCharacter(' ');
		DcMotor_Rotate(CW,SPEED1); /*25% of the maximum speed PWM signal with 25% duty cycle*/
	}
	else if(temp>=60 && temp<90){
			LCD_displayStringRowColumn(0,11,"ON ");
			LCD_moveCursor(1,11);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,SPEED2); /*50% of the maximum speed PWM signal with 50% duty cycle*/
		}
	else if(temp>=90 && temp<120){
			LCD_displayStringRowColumn(0,11,"ON ");
			LCD_moveCursor(1,11);
			LCD_intgerToString(temp);
			if(temp<100){
			LCD_displayCharacter(' ');
			}
			DcMotor_Rotate(CW,SPEED3); /*75% of the maximum speed PWM signal with 75% duty cycle*/
		}
	else if(temp>=120){
			LCD_displayStringRowColumn(0,11,"ON ");
			LCD_moveCursor(1,11);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW,SPEED4); /*100% of the maximum speed PWM signal with 100% duty cycle*/
		}
	}

}
