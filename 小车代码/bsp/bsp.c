#include "bsp.h"

/**
  * @brief  初始化项目
  * @param  无
  * @retval 无
  */ 
  void BSP_Init(void)
  {
		Port_Config();
		//初始化UART串口
		UART_Init();
		NRF_Init();
		INT3_Init();
		//初始化PWM
		PWM_Init();
  }