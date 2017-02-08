/*
 * EKE_keypad.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-safi
 */

#include "EKE_Keypad.h"

////////////////////////////////////////////////////////
void EKE_keypad_init(void)
{
  // check for ADC module  of ATmega32 to be off
   #if(keypadPort=='A')
	   ADCSRA=0;
   #endif
  // initialize row pins(0-->3)as input I/P
  EKE_DIO_InitPort(keypadPort,0b11110000);
  // Turn internal pull up resistors in ROW pins
  EKE_DIO_setPin(keypadPort,FIRST_ROW_PIN) ;
  EKE_DIO_setPin(keypadPort,SECOND_ROW_PIN);
  EKE_DIO_setPin(keypadPort,THIRD_ROW_PIN) ;
  EKE_DIO_setPin(keypadPort,FOURTH_ROW_PIN);
}
////////////////////////////////////////////////////////
U16_t EKE_getKey(void)
{
	U16_t Keypressed=11;

	//scan first column
	EKE_DIO_clearPin(keypadPort,FIRST_COLUMN_PIN);
	EKE_DIO_setPin(keypadPort,SECOND_COLUMN_PIN);
	EKE_DIO_setPin(keypadPort,THIRD_COLUMN_PIN);
	EKE_DIO_setPin(keypadPort,FOURTH_COLUMN_PIN);

	     if(!(keypadPort & (1<<FIRST_ROW_PIN)))  Keypressed=1  ;
	else if(!(keypadPort & (1<<SECOND_ROW_PIN))) Keypressed=4  ;
	else if(!(keypadPort & (1<<THIRD_ROW_PIN)))  Keypressed=7  ;
	else if(!(keypadPort & (1<<FOURTH_ROW_PIN))) Keypressed='*'; // ASCII (0X2A)


	//scan second  column
	EKE_DIO_clearPin(keypadPort,SECOND_COLUMN_PIN);
	EKE_DIO_setPin(keypadPort,FIRST_COLUMN_PIN);
	EKE_DIO_setPin(keypadPort,THIRD_COLUMN_PIN);
	EKE_DIO_setPin(keypadPort,FOURTH_COLUMN_PIN);

	     if(!(keypadPort & (1<<FIRST_ROW_PIN)))  Keypressed=2;
	else if(!(keypadPort & (1<<SECOND_ROW_PIN))) Keypressed=5;
	else if(!(keypadPort & (1<<THIRD_ROW_PIN)))  Keypressed=8;
	else if(!(keypadPort & (1<<FOURTH_ROW_PIN))) Keypressed=0;


	//scan 3rd  column
	EKE_DIO_clearPin(keypadPort,THIRD_COLUMN_PIN);
	EKE_DIO_setPin(keypadPort,FIRST_COLUMN_PIN);
	EKE_DIO_setPin(keypadPort,SECOND_COLUMN_PIN);
	EKE_DIO_setPin(keypadPort,FOURTH_COLUMN_PIN);

	     if(!(keypadPort & (1<<FIRST_ROW_PIN)))  Keypressed=3;
	else if(!(keypadPort & (1<<SECOND_ROW_PIN))) Keypressed=6;
	else if(!(keypadPort & (1<<THIRD_ROW_PIN)))  Keypressed=9;
	else if(!(keypadPort & (1<<FOURTH_ROW_PIN))) Keypressed='#'; // ASCII (0X23)

	//scan 4th  column
	EKE_DIO_clearPin(keypadPort,FOURTH_COLUMN_PIN);
	EKE_DIO_setPin(keypadPort,FIRST_COLUMN_PIN);
	EKE_DIO_setPin(keypadPort,SECOND_COLUMN_PIN);
	EKE_DIO_setPin(keypadPort,THIRD_COLUMN_PIN);

	     if(!(keypadPort & (1<<FIRST_ROW_PIN)))  Keypressed='A';
	else if(!(keypadPort & (1<<SECOND_ROW_PIN))) Keypressed='B';
	else if(!(keypadPort & (1<<THIRD_ROW_PIN)))  Keypressed='C';
	else if(!(keypadPort & (1<<FOURTH_ROW_PIN))) Keypressed='D';


	return Keypressed;
}
