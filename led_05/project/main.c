#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"

int main(void)
{
    clk_enable(); 
    led_init();

    while (1)
    {
        /* open led */
        led_switch(LED0, ON);
        delay(500);
        /* close led */
        led_switch(LED0, OFF);
        delay(500);
    }

    return 0;
}