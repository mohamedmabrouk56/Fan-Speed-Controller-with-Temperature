/**
 * @file 	lm35_sensor.h
 * @brief lm35 Header file.
 *
 * This file contains the declarations and definitions for the Temperature Sensor module
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

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

/* ===================================================================================================
										   Includes
   ===================================================================================================*/
#include "std_types.h"
/* ===================================================================================================
										Macro Definition
   ===================================================================================================*/

/**
  * @brief The used Channel for the Temperature Sensor
  *
  * @details
  * - Type: define
  * - Range: 0xFFU
  * - Resolution: Fixed
  * - Unit: Bits
  */
#define SENSOR_CHANNEL_ID 2

/**
  * @brief the Maximum Volt to Represent the Maximum Temperature
  *
  * @details
  * - Type: define
  * - Range: 1.5U
  * - Resolution: Fixed
  * - Unit: Bits
  */
/* 0 -> 150  150 * 10mv = 1.5 V */
#define SENSOR_MAX_VOLT 1.5

/**
  * @brief The Maximum Temperature the Sensor Can Read
  *
  * @details
  * - Type: define
  * - Range: 150U
  * - Resolution: Fixed
  * - Unit: Bits
  */
#define SENSOR_MAX_TEMP 150

/* ===================================================================================================
										Function Prototypes
   ===================================================================================================*/
uint8 LM35_getTemp(void);

#endif /* LM35_SENSOR_H_ */
