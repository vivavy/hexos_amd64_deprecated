if defined __PIT
else
__PIT equ 1

PIT_HZ = 119

macro pit.init a {
    __pit_init a
}

macro __pit_init hz {
    mov al, 0f9h
    out 21h, al
    mov al, 0efh
    out 0a1h, al
    mov al, 34h
    out 43h, al
    mov al, (1193180 / hz) AND 0ffh
    out 40h, al
    mov al, ((1193180 / hz) SHR 8h) AND 0ffh
    out 40h, al
}

end if
