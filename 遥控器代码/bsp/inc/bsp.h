#ifndef __BSP_H__
#define __BSP_H__

//包含库函数
#include <STC8G.h>
#include <INTRINS.H>

//包含头文件
#include "config.h"
#include "name.h"
#include "bsp_adc.h"
#include "UART.h"
#include "delay.h"
#include "nrf.h"
#include "SW.h"
#include "LED.h"

//包含函数声明
void BSP_Init(void);
#endif