if defined __DISPLAY
else
__DISPLAY equ 1

BLACK = 0
BLUE = 1
GREEN = 2
AQUA = 3
MAROON = 4
VIOLET = 5
BROWN = 6
GRAY = 7
DARKGRAY = 8
SKYBLUE = 9
LIME = 0ah
CYAN = 0bh
RED = 0ch
PURPLE = 0dh
YELLOW = 0eh
WHITE = 0fh

WITH equ SHL 4 OR

macro disp_set_palette_03h color {
    mov bh, color
    call __disp_set_palette_03h
}

macro __disp_set_palette mode, palette {
    disp_set_palette_#mode palette
}

macro disp.set_palette a {
    __disp_set_palette a
}

macro disp.hide_text_cursor a {
    __disp_hide_text_cursor a
}

macro __disp_hide_text_cursor {
    mov ah, 1
    mov cx, 0706h
    int 10h
}

macro __disp_print16 string {
    mov si, string
    call print16
}

macro disp.print16 a {
    __disp_print16 a
}

macro __disp_print32 string {
    mov esi, string
    call print32
}

macro disp.print32 a {
    __disp_print32 a
}

macro disp.save_text_cursor a {
    __disp_save_text_cursor a
}

macro __disp_save_text_cursor ofs, x {
    mov ah, 3
    mov bh, 0
    int 10h
    mov [x], dl
    xor ah, ah
    mov al, dh
    mov cl, 80
    mul cl
    xor dh, dh
    add ax, dx
    mov word [ofs], ax
}

end if
