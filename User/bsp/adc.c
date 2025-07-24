#include "adc.h"
void ADC_Init(void)
{
    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;
    (*Device_cal)();
    EDIS;

    EALLOW;
    //此处采用 顺序采集
    AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1;//产生AD结果后产生中断
    AdcRegs.ADCCTL2.bit.ADCNONOVERLAP = 1;// ADC 采集数据允许倍覆盖；
    AdcRegs.ADCCTL2.bit.CLKDIV2EN=0;// ADCCLK = SYSCLKOUT(60Mhz)
    AdcRegs.SOCPRICTL.bit.ONESHOT = 0;// ADC 单次采集启动 0 one shot disabled
    AdcRegs.SOCPRICTL.bit.RRPOINTER = 0x0F;// Round Robin Pointer
    AdcRegs.SOCPRICTL.bit.SOCPRIORITY=0x10;//SOC Priority
    /**/
    AdcRegs.ADCSOC0CTL.bit.CHSEL = 0x00;    //ADCA0
    AdcRegs.ADCSOC0CTL.bit.TRIGSEL = 0X05;  //0x05:ADCTRIG5 – ePWM1, ADCSOCA
    AdcRegs.ADCSOC0CTL.bit.ACQPS   = 0x5;   // 采样窗口25*CLK  总共650ns
    /*线电压Eab*/
    AdcRegs.ADCSOC1CTL.bit.CHSEL = 0x01;    //ADCA1
    AdcRegs.ADCSOC1CTL.bit.TRIGSEL = 0X05;  //0x05:ADCTRIG5 – ePWM1, ADCSOCA
    AdcRegs.ADCSOC1CTL.bit.ACQPS   = 0x10;   // 采样窗口25*CLK  总共650ns
    /**///预留
    //AdcRegs.ADCSOC2CTL.bit.CHSEL = 0x02;//ADCA2
    //AdcRegs.ADCSOC2CTL.bit.TRIGSEL = 0X11;//
    //AdcRegs.ADCSOC2CTL.bit.ACQPS   = 0x10;// 采样窗口25*CLK
    /*直流母线电压Vdc*/
    AdcRegs.ADCSOC2CTL.bit.CHSEL = 0X02;    //ADCA2
    AdcRegs.ADCSOC2CTL.bit.TRIGSEL = 0X05;  //
    AdcRegs.ADCSOC2CTL.bit.ACQPS   = 0x5;  // 采样窗口25*CLK
    /*线电流Iab*/
    AdcRegs.ADCSOC3CTL.bit.CHSEL = 0x03;    //ADCA3
    AdcRegs.ADCSOC3CTL.bit.TRIGSEL = 0X05;  //0x05:ADCTRIG5 – ePWM1, ADCSOCA
    AdcRegs.ADCSOC3CTL.bit.ACQPS   = 0x8;  // 采样窗口25*CLK
    /**/
    AdcRegs.ADCSOC4CTL.bit.CHSEL = 0x04;//ADCA4
    AdcRegs.ADCSOC4CTL.bit.TRIGSEL = 0X05;//
    AdcRegs.ADCSOC4CTL.bit.ACQPS   = 0x10;// 采样窗口25*CLK
    /**/
    AdcRegs.ADCSOC5CTL.bit.CHSEL = 0x05;//ADCA5
    AdcRegs.ADCSOC5CTL.bit.TRIGSEL = 0X05;//
    AdcRegs.ADCSOC5CTL.bit.ACQPS   = 0x10;// 采样窗口25*CLK
    /**/
    AdcRegs.ADCSOC6CTL.bit.CHSEL = 0x06;//ADCA6
    AdcRegs.ADCSOC6CTL.bit.TRIGSEL = 0X05;//
    AdcRegs.ADCSOC6CTL.bit.ACQPS   = 0x10;// 采样窗口25*CLK
    /**/
    AdcRegs.ADCSOC7CTL.bit.CHSEL = 0x07;//ADC07
    AdcRegs.ADCSOC7CTL.bit.TRIGSEL = 0X05;//
    AdcRegs.ADCSOC7CTL.bit.ACQPS   = 0x10;// 采样窗口25*CLK

    /***********************ADCB*****************************8*/
    AdcRegs.ADCSOC8CTL.bit.CHSEL = 0x08;//ADCB0
    AdcRegs.ADCSOC8CTL.bit.TRIGSEL = 0X00;//
    AdcRegs.ADCSOC8CTL.bit.ACQPS   = 0x10;// 采样窗口25*CLK
    /**/
    AdcRegs.ADCSOC9CTL.bit.CHSEL = 0x09;//ADCB1
    AdcRegs.ADCSOC9CTL.bit.TRIGSEL = 0X00;//
    AdcRegs.ADCSOC9CTL.bit.ACQPS   = 0x10;// 采样窗口25*CLK
    /**/
    AdcRegs.ADCSOC10CTL.bit.CHSEL = 0x0A;//ADCB2
    AdcRegs.ADCSOC10CTL.bit.TRIGSEL = 0X00;//
    AdcRegs.ADCSOC10CTL.bit.ACQPS   = 0x10;// 采样窗口25*CLK
    /**/
    AdcRegs.ADCSOC11CTL.bit.CHSEL = 0x0B;//ADCB3
    AdcRegs.ADCSOC11CTL.bit.TRIGSEL = 0X00;//
    AdcRegs.ADCSOC11CTL.bit.ACQPS   = 0x10;// 采样窗口25*CLK
    /**/
    AdcRegs.ADCSOC12CTL.bit.CHSEL = 0x0C;//ADCB4
    AdcRegs.ADCSOC12CTL.bit.TRIGSEL = 0X00;//
    AdcRegs.ADCSOC12CTL.bit.ACQPS   = 0x10;// 采样窗口25*CLK
    /**/
    AdcRegs.ADCSOC13CTL.bit.CHSEL = 0x0D;//ADCB5
    AdcRegs.ADCSOC13CTL.bit.TRIGSEL = 0X00;//
    AdcRegs.ADCSOC13CTL.bit.ACQPS   = 0x10;// 采样窗口25*CLK
    /**/
    AdcRegs.ADCSOC14CTL.bit.CHSEL = 0x0E;//ADCB6
    AdcRegs.ADCSOC14CTL.bit.TRIGSEL = 0X00;//
    AdcRegs.ADCSOC14CTL.bit.ACQPS   = 0x10;// 采样窗口25*CLK
    /**/
//    AdcRegs.ADCSOC14CTL.bit.CHSEL = 0x0F;//ADCB7
//    AdcRegs.ADCSOC14CTL.bit.TRIGSEL = 0X00;// ADCTRIG9 – TIM7, ADCSOCA触发采样
//    AdcRegs.ADCSOC14CTL.bit.ACQPS   = 0x10;// 采样窗口25*CLK
    /*ADC中断配置*/
    // Disable continuous sampling for ADCINT1 and ADCINT2
    AdcRegs.INTSEL1N2.bit.INT1CONT = 0;
    AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1;//完成一个周期的转化后产生中断
    AdcRegs.INTSEL1N2.bit.INT1SEL = 0x07;//选择通道14采样完成后产生中断信号
//    AdcRegs.ADCINTSOCSEL1.bit.SOC7 = 1;//ADCINT1中断源选择
    AdcRegs.INTSEL1N2.bit.INT1E = 1;//使能ADCint1中断

    PieCtrlRegs.PIEIFR1.bit.INTx1 = 0;
    PieCtrlRegs.PIEIER1.bit.INTx1 = 1;
    IER |= M_INT1;
    /*ADC开始采集*/
    AdcRegs.ADCCTL1.bit.ADCPWDN = 1;    // ADC 模拟电路内部核模块上电
    AdcRegs.ADCCTL1.bit.ADCREFPWD = 1;  // ADC 参考电路内部核模块上电
    AdcRegs.ADCCTL1.bit.ADCBGPWD = 1;   // ADC Bandgap电路内部核模块上电
    AdcRegs.ADCCTL1.bit.ADCREFSEL = 1;  // ADC外部内部电压参考1
    AdcRegs.ADCCTL1.bit.ADCENABLE = 1;  // ADC启动
    /*ADC变量初始化*/
    EDIS;
    DELAY_US(1000l);// ADC开始 转换前延迟1ms 开启后进入中断故障
}

/*
 *@brief:allow epwm trig adc sampling 
*/
void ADC_Trig_Init(void)
{
    EALLOW;
    EPwm1Regs.ETSEL.bit.SOCAEN  = 1;//使能SOCA触发功能
    EPwm1Regs.ETSEL.bit.SOCASEL = ET_CTR_ZERO;//Cnt=0 Event
    EPwm1Regs.ETPS.bit.SOCAPRD  = ET_1ST;//立即触发Generate pulse on 1st event
    EDIS;
}






