#ifndef __SYSTEM_HPP__
#define __SYSTEM_HPP__

#include "iostream.hpp"
#include "types.hpp"

namespace sys {

	void hlt(void) {asm volatile ("hlt");}
	void nop(void) {asm volatile ("nop");}

	void ok(const char *message) {
		prints("[*] ", "\x0f\x02\x0f\x07");
		print(message);
		print("\n");
	}

	void bad(const char *message) {
		prints("[!] ", "\x0f\x0e\x0f\x07");
		print(message);
		print("\n");
	}

	void warn(const char *message) {
		prints("[\x13] ", "\x0f\x0d\x0f\x07");
		print(message);
		print("\n");
	}

	void panic(const char *message) {
		prints("[X] ", "\x0f\x04\x0f\x07");
		print(message);
		print(". System halted\n");
		hlt();
	}

	void sleep(uint32 timer_count)
	{
	  	for (;;) {
	    		nop();
	    		timer_count--;
	    		if(timer_count <= 0)
	    	  	break;
	  	}
	}
}

#endif
