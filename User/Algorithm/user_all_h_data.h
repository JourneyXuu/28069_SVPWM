/*
 * user_all_h_data.h
 *
 *  Created on: 2018年11月21日
 *      Author: yan
 */

#ifndef USER_ALL_H_DATA_H_
#define USER_ALL_H_DATA_H_

// #include <user_pi.h>
// #include <user_clarke.h>
// #include <user_iclarke.h>
// #include <user_ipark.h>
// #include <user_park.h>
#include <rampgen.h>
// #include <user_pll.h>

typedef struct{
	float  Sine;
	float  Cosine;
	float  As;  		//  phase-a stator variable
	float  Bs;	    //  phase-b stator variable
	float  Cs;	    //  phase-c stator variable
	float  Alpha;		// stationary d-axis stator variable
	float  Beta;		//  stationary q-axis stator variable
	float  Ds;			// Output: rotating d-axis stator variable
	float  Qs;			// Output: rotating q-axis stator variable
}type_default;

typedef struct{

	type_default grid_voltage;
	type_default converter_current;
	type_default load_current;
	type_default converter_voltage;

}parallel_inverter;


#endif /* USER_ALL_H_DATA_H_ */
