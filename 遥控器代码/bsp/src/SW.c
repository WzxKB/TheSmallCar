#include "name.h"
#include "delay.h"

/**
  * @brief  检测SW1按下
  * @param	无
  * @retval	返回SW1
  */
u8 SW1_Down(void)
{
	Delay_ms(20);
	return ~SW1;

}

/**
  * @brief  检测SW1按下
  * @param	无
  * @retval	返回SW2
  */
u8 SW2_Down(void)
{
	Delay_ms(20);
	return ~SW2;

}