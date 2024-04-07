/**
 * @file 	timer.c
 * @brief TIMER Source file.
 *
 * This file contains The Implementation of Functions of the TIMER module
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
#include"timer.h"
#include"common_Macros.h"
#include"gpio.h"

	/* ===================================================================================================
											  Global Variables
	   ===================================================================================================*/

	   /*Global Pointer to function*/
static volatile void (*TIMER0_PtrCallBack)(void) = NULL_PTR;
static volatile void (*TIMER1_PtrCallBack)(void) = NULL_PTR;
static volatile void (*TIMER2_PtrCallBack)(void) = NULL_PTR;


/* ===================================================================================================
										  Function Definition
   ===================================================================================================*/

   /*Initializtion*/
void TIMER_init(Timer_ID Timer_num)
{
	switch(Timer_num)
	{
	case TIMER0:
	TCCR0 |= TIMER0_PRESCALLER;
#if TIMER0_MODE == OVF
	CLR_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);
	SET_BIT(TIMSK, TOIE0);
	SET_BIT(TCCR0, FOC0);
	CLR_BIT(TIMSK, OCIE0);
	SET_BIT(SREG, IBIT);

#elif TIMER0_MODE == CTC
	CLR_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
	SET_BIT(TIMSK, OCIE0);
	CLR_BIT(TIMSK, TOIE0);
	SET_BIT(TCCR0, FOC0);
	SET_BIT(SREG, IBIT);

#elif TIMER0_MODE == FAST_PWM
	SET_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
#if   TIMER0_FAST_PWM_MODE  == FAST_PWM_DISCONNECTED
	CLR_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);
#elif TIMER0_FAST_PWM_MODE  == FAST_PWM_NON_INVERTING
	SET_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);
#elif TIMER0_FAST_PWM_MODE  == FAST_PWM_INVERTING
	SET_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,COM00);
#endif
	SET_BIT(DDRB,3);

#elif TIMER0_MODE == PHASE_PWM
	SET_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);
	SET_BIT(DDRB,3);

#endif
	break;

	case TIMER1:
		TCCR1B |= TIMER1_PRESCALLER;
#if TIMER1_MODE == TIMER1_OVF
		CLR_BIT(TCCR1A, WGM10);
		CLR_BIT(TCCR1A, WGM11);
		CLR_BIT(TCCR1B, WGM12);
		CLR_BIT(TCCR1B, WGM13);
		SET_BIT(TCCR1A, FOC1A);
		SET_BIT(TIMSK, TOIE1);
		SET_BIT(SREG, IBIT);

#elif TIMER1_MODE == TIMER1_CTC_OCR
		CLR_BIT(TCCR1A, WGM10);
		CLR_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1B, WGM12);
		CLR_BIT(TCCR1B, WGM13);
		SET_BIT(TCCR1A, FOC1A);
		SET_BIT(TIMSK, OCIE1A);
		SET_BIT(SREG, IBIT);
#if   TIMER1_CTC_MODE  == OC_DISCONNECTED
		CLR_BIT(TCCR1A, COM1A1);
		CLR_BIT(TCCR1A, COM1A0);
		CLR_BIT(TCCR1A, COM1B1);
		CLR_BIT(TCCR1A, COM1B0);
#elif TIMER1_CTC_MODE  == OC_TOOGLE
		CLR_BIT(TCCR1A, COM1A1);
		SET_BIT(TCCR1A, COM1A0);
		CLR_BIT(TCCR1A, COM1B1);
		SET_BIT(TCCR1A, COM1B0);
#elif TIMER1_CTC_MODE  == OC_CLEAR
		SET_BIT(TCCR1A, COM1A1);
		CLR_BIT(TCCR1A, COM1A0);
		SET_BIT(TCCR1A, COM1B1);
		CLR_BIT(TCCR1A, COM1B0);
