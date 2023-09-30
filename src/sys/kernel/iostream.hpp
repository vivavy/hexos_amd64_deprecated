#ifndef __KSTDIO_HPP__
#define __KSTDIO_HPP__

#include "vga.hpp"
#include "types.hpp"

#define IOSTREAM_DEFAULT_COLORS 0x07

void putc(char c) {
    if (c == '\n') {
        vga::cursor.pos = vga::cursor.pos / 80 * 80 + 80;
    }
    else if (c == '\b') {
        vga::cursor.pos--;
    } else if (c == '\t') {
        vga::cursor.pos += 4;
    } else if (c == '\r') {
        vga::cursor.pos = vga::cursor.pos / 80 * 80;
    } else {
        vga::buffer[vga::cursor.pos*2] = c;
        vga::buffer[vga::cursor.pos*2+1] = IOSTREAM_DEFAULT_COLORS;
        vga::cursor.pos++;
        if (vga::cursor.pos > 2000)
            vga::cursor.pos = 0;
        else if (vga::cursor.pos < 0)
            vga::cursor.pos = 0;
    }

    if (vga::cursor.visible)
        vga::set_cursor(vga::cursor.pos);
};

void putcs(char c, char s) {
    if (c == '\n') {
        vga::cursor.pos = vga::cursor.pos / 80 * 80 + 80;
    }
    else if (c == '\b') {
        vga::cursor.pos--;
    } else if (c == '\t') {
        vga::cursor.pos += 4;
    } else if (c == '\r') {
        vga::cursor.pos = vga::cursor.pos / 80 * 80;
    } else {
        vga::buffer[vga::cursor.pos*2] = c;
        vga::buffer[vga::cursor.pos*2+1] = s;
        vga::cursor.pos++;
        if (vga::cursor.pos > 2000)
            vga::cursor.pos = 0;
        else if (vga::cursor.pos < 0)
            vga::cursor.pos = 0;
    }
};

void print(const char *text) {
    char c;
    for (int i = 0; (c = text[i]); i++) {
        putc(c);
    };
};

void prints(const char *text, const char *style) {
    char c; char s = IOSTREAM_DEFAULT_COLORS;
    bool stylish = true;
    for (int i = 0; (c = text[i]); i++) {
        if (stylish) {
            if (style[i])
                s = style[i];
            else
                stylish = false;
        }
        putcs(c, s);
    };
};

void clear() {
    for (int i = 0; i < 4000; i++) {
        vga::buffer[i] = ' ';
        vga::buffer[++i] = 0x0f;
    }
};

uint32 digit_count(int num)
{
  uint32 count = 0;
  if(num == 0)
    return 1;
  while(num > 0){
    count++;
    num = num/10;
  }
  return count;
}

uint32 digit_countb(u8 num)
{
  uint32 count = 0;
  if(num == 0)
    return 1;
  while(num > 0){
    count++;
    num = num/10;
  }
  return count;
}

void itoa(int num, char *number)
{
    bool neg = false;
    if (num < 0) {
        number[0] = '-';
        num = -num;
        neg = true;
    }
    int dgcount = digit_count(num);
    int index = dgcount - 1;
    char x;
    if(num == 0 && dgcount == 1){
        number[0] = '0';
        number[1] = '\0';
    } else {
        while(num != 0) {
            x = num % 10;
            number[index] = x + '0';
            index--;
            num = num / 10;
        }
        number[dgcount + (neg ? 1 : 0)] = '\0';
    }
}

void utoa(int num, char *number)
{
    int dgcount = digit_count(num);
    int index = dgcount - 1;
    char x;
    if(num == 0 && dgcount == 1){
        number[0] = '0';
        number[1] = '\0';
    } else {
        while(num != 0) {
            x = num % 10;
            number[index] = x + '0';
            index--;
            num = num / 10;
        }
        number[dgcount] = '\0';
    }
}

void ibtoa(i8 num, char *number)
{
    bool neg = false;
    if (num < 0) {
        number[0] = '-';
        num = -num;
        neg = true;
    }
    int dgcount = digit_countb(num);
    int index = dgcount - (neg ? 0 : 1);
    char x;
    if(num == 0 && dgcount == 1){
        number[0] = '0';
        number[1] = '\0';
    } else {
        while(num != 0) {
            x = num % 10;
            number[index] = x + '0';
            index--;
            num = num / 10;
        }
        number[dgcount + (neg ? 1 : 0)] = '\0';
    }
}

void ubtoa(u8 num, char *number)
{
    int dgcount = digit_countb(num);
    int index = dgcount - 1;
    char x;
    if(num == 0 && dgcount == 1){
        number[0] = '0';
        number[1] = '\0';
    } else {
        while(num != 0) {
            x = num % 10;
            number[index] = x + '0';
            index--;
            num = num / 10;
        }
        number[dgcount] = '\0';
    }
}

void strcat(char *s1, char *s2, char *buff) {
    int index = 0;
    char c;

    for (int i = 0; (c = s1[i]); i++, index++)
        buff[index] = c;
    for (int i = 0; (c = s2[i]); i++, index++)
        buff[index] = c;

    buff[index+1] = 0;
}

extern "C" {
    void __print(const char *text) {
        print(text);
    }
}

#endif
