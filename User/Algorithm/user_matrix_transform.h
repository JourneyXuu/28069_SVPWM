#ifndef USER_MATRIX_TRANSFORM_H_
#define USER_MATRIX_TRANSFORM_H_

#include "DSP28x_Project.h"
#include "user_all_h_data.h"

void Clarke_Marco(type_default *v);//abc -> alpha beta
void IClarke_Marco(type_default *v);//alpha beta -> abc
void Park_Marco(type_default *v);//alpha beta -> D Q
void IPark_Marco(type_default *v);//D Q -> abc or D Q -> alpha beta

#endif /* USER_CLARKE_H_ */
