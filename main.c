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

/******private parameter*********/
Uint16 OLED_count = 0;



void GPIO_Init();

void main()
{
    InitSysCtrl();
    DINT;           //Disable all the interrupts
    InitPieCtrl();
    IER = 0x0000;   //Disable CPU interrupts and clear all CPU interrupt flags
    IFR = 0x0000;
    InitPieVectTable();

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

/*
 *@brief:LED_Init
 *@param: BoardLED: GPIO17
 *@param: BuzzerIO: GPIO52
*/
void GPIO_Init()
{
    EALLOW;

    GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 0;    //Periphal as GPIO
    GpioCtrlRegs.GPADIR.bit.GPIO17 = 1;     // Set GPIO17 as output
    GpioCtrlRegs.GPAPUD.bit.GPIO17 = 1;     // DIsable pull-up for GPIO17

    //GPAMUX1:0-15 GPAMUX2:16-31 GPBMUX1:32-44 GPBMUX2:45-58
    EALLOW;
    GpioDataRegs.GPADAT.all = 0ul;// GPIOA DATA锟斤拷锟斤拷全锟斤拷0
    GpioDataRegs.GPBDAT.all = 0ul;// GPIOB DATA锟斤拷锟斤拷全锟斤拷0


    GpioCtrlRegs.GPBMUX2.bit.GPIO51 =   0;//key start
    GpioCtrlRegs.GPBDIR.bit.GPIO51  =   0;
    GpioCtrlRegs.GPBPUD.bit.GPIO51 = 1;

    GpioCtrlRegs.GPAMUX1.bit.GPIO12  =   0;// key end
    GpioCtrlRegs.GPADIR.bit.GPIO12   =   0;
    GpioDataRegs.GPACLEAR.bit.GPIO12=   1;

    GpioCtrlRegs.GPBMUX2.bit.GPIO50 =   0; //key1
    GpioCtrlRegs.GPBDIR.bit.GPIO50  =   0;
    GpioCtrlRegs.GPBPUD.bit.GPIO50 = 1;

    GpioCtrlRegs.GPAMUX2.bit.GPIO30 =   0;//key2
    GpioCtrlRegs.GPADIR.bit.GPIO30  =   0;
    GpioDataRegs.GPACLEAR.bit.GPIO30=   1;

    GpioCtrlRegs.GPAMUX2.bit.GPIO31 =   0;//key3
    GpioCtrlRegs.GPADIR.bit.GPIO31  =   0;
    GpioDataRegs.GPACLEAR.bit.GPIO31=   1;

    GpioCtrlRegs.GPAMUX2.bit.GPIO25 =   0;//key2
    GpioCtrlRegs.GPADIR.bit.GPIO25  =   0;
    GpioDataRegs.GPACLEAR.bit.GPIO25=   1;

    /***********************/
    //IO for Relay: 57 14 22 20
    //              13 24 23 21
    GpioCtrlRegs.GPBMUX2.bit.GPIO57  =   0; //RELAY1
    GpioCtrlRegs.GPBDIR.bit.GPIO57   =   1;
    GpioCtrlRegs.GPBPUD.bit.GPIO57 = 0;     //Enable Pull-up
    GpioDataRegs.GPBSET.bit.GPIO57=   1;
//    GpioDataRegs.GPBCLEAR.bit.GPIO57=   1;

    GpioCtrlRegs.GPAMUX1.bit.GPIO14 =   0;//RELAY2
    GpioCtrlRegs.GPADIR.bit.GPIO14  =   1;
    GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0;
    GpioDataRegs.GPASET.bit.GPIO14=1;

    GpioCtrlRegs.GPAMUX2.bit.GPIO22 =   0;//RELAY3
    GpioCtrlRegs.GPADIR.bit.GPIO22  =   1;
    GpioCtrlRegs.GPAPUD.bit.GPIO22 = 0;
    GpioDataRegs.GPASET.bit.GPIO22=1;

    GpioCtrlRegs.GPAMUX2.bit.GPIO20 =   0;//RELAY4
    GpioCtrlRegs.GPADIR.bit.GPIO20  =   1;
    GpioCtrlRegs.GPAPUD.bit.GPIO20 = 0;
    GpioDataRegs.GPASET.bit.GPIO20=1;

    //Buzzer: 55
    GpioCtrlRegs.GPBMUX2.bit.GPIO55 =   0;//Buzzer2
    GpioCtrlRegs.GPBDIR.bit.GPIO55  =   1;
    GpioCtrlRegs.GPBPUD.bit.GPIO55 = 1;
    GpioDataRegs.GPBCLEAR.bit.GPIO55=   1;


    GpioCtrlRegs.GPBMUX2.bit.GPIO52 =   0;//Buzzer1
    GpioCtrlRegs.GPBDIR.bit.GPIO52  =   1;
    GpioCtrlRegs.GPBPUD.bit.GPIO52 = 1;
    GpioDataRegs.GPBCLEAR.bit.GPIO52=   1;

    GpioCtrlRegs.GPACTRL.bit.QUALPRD1 = 0xFF;// Each sampling window is 510*SYSCLKOUT
    GpioCtrlRegs.GPACTRL.bit.QUALPRD2 = 0xFF;// Each sampling window is 510*SYSCLKOUT
    EDIS;

}


