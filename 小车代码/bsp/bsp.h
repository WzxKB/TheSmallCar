#ifndef __BSP_H__
#define __BSP_H__

//�����⺯��
#include <STC8H.h>

//����ͷ�ļ�
#include "config.h"
#include "name.h"
#include "UART.h"
#include "delay.h"
#include "nrf.h"
#include "led.h"
#include "INT.h"
#include "pwm.h"
//������������
void BSP_Init(void);
#endif