#elif TIMER1_CTC_MODE  == OC_SET
		SET_BIT(TCCR1A, COM1A1);
		SET_BIT(TCCR1A, COM1A0);
		SET_BIT(TCCR1A, COM1B1);
		SET_BIT(TCCR1A, COM1B0);
#endif

#elif TIMER1_MODE == TIMER1_FAST_PWM_8BIT
		SET_BIT(TCCR1A, WGM10);
		CLR_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1B, WGM12);
		CLR_BIT(TCCR1B, WGM13);
#if   TIMER1_FAST_PWM_MODE  == FAST_PWM_DISCONNECTED
		CLR_BIT(TCCR1A, COM1A1);
		CLR_BIT(TCCR1A, COM1A0);
		CLR_BIT(TCCR1A, COM1B1);
		CLR_BIT(TCCR1A, COM1B0);
#elif TIMER1_FAST_PWM_MODE  == FAST_PWM_NON_INVERTING
		SET_BIT(TCCR1A, COM1A1);
		CLR_BIT(TCCR1A, COM1A0);
		SET_BIT(TCCR1A, COM1B1);
		CLR_BIT(TCCR1A, COM1B0);
#elif TIMER1_FAST_PWM_MODE  == FAST_PWM_INVERTING
		SET_BIT(TCCR1A, COM1A1);
		SET_BIT(TCCR1A, COM1A0);
		SET_BIT(TCCR1A, COM1B1);
		SET_BIT(TCCR1A, COM1B0);
#endif
		SET_BIT(DDRD, PIN4_ID);
		SET_BIT(DDRD, PIN5_ID);
#elif TIMER1_MODE == TIMER1_FAST_PWM_9BIT
		CLR_BIT(TCCR1A, WGM10);
		SET_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1B, WGM12);
		CLR_BIT(TCCR1B, WGM13);
#if   TIMER1_FAST_PWM_MODE  == FAST_PWM_DISCONNECTED
		CLR_BIT(TCCR1A, COM1A1);
		CLR_BIT(TCCR1A, COM1A0);
		CLR_BIT(TCCR1A, COM1B1);
		CLR_BIT(TCCR1A, COM1B0);
#elif TIMER1_FAST_PWM_MODE  == FAST_PWM_NON_INVERTING
		SET_BIT(TCCR1A, COM1A1);
		CLR_BIT(TCCR1A, COM1A0);
		SET_BIT(TCCR1A, COM1B1);
		CLR_BIT(TCCR1A, COM1B0);
#elif TIMER1_FAST_PWM_MODE  == FAST_PWM_INVERTING
		SET_BIT(TCCR1A, COM1A1);
		SET_BIT(TCCR1A, COM1A0);
		SET_BIT(TCCR1A, COM1B1);
		SET_BIT(TCCR1A, COM1B0);
#endif
		SET_BIT(DDRD, PIN4_ID);
		SET_BIT(DDRD, PIN5_ID);

#elif TIMER1_MODE == TIMER1_FAST_PWM_10BIT
		SET_BIT(TCCR1A, WGM10);
		SET_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1B, WGM12);
		CLR_BIT(TCCR1B, WGM13);
#if   TIMER1_FAST_PWM_MODE  == FAST_PWM_DISCONNECTED
		CLR_BIT(TCCR1A, COM1A1);
		CLR_BIT(TCCR1A, COM1A0);
		CLR_BIT(TCCR1A, COM1B1);
		CLR_BIT(TCCR1A, COM1B0);
#elif TIMER1_FAST_PWM_MODE  == FAST_PWM_NON_INVERTING
		SET_BIT(TCCR1A, COM1A1);
		CLR_BIT(TCCR1A, COM1A0);
		SET_BIT(TCCR1A, COM1B1);
		CLR_BIT(TCCR1A, COM1B0);
