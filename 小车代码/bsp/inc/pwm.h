#ifndef __PWM_H__
#define __PWM_H__
void PWM_Init(void);
void PWM_SetLeftIN1 (u8 value,u8 speed);
void PWM_SetLeftIN2 (u8 value ,u8 speed);
void PWM_SetRightIN1 (u8 value,u8 speed);
void PWM_SetRightIN2 (u8 value,u8 speed);
#endif