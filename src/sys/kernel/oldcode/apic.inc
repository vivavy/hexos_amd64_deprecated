if defined __APIC
else
__APIC equ 1

macro apic.send_eoi a {
    __apic_send_eoi a
}

macro __apic_send_eoi {
    mov al, 20h
    out 20h, al
}

end if
