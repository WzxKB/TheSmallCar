#include "bsp.h"
#include "math.h"
BUF buf;
/**  
	小车代码
	2022.10.08
	devilwzx
**/

/***    小车行进模式，快衰减模式  ***/
void FastMode(void);
void main(void)
{
	BSP_Init();

	Delay_ms(1000);
	RX_Mode();								//配置为接收模式
	LED_Light(RED);
	LED_Light(LIGHT_GREEN);
	
	while(1)
	{
		buf=NRF_Receive();
		
	}
}



/**
  * @brief 中断函数，当NRF接收信号时中断，红灯闪烁并运动 
  * @param	无
  * @retval	无
  */
void INT3_Isr() interrupt 11   
{ 
	  LED_Red=~LED_Red;			
		FastMode();
	
}

/**
  * @brief 小车运动模式，和摇杆相关，摇杆上轮胎前进，摇杆下轮胎倒退，中摇杆作为速度系数，越往上推，系数越大。 
  * @param	无
  * @retval	无
  */
void FastMode(void)
{
	//左摇杆推上，左轮前进
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
	
	//右摇杆推上，右轮前进
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
