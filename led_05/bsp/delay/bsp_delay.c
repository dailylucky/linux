#include "bsp_led.h"

void delay_short(volatile unsigned int n)
{
    while (n--) { }
}

/*
 * @description: delay n ms at 396Mhz 
 */
void delay(volatile unsigned int n)
{
    while (n--)
    {
        delay_short(0x7ff);
    }
}