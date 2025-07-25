 /*
 * main.c
 *
 *  Created on: 2025-7-12
 *      Author: XU
 */

#include "DSP28x_Project.h"
#include "F2806x_MemCopy.h"
#include "hardware_config.h"

#include "OLED.h"
#include "bsp_key.h"
#include "MENU.h"
#include "user_svpwm_2l.h"
#include "rampgen.h"
#include "parameter.h"
#include "user_all_h_data.h"
#include "user_matrix_transform.h"
#include <math.h>
#include "epwm.h"
#pragma CODE_SECTION(Adc_ISR, "ramfuncs")

/************00.Private parameter Start*****************/
    Uint16 OLED_count = 0;  
    Uint16 Buzzer_count = 0;
    
    float svpwm_ua = 0;
    float svpwm_ub = 0;
    float svpwm_uc = 0;
    float udc = 0;

    float Uab_set = 0;
    float Ia_set = 0;
    
    float Uab_real = 0;
    float Vdc_real = 0;
    float Ia_real = 0;
/************00.Private parameter End*****************/

/************01.Private Flag End*****************/
    Uint8 RUN_Flag = 0; //运行标志位
    Uint8 Stop_Flag =1;
    Uint8 Buzzer_Flag = 0;
    Uint8 Mode = 0; //0: Grid-tied, 1: Off-grid
/************01.Private Flag End*****************/


/************02.Private Structure Start*****************/
SVPWM_2L svpwm_2l = SVPWM_2L_DEFAULTS;

RAMPGEN rampgen_vs = RAMPGEN_DEFAULTS;

type_default grid_voltage = {0, 0, 0, 0, 0, 0, 0, 0};
/************02.Private Structure End*****************/

/******private function*********/

/******private parameter*********/

interrupt void Adc_ISR(void);


void GPIO_Init();

void main()
{
    InitSysCtrl();
    DINT;           //Disable all the interrupts
    InitPieCtrl();
    IER = 0x0000;   //Disable CPU interrupts and clear all CPU interrupt flags
    IFR = 0x0000;
    InitPieVectTable();

    EALLOW;
    PieVectTable.ADCINT1 = &Adc_ISR;//AD中断函数向量定义
    EDIS;

    #ifdef _FLASHOK
    MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);
    InitFlash();
    #endif
    Hardware_Config();

    svpwm_2l.T1 = 0.00005; //调制周期
    svpwm_2l.Udc = 20;
/************02.Private Structure Init Start*****************/
    rampgen_vs.Umax = 20; //Vs = 2 / 3 * Vdc

/************02.Private Structure Init End*****************/





    while(1)
    {
        g_Button = Key_Scan(); 
        if(g_Button)
        {
            Buzzer_Flag = 1;
            GpioDataRegs.GPBSET.bit.GPIO52 = 1;
        }
        if(Buzzer_Flag == 1)
        {
            Buzzer_count++;
            if(Buzzer_count > 1000) //1s
            {
                Buzzer_count = 0;
                Buzzer_Flag = 0;
                GpioDataRegs.GPBCLEAR.bit.GPIO52 = 1;
            }
        }
        MENU_Item_KEY();
        if(OLED_count > 60000)  {OLED_count = 1;}
        else    {OLED_count++;}
        if(OLED_count == 1)
        {
            OLED_Display(Menu_Item);
            OLED_Refresh();
        }

    }

}


interrupt void Adc_ISR(void)
{
    if(AdcRegs.ADCINTFLG.bit.ADCINT1)
    {


        /*adc sample*/
        //1.line voltage vab、vbc
        //2.DC voltage vdc
        //3.line current ia、ib

/************01.Grid connection Begin**************/
        //abc -> alpha-beta



        //alpha-beta -> d-q


        //svpwm cal


        //PLL+PI


/************01.Grid connection End**************/

/************02.Grid Off Begin**************/
        rampgen_calc(&rampgen_vs);
        svpwm_2l.Ualpha = rampgen_vs.Sine * cos(rampgen_vs.Angle);
        svpwm_2l.Ubeta = rampgen_vs.Sine * sin(rampgen_vs.Angle);
        svpwm_2l.Udc = udc;
        svpwm_2l_calc(&svpwm_2l);

        svpwm_ua = (svpwm_2l.Tcmpa+1)*0.5*(EPWM1_TBPRD-1);
        svpwm_ub = (svpwm_2l.Tcmpb+1)*0.5*(EPWM1_TBPRD-1);
        svpwm_uc = (svpwm_2l.Tcmpc+1)*0.5*(EPWM1_TBPRD-1);

        if(svpwm_ua > EPWM1_TBPRD) {svpwm_ua = EPWM1_TBPRD;}
        if(svpwm_ub > EPWM1_TBPRD) {svpwm_ub = EPWM1_TBPRD;}
        if(svpwm_uc > EPWM1_TBPRD) {svpwm_uc = EPWM1_TBPRD;}

        if(RUN_Flag == 1)
        {
            PWM_EN();
            EPwm1Regs.CMPA.half.CMPA = (unsigned short)(svpwm_ua);//(0.
            EPwm2Regs.CMPA.half.CMPA = (unsigned short)(svpwm_ub);
            EPwm3Regs.CMPA.half.CMPA = (unsigned short)(svpwm_uc);
        }
        else
        {
            PWM_Dis();
        }

        // Clarke_Marco(&grid_voltage);

        //1.Generate ud、uq

        //2.ud、uq -> alpha-beta

        //3.alpha-beta -> abc

        //4.abc -> SVPWM


/************02.Grid Off End**************/



        AdcRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;       //Clear ADCINT1 flag reinitialize for next SOC
        PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;     // Acknowledge interrupt to PIE
        return;
    }
}

