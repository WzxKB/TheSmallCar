#include<STC8H.h>

void Port_Config(void)
{
	//P1.1 P1.2��Ϊ�������
	P1M1=0x00;
	P1M0=0x03;
	
	P2M1=0x00;
	P2M0=0x00;
	
	//P3.7��Ϊ��������
	P3M1=0x80;
	P3M0=0x00;
	
	P4M1=0x00;
	P4M0=0x00;
	
	
	//P5.5��Ϊ�������
	P5M1=0x00;
	P5M0=0x10;
}