#include "bsp.h"


/**
  * @brief  ��ʼ����Ŀ
  * @param  ��
  * @retval ��
  */ 
  void BSP_Init(void)
  {
	  //��ʼ���˿�
		Port_Config();	
	  //��ʼ��ADC
		ADC_Init();
	  //��ʼ��UART����
		UART_Init();
		NRF_Init();		//���ų�ʼ��
  }