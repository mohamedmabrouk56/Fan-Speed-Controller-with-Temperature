/**
  * @file timer.h
  * @brief Header file for the TIMER module.
  *
  * This file contains the declarations and definitions for the TIMER module
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

#ifndef TIMER_H_
#define TIMER_H_
 /* ===================================================================================================
										   Includes
	===================================================================================================*/
#include"Std_Types.h"
#include"timer_config.h"

 /* ===================================================================================================
								   	    Macro Definition
    ===================================================================================================*/

	   /* Control Registers*/
#define TCCR0    *((volatile uint8* const)(0x53))
#define TCCR1A   *((volatile uint8* const)(0x4F))
#define TCCR1B   *((volatile uint8* const)(0x4E))
#define TCCR2    *((volatile uint8* const)(0x45))
/*************************************************************************************************************/
	   /* Overflow Registers*/
#define TCNT0    *((volatile uint8* const)(0x52))
#define TCNT1H   *((volatile uint8* const)(0x4D))
#define TCNT1L   *((volatile uint8* const)(0x4C))
#define TCNT1   *((volatile uint16* const)(0x4C))
#define TCNT2    *((volatile uint8* const)(0x44))
/*************************************************************************************************************/
	   /* Compare Match Registers*/
#define OCR0     *((volatile uint8* const)(0x5C))
#define OCR1AH   *((volatile uint8* const)(0x4B))
#define OCR1AL   *((volatile uint8* const)(0x4A))
#define OCR1A   *((volatile uint16* const)(0x4A))
#define OCR1BH   *((volatile uint8* const)(0x49))
#define OCR1BL   *((volatile uint8* const)(0x48))
#define OCR1B   *((volatile uint16* const)(0x48))
#define OCR2     *((volatile uint8* const)(0x43))
/*************************************************************************************************************/
	   /* Input Capture Register*/
#define ICR1H   *((volatile uint8* const)(0x47))
#define ICR1L   *((volatile uint8* const)(0x46))
#define ICR1   *((volatile uint16* const)(0x46))
/*************************************************************************************************************/
		/* Interrupts Mask Register*/
#define TIMSK   *((volatile uint8* const)(0x59))
		/* Interrupts Flag Register*/
#define TIFR    *((volatile uint8* const)(0x58))

#ifndef SREG
#define SREG   *((volatile uint8* const)(0x5F))
#define IBIT 7
#endif
/*************************************************************************************************************/
/*TCCR0*/
#define 		FOC0									7
#define 		WGM00									6
#define 		COM01									5
#define 		COM00									4
#define 		WGM01									3
#define 		CS02									2
#define 		CS01									1
#define 		CS00									0
/*************************************************************************************************************/
/*TCCR1A*/
#define 		COM1A1									7
#define 		COM1A0									6
#define 		COM1B1									5
#define 		COM1B0									4
#define 		FOC1A									3
#define 		FOC1B									2
#define 		WGM11									1
#define 		WGM10									0
/*************************************************************************************************************/
/*TCCR1B*/
#define 		ICNC1									7
#define 		ICES1									6
#define 		WGM13									4
#define 		WGM12									3
#define 		CS12									2
#define 		CS11									1
#define 		CS10									0
/*************************************************************************************************************/
/*TCCR2*/
#define 		FOC2									7
#define 		WGM20									6
#define 		COM21									5
#define 		COM20									4
#define 		WGM21									3
#define 		CS22									2
#define 		CS21									1
#define 		CS20									0
/*************************************************************************************************************/
/*TIMSK BITS*/
#define 		OCIE2									7
#define 		TOIE2									6
#define 		TOCIE1									5
#define 		OCIE1A									4
#define 		OCIE1B									3
#define 		TOIE1									2
#define 		OCIE0									1
#define 		TOIE0									0

/*************************************************************************************************************/
/*TIFR BITS*/
#define 		OCF2									7
#define 		TOV2									6
#define 		ICF1									5
#define 		OCF1A									4
#define 		OCF1B									3
#define 		TOV1									2
#define 		OCF0									1
#define 		TOVO									0

/**************************************************************************************************************/


