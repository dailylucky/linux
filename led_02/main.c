#include "main.h"

/*
 * @description: enable all peripheral clock
 */
void clk_enable(void)
{
    CCM_CCGR0 = 0xffffffff;
    CCM_CCGR1 = 0xffffffff;
    CCM_CCGR2 = 0xffffffff;
    CCM_CCGR3 = 0xffffffff;
    CCM_CCGR4 = 0xffffffff;
    CCM_CCGR5 = 0xffffffff;
    CCM_CCGR6 = 0xffffffff;
}

void led_init(void)
{
    /* use PIN GPIO1_IO03 as GPIO1_IO03 */
    SW_MUX_GPIO1_IO_03 = 0x5;
    /* config attribution of PIN GPIO1_IO03 */
    SW_PAD_GPIO1_IO_03 = 0x10b0;
    /* set GPIO1_IO03 to OUTPUT mode */
    GPIO1_GDIR = 0x00000008;
    /* open led by output low level */
    GPIO1_DR = 0x0;
}

void led_on(void)
{
    /* set bit3 to 0 */
    GPIO1_DR &= ~(1 << 3);
}

void led_off(void)
{
    /* set bit3 to 1 */
    GPIO1_DR |= (1 << 3);
}

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

int main(void)
{
    clk_enable(); 
    led_init();

    while (1)
    {
        led_off();
        delay(500);
        led_on();
        delay(500);
    }

    return 0;
}