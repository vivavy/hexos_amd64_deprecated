#!/bin/make


main:
	@clear
	@make run >/dev/null || make error 1>/dev/null

run: iso
	@qemu-system-i386 images/hexos.iso -m 32M 2>/dev/null

iso: kernel
	@mkdir -p dst/boot/grub dst/sys
	@mv build/kernel.elf dst/sys/kernel.elf
	@cp scripts/grub.cfg dst/boot/grub/grub.cfg
	@grub-mkrescue -o images/hexos.iso dst 1>/dev/null 2>/dev/null

kernel: kcore.asm kmain.c
	@i686-elf-gcc -T scripts/linker.ld -o build/kernel.elf -ffreestanding -O2 -nostdlib build/kcore.o build/main.o

kcore.asm:
	@nasm src/sys/kernel/asm/kcore.asm -f elf32 -o build/kcore.o

kmain.c:
	@i686-elf-g++ -c src/sys/kernel/main.cpp -o build/main.o -ffreestanding -O2 -Wall -Wextra -Werror -Wno-unused-variable -Wno-unused-parameter

error:
	@printf ""
