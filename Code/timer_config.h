/** ===================================================================================================
  *File Name: TIMER_config.h
  *
  *Author: Mohamed Mabrouk
  *
  *Description: Timer Configration file
  *Date: 25/1/2024
  *version: 1
 ===================================================================================================*/

//#define  F_CPU 8000000UL					/*System Clock*/
#define MAX_TIMER0_OVF_TICK_NUM 0
#define MAX_TIMER2_OVF_TICK_NUM 0

		/* MODES */
#define TIMER0_MODE   			FAST_PWM
#define TIMER0_CTC_MODE 		OC_DISCONNECTED
#define TIMER0_FAST_PWM_MODE 	FAST_PWM_NON_INVERTING
#define TIMER0_PRESCALLER 		TIMER0_PRESCALER_8

#define TIMER1_CTC_MODE 		OC_TOOGLE
#define TIMER1_MODE    			TIMER1_FAST_PWM_ICR
#define TIMER1_FAST_PWM_MODE 	FAST_PWM_NON_INVERTING
#define TIMER1_PRESCALLER 		TIMER1_PRESCALER_8

#define TIMER2_CTC_MODE 		OC_TOOGLE
#define TIMER2_MODE   			FAST_PWM
#define TIMER2_FAST_PWM_MODE 	FAST_PWM_INVERTING
#define TIMER2_PRESCALLER 		TIMER2_PRESCALER_256
