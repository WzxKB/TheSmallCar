#include "name.h"


void LED_Light(u8 led)
{
	switch(led)
		{
		case 1:
			LED_Red=0;
			break;
		case 2:
			LED_LightGreen=0;
			break	;	
		case 3:
			LED_Green=0;
			break	;	
		} 
}

void LED_Extinguish(u8 led)
{
	switch(led)
		{
		case 1:
			LED_Red=1;
			break;
		case 2:
			LED_LightGreen=1;
			break	;	
		case 3:
			LED_Green=1;
			break	;	
		} 
}