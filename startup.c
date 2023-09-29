#include  <stdint.h>

/* Default empty handler */
void Dummy_Handler( void );

void Reset_Handler( void );

// Cortex-M0+ core Handlers
void NMI_Handler            ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void HardFault_Handler      ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SVC_Handler            ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PendSV_Handler         ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SysTick_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
// Peripherals Handlers
void PM_Handler             ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SYSCTRL_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void WDT_Handler            ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void RTC_Handler            ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void EIC_Handler            ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void NVMCTRL_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void DMAC_Handler           ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void USB_Handler            ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void EVSYS_Handler          ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SERCOM0_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SERCOM1_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SERCOM2_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SERCOM3_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SERCOM4_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void SERCOM5_Handler        ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TTC0_Handler           ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TTC1_Handler           ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TTC2_Handler           ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC3_Handler            ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC4_Handler            ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC5_Handler            ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC6_Handler            ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void TC7_Handler            ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void ADC_Handler            ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void AC_Handler             ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void DAC_Handler            ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void PTC_Handler            ( void ) __attribute__ ((weak, alias("Dummy_Handler")));
void I2S_Handler            ( void ) __attribute__ ((weak, alias("Dummy_Handler")));

// Vector Table
extern void _estack(void); // Defined in bshsamd32e18.ld

// Array of function pointers
__attribute__((section(".vectors"))) void (*const isrVectors[44])(void) = {
    //First two essential 
    _estack, Reset_Handler,
    //System Core Handlers
    NMI_Handler,
    HardFault_Handler,
    0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL,
    SVC_Handler,
    0UL, 0UL,
    PendSV_Handler,
    SysTick_Handler,
    //Peripheral Handlers (Configurable Interrupts)
    PM_Handler,
    SYSCTRL_Handler,
    WDT_Handler,
    RTC_Handler,
    EIC_Handler,
    NVMCTRL_Handler,
    DMAC_Handler,
    USB_Handler,
    EVSYS_Handler,
    SERCOM0_Handler,
    SERCOM1_Handler,
    SERCOM2_Handler,
    SERCOM3_Handler,
    SERCOM4_Handler,
    SERCOM5_Handler,
    TTC0_Handler,
    TTC1_Handler,
    TTC2_Handler,
    TC3_Handler,
    TC4_Handler,
    TC5_Handler,
    TC6_Handler,
    TC7_Handler,
    ADC_Handler,
    AC_Handler,
    DAC_Handler,
    PTC_Handler,
    I2S_Handler
};

// Startup Code
__attribute__((naked, noreturn)) void Reset_Handler (void){
    // memset .bss to zero & copy .data section to RAM 
    extern long _sbss, _ebss, _sdata, _edata, _sidata;
    for( long *dst = &_sbss; dst < &_ebss; dst++ ) *dst = 0;
    for( long *dst = &_sdata, *src = &_sidata; dst < &_edata; ) *dst++ = *src++;
    extern void main(void);
    for (;;) (void) 0; // Infinite Loop after main() returns
}

void Dummy_Handler( void )
{
    while( 1 ){
    }
}