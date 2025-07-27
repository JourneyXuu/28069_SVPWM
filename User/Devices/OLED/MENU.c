#include "MENU.h"
#include "bsp_key.h"
#include "OLED.h"
#include "bmp.h"
Uint8 Menu_Item = 20;  //original menu item
extern Uint8 RUN_Flag;
extern Uint8 Stop_Flag;
extern Uint8 Mode;

extern float Uab_set;
extern float Ia_set;

extern float Uab_real;
extern float Vdc_real;
extern float Ia_real;

void OLED_Display(Uint8 num)
{
	switch(num)      
	{
		case 0:
		OLED_ShowPicture(32,0,64,64,gImage_CUMT,1);
		break;
		
		case 1://Primary menu
			OLED_ShowString(40, 0,  "MENU", 16,1);  //title
			OLED_ShowString(20, 16, "Mode Select", 16,1);
			OLED_ShowString(20, 16*2, "Monitor", 16,1);
			OLED_ShowString(0, 16,  ">>", 16,1);    //index
		break;
/*****************************Secondary menu Start************************************/
		case 10:
            OLED_ShowString(20, 0, "Mode Select", 16,1); 
            OLED_ShowString(20, 16, "Grid-tied", 16,1);
            OLED_ShowString(20, 16*2, "Off-grid", 16,1);
			OLED_ShowString(0, 16, ">>", 16,1);
		break;
		case 11:
            OLED_ShowString(20, 0, "Mode Select", 16,1); 
            OLED_ShowString(20, 16, "Grid-tied", 16,1);
            OLED_ShowString(20, 16*2, "Off-grid", 16,1);
			OLED_ShowString(0, 16*2, ">>", 16,1);
		break;
/*****************************Secondary menu End************************************/

/*****************************tertiary menu Start************************************/
		case 110:	//on-grid mode
            OLED_ShowString(0, 0, "Grid-tied Mode", 16,1);
            OLED_ShowString(0, 16, "Press KEY2 to", 16,1);
            OLED_ShowString(20, 16*2, "START/STOP", 16,1);
            if(RUN_Flag == 1) {
                OLED_ShowString(20, 16*3, "Status: RUN", 16,0);
            } else {
                OLED_ShowString(20, 16*3, "Status: STOP", 16,0);
            }
            break;
		case 111:	//off-grid mode
            OLED_ShowString(0, 0, "Off-grid Mode", 16,1);
            OLED_ShowString(0, 16, "Press KEY2 to", 16,1);
            OLED_ShowString(20, 16*2, "START/STOP", 16,1);
            if(RUN_Flag == 1) {
                OLED_ShowString(20, 16*3, "Status: RUN", 16,0);
            } else {
                OLED_ShowString(20, 16*3, "Status: STOP", 16,0);
            }
		break;	
/*****************************tertiary menu End************************************/

	
		case 2:	//Primary menu
			OLED_ShowString(40, 0,  "MENU", 16,1);  //title
			OLED_ShowString(20, 16, "Mode Select", 16,1);
			OLED_ShowString(20, 16*2, "Monitor", 16,1);
			OLED_ShowString(0, 16*2,  ">>", 16,1);
		break;

/*****************************Secondary menu Start************************************/
		case 20://Secondary menu
			OLED_ShowString(40, 0,  "Monitor", 8,1);
			
			OLED_ShowString(20, 8, "Real",8,1);
			OLED_ShowString(90, 8, "Set",8,1);

			OLED_ShowString(20, 16, "Uab:",16,1);
			OLED_ShowString(20, 16*2, "Vdc:",16,1);
			OLED_ShowString(20, 16*3, "Ia:",16,1);

			// OLED_ShowFloat(50,16,Uab_real,16,1);
			// OLED_ShowFloat(50,16*2,Vdc_real,16,1);
			// OLED_ShowFloat(50,16*3,Ia_real,16,1);

			OLED_ShowFloat(90,16,Uab_set,16,1);
			OLED_ShowFloat(90,16*3,Ia_set,16,1);

			OLED_ShowString(0, 16*1,  ">>", 16,1);

		break;
		case 21:
			OLED_ShowString(40, 0,  "Monitor", 8,1);
			
			OLED_ShowString(20, 8, "Real",8,1);
			OLED_ShowString(90, 8, "Set",8,1);

			OLED_ShowString(20, 16, "Uab:",16,1);
			OLED_ShowString(20, 16*2, "Vdc:",16,1);
			OLED_ShowString(20, 16*3, "Ia:",16,1);

			OLED_ShowFloat(50,16,Uab_real,16,1);
			OLED_ShowFloat(50,16*2,Vdc_real,16,1);
			OLED_ShowFloat(50,16*3,Ia_real,16,1);

			OLED_ShowFloat(90,16,Uab_set,16,1);
			OLED_ShowFloat(90,16*3,Ia_set,16,1);

			OLED_ShowString(0, 16*3,  ">>", 16,1);
		break;		

/*****************************Secondary menu End************************************/
	}
/*****************************tertiary menu End************************************/
}

/*
 *@biref: Make each key press trigger a menu item change.
 *note:
    *  KEY1_PRES: Index down
    *  KEY2_PRES: Confirm selection
    *  KEY3_PRES: Home key (reset to initial state)
 *structure:
*MENU_1                                     *Menu_2                                 *Menu_3
*Menu_10 *Menu_11 *Menu_12 *Menu_13         *Menu_20 *Menu_21 *Menu_22 *Menu_23     *Menu_30 *Menu_31 *Menu_32 *Menu_33
*/
void MENU_Item_KEY(void)  
{
	switch(g_Button)	
	{
		case KEY1_PRES:  //index down   
            OLED_Clear();
			Menu_Item++;
                switch(Menu_Item) // index in a circle
                {
                    case 3: 
                        Menu_Item  = 1; 
                    break;

                    case 12:
                        Menu_Item = 10;
                    break;

                    case 112:
                    	Menu_Item = 110;
                    break;	
                    
                    case 22:
                        Menu_Item = 20;
                    break;
					default:
					break;
                }	
				break;
				
        case KEY2_PRES:     //confirm selection
            OLED_Clear();
            switch(Menu_Item)
            {
                case 1: 
                case 2:
                    Menu_Item *= 10;   
                break;
                
                case 10:      
                case 11:	
                    Menu_Item  += 100;   
                break;
                
                // case 20:      
                // case 21:	
                //     Menu_Item  += 100;   
                // break;

				case 110:
				case 111:
					if(RUN_Flag == 0) {
						RUN_Flag = 1;
						Stop_Flag = 0;
					} else {
						RUN_Flag = 0;
						Stop_Flag = 1;
					}
				break;
				default:
				break;
            }	


        break;
            
        case KEY3_PRES :              //home
            OLED_Clear();
            Menu_Item = 0;    
        break;

        case KEY4_PRES:  //Stop Imediately
			OLED_Clear();
			RUN_Flag = 0 ;
			Stop_Flag = 1;

        break;

        case KEY5_PRES:	//parameter add
			OLED_Clear();
			switch (Menu_Item)
			{
			case 20:
				Uab_set += 0.1;
			break;
			case 21:
				Ia_set += 0.1;
			break;
			default:
			break;
			}


        break;

        case KEY6_PRES: //parameter sub
			OLED_Clear();
			switch (Menu_Item)
			{
			case 20:
				Uab_set -= 0.1;
			break;
			case 21:
				Ia_set -= 0.1;
			break;
			default:
			break;
			}




        break;
	}


}








