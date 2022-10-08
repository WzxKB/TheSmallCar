#include<STC8G.h>

/**
  * @brief  初始化IO端口,设置输出输入模式
  * @param  无
  * @retval 无
  */
void Port_Config(void)
{
	//P1.0、P1.1、P1.2设为高阻输入（监听遥杆）
	P1M1=0x07;
	P1M0=0x00;
	
	P2M1=0x00;
	P2M0=0x00;
	
	//P3.4 P3.5设为推挽输出（点亮灯泡）3.3  P3.6设为高阻输入（监听开关）
	P3M1=0x14;
	P3M0=0x18;
	
	P4M1=0x00;
	P4M0=0x00;
	
	P5M1=0x00;
	P5M0=0x00;

}