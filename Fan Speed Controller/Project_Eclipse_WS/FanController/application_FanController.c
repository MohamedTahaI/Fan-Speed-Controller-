/******************************************************************************
 *
 * Module: Application
 *
 * File Name: Application.c - main
 *
 * Description: Application to fan controller
 *
 * Author: Mohamed taha
 *
 *******************************************************************************/

// include files used in a project

#include "lcd.h"
#include "dc_motor.h"
#include "lm35_sensor.h"
#include "std_types.h"
#include "adc.h"


int main()
{

	uint8 temperature_value;
	ADC_ConfigType adcConfig;
	adcConfig.ref_volt = VOLT_REF_2V56;
	adcConfig.prescaler = DIV_FACT_8;
	ADC_ConfigType *ptr;
	ptr=&adcConfig;


	LCD_init();
	DcMotor_Init();
	ADC_init(ptr);
	LCD_displayStringRowColumn(0,4,"Fan is");
	LCD_displayStringRowColumn(1,4,"temp =    c");

	while(1)
	{
		LCD_moveCursor(1,11);
		temperature_value = LM35_getTemperature();

		if(temperature_value>=100)
		{
			LCD_intgerToString(temperature_value);

		}
		else
		{
			LCD_intgerToString(temperature_value);
			LCD_displayString(" ");

		}

		if(temperature_value<30)
		{
			DcMotor_Rotate(STOP,0);
			LCD_displayStringRowColumn(0,11,"OFF");
		}
		else if( temperature_value>=30 && temperature_value<60 )
		{
			DcMotor_Rotate(CW,25);
			LCD_displayStringRowColumn(0,11,"ON");
		}
		else if(temperature_value>=60 && temperature_value<90)
		{
			DcMotor_Rotate(CW,50);
			LCD_displayStringRowColumn(0,11,"ON");
		}
		else if(temperature_value>=90 && temperature_value<120)
		{
			DcMotor_Rotate(CW,75);
			LCD_displayStringRowColumn(0,11,"ON");
		}
		else
		{
			DcMotor_Rotate(CW,100);
			LCD_displayStringRowColumn(0,11,"ON");
		}

	}

}
