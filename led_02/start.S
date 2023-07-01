
.global _start

_start:
    /* enter SVC mode */
    /* opertion on cpsr (special register) need use mrs, msr rather than ldr, str */
    mrs r0, cpsr
    bic r0, r0, #0x1f /* clear r0 5 low bit, that is clear the M0~M4 of cpsr */
    orr r0, r0, #0x13 /* r0 | 0x13, that is using SVC mode */
    msr cpsr, r0

    /* set stack pointer sp */
    ldr sp, =0x80200000

    /* jump to function main */
    b main