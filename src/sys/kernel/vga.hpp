#ifndef __VGA_HPP__
#define __VGA_HPP__

#include "macros.hpp"
#include "portio.hpp"
#include "types.hpp"

#define VGA_CTRL_REGISTER 0x3d4
#define VGA_DATA_REGISTER 0x3d5
#define VGA_OFFSET_LOW 0x0f
#define VGA_OFFSET_HIGH 0x0e

namespace vga {
    typedef struct {
        bool visible;
        int pos;
    } cursor_t;

    cursor_t cursor = {true, 0};

    char *buffer = (char *)0xb8000;

    void set_cursor(u16 offset) {
        offset /= 2;
        outb(VGA_CTRL_REGISTER, VGA_OFFSET_HIGH);
        outb(VGA_DATA_REGISTER, (u8) (offset >> 8));
        outb(VGA_CTRL_REGISTER, VGA_OFFSET_LOW);
        outb(VGA_DATA_REGISTER, (u8) (offset & 0xff));
    }

    int get_cursor() {
        outb(VGA_CTRL_REGISTER, VGA_OFFSET_HIGH);
        u16 offset = inb(VGA_DATA_REGISTER) << 8;
        outb(VGA_CTRL_REGISTER, VGA_OFFSET_LOW);
        offset += inb(VGA_DATA_REGISTER);
        return offset * 2;
    }

    void hide_cursor() {
        set_cursor(4000);
        cursor.visible = false;
    }

    void show_cursor() {
        set_cursor(cursor.pos);
        cursor.visible = true;
    }

    int init() {
        for (u16 i = 0; i < 4000; i++) {
            buffer[i] = '\0';
            buffer[++i] = '\x07';
        }
        cursor = {true, 0};
        return 0;
    }
}

extern "C" void __vga_init(void) {
    vga::init();
}

#endif
