 /******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: DC MOTOR.h
 *
 * Description: header file for the DC MOTOR
 *
 * Author: Mohamed Taha
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define DC_MOTOR_OUT_FIRST_PORT_ID                 PORTB_ID
#define  DC_MOTOR_OUT_FIRST_PIN_ID                 PIN0_ID

#define DC_MOTOR_OUT_SECOND_PORT_ID                PORTB_ID
#define DC_MOTOR_OUT_SECOND_PIN_ID                 PIN1_ID


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
	STOP,CW,A_CW
}DcMotor_State;



/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/


void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);



#endif /* DC_MOTOR_H_ */
