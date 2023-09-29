//-D0     :      PA08
//-D1     :      PA02
#include <stdint.h>


#define REG_PORT_DIR                (*(uint32_t*)0x41004400U)
#define REG_PORT_DIRCLR             (*(uint32_t*)0x41004404U)
#define REG_PORT_DIRSET             (*(uint32_t*)0x41004408U)
#define REG_PORT_DIRTGL             (*(uint32_t*)0X4100440CU)
#define REG_PORT_OUT                (*(uint32_t*)0x41004410U)
#define REG_PORT_OUTCLR             (*(uint32_t*)0x41004414U)
#define REG_PORT_OUTSET             (*(uint32_t*)0x41004418U)
#define REG_PORT_OUTTGL             (*(uint32_t*)0x4100441CU)
#define REG_PORT_IN                 (*(uint32_t*)0x41004420U)
#define REG_PORT_CTRL               (*(uint32_t*)0x41004424U)
#define REG_PORT_WRCONFIG           (*(uint32_t*)0x41004428U)

#define PIN_D0                      8
#define PIN_D1                      2                     

volatile unsigned int time;

int main(void) {
    //configure PA08 and PA02, set as OUTPUT
    REG_PORT_DIRSET = (1 << PIN_D0) | (1 << PIN_D1);
    while(1){
        for( time = 0; time < 5000; time++);
        REG_PORT_OUTSET = (1 << PIN_D0) | (1 << PIN_D1);
        for( time = 0; time < 5000; time++);
        REG_PORT_OUTCLR = (1 << PIN_D0) | (1 << PIN_D1);

    }


    return 0;
}