/* ===================================================================================================
										Types Declaration
   ===================================================================================================*/
/*TIMER 0, TIMER 2 MODES*/
#define	OVF 		 0
#define PHASE_PWM 	 1
#define CTC 		 2
#define FAST_PWM	 3

/*TIMER 1 MODES*/
#define	TIMER1_OVF				0
#define TIMER1_PHASE_PWM_8BIT	1
#define TIMER1_PHASE_PWM_9BIT	2
#define TIMER1_PHASE_PWM_10BIT	3
#define TIMER1_CTC_OCR			4
#define TIMER1_FAST_PWM_8BIT	5
#define TIMER1_FAST_PWM_9BIT	6
#define TIMER1_FAST_PWM_10BIT	7
#define TIMER1_CTC_ICR			12
#define TIMER1_FAST_PWM_ICR		14
#define TIMER1_FAST_PWM_OCR		15


/*PWM MODES */
#define	FAST_PWM_DISCONNECTED 0
#define FAST_PWM_NON_INVERTING 1
#define FAST_PWM_INVERTING 2

#define OC_DISCONNECTED 0
#define OC_TOOGLE 1
#define OC_CLEAR 2
#define OC_SET 3


typedef enum
{
	TIMER0,
	TIMER1,
	TIMER2
}Timer_ID;
typedef enum
{
	/*Timer 0*/
	TIMER0_NO_SOURCE=0,
	TIMER0_NO_PRESCALER,
	TIMER0_PRESCALER_8,
	TIMER0_PRESCALER_64,
	TIMER0_PRESCALER_256,
	TIMER0_PRESCALER_1024,
	TIMER0_EXTSOURCE_FALLING,
	TIMER0_EXTSOURCE_RISING,

	/*Timer 1*/
	TIMER1_NO_SOURCE=0,
	TIMER1_NO_PRESCALER,
	TIMER1_PRESCALER_8,
	TIMER1_PRESCALER_64,
	TIMER1_PRESCALER_256,
	TIMER1_PRESCALER_1024,
	TIMER1_EXTSOURCE_FALLING,
	TIMER1_EXTSOURCE_RISING,

	/*Timer 2*/
	TIMER2_NO_SOURCE=0,
	TIMER2_NO_PRESCALER,
	TIMER2_PRESCALER_8,
	TIMER2_PRESCALER_32,
	TIMER2_PRESCALER_64,
	TIMER2_PRESCALER_128,
	TIMER2_PRESCALER_256,
	TIMER2_PRESCALER_1024,

}TIMER_Prescaler;
/* ===================================================================================================
									   Function Prototypes
   ===================================================================================================*/

   /*Initializtion*/

void TIMER_init(Timer_ID Timer_num);

uint8 TIMER_read(Timer_ID Timer_num);

void TIMER_setPreloadValue (Timer_ID Timer_num,uint16 Preload);

void TIMER_setCompareMatch (Timer_ID Timer_num, uint16 Value);

/* Timer 0*/
void TIMER0_setCallBack(void (*copy_ptr)(void));

void PWM_Timer0_Start (uint8 DutyCycle);

/* Timer 1*/
void TIMER1_setCallBack(void (*copy_ptr)(void));

void PWM_Timer1_Start (uint8 DutyCycle,uint8 Circuit);
/* Timer 2 */
void TIMER2_setCallBack(void (*copy_ptr)(void));

void PWM_Timer2_Start (uint8 DutyCycle);

/*ISR*/

void __vector_4(void)     __attribute__((signal)); /*TIMER2 COMP ISR*/

void __vector_5(void)     __attribute__((signal)); /*TIMER2 OVF ISR*/

void __vector_7(void)     __attribute__((signal)); /*TIMER1 COMPA ISR*/

void __vector_8(void)     __attribute__((signal)); /*TIMER1 COMPB ISR*/

void __vector_9(void)     __attribute__((signal)); /*TIMER1 OVF ISR*/

void __vector_10(void)    __attribute__((signal)); /*TIMER0 COMP ISR*/

void __vector_11(void)    __attribute__((signal)); /*TIMER0 OVF ISR*/

#endif /* TIMER_H_ */
