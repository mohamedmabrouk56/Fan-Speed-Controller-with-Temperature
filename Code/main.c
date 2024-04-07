/**
  * @file 	main.c
  * @brief APP Source file.
  *
  * This file contains The Application of The Fan Controller 
  *
  * @author [Mohamed Mabrouk]
  * @date [13 FEB 2024]
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
#include"lcd.h"
#include"DcMotor.h"
#include"lm35_sensor.h"
#include"util/delay.h"
#include"adc.h"
#include"timer.h"

/* ===================================================================================================
									             Main Project
   ===================================================================================================*/

int main(void)
{
	/* Initialize variables and peripherals */
	uint8 temp_value = 0;
	LCD_init();
	DcMotor_init();
	ADC_init(&ADC_Configuration);
	TIMER_init(TIMER0);
	LCD_moveCursor(0, 4);
	LCD_displayString("Fan is ");
	LCD_moveCursor(1, 4);
	LCD_displayString("Temp =  ");

	for (;;)
	{
		/* Read temperature value */
		temp_value = LM35_getTemp();
		LCD_moveCursor(0, 4);
		/* Determine fan control based on temperature */
		if (temp_value < 30)
		{
			/* Fan is off State */
			LCD_displayString("Fan is OFF");
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp_value);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(STOP, 0);
		}
		else if (temp_value < 60)
		{
			/* Fan is on at low speed State*/
			LCD_displayString("Fan is ON ");
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp_value);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(ANTICLOCKWISE, 25);
		}
		else if (temp_value < 90)
		{
			/* Fan is on at medium speed State */
			LCD_displayString("Fan is ON ");
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temp_value);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(ANTICLOCKWISE, 50);
		}
		else if (temp_value < 100)
		{
			/* Fan is on at high speed State */
			LCD_displayString("Fan is ON ");
	

	}

}
