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
#pragma CODE_SECTION(svgendq_calc, "ramfuncs")
#pragma CODE_SECTION(svpwm_2l_calc, "ramfuncs")
#pragma CODE_SECTION(rampgen_calc, "ramfuncs")

/************00.Private parameter Start*****************/
    Uint16 OLED_count = 0;  
    Uint16 Buzzer_count = 0;
    
    float svpwm_ua = 0;
    float svpwm_ub = 0;
    float svpwm_uc = 0;
    float udc = 1.0;

    float Uab_set = 0;
    float Ia_set = 0;
    
    float Uab_real = 0;
    float Vdc_real = 0;
    float Ia_real = 0;

    Uint16 Watch_count = 0;

    volatile float temp1[200] = {0};
    volatile float temp2[200] = {0};
    volatile float temp3[200] = {0}; 


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


/************02.Private Structure Init Start*****************/
    rampgen_vs.Umax = 1; //Vs = 2 / 3 * Vdc
    rampgen_vs.StepAngle =  2 * PI * BASE_FREQ * T;


    svpwm_2l.T1 = 1; //调制周期
    svpwm_2l.Udc = 1;
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

/*
 *@brief:
 *@note:  interrupt take 9000 clocks , equal to 10k ,0.1ms
 */
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

        svpwm_2l.Ualpha = rampgen_vs.U * cos(rampgen_vs.Angle);
        svpwm_2l.Ubeta = rampgen_vs.U * sin(rampgen_vs.Angle);
        svpwm_2l.Udc = udc;
        // svpwm_2l_calc(&svpwm_2l);
        svgendq_calc(&svpwm_2l);
        // my_svpwm_2l_calc(&svpwm_2l);
        svpwm_ua = svpwm_2l.Tcmpa * (EPWM1_TBPRD-1);
        svpwm_ub = svpwm_2l.Tcmpb * (EPWM1_TBPRD-1);
        svpwm_uc = svpwm_2l.Tcmpc * (EPWM1_TBPRD-1);

        // svpwm_ua = (svpwm_2l.Tcmpa + 1.0)*0.5*(EPWM1_TBPRD-1);
        // svpwm_ub = (svpwm_2l.Tcmpb + 1.0)*0.5*(EPWM1_TBPRD-1);
        // svpwm_uc = (svpwm_2l.Tcmpc + 1.0)*0.5*(EPWM1_TBPRD-1);

        // if(svpwm_ua > EPWM1_TBPRD) {svpwm_ua = EPWM1_TBPRD;}
        // if(svpwm_ua < 0) {svpwm_ua = 0;}
        // if(svpwm_ub > EPWM1_TBPRD) {svpwm_ub = EPWM1_TBPRD;}
        // if(svpwm_ub < 0) {svpwm_ub = 0;}
        // if(svpwm_uc > EPWM1_TBPRD) {svpwm_uc = EPWM1_TBPRD;}
        // if(svpwm_uc < 0) {svpwm_uc = 0;}

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

        if(Watch_count > 199) {Watch_count -= 200;}
        else {Watch_count++;}
        temp1[Watch_count] = svpwm_2l.Tcmpa;//svpwm_2l.Ualpha////svpwm_ua
        temp2[Watch_count] = svpwm_2l.Tcmpb;//svpwm_ub//svpwm_2l.Ubeta////
        temp3[Watch_count] = svpwm_2l.Tcmpc;//svpwm_uc////


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

