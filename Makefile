PORT=/dev/ttyACM0

CFLAGS	?=	-Wall -W -Werror \
			-g -fno-common -Os -ffunction-sections -fdata-sections -I. \
			-DF_CPU=48000000UL -mcpu=cortex-m0plus -mthumb
LDFLAGS ?=	-Tbshsamd21e18.ld -nostartfiles -W
SOURCES = main.c startup.c

build:	firmware.bin

firmware.elf: $(SOURCES)
		arm-none-eabi-gcc $(SOURCES) $(CFLAGS) $(LDFLAGS) -o $@

firmware.bin: firmware.elf
		arm-none-eabi-objcopy -O binary $< $@

flash: firmware.bin
		bossac -i -d --port=${PORT} --usb-port=true -e -w -v -R --offset=0x2000 firmware.bin

clean:
		rm -f firmware.* 
		