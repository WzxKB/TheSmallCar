#include "bsp.h"

/**
  * @brief  ADC模块初始化
  * @param  CS 片选位,范围是0~2,0初始化P1.0;1初始化P1.1;2初始化P1.2
  * @retval 无
  */
void  BSP_ADC_Init(u8 CS)
{
	P1M0|=0x00;
	P1M1|=0x07;		//P1.0、P1.1、P1.2设为高阻输入,设为ADC口
	P_SW2=0x80;		//使用ADC需要将EAXFR位置1,使能PWM触发ADC功能
	ADC_CONTR=0x80|CS;	//开启ADC,使能P1.0、P1.1、P1.2口
	ADCTIM=0x3f;	//设置ADC内部时序
	P_SW2&=0x7f;	//EAFXR清零
	ADCCFG=0x2f;	//设置ADC时钟频率为系统时钟16分频,采用数据格式为右对齐
}

void ADC_Init()
{
	BSP_ADC_Init(0);
	BSP_ADC_Init(1);
	BSP_ADC_Init(2);
}
/**
  * @brief  ADC值读取
  * @param  CS 片选位,范围是0~2,0读取P1.0;1读取P1.1;2读取P1.2
  * @retval 无
  */
u16 ADC_Read(u8 CS)
{
	u16 adc_value;
	//ADC_Init();
	ADC_CONTR=0x80|CS;	//开启ADC,使能P1.0、P1.1、P1.2口
	Delay_ms(5);
	ADC_CONTR |= 0x40; //ADC开始转换
	_nop_();
	_nop_();
	while(!(ADC_CONTR&0x20));	//查询ADC完成标志
	ADC_CONTR &= ~0x20;	//清完成标志
	adc_value = ADC_RES;	//读取左边ADC结果
	adc_value <<= 8;	//左移8位
	adc_value |= 	ADC_RESL;	//读取ADC右边结果
	return adc_value;
}

/**
  * @brief 遥杆的封装函数,使用它可以获得三个遥杆的值 left 左摇杆 middle 中遥杆 right 右摇杆
  * @param	无
  * @retval	Analog_Stick 返回遥杆的结构体
  */
AnalogStick Analog_Stick(void)
{
	AnalogStick Analog_Stick;
	Analog_Stick.left=ADC_Read(2);
	Analog_Stick.middle=ADC_Read(1);
	Analog_Stick.right=ADC_Read(0);
	return Analog_Stick;
}

	


