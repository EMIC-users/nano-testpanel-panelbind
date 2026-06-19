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
uint16_t RPM = 0;

void onReset()
{
    Graphics_OLED_clear();
    display1();
    setTime1(5000, 'A');
}


void display1(void)
{
    Graphics_OLED_clear();
    Graphics_OLED_circle(20, 53, 8);
    Graphics_OLED_rect(105, 7, 11, 11);
    Graphics_OLED_bindAt(16, 11, 0, &counter, 1, "%4u");
    Graphics_OLED_bindAt(99, 51, 0, &RPM, 1, "%4u");
}


void etOut1()
{
    LEDs_Led1_blink(100, 101, 1);
    counter = counter + 1;
    pI2C("CNT\t%u", counter);
}


void eI2C(char* tag, const streamIn_t* const msg)
{
    LEDs_Led2_blink(100, 101, 1);
    if (strncmp(tag, "miVar", 5) == 0)
    {
        miVar = streamIn_t_ptr_to_uint8_t((streamIn_t*)msg);
    }
    else if (strncmp(tag, "RPM", 3) == 0)
    {
        RPM = streamIn_t_ptr_to_uint16_t((streamIn_t*)msg);
    }
    else
    {
        /* default case - no action */
    }
}



