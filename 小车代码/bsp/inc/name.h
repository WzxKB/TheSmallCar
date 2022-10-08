#ifndef __NAME_H__
#define __NAME_H__
#include <stc8h.h>

typedef unsigned char u8;
typedef unsigned int u16;

/******定义名*******/
sbit LED_Red = P1^1;
sbit LED_Green = P1^2;
sbit LED_LightGreen = P5^5;

sbit CE =  P3^5;
sbit CSN=  P3^6;
sbit SCK=  P3^2;
sbit MOSI= P3^4;
sbit MISO= P3^3;
sbit IRQ = P3^7;


/******定义结构体******/
typedef struct
{
	u8 sw1;
	u8 sw2;
	u16 left;
	u16 middle;
	u16 right;
}BUF;

//遥杆上面的临界点，此值往上则前进
#define ROC_UP 110
//摇杆下面的临界点，此值往下则倒退
#define ROC_DOWN 90

#endif