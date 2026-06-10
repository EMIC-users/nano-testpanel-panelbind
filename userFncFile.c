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

void onReset()
{
    counter = 0;
    setTime1(1000, 'A');
}


void etOut1()
{
    LEDs_Led1_state(2);
    counter = counter + 1;
}


void PantallaPrincipal()
{
    Graphics_OLED_clear();
    Graphics_OLED_printAt(20, 0, 1, "TITULO");
    Graphics_OLED_line(0, 20, 127, 20);
    Graphics_OLED_printAt(0, 40, 1, "COUNT:");
    Graphics_OLED_bindAt(50, 40, 1, &counter, 1, "%4u");
}


void testCanvas(void)
{
    Graphics_OLED_clear();
    Graphics_OLED_printAt(34, 6, 1, "TITULO");
    Graphics_OLED_line(0, 22, 127, 22);
    Graphics_OLED_printAt(16, 40, 0, "COUNT:");
    Graphics_OLED_bindAt(81, 41, 0, &counter, 1, "%4u");
}



