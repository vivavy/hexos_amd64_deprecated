#ifndef __PORTIO_HPP__
#define __PORTIO_HPP__

#include "types.hpp"

u8 inb(u16 port)
{
  u8 ret;
  asm volatile("inb %1, %0" : "=a"(ret) : "d"(port));
  return ret;
}

void outb(u16 port, u8 data)
{
  asm volatile("outb %0, %1" : "=a"(data) : "d"(port));
}

u16 inw(u16 port)
{
  u16 ret;
  asm volatile("inw %1, %0" : "=a"(ret) : "d"(port));
  return ret;
}

void outw(u16 port, u16 data)
{
  asm volatile("outw %0, %1" : "=a"(data) : "d"(port));
}

#endif
