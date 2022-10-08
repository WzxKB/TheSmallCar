#include "bsp.h"


/**
  * @brief  初始化项目
  * @param  无
  * @retval 无
  */ 
  void BSP_Init(void)
  {
	  //初始化端口
		Port_Config();	
	  //初始化ADC
		ADC_Init();
	  //初始化UART串口
		UART_Init();
		NRF_Init();		//引脚初始化
  }