/*
 * EKE_ADC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-safi
 */
#include "EKE_ADC.h"
/************************* ADC INIT *************************************************************/

void EKE_ADC_init( U8_t volt_Ref,U8_t adcEN)
{
	EKE_DIO_InitPort('a',input);

	switch(volt_Ref)
	  {
	     case 0:
	             ADMUX&=~(1<<REFS1);
	             ADMUX&=~(1<<REFS0);
	             ADMUX&=~(1<<ADLAR);    break;
	     case 1:
	    	     ADMUX|=(1<<REFS0);
	    	     ADMUX&=~(1<<ADLAR);    break;
	     case 2:
	    	     ADMUX|=(1<<REFS0)|(1<<REFS1);
	    	     ADMUX&=~(1<<ADLAR);    break;
	  }

     if(adcEN==1) ADCSRA |= (1<<ADEN);
else if(adcEN==0) ADCSRA &=~(1<<ADEN);

}
//////////////////////////////////////////////////////////////////////////////////////////////////

/******************** ADC READ  **********************************************************/
U16_t EKE_ADC_read(U8_t adcPin)
{
	switch(adcPin)
		{
		  case 0:
			  ADMUX&=~(1<<MUX0);ADMUX&=~(1<<MUX1);ADMUX&=~(1<<MUX2);ADMUX&=~(1<<MUX3);ADMUX&=~(1<<MUX4);break;
		  case 1:
			  ADMUX|=(1<<MUX0);ADMUX&=~(1<<MUX1);ADMUX&=~(1<<MUX2);ADMUX&=~(1<<MUX3);ADMUX&=~(1<<MUX4);break;
		  case 2:
			  ADMUX&=~(1<<MUX0);ADMUX&=~(1<<MUX1);ADMUX&=~(1<<MUX2);ADMUX&=~(1<<MUX3);ADMUX&=~(1<<MUX4);break;
		  case 3:
			  ADMUX&=~(1<<MUX0);ADMUX|=(1<<MUX1);ADMUX&=~(1<<MUX2);ADMUX&=~(1<<MUX3);ADMUX&=~(1<<MUX4);break;
		  case 4:
			  ADMUX&=~(1<<MUX0);ADMUX&=~(1<<MUX1);ADMUX|=(1<<MUX2);ADMUX&=~(1<<MUX3);ADMUX&=~(1<<MUX4);break;
		  case 5:
			  ADMUX|=(1<<MUX0);ADMUX&=~(1<<MUX1);ADMUX|=(1<<MUX2);ADMUX&=~(1<<MUX3);ADMUX&=~(1<<MUX4);break;
		  case 6:
			  ADMUX&=~(1<<MUX0);ADMUX|=(1<<MUX1);ADMUX|=(1<<MUX2);ADMUX&=~(1<<MUX3);ADMUX&=~(1<<MUX4);break;
		  case 7:
			  ADMUX|=(1<<MUX0);ADMUX|=(1<<MUX1);ADMUX|=(1<<MUX2);ADMUX&=~(1<<MUX3);ADMUX&=~(1<<MUX4);break;
		}
	ADCSRA|=(1<<ADSC);
    while(ADCSRA&(1<<ADSC));
	ADCSRA|=(1<<ADIF);

	return ADC;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void EKE_ADC_clk_interr(U8_t division_factor,U8_t interrEN)
{
	switch(division_factor)
	  {

	     case 2:                                                               //2
	    	 ADCSRA&=~(1<<ADPS2);ADCSRA&=~(1<<ADPS1);ADCSRA|=(1<<ADPS0);break;
	     case 4:                                                               //4
	         ADCSRA&=~(1<<ADPS2);ADCSRA|=(1<<ADPS1);ADCSRA&=~(1<<ADPS0);break;
	     case 8:                                                               //8
	    	 ADCSRA&=~(1<<ADPS2);ADCSRA|=(1<<ADPS1);ADCSRA|=(1<<ADPS0);break;
	     case 16:                                                             //16
	    	 ADCSRA|=(1<<ADPS2);ADCSRA&=~(1<<ADPS1);ADCSRA&=~(1<<ADPS0);break;
	     case 32:                                                             //32
	    	 ADCSRA|=(1<<ADPS2);ADCSRA&=~(1<<ADPS1);ADCSRA|=(1<<ADPS0);break;
	     case 64:                                                             //64
	    	 ADCSRA|=(1<<ADPS2);ADCSRA|=(1<<ADPS1);ADCSRA&=~(1<<ADPS0);break;
	     case 128:                                                            //128
	    	 ADCSRA|=(1<<ADPS2);ADCSRA|=(1<<ADPS1);ADCSRA|=(1<<ADPS0);break;
	  }
if(interrEN==1)
{
    ADCSRA|=(1<<ADIE);
    sei();
}

else if(interrEN==0)
{
	ADCSRA&=~(1<<ADIE);
}

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////















