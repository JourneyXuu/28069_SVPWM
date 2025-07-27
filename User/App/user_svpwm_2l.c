/////////////////////////////////
//SVPWM_2L.c
/////////////////////////////////
#include "user_svpwm_2l.h"
#include <math.h>

/*
 *@brief:SVPWN
*/
void svpwm_2l_calc(SVPWM_2L *p)
{
 //定义动态局部变量
          float temp;
          float X,Y,Z,t1,t2;
          Uint16 A,B,C,N,Sector;
          float Ta,Tb,Tc;
          float K=1.73205081;      //sqrt(3)/2=1.73205081


      //将整个调制周期归一化处理，之后为EPWM模块赋值时再乘上调制周期；也可以将此句屏蔽，直接计算时间
          p->T1=1.0;
          //先求取基本时间变量
          X =  K*p->Ubeta / p->Udc * p->T1;
          Y = (K*p->Ubeta +3 * p->Ualpha) / (2 * p->Udc) * p->T1;//1.73205081*K
          Z = (K*p->Ubeta -3 * p->Ualpha) / (2 * p->Udc) * p->T1;

 //扇区判别
          if(p->Ubeta>0)
          {A=1;}
          else
          {A=0;}
          if((K*p->Ualpha-p->Ubeta)>0)
          {B=1;}
          else
          {B=0;}
          if((-K*p->Ualpha-p->Ubeta)>0)
          {C=1;}
          else
          {C=0;}
          N=A+2*B+4*C;
          switch(N)
          {
          case 1:{Sector=2;break;}
          case 2:{Sector=6;break;}
          case 3:{Sector=1;break;}
          case 4:{Sector=4;break;}
          case 5:{Sector=3;break;}
          case 6:{Sector=5;break;}
          default:{;}
          }
 //根据参考电压矢量所在扇区选择基本矢量作用时间
          switch(Sector)
          {
          case 1:{t1=-Z;t2=X;break;}
          case 2:{t1=Z;t2=Y;break;}
          case 3:{t1=X;t2=-Y;break;}
          case 4:{t1=-X;t2=Z;break;}
          case 5:{t1=-Y;t2=-Z;break;}
          case 6:{t1=Y;t2=-X;break;}
          default:{;}
          }
 //对过调制进行调整,标准化
          if((t1+t2)>p->T1)
          {
          temp=t1+t2;
          t1=t1*p->T1/temp;
          t2=t2*p->T1/temp;
          }
     //作用时间分配
          Ta=0.25*(p->T1-t1-t2);
          Tb=Ta+0.5*t1;
          Tc=Tb+0.5*t2;
 //根据扇区选择A、B、C、三个通道的比较值
     switch(Sector)
     {
          case 1:{p->Tcmpa=Ta;p->Tcmpb=Tb;p->Tcmpc=Tc;break;}
          case 2:{p->Tcmpa=Tb;p->Tcmpb=Ta;p->Tcmpc=Tc;break;}
          case 3:{p->Tcmpa=Tc;p->Tcmpb=Ta;p->Tcmpc=Tb;break;}
          case 4:{p->Tcmpa=Tc;p->Tcmpb=Tb;p->Tcmpc=Ta;break;}
          case 5:{p->Tcmpa=Tb;p->Tcmpb=Tc;p->Tcmpc=Ta;break;}
          case 6:{p->Tcmpa=Ta;p->Tcmpb=Tc;p->Tcmpc=Tb;break;}
          default:{;}
     }
}


