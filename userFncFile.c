#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "inc/userFncFile.h"
#include "inc/systemTimer.h"
#include "inc/led_Led1.h"
#include "inc/led_Led2.h"
#include "inc/timer_api1.h"
#include "inc/conversionFunctions.h"
#include "inc/Graphics_OLED.h"
#include "inc/Keyboard_Pad.h"
#include "inc/Keyboard_Nav.h"
#include "inc/EMICBus.h"

/* User Variables */
uint16_t counter = 0;
uint8_t miVar;
char key_pad;
char key_nav;
uint64_t bigcounter = 0;
char keychar = 65;

void onReset()
{
    Graphics_OLED_clear();
    Graphics_OLED_bindAt(60, 0, 1, counter, 1, "%5u");
    Graphics_OLED_bindAt(0, 20, 1, bigcounter, 7, "%10llu");
    Graphics_OLED_bindAt(0, 40, 1, keychar, 9, "%c");
    setTime1(5000, 'T');
}


void display1(void)
{
    Graphics_OLED_clear();
    Graphics_OLED_circle(20, 53, 8);
    Graphics_OLED_rect(105, 7, 11, 11);
}


void etOut1()
{
    display1();
}



