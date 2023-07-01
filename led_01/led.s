/*
 * arm assembly
 * led demo
 */

.global _start /* global mark */

_start: /* default entry */
    /* step1. enable all clocks */
    ldr r0, =0x020c4068 /* address of CCGR0 */
    ldr r1, =0xffffffff /* value to set */
    str r1, [r0]

    ldr r0, =0x020c406c /* address of CCGR1 */
    str r1, [r0]

    ldr r0, =0x020c4070 /* address of CCGR2 */
    str r1, [r0]

    ldr r0, =0x020c4074 /* address of CCGR3 */
    str r1, [r0]

    ldr r0, =0x020c4078 /* address of CCGR4 */
    str r1, [r0]

    ldr r0, =0x020c407c /* address of CCGR5 */
    str r1, [r0]

    ldr r0, =0x020c4080 /* address of CCGR6 */
    str r1, [r0]

    /* step2. set PIN GPIO1_IO03 as GPIO1_IO03 */
    ldr r0, =0x020e0068 /* address of SW_MUX_GPIO1_IO03_BASE */
    ldr r1, =0x5 
    str r1, [r0]

    /* step3. config IO attribution of GPIO1_IO03 */
    ldr r0, =0x020e02f4 /* address of SW_PAD_GPIO1_IO03_BASE */
    ldr r1, =0x10b0
    str r1, [r0]

    /* step4. set GPIO1_IO03 to OUTPUT mode */
    ldr r0, =0x0209c004 /* address of GPIO1_GDIR */
    ldr r1, =0x00000008
    str r1, [r0]

    /* step5. open led by setting GPIO1_IO03 to output low level */
    ldr r0, =0x0209c000 /* address of GPIO1_DR */
    ldr r1, =0
    str r1, [r0]

    /* enter endless loop */
loop: 
    b loop
