#include "bsp_led.h"

/**
 * @description: init the GPIO of LED
*/
void led_init(void)
{
    /* 1. init IO mux */
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0);

    /* 2. config attribution of GPIO */
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0x10b0);

    /* 3. set to OUTPUT mode */
    GPIO1->GDIR |= (1 << 3);

    /* 4. output low level */
    GPIO1->DR &= ~(1 << 3);
}

/**
 * @description: open or close LED
 * @param led: LED number
 * @param status: 0 means open, 1 means close
 * @return None
*/
void led_switch(int led, int status)
{
    switch(led)
    {
    case LED0:
        if (status == ON)
            GPIO1->DR &= ~(1 << 3);
        else if (status == OFF)
            GPIO1->DR |= (1 << 3);
        break;
    }
}