 /******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: DC MOTOR.h
 *
 * Description: Source file for the DC MOTOR
 *
 * Author: Mohamed Taha
 *
 *******************************************************************************/


#include "dc_motor.h"
#include "gpio.h"
#include "pwm.h"

void DcMotor_Init(void)
{
	GPIO_setupPinDirection(DC_MOTOR_OUT_FIRST_PORT_ID ,DC_MOTOR_OUT_FIRST_PIN_ID ,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_OUT_SECOND_PORT_ID ,DC_MOTOR_OUT_SECOND_PIN_ID ,PIN_OUTPUT);

	GPIO_writePin(DC_MOTOR_OUT_FIRST_PORT_ID ,DC_MOTOR_OUT_FIRST_PIN_ID ,LOGIC_LOW );
	GPIO_writePin(DC_MOTOR_OUT_SECOND_PORT_ID ,DC_MOTOR_OUT_SECOND_PIN_ID ,LOGIC_LOW );

}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	switch(state)
	{
	case STOP :

		GPIO_writePin(DC_MOTOR_OUT_FIRST_PORT_ID ,DC_MOTOR_OUT_FIRST_PIN_ID ,LOGIC_LOW );
		GPIO_writePin(DC_MOTOR_OUT_SECOND_PORT_ID ,DC_MOTOR_OUT_SECOND_PIN_ID ,LOGIC_LOW );

		PWM_Timer0_Start(speed);

	break;
	case CW :

		GPIO_writePin(DC_MOTOR_OUT_FIRST_PORT_ID ,DC_MOTOR_OUT_FIRST_PIN_ID,LOGIC_LOW );
		GPIO_writePin(DC_MOTOR_OUT_SECOND_PORT_ID ,DC_MOTOR_OUT_SECOND_PIN_ID ,LOGIC_HIGH );

		PWM_Timer0_Start(speed);

	break;
	case A_CW :

		GPIO_writePin(DC_MOTOR_OUT_FIRST_PORT_ID ,DC_MOTOR_OUT_FIRST_PIN_ID,LOGIC_HIGH );
		GPIO_writePin(DC_MOTOR_OUT_SECOND_PORT_ID ,DC_MOTOR_OUT_SECOND_PIN_ID ,LOGIC_LOW );

		PWM_Timer0_Start(speed);

	break;
	}

}
