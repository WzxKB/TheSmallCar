#ifndef __BSP_H__
#define __BSP_H__

//�����⺯��
#include <STC8G.h>
#include <INTRINS.H>

//����ͷ�ļ�
#include "config.h"
#include "name.h"
#include "bsp_adc.h"
#include "UART.h"
#include "delay.h"
#include "nrf.h"
#include "SW.h"
#include "LED.h"

//������������
void BSP_Init(void);
#endif