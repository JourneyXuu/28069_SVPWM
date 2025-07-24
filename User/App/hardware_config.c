#include "hardware_config.h"
#include "gpio.h"
#include "epwm.h"
#include "adc.h"

void Hardware_Config(void)
{
    GPIO_Init();
    Master_EPWM_Init();        //EPWM1
    Slave_EPWM_Init(&EPwm2Regs);//EPWM2
    Slave_EPWM_Init(&EPwm3Regs);//EPWM3 

    ADC_Trig_Init();
    ADC_Init();

    PieCtrlRegs.PIEIER1.bit.INTx1 = 1;   // Enable ADC EOC interrupt (INT1.1)
    IER |= M_INT1;                       // Enable CPU interrupt INT1
    PieCtrlRegs.PIEACK.all = 0xFFFF;     // Acknowledge all PIE interrupts to clear any pending flags
    // Note: Other interrupts like Timer 0 or INT13 are not enabled in this configuration
    EINT;
    ERTM;

    /* Start CPU Timer 0 and Timer 1 */
    CpuTimer0Regs.TCR.bit.TSS = 0;
    CpuTimer1Regs.TCR.bit.TSS = 0;
    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;
    EDIS;

}























