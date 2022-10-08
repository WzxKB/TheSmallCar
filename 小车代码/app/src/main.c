#include "bsp.h"
#include "math.h"
BUF buf;
/**  
	С������
	2022.10.08
	devilwzx
**/

/***    С���н�ģʽ����˥��ģʽ  ***/
void FastMode(void);
void main(void)
{
	BSP_Init();

	Delay_ms(1000);
	RX_Mode();								//����Ϊ����ģʽ
	LED_Light(RED);
	LED_Light(LIGHT_GREEN);
	
	while(1)
	{
		buf=NRF_Receive();
		
	}
}



/**
  * @brief �жϺ�������NRF�����ź�ʱ�жϣ������˸���˶� 
  * @param	��
  * @retval	��
  */
void INT3_Isr() interrupt 11   
{ 
	  LED_Red=~LED_Red;			
		FastMode();
	
}

/**
  * @brief С���˶�ģʽ����ҡ����أ�ҡ������̥ǰ����ҡ������̥���ˣ���ҡ����Ϊ�ٶ�ϵ����Խ�����ƣ�ϵ��Խ�� 
  * @param	��
  * @retval	��
  */
void FastMode(void)
{
	//��ҡ�����ϣ�����ǰ��
	if(buf.left>ROC_UP)
	{
		PWM_SetLeftIN1(100,0);
		PWM_SetLeftIN2(buf.left,buf.middle);
		LED_Green=0;
		 
	}
	else if(buf.left<ROC_DOWN)
	{
	
		PWM_SetLeftIN1(buf.left,buf.middle);
		PWM_SetLeftIN2(100,0);
		LED_Green=0;

	}
	else if(buf.left>=ROC_DOWN&&buf.left<=ROC_UP)
	{
		PWM_SetLeftIN1(200,34);
		PWM_SetLeftIN2(200,34);
		LED_Green=0;
	
	}
	
	//��ҡ�����ϣ�����ǰ��
	if(buf.right>ROC_UP)
	{
		PWM_SetRightIN1(100,0);
		PWM_SetRightIN2(buf.right,buf.middle);
		LED_Green=0;
	}
	else if(buf.right<ROC_DOWN)
	{
		
		PWM_SetRightIN1(buf.right,buf.middle);
		PWM_SetRightIN2(100,0);
		LED_Green=0;

	}
	else if(buf.right>=ROC_DOWN&&buf.right<=ROC_UP)
	{
		PWM_SetRightIN1(200,34);
		PWM_SetRightIN2(200,34);
		LED_Green=0;
	
	}
}
