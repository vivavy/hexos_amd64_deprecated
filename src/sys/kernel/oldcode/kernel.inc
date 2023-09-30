if defined __KERNEL
else
__KERNEL equ 1

macro a20.enable a {
    __a20_enable a
}

macro __a20_enable {
    call enable_a20
}

macro irqs.maskall a {
    __irqs_maskall a
}

macro __irqs_maskall {
    mov     al, 0ffh
    out     0a1h, al
    out     21h, al
}

struc proc id, base, limit, priority, ring {
    db id
    dd base
    dd limit
    ;; eax  ebx  ecx  edx  esp  ebp  eip  esi  edi 
    dd 0,   0,   0,   0,   0,   0,   0,   0,   0
    ;; cs   ds   es   ss   gs   fs
    dw 0,   0,   0,   0,   0,   0
    db priority OR (ring SHL 2) OR (1111 SHL 4)
}

RPL_KERN = 0
RPL_USER = 1

T_GDT = 0
T_LDT = 100b

CR0_PE = 1

macro cl a {
    __cl a
}

macro __cl [a] {
    forward
        cl#a
}

macro st a {
    __st a
}

macro __st [a] {
    forward
        st#a
}

macro func name {
name:
}

label fix func
data16 fix
data32 fix

macro segment a {
    a
}

null = 0

end if