#elif TIMER1_FAST_PWM_MODE  == FAST_PWM_INVERTING
		SET_BIT(TCCR1A, COM1A1);
		SET_BIT(TCCR1A, COM1A0);
		SET_BIT(TCCR1A, COM1B1);
		SET_BIT(TCCR1A, COM1B0);
#endif
		SET_BIT(DDRD, PIN4_ID);
		SET_BIT(DDRD, PIN5_ID);

#elif TIMER1_MODE == TIMER1_CTC_ICR
		CLR_BIT(TCCR1A, WGM10);
		CLR_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1B, WGM12);
		SET_BIT(TCCR1B, WGM13);
		SET_BIT(TCCR1A, FOC1A);
		SET_BIT(TIMSK, OCIE1A);
		SET_BIT(SREG, IBIT);
#if   TIMER1_CTC_MODE  == OC_DISCONNECTED
		CLR_BIT(TCCR1A, COM1A1);
		CLR_BIT(TCCR1A, COM1A0);
		CLR_BIT(TCCR1A, COM1B1);
		CLR_BIT(TCCR1A, COM1B0);
#elif TIMER1_CTC_MODE  == OC_TOOGLE
		CLR_BIT(TCCR1A, COM1A1);
		SET_BIT(TCCR1A, COM1A0);
		CLR_BIT(TCCR1A, COM1B1);
		SET_BIT(TCCR1A, COM1B0);
#elif TIMER1_CTC_MODE  == OC_CLEAR
		SET_BIT(TCCR1A, COM1A1);
		CLR_BIT(TCCR1A, COM1A0);
		SET_BIT(TCCR1A, COM1B1);
		CLR_BIT(TCCR1A, COM1B0);
#elif TIMER1_CTC_MODE  == OC_SET
		SET_BIT(TCCR1A, COM1A1);
		SET_BIT(TCCR1A, COM1A0);
		SET_BIT(TCCR1A, COM1B1);
		SET_BIT(TCCR1A, COM1B0);
#endif

#elif TIMER1_MODE == TIMER1_FAST_PWM_ICR	
		CLR_BIT(TCCR1A, WGM10);
		SET_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1B, WGM12);
		SET_BIT(TCCR1B, WGM13);
#if   TIMER1_FAST_PWM_MODE  == FAST_PWM_DISCONNECTED
		CLR_BIT(TCCR1A, COM1A1);
		CLR_BIT(TCCR1A, COM1A0);
		CLR_BIT(TCCR1A, COM1B1);
		CLR_BIT(TCCR1A, COM1B0);
#elif TIMER1_FAST_PWM_MODE  == FAST_PWM_NON_INVERTING
		SET_BIT(TCCR1A, COM1A1);
		CLR_BIT(TCCR1A, COM1A0);
		SET_BIT(TCCR1A, COM1B1);
		CLR_BIT(TCCR1A, COM1B0);
#elif TIMER1_FAST_PWM_MODE  == FAST_PWM_INVERTING
		SET_BIT(TCCR1A, COM1A1);
		SET_BIT(TCCR1A, COM1A0);
		SET_BIT(TCCR1A, COM1B1);
		SET_BIT(TCCR1A, COM1B0);
#endif
		SET_BIT(DDRD, PIN6_ID);
#elif TIMER1_MODE == TIMER1_FAST_PWM_OCR
		SET_BIT(TCCR1A, WGM10);
		SET_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1B, WGM12);
		SET_BIT(TCCR1B, WGM13);
#if   TIMER1_FAST_PWM_MODE  == FAST_PWM_DISCONNECTED
		CLR_BIT(TCCR1A, COM1A1);
		CLR_BIT(TCCR1A, COM1A0);
		CLR_BIT(TCCR1A, COM1B1);
		CLR_BIT(TCCR1A, COM1B0);
#elif TIMER1_FAST_PWM_MODE  == FAST_PWM_NON_INVERTING
		SET_BIT(TCCR1A, COM1A1);
		CLR_BIT(TCCR1A, COM1A0);
		SET_BIT(TCCR1A, COM1B1);
		CLR_BIT(TCCR1A, COM1B0);
