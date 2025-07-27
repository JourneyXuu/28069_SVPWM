/*=====================================================================================
 File name:        RAMPGEN.C  (IQ version)                  
                    
 Originator:	Digital Control Systems Group
			Texas Instruments

 Description:  The Ramp Generation                   

=====================================================================================
 History:
-------------------------------------------------------------------------------------
 07-22-2011	Version 1.00
-------------------------------------------------------------------------------------*/


// Don't forget to set a proper GLOBAL_Q in "IQmathLib.h" file

#include "rampgen.h"
#include "parameter.h"
#include <math.h>

/*
 *@brief:  ramp generation with soft start
*/
void rampgen_calc(RAMPGEN *v)
{	
// Compute the angle rate
    v->Angle += v->StepAngle;;    // v->Angle += v->StepAngleMax;   (v->Angle > (2 * PI))
    if  (v->Angle > (2 * PI))
            v->Angle -= (2 * PI);
    
    if(v->U > v->Umax)  { v->U = v->Umax;  }
    else
    {
        v->U += v->Umax * 0.0002 * v->T_step;
    }
// Compute the ramp output
        v->Sine = v->U * sin(v->Angle);
	    v->Cosine = v->U * cos(v->Angle);
}

