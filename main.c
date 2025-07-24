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

    #ifdef _FLASHOK
    MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);
    InitFlash();
    #endif

    GPIO_Init();
    OLED_Init();
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



















}

