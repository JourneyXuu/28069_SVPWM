#ifndef __EPWM_H__
#define __EPWM_H__


#include "DSP28x_Project.h"

#define FREQUENCY   (10000)//PWM开关频率 10K
#define EPWM1_TBPRD   ( (90000000/FREQUENCY/2) - 1)//PWM设置最大计数值 1000-1 2250

void Master_EPWM_Init(void);
void Slave_EPWM_Init(volatile struct EPWM_REGS* EPWM_Str);

void Master_EPWM_Init(void);
void Slave_EPWM_Init(volatile struct EPWM_REGS* EPWM_Str);
void PWM_EN(void);
void PWM_Dis(void);

#endif // !








