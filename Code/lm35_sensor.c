/**
 * @file 	lm35_sensor.c
 * @brief lm35 Source file.
 *
 * This file contains The Implementation of Functions of the Temperature Sensor module
  *
  * @author [Mohamed Mabrouk]
  * @date [17 FEB 2024]
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
#include"lm35_sensor.h"
#include"adc.h"

/* ===================================================================================================
										Function Definition
   ===================================================================================================*/

/**
 *
 * This Function responsible for Getting the Temperature.
 *
 * @param[in]  none
 * @param[out] none
 * @return uint8
 */
uint8 LM35_getTemp(void)
{

    uint8 a_temperature = 0;
	uint16 a_adc_value = 0;

	/* Read the ADC channel which the temperature sensor is connected to */
	a_adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Calculate the temperature */
	a_temperature = (uint8)(((uint32) a_adc_value * ADC_REF_VOLT_VALUE * SENSOR_MAX_TEMP) / (SENSOR_MAX_VOLT * ADC_MAXIMUM_VALUE));

	return a_temperature;
}
