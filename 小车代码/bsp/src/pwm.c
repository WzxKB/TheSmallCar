#include <stc8h.h>
#include "name.h"
#include <math.h>
#include <bsp.h>

/**
  * @brief  PWM初始化，开启P1.7 P5.4 1.0 1.6，周期为100
  * @param	无
  * @retval	无
  */
void PWM_Init(void)
{
	P_SW2 = 0x80;		//外设功能脚切换
	PWMB_PS=0x05;		//功能脚切换，切换P1.7 P5.4，1.0 1.6默认不用切换
	/*****开启P1.0脚      PWMA1P****/
	PWMA_CCER1 = 0x00;                          //CCER设置之前先清零
  PWMA_CCMR1 = 0x60;                       		//捕获比较		PWMA1P	
  PWMA_CCER1 = 0x01;  												//捕获比较使能 PWMA_1P

	/*****开启P1.6脚			PWMA4P****/	
  PWMA_CCER2 = 0x00;                          //CCER设置之前先清零
  PWMA_CCMR4 = 0x60;													//捕获比较		PWMA4P		 
  PWMA_CCER2 = 0x10;  												//捕获比较使能 PWMA4P

	/*****开启P1.7脚			PWMB5_2****/	
	PWMB_CCER1 = 0x00;                          //CCER设置之前先清零
  PWMB_CCMR1 = 0x60;                          //捕获比较		PWMB5_2		 
  PWMB_CCER1 = 0x11;                          //捕获比较使能 PWMB5_2 PWMB6_2
	
	/*****开启P5.4脚			PWMB6_2****/	
	
  PWMB_CCMR2 = 0x60;                          //捕获比较		PWMB5_2		 
  
	PWMA_ENO = 0x41;                            //使能 PWMA1P	PWMA4P
	PWMB_ENO = 0x05;                          	//使能 PWMB5_2 PWMB5_2
	PWMA_BKR = 0x80;														//刹车寄存器
	PWMB_BKR = 0x80;                            
  PWMA_CR1 = 0x01;														//PWMA开始计数
	PWMB_CR1 = 0x01;														//PWMB开始计数
	
	PWMA_ARR = 100; 
	PWMB_ARR = 100;
	
		
}

/**
  * @brief  设置小车左侧8236IN1的PWM
  * @param	value 左摇杆ad值 speed 中摇杆ad值
  * @retval	无
  */
void PWM_SetLeftIN1 (u8 value,u8 speed)
{
	//IN1_Left 的PWM值 = (左摇杆的值-100的绝对值) * 中摇杆的值/100
	PWMA_CCR1 = abs(value-100)*((float)speed/100+0.66);
	
}

/**
  * @brief  设置小车左侧8236IN2的PWM
  * @param	value 左摇杆ad值 speed 中摇杆ad值
  * @retval	无
  */
void PWM_SetLeftIN2(u8 value, u8 speed)
 {
	//IN2_Left 的PWM值 = (左摇杆的值-100的绝对值) * 中摇杆的值/100
	PWMA_CCR4 =abs(value-100)*((float)speed/100+0.66);
}

/**
  * @brief  设置小车右侧8236IN1的PWM
  * @param	value 左摇杆ad值 speed 中摇杆ad值
  * @retval	无
  */
void PWM_SetRightIN1(u8 value,u8 speed)
{
	//IN1_Right 的PWM值 = (右摇杆的值-100的绝对值) * 中摇杆的值/100
	PWMB_CCR5 = abs(value-100)*((float)speed/100+0.66);
}
/**
  * @brief  设置小车右侧8236IN2的PWM
  * @param	value 左摇杆ad值 speed 中摇杆ad值
  * @retval	无
  */
void PWM_SetRightIN2(u8 value,u8 speed)
{
	//IN2_Right 的PWM值 = (右摇杆的值-100的绝对值) * 中摇杆的值/100
	PWMB_CCR6 = abs(value-100)*((float)speed/100+0.66);
}






