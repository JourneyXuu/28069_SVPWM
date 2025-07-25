/* =================================================================================
File name:        RAMPGEN.H  (IQ version)                   
                    
Originator:	Digital Control Systems Group
			Texas Instruments

Description: 
This file contains type definitions, constants and initializers for
the ramp generation functions contained in RAMPGEN.C
=====================================================================================
 History:
-------------------------------------------------------------------------------------
  07-22-2011	Version 1.00
------------------------------------------------------------------------------*/
#ifndef __RAMPGEN_H__
#define __RAMPGEN_H__

#include "DSP28x_Project.h"
#include "parameter.h"

typedef struct {
				float	StepAngle;	// Parameter:step angle
				float	Angle;		// Variable: Step angle
				float	Sine;  	 	// Output: Ramp signal
				float	Cosine;	    // Output: Ramp signal
				float 	Umax;
				float 	U;
				float 	T_step;
	  	  	    void  (*calc)();	  	// Pointer to calculation function
			} RAMPGEN;

/*------------------------------------------------------------------------------
    Object Initializers
------------------------------------------------------------------------------*/                       
#define RAMPGEN_DEFAULTS {	2 * PI * BASE_FREQ * T,\
                            0,\
                            0,\
                            0,\
                            0,\
                            0,\
                            1,\
                            (void (*)(Uint32))rampgen_calc }
/*------------------------------------------------------------------------------
    Funtion prototypes
------------------------------------------------------------------------------*/                                               
void rampgen_calc(RAMPGEN *v);

#endif // __RAMPGEN_H__
