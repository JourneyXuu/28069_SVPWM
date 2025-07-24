#ifndef MENU_H_
#define MENU_H_

#include "DSP28x_Project.h"

#define KEY1_PRES 1
#define KEY2_PRES 2
#define KEY3_PRES 3
#define KEY4_PRES 4
#define KEY5_PRES 5
#define KEY6_PRES 6

extern Uint8 Menu_Item ; 
void OLED_Display(Uint8 num);
void MENU_Item_KEY(void) ;

/*
 * Menu structure explanation
 *
 * Main Menu:
 * - Menu_Item = 1  --> Menu_1
 * - Menu_Item = 2  --> Menu_2
 * - Menu_Item = 3  --> Menu_3
 *
 * Sub Menus:
 *
 * Menu_1 (Menu_Item = 1):
 * - Menu_10 (Menu_Item = 10)
 * - Menu_11 (Menu_Item = 11)
 * - Menu_12 (Menu_Item = 12)
 * - Menu_13 (Menu_Item = 13) --> Return to the start of Menu_1 (Menu_10)
 *
 * Menu_2 (Menu_Item = 2):
 * - Menu_20 (Menu_Item = 20)
 * - Menu_21 (Menu_Item = 21)
 * - Menu_22 (Menu_Item = 22)
 * - Menu_23 (Menu_Item = 23) --> Return to the start of Menu_2 (Menu_20)
 *
 * Menu_3 (Menu_Item = 3):
 * - Menu_30 (Menu_Item = 30)
 * - Menu_31 (Menu_Item = 31)
 * - Menu_32 (Menu_Item = 32)
 * - Menu_33 (Menu_Item = 33) --> Return to the start of Menu_3 (Menu_30)
 *
 * Special Handling:
 * - Menu_Item = 111, 112, 113 --> Return to the previous level menu (decrement)
 * - Menu_Item = 121, 122, 123, 124 --> Return to the previous level menu (decrement)
 * - Menu_Item = 131, 132, 133, 134 --> Return to the previous level menu (decrement)
 *
 * Function Key Descriptions:
 * - KEY1_PRES: Next Item (Index Down)
 * - KEY2_PRES: Confirm Selection --> Enter the next level menu or execute action
 * - KEY3_PRES: Return to Main Menu (Home Key)
 */



#endif // !MENU_H_
