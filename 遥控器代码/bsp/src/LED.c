#include "name.h"

/**
  * @brief LEDµ„¡¡ 
  * @param	Œﬁ
  * @retval	Œﬁ
  */
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
		} 
}