#include <xc.h>
.text
.set noreorder

.global asmfunction
.ent asmfunction

asmfunction:
    addiu t1,zero,4
    addiu t2, zero, 2
    subu t3, t1, t2
    addiu t4,zero,5
    multu t4,t3
    mfhi t6
    mflo t5
    nop
    la s0, global_cVariable
    sw t5, 0(s0)
    jr ra
    nop
.end asmfunction