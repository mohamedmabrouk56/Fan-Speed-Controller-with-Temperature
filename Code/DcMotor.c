/**
 * @file DcMotor.c
 * @brief DCMOTOR Source file.
 *
 * This file contains The Implementation of Functions of the DcMotor module
 *
 * @author [Mohamed Mabrouk]
 * @date [25 JAN 2024]
 *
 * @SWversion 1.0.0
 *
 * @remarks
 *    -Platform         : AVR
 *    -Peripherial      : Atmega32
 */
  /*==================================================================================================================================*/

 /* ===================================================================================================
											  Includes
	===================================================================================================*/
#include"DcMotor.h"
#include"gpio.h"
#include"timer.h"
#include"common_Macros.h"

/* ===================================================================================================
										  Function Definition
   ===================================================================================================*/

   /*Initializtion*/
void DcMotor_init(void)
{
	GPIO_setupPinDirection(MOTOR_L_PORT_ID, MOTOR_L_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_R_PORT_ID, MOTOR_R_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_E_PORT_ID, MOTOR_E_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(MOTOR_L_PORT_ID, MOTOR_L_PIN_ID, LOGIC_LOW);
	GPIO_writePin(MOTOR_R_PORT_ID, MOTOR_R_PIN_ID, LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
    if (state == STOP) {
    	PWM_Timer0_Start(0);
        GPIO_writePin(MOTOR_L_PORT_ID, MOTOR_L_PIN_ID, LOGIC_LOW);
        GPIO_writePin(MOTOR_R_PORT_ID, MOTOR_R_PIN_ID, LOGIC_LOW);
    }
    else if (state == CLOCKWISE)
    {
    	PWM_Timer0_Start(speed);
        GPIO_writePin(MOTOR_L_PORT_ID, MOTOR_L_PIN_ID, LOGIC_LOW);
        GPIO_writePin(MOTOR_R_PORT_ID, MOTOR_R_PIN_ID, LOGIC_HIGH);
    }
    else if (state == ANTICLOCKWISE)
    {
    	PWM_Timer0_Start(speed);
        GPIO_writePin(MOTOR_L_PORT_ID, MOTOR_L_PIN_ID, LOGIC_HIGH);
        GPIO_writePin(MOTOR_R_PORT_ID, MOTOR_R_PIN_ID, LOGIC_LOW);
    }
}
