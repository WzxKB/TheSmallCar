#include "bsp.h"

AnalogStick analogStick;
BUF buf;
/**************************************************
Function: main();

Description:
  control all subprogrammes;
/**************************************************/
void main(void)
{
	BSP_Init();
	Delay_ms(1000);	
	TX_Mode();
	LED_Light(LIGHT_GREEN);
	LED_Red=0;
	while(1)
	{
	analogStick=Analog_Stick();	
//	if(buf.sw1!=SW1_Down()||buf.sw2!=SW2_Down()||	buf.left!=analogStick.left||buf.middle!=analogStick.middle|| buf.right!=analogStick.right)		
//		{
//			
			NRF_Send(SW1_Down(),SW2_Down(),analogStick);

		//	LED_LightGreen=~LED_LightGreen;
//		}
//	buf.sw1=SW1_Down();
//	buf.sw2=SW2_Down();
//	buf.left=analogStick.left;
//	buf.middle=analogStick.middle;
//	buf.right=analogStick.right;



	}
}
	