#ifndef __LOW_PASS_FILTER_H__
#define __LOW_PASS_FILTER_H__

#include "DSP28x_Project.h"
#include "IQmathLib.h"

typedef struct {
        _iq in;        
        _iq out;       
        _iq Uplimt;
        _iq Downlimt;
        _iq K1;         		
        _iq K2;         		      
        void (*calc)();  	
        } LOW_PASS_FILTER;   	

typedef LOW_PASS_FILTER *LOW_PASS_FILTER_handle;
/*-----------------------------------------------------------------------------
Default initalizer for the SPEED_MEAS_QEP object.
-----------------------------------------------------------------------------*/                     
#define LOW_PASS_FILTER_DEFAULTS   {0,\
                                    0,\
                                    0,0,\
                                    0,0,\
                                    (void (*)(Uint32))low_pass_filter_calc }

/*------------------------------------------------------------------------------
Prototypes for the functions in SPEED_FR.C
------------------------------------------------------------------------------*/
void low_pass_filter_calc(LOW_PASS_FILTER_handle); 








#endif // __LOW_PASS_FILTER_H__















