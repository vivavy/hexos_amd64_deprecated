/* entry point of our kernel */
ENTRY(_start)

SECTIONS
{
	/* we need 1MB of space atleast */
	. = 1M;

  	/* text section */
	.text BLOCK(1) : ALIGN(1)
	{
		*(.multiboot)
		*(.text)
	}

	/* read only data section */
	.rodata BLOCK(1) : ALIGN(1)
	{
		*(.rodata)
	}

	/* data section */
	.data BLOCK(1) : ALIGN(1)
	{
		*(.data)
	}

	/* bss section */
	.bss BLOCK(1) : ALIGN(1)
	{
		*(COMMON)
		*(.bss)
	}

}