#include "imx6ul.h"

/*
 * @description: enable all peripheral clock
 */
void clk_enable(void)
{
    CCM->CCGR0 = 0xffffffff;
    CCM->CCGR1 = 0xffffffff;
    CCM->CCGR2 = 0xffffffff;
    CCM->CCGR3 = 0xffffffff;
    CCM->CCGR4 = 0xffffffff;
    CCM->CCGR5 = 0xffffffff;
    CCM->CCGR6 = 0xffffffff;
}

void led_init(void)
{
    /* use PIN GPIO1_IO03 as GPIO1_IO03 */
    IOMUX_SW_MUX->GPIO1_IO03 = 0x5;
    /* config attribution of PIN GPIO1_IO03 */
    IOMUX_SW_PAD->GPIO1_IO03 = 0x10b0;
    /* set GPIO1_IO03 to OUTPUT mode */
    GPIO1->GDIR = 0x00000008;
    /* open led by output low level */
    GPIO1->DR = 0x0;
}

void led_on(void)
{
    /* set bit3 to 0 */
    GPIO1->DR &= ~(1 << 3);
}

void led_off(void)
{
    /* set bit3 to 1 */
    GPIO1->DR |= (1 << 3);
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