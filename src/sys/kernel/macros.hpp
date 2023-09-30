#ifndef __MACROS_HPP__
#define __MACROS_HPP__

#define true 1
#define false 0
#define bool int

#define lo16(a) (u16)((a) & 0xFFFF)
#define hi16(a) lo16(((a) >> 16))
#define lo8(a) (u8)((a) & 0xFF)
#define hi8(a) lo8(((a) >> 8))

#endif
