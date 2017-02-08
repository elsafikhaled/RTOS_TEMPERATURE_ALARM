/*
 * EKE_ADC.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-safi
 */

#ifndef EKE_ADC_H_
#define EKE_ADC_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "C:\EL-SAFI\Embedded Systems\Embedded fab\EKE   MY Dr.layers\Microcontroller Abstraction Layers\ADC\DIO LAYER\DIO_layer.h"


void EKE_ADC_init( U8_t volt_Ref,U8_t adcEN);
/*******************************************************************************************************************************************
 * Function    :void EKE_ADC_init( U8_t volt_Ref);
 *
 * Parameters  :U8_t volt_Ref
 *
 * Description :* determine voltage reference by  - pass --> 0   extrnal AREF
 *                                                - pass --> 1   AREF=Vcc and connect capactor with pin and GND
 *                                                - pass --> 2   AREF= internal voltage 2.56v  and connect capactor with pin and GND
 *
 *              * ADC module                      - pass --> 1   active adc
 *                                                - pass --> 0   disable it
 *
 * return      : void
 *******************************************************************************************************************************************/

U16_t EKE_ADC_read(U8_t adcPin);
/*******************************************************************************************************************************************
 * Function    :U16_t EKE_ADC_read(U8_t adcPin);
 *
 * Parameters  :U8_t adcPin
 *
 * Description :* determine ADC MODULE            - pass --> 0   ADC0
 *                                                - pass --> 1   ADC1
 *                                                - pass --> 2   ADC2
 *                                                - pass --> 3   ADC3
 *                                                - pass --> 4   ADC4
 *                                                - pass --> 5   ADC5
 *                                                - pass --> 6   ADC6
 *                                                - pass --> 7   ADC7
 *
 * return      : ADC --> equal ADCL+ADCH
 *******************************************************************************************************************************************/

void EKE_ADC_clk_interr(U8_t division_factor,U8_t interrEN);
/*******************************************************************************************************************************************
 *  Function  : void EKE_ADC_clk_interr(U8_t division_factor,U8_t interrEN);
 *
 *
 * Parameters : U8_t division_factor,U8_t interrEN
 *
 *
 * Description: division_factor:: pass--> 2,4,8,16,32,64,128,256
 *              interrEN       :: pass--> 1 active and 0 disable
 *
 *
 *******************************************************************************************************************************************/




#endif /* EKE_ADC_H_ */
