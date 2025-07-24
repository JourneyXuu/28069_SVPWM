#include "gpio.h"

void GPIO_Init()
{
    //GPAMUX1:0-15 GPAMUX2:16-31 GPBMUX1:32-44 GPBMUX2:45-58
    EALLOW;
    GpioDataRegs.GPADAT.all = 0ul;// GPIOA DATA数据全清0
    GpioDataRegs.GPBDAT.all = 0ul;// GPIOB DATA数据全清0

    GpioCtrlRegs.GPBMUX2.bit.GPIO51 =   0;//key start
    GpioCtrlRegs.GPBDIR.bit.GPIO51  =   0;
    GpioCtrlRegs.GPBPUD.bit.GPIO51 =    1;

    GpioCtrlRegs.GPAMUX1.bit.GPIO12  =   0;// key end
    GpioCtrlRegs.GPADIR.bit.GPIO12   =   0;
    GpioDataRegs.GPACLEAR.bit.GPIO12 =   1;

    GpioCtrlRegs.GPBMUX2.bit.GPIO50 =   0; //key1
    GpioCtrlRegs.GPBDIR.bit.GPIO50  =   0;
    GpioCtrlRegs.GPBPUD.bit.GPIO50  =   1;

    GpioCtrlRegs.GPAMUX2.bit.GPIO30 =   0;//key2
    GpioCtrlRegs.GPADIR.bit.GPIO30  =   0;
    GpioDataRegs.GPACLEAR.bit.GPIO30=   1;

    GpioCtrlRegs.GPAMUX2.bit.GPIO31 =   0;//key3
    GpioCtrlRegs.GPADIR.bit.GPIO31  =   0;
    GpioDataRegs.GPACLEAR.bit.GPIO31=   1;

    GpioCtrlRegs.GPAMUX2.bit.GPIO25 =   0;//key24
    GpioCtrlRegs.GPADIR.bit.GPIO25  =   0;
    GpioDataRegs.GPACLEAR.bit.GPIO25=   1;

    /***********************/
    //IO for Relay: 57 14 22 20
    //              13 24 23 21
    //Relay is a convert signal, so it is set to 1 by default.
    GpioCtrlRegs.GPBMUX2.bit.GPIO57  =   0; //RELAY1
    GpioCtrlRegs.GPBDIR.bit.GPIO57   =   1;
    GpioCtrlRegs.GPBPUD.bit.GPIO57   =   0;     //Enable Pull-up
    GpioDataRegs.GPBSET.bit.GPIO57   =   1;
//    GpioDataRegs.GPBCLEAR.bit.GPIO57=   1;

    GpioCtrlRegs.GPAMUX1.bit.GPIO14 =   0;//RELAY2
    GpioCtrlRegs.GPADIR.bit.GPIO14  =   1;
    GpioCtrlRegs.GPAPUD.bit.GPIO14  =   0;
    GpioDataRegs.GPASET.bit.GPIO14  =   1;

    GpioCtrlRegs.GPAMUX2.bit.GPIO22 =   0;//RELAY3
    GpioCtrlRegs.GPADIR.bit.GPIO22  =   1;
    GpioCtrlRegs.GPAPUD.bit.GPIO22  =   0;
    GpioDataRegs.GPASET.bit.GPIO22  =   1;

    GpioCtrlRegs.GPAMUX2.bit.GPIO20 =   0;//RELAY4
    GpioCtrlRegs.GPADIR.bit.GPIO20  =   1;
    GpioCtrlRegs.GPAPUD.bit.GPIO20  =   0;
    GpioDataRegs.GPASET.bit.GPIO20  =   1;

    //Buzzer: 55
    GpioCtrlRegs.GPBMUX2.bit.GPIO55 =   0;//Buzzer2
    GpioCtrlRegs.GPBDIR.bit.GPIO55  =   1;
    GpioCtrlRegs.GPBPUD.bit.GPIO55  =   1;
    GpioDataRegs.GPBCLEAR.bit.GPIO55=   1;

    GpioCtrlRegs.GPBMUX2.bit.GPIO52 =   0;//Buzzer1
    GpioCtrlRegs.GPBDIR.bit.GPIO52  =   1;
    GpioCtrlRegs.GPBPUD.bit.GPIO52  =   1;
    GpioDataRegs.GPBCLEAR.bit.GPIO52=   1;

    GpioCtrlRegs.GPACTRL.bit.QUALPRD1 = 0xFF;// Each sampling window is 510*SYSCLKOUT
    GpioCtrlRegs.GPACTRL.bit.QUALPRD2 = 0xFF;// Each sampling window is 510*SYSCLKOUT

    //PWM-Disable
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 =   0;//EPWM1A
    GpioCtrlRegs.GPADIR.bit.GPIO0  =   1;
    GpioDataRegs.GPACLEAR.bit.GPIO0=   1;
    GpioCtrlRegs.GPAPUD.bit.GPIO0  =   1;

    GpioCtrlRegs.GPAMUX1.bit.GPIO1 =   0;//EPWM1B
    GpioCtrlRegs.GPADIR.bit.GPIO1  =   1;
    GpioDataRegs.GPACLEAR.bit.GPIO1=   1;
    GpioCtrlRegs.GPAPUD.bit.GPIO1  =   1;

    GpioCtrlRegs.GPAMUX1.bit.GPIO2 =   0;//EPWM2A
    GpioCtrlRegs.GPADIR.bit.GPIO2  =   1;
    GpioDataRegs.GPACLEAR.bit.GPIO2=   1;
    GpioCtrlRegs.GPAPUD.bit.GPIO2  =   1;

    GpioCtrlRegs.GPAMUX1.bit.GPIO3 =   0;//EPWM2B
    GpioCtrlRegs.GPADIR.bit.GPIO3  =   1;
    GpioDataRegs.GPACLEAR.bit.GPIO3=   1;
    GpioCtrlRegs.GPAPUD.bit.GPIO3  =   1;

    GpioCtrlRegs.GPAMUX1.bit.GPIO3 =   0;//EPWM3A
    GpioCtrlRegs.GPADIR.bit.GPIO3  =   1;
    GpioDataRegs.GPACLEAR.bit.GPIO3=   1;
    GpioCtrlRegs.GPAPUD.bit.GPIO3  =   1;

    GpioCtrlRegs.GPAMUX1.bit.GPIO4 =   0;//EPWM3B
    GpioCtrlRegs.GPADIR.bit.GPIO4  =   1;
    GpioDataRegs.GPACLEAR.bit.GPIO4=   1;
    GpioCtrlRegs.GPAPUD.bit.GPIO4  =   1;

    /*AD引脚*/
    //GpioCtrlRegs.AIOMUX1.bit.AIO2 = 2;//A2预留
    GpioCtrlRegs.AIOMUX1.bit.AIO4 = 2;//A4
    GpioCtrlRegs.AIOMUX1.bit.AIO6 = 2;//A6
    GpioCtrlRegs.AIOMUX1.bit.AIO10 = 2;//B2
    GpioCtrlRegs.AIOMUX1.bit.AIO12 = 2;//B4
    GpioCtrlRegs.AIOMUX1.bit.AIO14 = 2;//B6

    XIntruptRegs.XINT1CR.bit.ENABLE = 0;// Enable XINT1
    XIntruptRegs.XINT2CR.bit.ENABLE = 0;// Enable XINT2

    EDIS;

}

