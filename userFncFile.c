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


void perrolLoco(void)
{
    Graphics_OLED_clear();
    Graphics_OLED_printAt(35, 3, 0, "PERRO LOCO");
    Graphics_OLED_bindAt(50, 34, 0, &counter, 1, "%4u");
    Graphics_OLED_circle(67, 38, 20);
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
    Graphics_OLED_printAt(43, 2, 1, "TITULO");
    Graphics_OLED_line(0, 57, 127, 57);
    Graphics_OLED_printAt(88, 26, 0, "COUNT:");
    Graphics_OLED_bindAt(84, 40, 0, &counter, 1, "%05u");
    Graphics_OLED_line(57, 14, 57, 56);
    Graphics_OLED_line(0, 13, 127, 13);
    Graphics_OLED_circle(31, 35, 19);
    Graphics_OLED_rect(81, 37, 41, 13);
}



