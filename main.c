 /*
 * main.c
 *
 *  Created on: 2025-7-12
 *      Author: XU
 */

#include "DSP28x_Project.h"
#include "F2806x_MemCopy.h"
#include "OLED.h"
#include "bsp_key.h"
#include "MENU.h"
#include "hardware_config.h"
#include "user_svpwm_2l.h"
#include "rampgen.h"
#include "parameter.h"

/************00.Private parameter Start*****************/
    float svpwm_ua = 0;
    float svpwm_ub = 0;
    float svpwm_uc = 0;
    float udc = 0;
/************00.Private parameter End*****************/

/************01.Private Flag End*****************/
    Uint8 Run_Flag = 0; //运行标志位
    Uint8 Stop_Flag =1;

/************01.Private Flag End*****************/


/************02.Private Structure Start*****************/
SVPWM_2L svpwm_2l = SVPWM_2L_DEFAULTS;

RAMPGEN rampgen1 = RAMPGEN_DEFAULTS;
RAMPGEN rampgen2 = RAMPGEN_DEFAULTS;
RAMPGEN rampgen3 = RAMPGEN_DEFAULTS;


/************02.Private Structure End*****************/


#define _FLASHOK 1

/******private function*********/
#pragma CODE_SECTION(Adc_ISR, "ramfuncs")

/******private parameter*********/
Uint16 OLED_count = 0;

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

    Hardware_Config();
    #ifdef _FLASHOK
    MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);
    InitFlash();
    #endif

/************02.Private Structure Init Start*****************/
    rampgen1.Angle = 0;
    rampgen2.Angle = 0.333 * PI; //120 degrees
    rampgen3.Angle = 0.666 * PI; //240 degrees

/************02.Private Structure Init End*****************/




    OLED_Refresh();
    OLED_Clear();
//    OLED_ShowString(0,0,"Uab:",16,1);
//    OLED_ShowString(0,16,"Udc:",16,1);
//    OLED_ShowString(0,32,"Iab:",16,1);
    OLED_Refresh();
    DELAY_US(1);


    while(1)
    {
        g_Button = Key_Scan(); 
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
        rampgen_calc(&rampgen1);
        rampgen_calc(&rampgen2);
        rampgen_calc(&rampgen3);
        //1.Generate ud、uq

        //2.ud、uq -> alpha-beta

        //3.alpha-beta -> abc

        //4.abc -> SVPWM
        svpwm_2l.Ualpha = svpwm_ua;
        svpwm_2l.Ubeta = svpwm_ub;
        svpwm_2l.Udc = udc;

/************02.Grid Off End**************/




}

