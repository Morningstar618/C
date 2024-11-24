ENTRY(_start)
OUTPUT_FORMAT(binary)

SECTIONS
{
    . = 1M;     /* Loading our kernel 1MB into memory */

    .text : ALIGN(4096)
    {
        *(.text)
    }

    .rodata : ALIGN(4096)  /* read only data section */
    {
        *(.rodata)
    }

    .data : ALIGN(4096)
    {
        *(.data)
    }

    .bss : ALIGN(4096)
    {
        *(COMMON)
        *(.bss)
    }

    .asm : ALIGN(4096)
    {
        *(.asm)
    }

}