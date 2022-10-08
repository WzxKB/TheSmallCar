#include <STC8H.h>
#include "bsp.h"




/**
  * @brief  UART串口通信初始化
  * @param	无
  * @retval	无
  */
void UART_Init()
{
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x01;		//串口1选择定时器2为波特率发生器
	AUXR |= 0x04;		//定时器时钟1T模式
	T2L = 0xE8;		//设置定时初始值
	T2H = 0xFF;		//设置定时初始值
	AUXR |= 0x10;		//定时器2开始计时
}

/**
  * @brief 串口发送数据 
  * @param	Byte,发送的数据
  * @retval
  */
void UART_Send(int dat)
{
//	while(busy);
//	busy=1;
	SBUF=dat;
	while(TI==0);	//判断数据有没有发送完
	TI=1;
}
