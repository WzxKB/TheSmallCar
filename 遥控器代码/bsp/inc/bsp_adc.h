#ifndef __BSP_ADC_H__
#define __BSP_ADC_H__

#include "name.h"

void BSP_ADC_Init(u8 CS);
void ADC_Init();
u16 ADC_Read(u8 CS);
AnalogStick Analog_Stick(void);

#endif