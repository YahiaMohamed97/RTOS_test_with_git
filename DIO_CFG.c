/*
 * DIO_CFG.c
 *
 *  Created on: Dec 13, 2020
 *      Author: yahia
 */



#include "STD_TYPES.h"
#include "DIO_CFG.h"

uint8_t  arr_pins_cfg[LAST_PIN]={
		INPUT_FLOATING,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,  											 /* PORT A */
		OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,																 /* PORT B */
		OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,		 /* PORT C */
		OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT,OUTPUT  /* PORT D */
};