void svgendq_calc(SVPWM_2L *v)
{	

	float Va,Vb,Vc,t1,t2;
	Uint32 Sector = 0;  // Sector is treated as Q0 - independently with global Q
																	
// Inverse clarke transformation
     Va = v->Ubeta;
     Vb = -0.5f * v->Ubeta + 0.8660254f * v->Ualpha;  // 0.8660254 = sqrt(3)/2 
     Vc = -0.5f * v->Ubeta - 0.8660254f * v->Ualpha;  // 0.8660254 = sqrt(3)/2

// 60 degree Sector determination
     if (Va > 0.0f)
          Sector = 1; 
     if (Vb > 0.0f)
          Sector = Sector + 2;
     if (Vc > 0.0f)   
          Sector = Sector + 4;
          
// X,Y,Z (Va,Vb,Vc) calculations
     Va = v->Ubeta;                                                       // X = Va 
     Vb = 0.5f * v->Ubeta + 0.8660254f * v->Ualpha;   // Y = Vb 
     Vc = 0.5f * v->Ubeta - 0.8660254f * v->Ualpha;   // Z = Vc

     if (Sector==0)  // Sector 0: this is special case for (Ualpha,Ubeta) = (0,0)
     {
          v->Tcmpa = 0.5f;
          v->Tcmpb = 0.5f;
          v->Tcmpc = 0.5f;
     }
     if (Sector==1)  // Sector 1: t1=Z and t2=Y (abc ---> Tb,Ta,Tc)
     {
          t1 = Vc;
          t2 = Vb;
          v->Tcmpb = 0.5f * (1.0f - t1 - t2);      // tbon = (1-t1-t2)/2
          v->Tcmpa = v->Tcmpb + t1;                // taon = tbon+t1
          v->Tcmpc = v->Tcmpa + t2;                // tcon = taon+t2
     }
     else if (Sector==2)  // Sector 2: t1=Y and t2=-X (abc ---> Ta,Tc,Tb)
     {
          t1 = Vb;
          t2 = -Va;
          v->Tcmpa = 0.5f * (1.0f - t1 - t2);      // taon = (1-t1-t2)/2
          v->Tcmpc = v->Tcmpa + t1;                // tcon = taon+t1
          v->Tcmpb = v->Tcmpc + t2;                // tbon = tcon+t2
     }      
     else if (Sector==3)  // Sector 3: t1=-Z and t2=X (abc ---> Ta,Tb,Tc)
     {
          t1 = -Vc;
          t2 = Va;
          v->Tcmpa = 0.5f * (1.0f - t1 - t2);      // taon = (1-t1-t2)/2
          v->Tcmpb = v->Tcmpa + t1;                // tbon = taon+t1
          v->Tcmpc = v->Tcmpb + t2;                // tcon = tbon+t2
     }   
     else if (Sector==4)  // Sector 4: t1=-X and t2=Z (abc ---> Tc,Tb,Ta)
     {
          t1 = -Va;
          t2 = Vc;
          v->Tcmpc = 0.5f * (1.0f - t1 - t2);      // tcon = (1-t1-t2)/2
          v->Tcmpb = v->Tcmpc + t1;                // tbon = tcon+t1
          v->Tcmpa = v->Tcmpb + t2;                // taon = tbon+t2
     }   
     else if (Sector==5)  // Sector 5: t1=X and t2=-Y (abc ---> Tb,Tc,Ta)
     {
          t1 = Va;
          t2 = -Vb;
          v->Tcmpb = 0.5f * (1.0f - t1 - t2);      // tbon = (1-t1-t2)/2
          v->Tcmpc = v->Tcmpb + t1;                // tcon = tbon+t1
          v->Tcmpa = v->Tcmpc + t2;                // taon = tcon+t2
     }   
     else if (Sector==6)  // Sector 6: t1=-Y and t2=-Z (abc ---> Tc,Ta,Tb)
     {
          t1 = -Vb;
          t2 = -Vc;
          v->Tcmpc = 0.5f * (1.0f - t1 - t2);      // tcon = (1-t1-t2)/2
          v->Tcmpa = v->Tcmpc + t1;                // taon = tcon+t1
          v->Tcmpb = v->Tcmpa + t2;                // tbon = taon+t2 
     }
          
}































//End of file
