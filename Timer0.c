

#include "Timer0.h"

#define CLK_PINS 0x07

str_timer_cfg TIMER0;

ISR (TIMER0_OVF_vect)
{
	Timer_counter++;
	if (Timer_counter == 400)
	{Timer_counter=0;}
}


void FillStruct(void)
{
	TIMER0.Timer_mode=NORMAL_MODE;
	TIMER0.clk_src=PRESCALER_256;
	TIMER0.interruptMask=OVERFLOW_INTERRUPT_ENABLE;
	TIMER0.intrruptMode=TIMER_INTERRUPT_ON;
}

/***
 * 
 * IF F_CPU = 8MHz
 * | pre Scaler | OverFlow Time
 * |     1      |	32 u	
 * |     8      |	256 u
 * |	64		|	2.048 m
 * |	256		|	8.192 m
 * |	1024	|	32.768 m
 * 
 ***/


void Timer0Init(void)
{
	FillStruct(); /***		Just for Testing		***/ 
	//TODO: Delete The above Line 
	TCCR0 = TIMER0.Timer_mode;
	TCCR0 |= (TCCR0&(CLK_PINS))|(TIMER0.clk_src);
	if (TIMER0.Timer_mode != NORMAL_MODE)
	{
		OCR0=TIMER0_MAX_VALUE;
	}
	if (TIMER0.intrruptMode == TIMER_INTERRUPT_ON)
	{
		TIMSK = TIMER0.interruptMask;
	}
}



void Timer0Update(str_timer_cfg * Update)
{

	TCCR0 = Update->Timer_mode;
	TCCR0 |= (TCCR0&(CLK_PINS))|(Update->clk_src);
	if (Update->Timer_mode != NORMAL_MODE)
	{
		OCR0=TIMER0_MAX_VALUE;
	}
	if (Update->intrruptMode == TIMER_INTERRUPT_ON)
	{
		TIMSK = Update->interruptMask;
	}
}

void writeTimr0(uint8_t val)
{

	TCNT0 = val;

}

void readTimr0(uint8_t* val)
{

	*val=TCNT0;

}


void Timr0_delay_ms(uint16_t delay)
{

	/* Update Prescaler + count   */
}


void Timr0_delay_us(uint16_t delay)
{

}


void writeTimr0CTC(uint8_t val)
{

	OCR0=val;

}


void Timer0DeInit(void)
{

}
void xx (void)
{

}

