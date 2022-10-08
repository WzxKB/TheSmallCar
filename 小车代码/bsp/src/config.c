#include<STC8H.h>

void Port_Config(void)
{
	//P1.1 P1.2设为推挽输出
	P1M1=0x00;
	P1M0=0x03;
	
	P2M1=0x00;
	P2M0=0x00;
	
	//P3.7设为高阻输入
	P3M1=0x80;
	P3M0=0x00;
	
	P4M1=0x00;
	P4M0=0x00;
	
	
	//P5.5设为推挽输出
	P5M1=0x00;
	P5M0=0x10;
}