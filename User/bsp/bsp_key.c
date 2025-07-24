#include "bsp_key.h"

Uint8 key1_flag[4] = {0};       //Start
Uint8 key2_flag[4] = {0};       //End
Uint8 key3_flag[4] = {0};       
Uint8 key4_flag[4] = {0};
Uint8 key5_flag[4] = {0};
Uint8 key6_flag[4] = {0};       
Uint8 g_Button = 0;

Uint8 Key_Scan(void)
{

    key1_flag[3]=key1_flag[2];
    key1_flag[2]=key1_flag[1];
    key1_flag[1]=key1_flag[0];
    key1_flag[0]=GpioDataRegs.GPBDAT.bit.GPIO51;

    key2_flag[3]=key2_flag[2];
    key2_flag[2]=key2_flag[1];
    key2_flag[1]=key2_flag[0];
    key2_flag[0]=GpioDataRegs.GPADAT.bit.GPIO12;

    key3_flag[3]=key3_flag[2];
    key3_flag[2]=key3_flag[1];
    key3_flag[1]=key3_flag[0];
    key3_flag[0]=GpioDataRegs.GPBDAT.bit.GPIO50;

    key4_flag[3]=key4_flag[2];
    key4_flag[2]=key4_flag[1];
    key4_flag[1]=key4_flag[0];
    key4_flag[0]=GpioDataRegs.GPADAT.bit.GPIO30;

    key5_flag[3]=key5_flag[2];
    key5_flag[2]=key5_flag[1];
    key5_flag[1]=key5_flag[0];
    key5_flag[0]=GpioDataRegs.GPADAT.bit.GPIO31;
    
    key6_flag[3]=key6_flag[2];
    key6_flag[2]=key6_flag[1];
    key6_flag[1]=key6_flag[0];
    key6_flag[0]=GpioDataRegs.GPADAT.bit.GPIO25;

    if (key1_flag[0]==0 && key1_flag[1]==0 && key1_flag[2]==1 && key1_flag[3]==1) return 1;
    else if (key2_flag[0]==0 && key2_flag[1]==0 && key2_flag[2]==1 && key2_flag[3]==1) return 2;
    else if (key3_flag[0]==0 && key3_flag[1]==0 && key3_flag[2]==1 && key3_flag[3]==1) return 3;
    else if (key4_flag[0]==0 && key4_flag[1]==0 && key4_flag[2]==1 && key4_flag[3]==1) return 3;
    else if (key5_flag[0]==0 && key5_flag[1]==0 && key5_flag[2]==1 && key5_flag[3]==1) return 3;
    else if (key6_flag[0]==0 && key6_flag[1]==0 && key6_flag[2]==1 && key6_flag[3]==1) return 3;
    else return 0;

}







