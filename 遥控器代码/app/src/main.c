#include "bsp.h"

AnalogStick analogStick;
BUF buf;
/**  
	遥控器代码
	2022.10.08
	devilwzx
**/
void main(void)
{
	BSP_Init();
	Delay_ms(1000);	
	/*设置为发送模式*/
	TX_Mode();
	LED_Light(LIGHT_GREEN);
	LED_Light(RED);
	while(1)
	{
		/*摇杆adc值和开关bull值转换，转换完成后存到buf 结构体中*/
		analogStick=Analog_Stick();	
		/*将存好的结构体通过NRF发送出去*/
		NRF_Send(SW1_Down(),SW2_Down(),analogStick);
		LED_Red=~LED_Red;
	}
}
	