func print32
    lodsb
    cmp al, 0
    je .zero
    cmp al, 7
    je .bell
    cmp al, 8
    je .bs
    cmp al, 9
    je .tab
    cmp al, 10
    je .endl
    cmp al, 11
    je .vt
    cmp al, 12
    je .ff
    call putc32
    ; jmp .fixregs
.cont:
    jmp print32

.zero:
    ret

.bell:
    ;; TODO: make a bell
    jmp .cont
.bs:
    mov dx, word [tcur]
    mov cl, [tcurx]
    cmp dx, 0
    jle .cont
    cmp cl, 0
    jg @f
    mov cl, 162
@@:
    sub cl, 2
    sub dx, 2
    mov word [tcur], dx
    mov [tcurx], cl
    jmp .cont
.tab:
    mov dx, word [tcur]
    mov cl, [tcurx]
    add dx, 8
    add cl, 8
.fixregs:
    cmp cl, 160
    jl .cont
    sub cl, 160
    mov word [tcur], dx
    mov [tcurx], cl
    jmp .cont
.endl:
    mov dx, word [tcur]
    mov cl, [tcurx]
    add dx, 160
    xor ch, ch
    sub dx, cx
    mov cl, 0
    mov word [tcur], dx
    mov [tcurx], cl
    jmp .cont
.vt:
.ff:
    jmp .cont

func putc32
    mov dl, al
    xor eax, eax
    mov ax, word [tcur]
    mov byte [gs:eax], dl
    add word [tcur], 2
    add byte [tcurx], 2
    ret

tcur dw 0
tcurx db 0
