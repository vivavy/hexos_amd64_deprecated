func enable_a20
    in      al, 0x64
    test    al, 2
    jnz     enable_a20
    mov     al, 0xD1
    out     0x64, al
.2:
    in      al, 0x64
    test    al, 2
    jnz     .2
    mov     al, 0xDF
    out     0x60, al
.3:
    in      al, 0x64
    test    al, 2
    jnz     .3
    mov     al, 0xFF
    out     0x64, al
    ret
