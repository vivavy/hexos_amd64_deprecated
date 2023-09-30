if defined __CPU
else
__CPU equ 1

macro cpu.enable_pe a {
    __cpu_enable_pe a
}

macro __cpu_enable_pe {
    mov eax, cr0
    or al, 1
    mov cr0, eax
}

macro cpu.outb a {
    __cpu_outb a
}

macro __cpu_outb port, value {
    mov al, value
    out port, al
}

end if
