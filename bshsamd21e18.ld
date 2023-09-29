ENTRY(Reset_Handler); /* tells the linker the value of entry point in the generated ELF header */
MEMORY {
    /* IMPORTANT, SAMD21 boards have 8KB(0x2000) bootloader on flash */
    flash(rx)   : ORIGIN = 0x00002000, LENGTH = 256k
    sram(rwx)   : ORIGIN = 0x20000000, LENGTH = 32k
}
_estack         = ORIGIN(sram) + LENGTH(sram); /* Init Stack points to the end of SRAM */

SECTIONS {

    .vectors    : { KEEP(*(.vectors)) } > flash /* vector table */
    .text       : { *(.text*) }         > flash /* main.c */
    .rodata     : { *(.rodata*) }       > flash /* read only data, static const */

    .data : {           /* tell linker to create _sdata & _edata symbol  to use in reset()*/
        _sdata = .;     /* .data section start */
        *(.first_data)
        *(.data SORT(.data.*))
        _edata = .;     /* .data section end */
    } > sram AT > flash
    _sidata = LOADADDR(.data);  /* _sidata holds a copy of initial content of .data */

    .bss : {
        _sbss = .;      /* .bss section start */
        *(.bss SORT(.bss.*) COMMON)
        _ebss = .;      /* .bss section end */
    } > sram 

    . = ALIGN(8);
    _end = .;           /* for cmsis_gcc.h */
}   
