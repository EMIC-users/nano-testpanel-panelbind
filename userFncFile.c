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

void onReset()
{
    counter = 0;
    perrolLoco();
    setTime1(1000, 'A');
}


void etOut1()
{
    LEDs_Led1_state(2);
    counter = counter + 1;
}


void Keyboard_Nav_onPress(uint8_t key)
{
    key_nav = (char)(key);
}


void Keyboard_Pad_onPress(uint8_t key)
{
    key_pad = (char)(key);
}


void perrolLoco(void)
{
    Graphics_OLED_clear();
    Graphics_OLED_bindAt(16, 34, 0, &key_pad, 1, "%4d");
    Graphics_OLED_bindAt(87, 33, 0, &key_nav, 1, "%4d");
    Graphics_OLED_printAt(25, 22, 0, "PAD");
    Graphics_OLED_printAt(99, 21, 0, "NAV");
}