#elif TIMER1_FAST_PWM_MODE  == FAST_PWM_INVERTING
		SET_BIT(TCCR1A, COM1A1);
		SET_BIT(TCCR1A, COM1A0);
		SET_BIT(TCCR1A, COM1B1);
		SET_BIT(TCCR1A, COM1B0);
#endif
		SET_BIT(DDRD, PIN4_ID);
		SET_BIT(DDRD, PIN5_ID);
#endif

		break;

		/*Timer2 initiaillitation*/
	case TIMER2:
		TCCR2 |= TIMER2_PRESCALLER;
		#if TIMER2_MODE == OVF
			CLR_BIT(TCCR2, WGM20);
			CLR_BIT(TCCR2, WGM21);
			SET_BIT(TIMSK, OCIE2);
			SET_BIT(TCCR2, FOC2);
			SET_BIT(SREG, IBIT);

		#elif TIMER2_MODE == CTC
			CLR_BIT(TCCR2, WGM20);
			SET_BIT(TCCR2, WGM21);
			SET_BIT(TIMSK, OCIE2);
			SET_BIT(TCCR2, FOC2);
			CLR_BIT(TIMSK, TOIE0);
			SET_BIT(SREG, IBIT);
		#elif TIMER2_MODE == FAST_PWM
			SET_BIT(TCCR2, WGM20);
			SET_BIT(TCCR2, WGM21);
		#if   TIMER2_FAST_PWM_MODE  == FAST_PWM_DISCONNECTED
			CLR_BIT(TCCR2,COM21);
			CLR_BIT(TCCR2,COM20);
		#elif TIMER2_FAST_PWM_MODE  == FAST_PWM_NON_INVERTING
			SET_BIT(TCCR2,COM21);
			CLR_BIT(TCCR2,COM20);
		#elif TIMER2_FAST_PWM_MODE  == FAST_PWM_INVERTING
			SET_BIT(TCCR2,COM21);
			SET_BIT(TCCR2,COM20);
		#endif
			SET_BIT(DDRD,PIN7_ID);
		#elif TIMER2_MODE == PHASE_PWM
			SET_BIT(TCCR2, WGM20);
			CLR_BIT(TCCR2, WGM21);
			SET_BIT(DDRD,PIN7_ID);

		#endif
			break;
	}
}

uint8 TIMER_read(Timer_ID Timer_num)
{
	switch(Timer_num)
	{
	case TIMER0:
	return TCNT0;
	break;
	case TIMER1:
	return TCNT1;
	break;
	case TIMER2:
	return TCNT2;
	break;
	default:
	return 0;
	}

}

void TIMER_setPreloadValue (Timer_ID Timer_num,uint16 Preload)
{
	switch(Timer_num)
	{
   case TIMER0:
		TCNT0 =Preload;
   	break;
   	case TIMER1:
   		TCNT1 =Preload;
   	break;
   	case TIMER2:
   		TCNT2 =Preload;
   	break;
	}
}

void TIMER_setCompareMatch (Timer_ID Timer_num, uint16 Value)
{
	switch(Timer_num){
case TIMER0:
		OCR0 = Value;
  	break;
  	case TIMER1:
#if TIMER1_MODE == TIMER1_CTC_OCR
  		OCR1A = Value;
#elif TIMER1_MODE == TIMER1_CTC_ICR
  		ICR1 = Value;
#endif
  	break;
  	case TIMER2:
  		OCR2 = Value;
  	break;
	}
}

void TIMER_setCallBack(Timer_ID Timer_num , void (*copy_ptr)(void))
{
	switch(Timer_num)
	{
	case TIMER0:
		TIMER0_PtrCallBack = copy_ptr;
		break;
	case TIMER1:
		TIMER1_PtrCallBack = copy_ptr;
		break;
	case TIMER2:
		TIMER2_PtrCallBack = copy_ptr;
		break;
	default :
	  	/* Wrong Timer Num */
		break;
	}
}

