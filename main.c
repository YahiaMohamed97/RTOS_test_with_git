/*
 * main.c
 *
 *  Created on: Mar 19, 2021
 *      Author: yahia
 */


#include "STD_TYPES.h"
#include "DIO_AVR.h"
#include "ADC_AVR.h"
#include "schedule.h"

 uint32_t counter=0;



void function1(void){
	TOGGLE_BIT(PORTA,1);
	PORTB=arr_data_read[0];
	PORTC=arr_data_read[0]>>8;
}
void function2(void){
	TOGGLE_BIT(PORTA,2);
}
void function3(void){
	TOGGLE_BIT(PORTA,6);
}
int main(void)
{
	DIO_Init();
	Timer_counter=0;
	numberOfChannels=0;
	str_adc_channel_config channel1;
	channel1.adc_referance=AVCC_ADC;
	channel1.pin=0;
	channel1.adj=RIGHT_ADJ;
	channel1.pre_scaler=PRESCALER_64;


	adc_init_channel(&channel1);
	status=FREE;


	add_task(function1,PERIODIC,0);
	add_task(function2,PERIODIC,0);

	add_task(adc_read,PERIODIC,0);

	add_task(function3,PERIODIC,0);
	init_schedule();
	schedule_start();
}
