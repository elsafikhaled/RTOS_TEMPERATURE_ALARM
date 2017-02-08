/*
 * temperatureAlarm.c
 *
 * Created: 16/10/2016 01:59:30 م
 *  Author: El-safi
 */ 

/*
 * alarm.c
 *
 * Created: 15/10/2016 11:06:36 ص
 *  Author: El-safi
 */ 

// FREERTOS FILES
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"
#include "EKE_ADC.h"
#include "EKE_Keypad.h"
#include "lcdEKE.h"
#include "DIO_layer.h"
#include "std_data_types_EKE.h"
// system tasks 
void T_checks(void*ptrToPara);
void T_alarm(void*ptrToPara);
void T_LCD(void*ptrToPara);
void T_ADC(void*ptrToPara);
void T_keybad(void*ptrToPara);
void system_init(void);
//system declarations ADC and LCD queue
xQueueHandle TEMPQ ;

// EVENT GROUP alarmSystem DEFINITIONS

#define alarmset       (1<<0)
//event group name 
EventGroupHandle_t    alarmSystem ;
EventBits_t  ebVal;

int main(void)
{
  system_init();
  xTaskCreate(T_LCD,NULL,100,NULL,1,NULL);
 // xTaskCreate(T_keybad,NULL,100,NULL,2,NULL); 
  xTaskCreate(T_ADC,NULL,100,NULL,3,NULL); 
 // xTaskCreate(T_checks,NULL,100,NULL,4,NULL); 
 // xTaskCreate(T_alarm,NULL,100,NULL,5,NULL);   // output task high priority
 // alarmSystem = xEventGroupCreate();
 TEMPQ = xQueueCreate(1,2);
  vTaskStartScheduler();
} 

void T_checks(void*ptrToPara)
{
	//unsigned char maxTemp=130;
	//unsigned char thTemp=25;
	
	while (1)
	{
		
	}
}

void T_alarm(void*ptrToPara)
{
	while (1)
	{
		 ebVal= xEventGroupWaitBits(alarmSystem,alarmset, 0, 0, 1000);
		 if(ebVal&(alarmset))
		 {
			PORTD^=(1<<PD5); // buzzer on  
			vTaskDelay(500);
			 
		 }
		else if(ebVal&(alarmset))
		 {
			 PORTD&=~(1<<PD5); // buzzer off
			 vTaskDelay(500); 
		 }
		 
	}
}
void system_init(void)
{
  DDRD&=~(1<<PD2);
  DDRD&=~(1<<PD3);  // buttons
  DDRD|=(1<<PD5);           // alarm
 EKE_ADC_init(1,1);
 EKE_LCD_INIT();
 EKE_keypad_init();
}

void T_LCD(void*ptrToPara)
{
	unsigned short display=0;
	
	while (1)
	{
	    xQueueReceive(TEMPQ,&display,1000);
		goToRowColumn(1,1);
		EKE_LCD_string((unsigned char *)"TEMP: ");
		goToRowColumn(1,8);
		EKE_LCD_intNumASCII(display);
		
	}
}
void T_ADC(void*ptrToPara)
{
   unsigned short data=0;
   unsigned short digital=0;
   EKE_ADC_clk_interr(128,0);	
	while (1)
	{
		digital=EKE_ADC_read(1);
		data=(digital*5)/(10);
		
		xQueueSend(TEMPQ,&data,1000);
		vTaskDelay(1000);
	}
}

void T_keybad(void*ptrToPara)
{
	while (1)
	{
	}
	
}

