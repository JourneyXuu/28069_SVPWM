#ifndef __HARDWARE_CONFIG_H
#define __HARDWARE_CONFIG_H 

#include "DSP28x_Project.h"

#define      _FLASHOK        1

#ifdef _FLASHOK
extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadEnd;
extern Uint16 RamfuncsRunStart;
extern Uint16 RamfuncsLoadSize;
#endif

void Hardware_Config(void);




#endif












