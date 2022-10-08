#include "name.h"
#include "delay.h"

/**
  * @brief  ���SW1����
  * @param	��
  * @retval	����SW1
  */
u8 SW1_Down(void)
{
	Delay_ms(20);
	return ~SW1;

}

/**
  * @brief  ���SW1����
  * @param	��
  * @retval	����SW2
  */
u8 SW2_Down(void)
{
	Delay_ms(20);
	return ~SW2;

}