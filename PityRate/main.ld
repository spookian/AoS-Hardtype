"currentEnemyPity" = 0x02027FF0;

SECTIONS
{
	. = 0x08000000;
	baserom : { KEEP(*(baserom) ) }
	ENDROM = .;
	
	. = 0x080684EC;
	pityFuncHook : { KEEP( trampoline.o(pityFuncHook) ) }
	

	. = ENDROM;
	pityHack : { KEEP(*(pityHack)) }
	
	.text : { KEEP(*(.text .text.*)) }
	.data :
	{
		KEEP(*(.rodata .rodata.*))
		KEEP(*(.data .data.*)) 
		KEEP(*(.sdata .sdata.* ))
		KEEP(*(.sdata2 .sdata2.*))
		KEEP(*(.bss .bss.*))
		KEEP(*(.sbss2 .sbss2.*))
		KEEP(*(.sbss .sbss.*))
	}
	
}