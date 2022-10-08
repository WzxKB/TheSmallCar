#ifndef __NAME_H__
#define __NAME_H__
#include <STC8G.H>
/******定义名*******/
sbit LED_LightGreen = P3^4;
sbit LED_Red = P3^5;

sbit SW1=P3^6;
sbit SW2=P3^3;

sbit CE =  P1^6;
sbit CSN=  P5^4;
sbit SCK=  P1^5;
sbit MOSI= P1^3;
sbit MISO= P1^4;
sbit IRQ = P3^2;

typedef unsigned char u8;
typedef unsigned int u16;



/******定义结构体*******/
typedef struct {
	unsigned int left;
	unsigned int middle;
	unsigned int right ;
}AnalogStick;


typedef struct
{
	u8 sw1;
	u8 sw2;
	u16 left;
	u16 middle;
	u16 right;
}BUF;



#endif  