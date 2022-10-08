/**
  * @brief  延时函数
  * @param  pms 延时的毫秒数
  * @retval 无
  */
void Delay_ms(unsigned int pms)		//@11.0592MHz
{
	unsigned char i, j;
	while(pms--)
	{
		i = 15;
		j = 90;
		do
		{
			while (--j);
		} while (--i);
	}
}
