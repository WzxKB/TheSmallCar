/**
  * @brief  ��ʱ����
  * @param  pms ��ʱ�ĺ�����
  * @retval ��
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
