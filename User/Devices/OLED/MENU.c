#include "MENU.h"
#include "bsp_key.h"
#include "OLED.h"
#include "bmp.h"
Uint8 Menu_Item = 0;  //original menu item

void OLED_Display(Uint8 num)
{
	switch(num)      
	{
		case 0:
		OLED_ShowPicture(32,0,64,64,gImage_CUMT,1);
		break;
		
		case 1://Primary menu
			OLED_ShowString(40, 0,  "MENU1", 16,1);  //title
			OLED_ShowString(20, 16, "Converter", 16,1);
			OLED_ShowString(20, 16*2, "Monitor", 16,1);
			OLED_ShowString(20, 16*3, "Task", 16,1);
			OLED_ShowString(0, 16,  ">>", 16,1);    //index
		break;
/*****************************Secondary menu Start************************************/
		case 10:
			OLED_ShowString(40, 0, "Converter", 16,1); //title
			OLED_ShowString(20, 16, "On-Grid", 16,1);
			OLED_ShowString(20, 16*2, "Off-Grid", 16,1);
			OLED_ShowString(20, 16*3, "Euler angle", 16,1);
			OLED_ShowString(0, 16, ">>", 16,1);
		break;
		case 11:
			OLED_ShowString(40, 0, "Converter", 16,1); //title
			OLED_ShowString(20, 16, "On-Grid", 16,1);
			OLED_ShowString(20, 16*2, "Off-Grid", 16,1);
			OLED_ShowString(20, 16*3, "Euler angle", 16,1);
			OLED_ShowString(0, 16*2, ">>", 16,1);
		break;
		case 12:
			OLED_ShowString(40, 0, "Converter", 16,1); //title
			OLED_ShowString(20, 16, "On-Grid", 16,1);
			OLED_ShowString(20, 16*2, "Off-Grid", 16,1);
			OLED_ShowString(20, 16*3, "Euler angle", 16,1);
			OLED_ShowString(0, 16*3, ">>", 16,1);
		break;
/*****************************Secondary menu End************************************/

	
		case 2:	//Primary menu
			OLED_ShowString(40, 0,  "MENU", 16,1);
			OLED_ShowString(20, 16, "MPU6050", 16,1);
			OLED_ShowString(20, 16*2, "TASK", 16,1);
			OLED_ShowString(20, 16*3, "TEST", 16,1);
			OLED_ShowString(0, 16*2,  ">>", 16,1);
		break;

/*****************************Secondary menu Start************************************/
		case 20://Secondary menu
			OLED_ShowString(40, 0,  "TASK", 16,1);
			OLED_ShowString(20, 16, "TASK1", 16,1);
			OLED_ShowString(20, 16*2, "TASK2", 16,1);
			OLED_ShowString(20, 16*3, "TASK3", 16,1);
			OLED_ShowString(0, 16,  ">>", 16,1);
		break;
		case 21:
			OLED_ShowString(40, 0,  "TASK", 16,1);
			OLED_ShowString(20, 16, "TASK1", 16,1);
			OLED_ShowString(20, 16*2, "TASK2", 16,1);
			OLED_ShowString(20, 16*3, "TASK3", 16,1);
			OLED_ShowString(0, 16*2,  ">>", 16,1);
		break;		
		case 22:
			OLED_ShowString(40, 0,  "TASK", 16,1);
			OLED_ShowString(20, 16, "TASK1", 16,1);
			OLED_ShowString(20, 16*2, "TASK2", 16,1);
			OLED_ShowString(20, 16*3, "TASK3", 16,1);
			OLED_ShowString(0, 16*3,  ">>", 16,1);
		break;	
/*****************************Secondary menu End************************************/

/*****************************tertiary menu Start************************************/
		case 120:
			OLED_ShowString(40, 0,  "TASK1", 16,1);
			OLED_ShowString(20, 16, "To_Be_Set", 16,1);
		break;	
		case 121:
			OLED_ShowString(40, 0,  "TASK2", 16,1);
			OLED_ShowString(20, 16, "To_Be_Set", 16,1);	
		break;	
		case 122:
			OLED_ShowString(40, 0,  "TASK3", 16,1);
			OLED_ShowString(20, 16, "To_Be_Set", 16,1);
		break;	
		case 123:
			OLED_ShowString(40, 0,  "TASK ALL", 16,1);
			OLED_ShowString(20, 16, "To_Be_Set", 16,1);	
		break;	
/*****************************tertiary menu End************************************/

		case 3://primary menu	
			OLED_ShowString(40, 0,  "MENU", 16,1);
			OLED_ShowString(20, 16, "MPU6050", 16,1);
			OLED_ShowString(20, 16*2, "TASK", 16,1);
			OLED_ShowString(20, 16*3, "TEST", 16,1);
			OLED_ShowString(0, 16*3,  ">>", 16,1);
		break;

/*****************************Secondary menu Start************************************/
		case 30: //*TEST.1	
			OLED_ShowString(40, 0,  "TEST", 16,1);
			OLED_ShowString(20, 16, "Motor", 8,1);		
			OLED_ShowString(20, 16+8*1, "ADC", 8,1);
			OLED_ShowString(20, 16+8*2, "Openmv", 8,1);
			OLED_ShowString(20, 16+8*3, "Bluetooth", 8,1);		
			OLED_ShowString(0, 16,  ">>", 8,1);
		break;				
		case 31://*TEST.2	
			OLED_ShowString(40, 0,  "TEST", 16,1);
			OLED_ShowString(20, 16, "Motor", 8,1);		
			OLED_ShowString(20, 16+8*1, "ADC", 8,1);
			OLED_ShowString(20, 16+8*2, "Openmv", 8,1);
			OLED_ShowString(20, 16+8*3, "Bluetooth", 8,1);
			OLED_ShowString(0, 16+8*1, ">>", 8,1);
		break;			
		case 32://*TEST.3	
			OLED_ShowString(40, 0,  "TEST", 16,1);
			OLED_ShowString(20, 16, "Motor", 8,1);		
			OLED_ShowString(20, 16+8*1, "ADC", 8,1);
			OLED_ShowString(20, 16+8*2, "Openmv", 8,1);
			OLED_ShowString(20, 16+8*3, "Bluetooth", 8,1);
			OLED_ShowString(0, 16+8*2,  ">>", 8,1);
		break;			
		case 33://*TEST.4	
			OLED_ShowString(40, 0,  "TEST", 16,1);
			OLED_ShowString(20, 16, "Motor", 8,1);		
			OLED_ShowString(20, 16+8*1,"ADC", 8,1);
			OLED_ShowString(20, 16+8*2, "Openmv", 8,1);
			OLED_ShowString(20, 16+8*3, "Bluetooth", 8,1);	
			OLED_ShowString(0, 16+8*3,  ">>", 8,1);
		break;
/*****************************Secondary menu End************************************/

/*****************************tertiary menu Start************************************/
		case 130:
			OLED_ShowString(40, 0,  	"TEST 1", 16,1);	
			OLED_ShowString(20, 16,  	"Nothing here", 8,1);		
			OLED_ShowString(20, 16+8*1,  "ME"	, 8,1);
			OLED_ShowString(20, 16+8*2,  "and"	, 8,1);	
			OLED_ShowString(20, 16+8*3,  "You"	, 8,1);		
			OLED_ShowString(20, 16+8*4,  "He"	, 8,1);			
			OLED_ShowString(20, 16+8*5,  "She"	, 8,1);	

		
		break;
		case 131:	
			OLED_ShowString(40, 0,  	"TEST 2", 16,1);	
			OLED_ShowString(20, 16,  	"Nothing here", 8,1);		
			OLED_ShowString(20, 16+8*1,  "ME"	, 8,1);
			OLED_ShowString(20, 16+8*2,  "and"	, 8,1);	
			OLED_ShowString(20, 16+8*3,  "You"	, 8,1);		
			OLED_ShowString(20, 16+8*4,  "He"	, 8,1);			
			OLED_ShowString(20, 16+8*5,  "She"	, 8,1);			
		break;
		case 132:
        	OLED_ShowString(40, 0,  	"TEST 2", 16,1);	
			OLED_ShowString(20, 16,  	"Nothing here", 8,1);		
			OLED_ShowString(20, 16+8*1,  "ME"	, 8,1);
			OLED_ShowString(20, 16+8*2,  "and"	, 8,1);	
			OLED_ShowString(20, 16+8*3,  "You"	, 8,1);		
			OLED_ShowString(20, 16+8*4,  "He"	, 8,1);			
			OLED_ShowString(20, 16+8*5,  "She"	, 8,1);			
		break;
		case 133:
        	OLED_ShowString(40, 0,  	"TEST 2", 16,1);	
			OLED_ShowString(20, 16,  	"Nothing here", 8,1);		
			OLED_ShowString(20, 16+8*1,  "ME"	, 8,1);
			OLED_ShowString(20, 16+8*2,  "and"	, 8,1);	
			OLED_ShowString(20, 16+8*3,  "You"	, 8,1);		
			OLED_ShowString(20, 16+8*4,  "He"	, 8,1);			
			OLED_ShowString(20, 16+8*5,  "She"	, 8,1);			
		break;		
		case 134:
        	OLED_ShowString(40, 0,  	"TEST 2", 16,1);	
			OLED_ShowString(20, 16,  	"Nothing here", 8,1);		
			OLED_ShowString(20, 16+8*1,  "ME"	, 8,1);
			OLED_ShowString(20, 16+8*2,  "and"	, 8,1);	
			OLED_ShowString(20, 16+8*3,  "You"	, 8,1);		
			OLED_ShowString(20, 16+8*4,  "He"	, 8,1);			
			OLED_ShowString(20, 16+8*5,  "She"	, 8,1);			
        break;	
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
                    case 4: 
                        Menu_Item  = 1; 
                    break;

                    case 13:
                        Menu_Item = 10;
                    break;

                    case 111:
                    case 112:
                    case 113:   
                    Menu_Item--;
                    break;	
                    
                    case 23:
                        Menu_Item = 20;
                    break;
                    
                    case 121:
                    case 122:
                    case 123: 
                    case 124:							
                        Menu_Item--;
                    break;
                    
                    case 34:
                        Menu_Item = 30;
                    break;
                    
                    case 131:
                    case 132:
                    case 133:
                    case 134:							
                        Menu_Item--;
                    break;
                }	
				break;
				
        case KEY2_PRES:     //confirm selection
            OLED_Clear();
            switch(Menu_Item)
            {
                case 1: 
                case 2:
                case 3:
                    Menu_Item *= 10;   
                break;
                
                case 10:      
                case 11:	
                case 12:
                    Menu_Item  += 100;   
                break;
                
                case 20:      
                case 21:	
                case 22:
                case 23:
                    Menu_Item  += 100;   
                break;
                
                case 30:      
                case 31:	
                case 32:
                case 33:
                    Menu_Item  += 100;   
                break;
            }					
        break;
            
        case KEY3_PRES :              //home
            OLED_Clear();
            Menu_Item = 0;    
        break;

        // case KEY4_PRES: 
        // break;

        // case KEY5_PRES:
        // break;

        // case KEY6_PRES:
        // break;
	}


}








