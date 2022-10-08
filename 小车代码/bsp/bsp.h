#ifndef __BSP_H__
#define __BSP_H__

//包含库函数
#include <STC8H.h>

//包含头文件
#include "config.h"
#include "name.h"
#include "UART.h"
#include "delay.h"
#include "nrf.h"
#include "led.h"
#include "INT.h"
#include "pwm.h"
//包含函数声明
void BSP_Init(void);
#endif