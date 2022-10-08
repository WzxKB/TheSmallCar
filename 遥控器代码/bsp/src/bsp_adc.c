#include "bsp.h"

/**
  * @brief  ADCģ���ʼ��
  * @param  CS Ƭѡλ,��Χ��0~2,0��ʼ��P1.0;1��ʼ��P1.1;2��ʼ��P1.2
  * @retval ��
  */
void  BSP_ADC_Init(u8 CS)
{
	P1M0|=0x00;
	P1M1|=0x07;		//P1.0��P1.1��P1.2��Ϊ��������,��ΪADC��
	P_SW2=0x80;		//ʹ��ADC��Ҫ��EAXFRλ��1,ʹ��PWM����ADC����
	ADC_CONTR=0x80|CS;	//����ADC,ʹ��P1.0��P1.1��P1.2��
	ADCTIM=0x3f;	//����ADC�ڲ�ʱ��
	P_SW2&=0x7f;	//EAFXR����
	ADCCFG=0x2f;	//����ADCʱ��Ƶ��Ϊϵͳʱ��16��Ƶ,�������ݸ�ʽΪ�Ҷ���
}

void ADC_Init()
{
	BSP_ADC_Init(0);
	BSP_ADC_Init(1);
	BSP_ADC_Init(2);
}
/**
  * @brief  ADCֵ��ȡ
  * @param  CS Ƭѡλ,��Χ��0~2,0��ȡP1.0;1��ȡP1.1;2��ȡP1.2
  * @retval ��
  */
u16 ADC_Read(u8 CS)
{
	u16 adc_value;
	//ADC_Init();
	ADC_CONTR=0x80|CS;	//����ADC,ʹ��P1.0��P1.1��P1.2��
	Delay_ms(5);
	ADC_CONTR |= 0x40; //ADC��ʼת��
	_nop_();
	_nop_();
	while(!(ADC_CONTR&0x20));	//��ѯADC��ɱ�־
	ADC_CONTR &= ~0x20;	//����ɱ�־
	adc_value = ADC_RES;	//��ȡ���ADC���
	adc_value <<= 8;	//����8λ
	adc_value |= 	ADC_RESL;	//��ȡADC�ұ߽��
	return adc_value;
}

/**
  * @brief ң�˵ķ�װ����,ʹ�������Ի������ң�˵�ֵ left ��ҡ�� middle ��ң�� right ��ҡ��
  * @param	��
  * @retval	Analog_Stick ����ң�˵Ľṹ��
  */
AnalogStick Analog_Stick(void)
{
	AnalogStick Analog_Stick;
	Analog_Stick.left=ADC_Read(2);
	Analog_Stick.middle=ADC_Read(1);
	Analog_Stick.right=ADC_Read(0);
	return Analog_Stick;
}

	


