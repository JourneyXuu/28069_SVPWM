#include "hardware_config.h"
#include "gpio.h"
#include "epwm.h"
void Hardware_Config(void)
{
    GPIO_Init();
    Master_EPWM_Init();        //EPWM1
    Slave_EPWM_Init(&EPwm2Regs);//EPWM2
    Slave_EPWM_Init(&EPwm3Regs);//EPWM3 


    
}























