%macro table 1
%1:
	dw _e%1 - _s%1
	dd _s%1
_s%1:
%endmacro

%macro endtable 1
_e%1:
%endmacro

%macro gate 1
	dw (%1 - $$) ; & 0ffffh
	dw 8
	db 0
	db 8eh
	dw 0 ;(%1 - $$) >> 16
%endmacro

%macro callc 1
	call %1
%endmacro

%macro callc 2
	__callc_push %2
	call %1
	__callc_pop %2
%endmacro

%macro __callc_push 0-*
	%rep %0
		%rotate -1
		push %1
	%endrep
%endmacro

%macro __callc_pop 0-*
	%assign i 0
	%rep %0
		%assign i i + 1
	%endrep
	add esp, ((i) * 4)
%endmacro


extern main
extern __print
extern string
extern __vga_init
extern interrupt

global _start

section .multiboot alloc

	dd 0x1BADB002
	dd 0
	dd -0x1BADB002

section .text exec write 

_start:
	mov esp, stack_top
	callc _asm_main
.infloop:
	cli
	hlt
	jmp .infloop
	ret

_asm_main:
	enter 0, 0
	callc __vga_init
	callc __print, {dword version}
	callc main
	leave
	ret

idt_init:
	enter 0, 0
	lidt [idt]
	sti
	leave
	ret

%include "src/sys/kernel/asm/interrupts.inc"

section .data

table idt

	%include "src/sys/kernel/asm/idt.inc"

endtable idt


section .rodata

version: db "HexCore ver 0.7.3 rev 0054", 10, 0

section .bss nobits write

	resb 2048

stack_top:
