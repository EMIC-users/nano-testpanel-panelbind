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

void onReset()
{
    counter = 0;
    Graphics_OLED_clear();
    Graphics_OLED_printAt(0, 0, 1, "COUNT:");
    Graphics_OLED_bindAt(60, 0, 1, counter, 1, "%5u");
    setTime1(1000, 'A');
}


void etOut1()
{
    LEDs_Led1_state(2);
    counter = counter + 1;
}



