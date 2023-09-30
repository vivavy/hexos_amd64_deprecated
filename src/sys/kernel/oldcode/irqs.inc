irq0:
    inc dword [timer.ticks]
    inc byte [gs:78]
    cpu.outb<0x20, 0x20>
    iret

irq1:
    iret
