#include "types.hpp"
#include "iostream.hpp"
#include "vga.hpp"
#include "system.hpp"

const char *version = "HexOS ver 0.9.1 rev 0926\n";


extern "C" void interrupt(u32 index) {
	print("INT!\n");
}

void main(void) {
	print(version);
	// asm volatile("int $0");
}
