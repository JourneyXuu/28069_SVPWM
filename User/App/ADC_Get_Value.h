/* ==================================================================================
File name:       DSP2833xAD_VdcEI.H
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Description: This file contains source for the F2833x Two leg current measurement,
Two volatage measurement and DC-bus measurement driver.

Target: TMS320F2833x family

=====================================================================================
History:
-------------------------------------------------------------------------------------
----------------------------------------------------------------------------------*/

#ifndef __ADC_GET_VALUE_H__
#define __ADC_GET_VALUE_H__

#include "DSP28x_Project.h"

/*-----------------------------------------------------------------------------
Define the structure of the ILEG2DCBUSMEAS Object
-----------------------------------------------------------------------------*/
typedef struct {   
				 float EabMeasGain;    // 1 Eab   Parameter: gain for Eab  
                 float EabMeasOffset;  // 1 Eab   Parameter: offset for Eab  
                 float EabMeas;        // 1 Eab   Output: measured Eab

                 float VdcMeasGain;   // 5 VdcP  Parameter: gain for VdcP
                 float VdcMeasOffset; // 5 VdcP  Parameter: offset for VdcP
                 float VdcMeas;       // 5 VdcP  Output: measured VdcP

                 float IaMeasGain;     // 6 Ia  Parameter: gain for Ia  
                 float IaMeasOffset;   // 6 Ia  Parameter: offset for Ia 
                 float IaMeas;         // 6 Ia  Output: measured Ia 

                 void (*calc)();       // Pointer to the read function
               } ADC_Get_Value;

typedef ADC_Get_Value *ADC_Get_handle;

#define ADC_Get_Value_DEFAULTS   { 36.882,60.084,0,             \
                                          23.842,0.097,0,             \
                                          7.2168,11.967,0,             \
                                          (void (*)(Uint32))ADC_Get_Value_calc  \
                                        }

/*------------------------------------------------------------------------------
 Prototypes for the functions in F281XILEG_VDC.C
------------------------------------------------------------------------------*/
void ADC_Get_Value_calc(ADC_Get_handle);

#endif // __F281XILEG_VDC_H__


