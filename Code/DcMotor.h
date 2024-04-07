/**
   * @file DcMotor.h
   * @brief Header file for the DCMOTOR module.
   *
   * This file contains the declarations and definitions for the DCMOTOR module
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

#ifndef DCMOTOR_H_
#define DCMOTOR_H_
 /* ===================================================================================================
										   Includes
	===================================================================================================*/
#include"Std_Types.h"
/* ===================================================================================================
										   Macro Definition
   ===================================================================================================*/

#define MOTOR_L_PORT_ID                  PORTB_ID
#define MOTOR_L_PIN_ID                   PIN0_ID
#define MOTOR_R_PORT_ID                  PORTB_ID
#define MOTOR_R_PIN_ID                   PIN1_ID
#define MOTOR_E_PORT_ID                  PORTB_ID
#define MOTOR_E_PIN_ID                   PIN3_ID

typedef enum
{
 STOP,CLOCKWISE,ANTICLOCKWISE
}DcMotor_State;

 /* ===================================================================================================
											  Function Prototypes
    ===================================================================================================*/

 /*Initializtion*/
void DcMotor_init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DCMOTOR_H_ */
