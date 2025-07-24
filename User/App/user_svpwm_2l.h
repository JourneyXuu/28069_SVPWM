//Svpwm_2l.h
//////////////////////////
#ifndef USER_SVPWM_2L_H_
#define USER_SVPWM_2L_H_

#include "DSP28x_Project.h"

//////////////////////////
//定义两电平svpwm结构体对象类型，使用时，只需将变量声明为SVPWM_2L即可
//////////////////////////
typedef struct  {
                float Ualpha;     //输入
				float Ubeta;      //输入
				float Udc;        //直流侧电压输入
				float T;          //调制周期输入
				float Tcmpa;      //A相调制波比较时刻值
				float Tcmpb;      //B相调制波比较时刻值
				float Tcmpc;      //C相调制波比较时刻值
				void ( * calc)();  //指针计算过程
                }SVPWM_2L;
//
//声明SVPWM_2L_handle为SVPWM_2L指针类型
//
typedef SVPWM_2L *SVPWM_2L_handle;
//
//定义算法计算过程中的初始值


#define SVPWM_2L_DEFAULTS {0,  \
                        0,  \
                        0,  \
                        0.00005,\
                        0.0,\
                        0.0,\
                        0.0,\
						(void(*) (Uint32))svpwm_2l_calc}


//函数声明
void svpwm_2l_calc(SVPWM_2L_handle);
#endif
//////////////////////////////////
//End of file
