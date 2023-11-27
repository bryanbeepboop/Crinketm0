//-D0     :      PA08
//-D1     :      PA02
#include <stdint.h>


#define REG_PORT_DIR                0x41004400U
#define REG_PORT_DIRCLR             0x41004404U
#define REG_PORT_DIRSET             0x41004408U
#define REG_PORT_DIRTGL             0X4100440CU
#define REG_PORT_OUT                0x41004410U
#define REG_PORT_OUTCLR             0x41004414U
#define REG_PORT_OUTSET             0x41004418U
#define REG_PORT_OUTTGL             0x4100441CU
#define REG_PORT_IN                 0x41004420U
#define REG_PORT_CTRL               0x41004424U
#define REG_PORT_WRCONFIG           0x41004428U

#define PIN_D0                      8
#define PIN_D1                      2                     

volatile unsigned int time;

void main(void) {
    //configure PA08 and PA02, set as OUTPUT
    REG_PORT_DIRSET |= (1 << PIN_D0) | (1 << PIN_D1);
    while(1){
        for( time = 0; time < 5000; time++);
        REG_PORT_OUTSET |= (1 << PIN_D0) | (1 << PIN_D1);
        for( time = 0; time < 5000; time++);
        REG_PORT_OUTCLR |= (1 << PIN_D0) | (1 << PIN_D1);

    }


    
}