/* TIMER 0*/
void PWM_Timer0_Start (uint8 DutyCycle)
{
	OCR0 = (float32)((float32)DutyCycle/100)*255;
}

void PWM_Timer1_Start (uint8 DutyCycle,uint8 Circuit)
{
#if TIMER1_MODE == TIMER1_FAST_PWM_8BIT
	switch(Circuit)
		{
	case 1:
	OCR1A = (float32)((float32)DutyCycle/100)*255;
	break;
	case 2:
	OCR1B = (float32)((float32)DutyCycle/100)*255;
	break;
		}
#elif TIMER1_MODE == TIMER1_FAST_PWM_9BIT
	switch(Circuit)
		{
	case 1:
	OCR1A = (float32)((float32)DutyCycle/100)*511;
	break;
	case 2:
	OCR1B = (float32)((float32)DutyCycle/100)*511;
	break;
		}
#elif TIMER1_MODE == TIMER1_FAST_PWM_10BIT
	switch(Circuit)
		{
	case 1:
	OCR1A = (float32)((float32)DutyCycle/100)*1023;
	break;
	case 2:
	OCR1B = (float32)((float32)DutyCycle/100)*1023;
	break;
		}
#elif TIMER1_MODE == TIMER1_FAST_PWM_ICR
	ICR1 = 2499;
	OCR1A=DutyCycle;
#elif TIMER1_MODE == TIMER1_FAST_PWM_OCR
	OCR1A = 65535;
	OCR1B = (float32)((float32)DutyCycle/100)*65535;
#endif
}

void PWM_Timer2_Start (uint8 DutyCycle)
{
	OCR2 = (float32)((float32)DutyCycle/100)*255;
}

/*ISR*/

void __vector_4(void) /* TIMER2 COMP ISR */
{
//	static uint8 Local_Tick = 0;
	if (TIMER2_PtrCallBack != NULL_PTR)
			{
			TIMER2_PtrCallBack();
			}
	else
			{
			/* Do Nothing */
			}
}
void __vector_5(void) /* TIMER2 OVF ISR */
{
	static uint8 Local_Tick = 0;
		if (TIMER2_PtrCallBack != NULL_PTR)
		{
			TIMER2_PtrCallBack();
		}
		else
		{
			/* Do Nothing */
		}

}

void __vector_7(void) /* TIMER1 COMPA ISR */
{
	//static uint16 Local_Tick = 0;
	if (TIMER1_PtrCallBack != NULL_PTR)
			{
	TIMER1_PtrCallBack();
			}
	else
			{
			/* Do Nothing */
			}

}
void __vector_8(void) /* TIMER1 COMPB ISR */
{
	//static uint16 Local_Tick = 0;
	if (TIMER1_PtrCallBack != NULL_PTR)
				{
		TIMER1_PtrCallBack();
				}
		else
				{
				/* Do Nothing */
				}
}
void __vector_9(void) /* TIMER1 OVF ISR */
{
	//static uint16 Local_Tick = 0;
	if (TIMER1_PtrCallBack != NULL_PTR)
				{
		TIMER1_PtrCallBack();
				}
		else
				{
				/* Do Nothing */
				}
}
void __vector_10(void) /* TIMER0 COMP ISR */
{
	//static uint8 Local_Tick = 0;
	if (TIMER0_PtrCallBack != NULL_PTR)
			{
	TIMER0_PtrCallBack();
			}
	else
			{
			/* Do Nothing */
			}
}
void __vector_11(void) /* TIMER0 OVF ISR */
{

		if (TIMER0_PtrCallBack != NULL_PTR)
		{
			TIMER0_PtrCallBack();
		}
		else
		{
			/* Do Nothing */
		}
}
