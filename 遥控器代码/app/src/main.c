#include "bsp.h"

AnalogStick analogStick;
BUF buf;
/**  
	ң��������
	2022.10.08
	devilwzx
**/
void main(void)
{
	BSP_Init();
	Delay_ms(1000);	
	/*����Ϊ����ģʽ*/
	TX_Mode();
	LED_Light(LIGHT_GREEN);
	LED_Light(RED);
	while(1)
	{
		/*ҡ��adcֵ�Ϳ���bullֵת����ת����ɺ�浽buf �ṹ����*/
		analogStick=Analog_Stick();	
		/*����õĽṹ��ͨ��NRF���ͳ�ȥ*/
		NRF_Send(SW1_Down(),SW2_Down(),analogStick);
		LED_Red=~LED_Red;
	}
}
	