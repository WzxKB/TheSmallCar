#include "bsp.h"

/**
  * @brief  ��ʼ����Ŀ
  * @param  ��
  * @retval ��
  */ 
  void BSP_Init(void)
  {
		Port_Config();
		/*��ʼ��UART����*/
		UART_Init();
		/*��ʼ��NRF*/
		NRF_Init();
		INT3_Init();
		/*��ʼ��PWM*/
		PWM_Init();
  }