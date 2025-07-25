#include "ADC_Get_Value.h"
#include "adc.h"

void ADC_Get_Value_calc(ADC_Get_Value *p)
{
    //输出电流  输出电压  滑动变阻器
    int16 DatQ15;
           //Uint16 Dat;
    float Tmp1;
    
            DatQ15 = AdcResult.ADCRESULT1;
            //DatQ15 = Dat^0x8000;                      //Vdc Convert raw result to bipolar signal
            Tmp1 = 3.3  *( (float)(DatQ15)/ 4095.0);       //0xFFF0 ==>65520
            p->EabMeas = Tmp1;
            p->EabMeas = p->EabMeasGain * Tmp1;         // p->VdcMeas = gain*dat
            p->EabMeas -= p->EabMeasOffset;             // Add offset
//            p->EabMeas *= 20;                            // Positive direction

            DatQ15 = AdcResult.ADCRESULT2;
           // DatQ15 = Dat^0x8000;                      //eab Convert raw result to bipolar signal
            Tmp1 = 3.3  *( (float)DatQ15/ 4095.0);       //0xFFF0 ==>65520
            p->VdcMeas = Tmp1;
            p->VdcMeas = p->VdcMeasGain * Tmp1;         // p->EaMeas = gain*dat
            p->VdcMeas -= p->VdcMeasOffset;             // Add offset
//            p->VdcMeas *= 30.19;                            // Positive direction

            DatQ15 = AdcResult.ADCRESULT3;
           // DatQ15 = Dat^0x8000;                      //ebc Convert raw result to bipolar signal
            Tmp1 = 3.3  *( (float)DatQ15/ 4095.0);       //0xFFF0 ==>65520
            p->IaMeas = Tmp1;
            p->IaMeas = p->IaMeasGain * Tmp1;         // p->EbMeas = gain*dat
            p->IaMeas -= p->IaMeasOffset;             // Add offset
//            p->IaMeas *= 4.5;
}
