#include "bsp.h"
#include "math.h"
BUF buf;

void FastMode(void);
void BrakeMode(void);
void SlideMode(void);

void main(void)
{
	BSP_Init();

	Delay_ms(1000);
	RX_Mode();								//配置为接收模式
	LED_Red=0;
	LED_LightGreen=0;
	
	while(1)
	{
		buf=NRF_Receive();
		
	}
}




void INT3_Isr() interrupt 11   
{ 
	  LED_Red=~LED_Red;			
			FastMode();
	
}


void FastMode(void)
{
	//左摇杆推上，左轮前进
	if(buf.left>110)
	{
		PWM_SetLeftIN1(100,0);
		PWM_SetLeftIN2(buf.left,buf.middle);
		LED_Green=0;
		 
	}
	else if(buf.left<90)
	{
	
		PWM_SetLeftIN1(buf.left,buf.middle);
		PWM_SetLeftIN2(100,0);
		LED_Green=0;

	}
	else if(buf.left>=90&&buf.left<=110)
	{
		PWM_SetLeftIN1(200,34);
		PWM_SetLeftIN2(200,34);
		LED_Green=0;
	
	}
	
	//右摇杆推上，右轮前进
	if(buf.right>110)
	{
		PWM_SetRightIN1(100,0);
		PWM_SetRightIN2(buf.right,buf.middle);
		LED_Green=0;
	}
	else if(buf.right<90)
	{
		
		PWM_SetRightIN1(buf.right,buf.middle);
		PWM_SetRightIN2(100,0);
		LED_Green=0;

	}
	else if(buf.right>=90&&buf.right<=110)
	{
		PWM_SetRightIN1(200,34);
		PWM_SetRightIN2(200,34);
		LED_Green=0;
	
	}
}
