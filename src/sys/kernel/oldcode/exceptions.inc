exc0:
    cli
    mov eax, [mt.current_task]
    mov [exc.task], eax
    mov eax, 0   ; scope 0 - base I/O
    mov ecx, -1  ; cond -1 - crash, 0 - exit, -2 - kill, -3 - stop
    mov edx, 0   ; status - zerodiv
    iret

exc1:
    cli
    mov eax, [mt.current_task]
    mov [exc.task], eax
    mov eax, 0   ; scope 0 - base I/O
    mov ecx, -1  ; cond -1 - crash, 0 - exit, -2 - kill, -3 - stop
    mov edx, 1   ; status - debugexc
    iret

exc2:
    cli
    mov eax, [mt.current_task]
    mov [exc.task], eax
    mov eax, 0   ; scope 0 - base I/O
    mov ecx, -1  ; cond -1 - crash, 0 - exit, -2 - kill, -3 - stop
    mov edx, 2   ; status - nmie
    iret

exc3:
    cli
    mov eax, [mt.current_task]
    mov [exc.task], eax
    mov eax, 0   ; scope 0 - base I/O
    mov ecx, -1  ; cond -1 - crash, 0 - exit, -2 - kill, -3 - stop
    mov edx, 3   ; status - bpe
    iret

exc4:
    cli
    mov eax, [mt.current_task]
    mov [exc.task], eax
    mov eax, 0   ; scope 0 - base I/O
    mov ecx, -1  ; cond -1 - crash, 0 - exit, -2 - kill, -3 - stop
    mov edx, 4   ; status - intodofe
    iret

exc5:
    cli
    mov eax, [mt.current_task]
    mov [exc.task], eax
    mov eax, 0   ; scope 0 - base I/O
    mov ecx, -1  ; cond -1 - crash, 0 - exit, -2 - kill, -3 - stop
    mov edx, 5   ; status - ofbe
    iret

exc6:
    cli
    mov eax, [mt.current_task]
    mov [exc.task], eax
    mov eax, 0   ; scope 0 - base I/O
    mov ecx, -1  ; cond -1 - crash, 0 - exit, -2 - kill, -3 - stop
    mov edx, 6   ; status - ioe
    iret

exc7:
    cli
    mov eax, [mt.current_task]
    mov [exc.task], eax
    mov eax, 0   ; scope 0 - base I/O
    mov ecx, -1  ; cond -1 - crash, 0 - exit, -2 - kill, -3 - stop
    mov edx, 7   ; status - nce
    iret

exc8:
    cli
    mov eax, [mt.current_task]
    mov [exc.task], eax
    mov eax, 0   ; scope 0 - base I/O
    mov ecx, -1  ; cond -1 - crash, 0 - exit, -2 - kill, -3 - stop
    mov edx, 8   ; status - dfe
    iret

exc9:
    cli
    mov eax, [mt.current_task]
    mov [exc.task], eax
    mov eax, 0   ; scope 0 - base I/O
    mov ecx, -1  ; cond -1 - crash, 0 - exit, -2 - kill, -3 - stop
    mov edx, 9   ; status - csoe
    iret

exc10:
    cli
    mov eax, [mt.current_task]
    mov [exc.task], eax
    mov eax, 0   ; scope 0 - base I/O
    mov ecx, -1  ; cond -1 - crash, 0 - exit, -2 - kill, -3 - stop
    mov edx, 10  ; status - btsse
    iret

exc11:
    cli
    mov eax, [mt.current_task]
    mov [exc.task], eax
    mov eax, 0   ; scope 0 - base I/O
    mov ecx, -1  ; cond -1 - crash, 0 - exit, -2 - kill, -3 - stop
    mov edx, 11  ; status - snpe
    iret

exc12:
    cli
    mov eax, [mt.current_task]
    mov [exc.task], eax
    mov eax, 0   ; scope 0 - base I/O
    mov ecx, -1  ; cond -1 - crash, 0 - exit, -2 - kill, -3 - stop
    mov edx, 12  ; status - sfe
    iret

exc13:
    cli
    mov eax, [mt.current_task]
    mov [exc.task], eax
    mov eax, 0   ; scope 0 - base I/O
    mov ecx, -1  ; cond -1 - crash, 0 - exit, -2 - kill, -3 - stop
    mov edx, 13  ; status - gpfe
    ; hlt
    iret

exc14:
    cli
    mov eax, [mt.current_task]
    mov [exc.task], eax
    mov eax, 0   ; scope 0 - base I/O
    mov ecx, -1  ; cond -1 - crash, 0 - exit, -2 - kill, -3 - stop
    mov edx, 14  ; status - pfe
    iret

exc15:
    cli
    mov eax, [mt.current_task]
    mov [exc.task], eax
    mov eax, 0   ; scope 0 - base I/O
    mov ecx, -1  ; cond -1 - crash, 0 - exit, -2 - kill, -3 - stop
    mov edx, 15  ; status - uie
    iret

exc16:
    cli
    mov eax, [mt.current_task]
    mov [exc.task], eax
    mov eax, 0   ; scope 0 - base I/O
    mov ecx, -1  ; cond -1 - crash, 0 - exit, -2 - kill, -3 - stop
    mov edx, 16  ; status - cfe
    iret

exc17:
    cli
    mov eax, [mt.current_task]
    mov [exc.task], eax
    mov eax, 0   ; scope 0 - base I/O
    mov ecx, -1  ; cond -1 - crash, 0 - exit, -2 - kill, -3 - stop
    mov edx, 17  ; status - ace
    iret

exc18:
    cli
    mov eax, [mt.current_task]
    mov [exc.task], eax
    mov eax, 0   ; scope 0 - base I/O
    mov ecx, -1  ; cond -1 - crash, 0 - exit, -2 - kill, -3 - stop
    mov edx, 18  ; status - mce
    iret

exc19:
exc20:
exc21:
exc22:
exc23:
exc24:
exc25:
exc26:
exc27:
exc28:
exc29:
exc30:
exc31:
    cli
    mov eax, [mt.current_task]
    mov [exc.task], eax
    mov eax, 0   ; scope 0 - base I/O
    mov ecx, -1  ; cond -1 - crash, 0 - exit, -2 - kill, -3 - stop
    mov edx, 19  ; status - uee
    iret
