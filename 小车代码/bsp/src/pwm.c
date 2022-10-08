#include <stc8h.h>
#include "name.h"
#include <math.h>
#include <bsp.h>

/**
  * @brief  PWM��ʼ��������P1.7 P5.4 1.0 1.6������Ϊ100
  * @param	��
  * @retval	��
  */
void PWM_Init(void)
{
	P_SW2 = 0x80;		//���蹦�ܽ��л�
	PWMB_PS=0x05;		//���ܽ��л����л�P1.7 P5.4��1.0 1.6Ĭ�ϲ����л�
	/*****����P1.0��      PWMA1P****/
	PWMA_CCER1 = 0x00;                          //CCER����֮ǰ������
  PWMA_CCMR1 = 0x60;                       		//����Ƚ�		PWMA1P	
  PWMA_CCER1 = 0x01;  												//����Ƚ�ʹ�� PWMA_1P

	/*****����P1.6��			PWMA4P****/	
  PWMA_CCER2 = 0x00;                          //CCER����֮ǰ������
  PWMA_CCMR4 = 0x60;													//����Ƚ�		PWMA4P		 
  PWMA_CCER2 = 0x10;  												//����Ƚ�ʹ�� PWMA4P

	/*****����P1.7��			PWMB5_2****/	
	PWMB_CCER1 = 0x00;                          //CCER����֮ǰ������
  PWMB_CCMR1 = 0x60;                          //����Ƚ�		PWMB5_2		 
  PWMB_CCER1 = 0x11;                          //����Ƚ�ʹ�� PWMB5_2 PWMB6_2
	
	/*****����P5.4��			PWMB6_2****/	
	
  PWMB_CCMR2 = 0x60;                          //����Ƚ�		PWMB5_2		 
  
	PWMA_ENO = 0x41;                            //ʹ�� PWMA1P	PWMA4P
	PWMB_ENO = 0x05;                          	//ʹ�� PWMB5_2 PWMB5_2
	PWMA_BKR = 0x80;														//ɲ���Ĵ���
	PWMB_BKR = 0x80;                            
  PWMA_CR1 = 0x01;														//PWMA��ʼ����
	PWMB_CR1 = 0x01;														//PWMB��ʼ����
	
	PWMA_ARR = 100; 
	PWMB_ARR = 100;
	
		
}

/**
  * @brief  ����С�����8236IN1��PWM
  * @param	value ��ҡ��adֵ speed ��ҡ��adֵ
  * @retval	��
  */
void PWM_SetLeftIN1 (u8 value,u8 speed)
{
	//IN1_Left ��PWMֵ = (��ҡ�˵�ֵ-100�ľ���ֵ) * ��ҡ�˵�ֵ/100
	PWMA_CCR1 = abs(value-100)*((float)speed/100+0.66);
	
}

/**
  * @brief  ����С�����8236IN2��PWM
  * @param	value ��ҡ��adֵ speed ��ҡ��adֵ
  * @retval	��
  */
void PWM_SetLeftIN2(u8 value, u8 speed)
 {
	//IN2_Left ��PWMֵ = (��ҡ�˵�ֵ-100�ľ���ֵ) * ��ҡ�˵�ֵ/100
	PWMA_CCR4 =abs(value-100)*((float)speed/100+0.66);
}

/**
  * @brief  ����С���Ҳ�8236IN1��PWM
  * @param	value ��ҡ��adֵ speed ��ҡ��adֵ
  * @retval	��
  */
void PWM_SetRightIN1(u8 value,u8 speed)
{
	//IN1_Right ��PWMֵ = (��ҡ�˵�ֵ-100�ľ���ֵ) * ��ҡ�˵�ֵ/100
	PWMB_CCR5 = abs(value-100)*((float)speed/100+0.66);
}
/**
  * @brief  ����С���Ҳ�8236IN2��PWM
  * @param	value ��ҡ��adֵ speed ��ҡ��adֵ
  * @retval	��
  */
void PWM_SetRightIN2(u8 value,u8 speed)
{
	//IN2_Right ��PWMֵ = (��ҡ�˵�ֵ-100�ľ���ֵ) * ��ҡ�˵�ֵ/100
	PWMB_CCR6 = abs(value-100)*((float)speed/100+0.66);
}






