OBJECTS:=kernel/kernel.o kernel/test.o boot/boot.o
CC:=i686-elf-g++
SYSROOTINCLUDE:=../sysroot/usr/include/
CCFLAGS:=-g -ffreestanding -Wall -Wextra -fno-exceptions -fno-rtti -isystem $(SYSROOTINCLUDE) -D__is_kernel -Iinclude
LD:=i686-elf-g++
LDFLAGS:=-ffreestanding -nostdlib
ASM:=nasm
ASMFLAGS:= -felf32

LINKER.LD_PATH:=../configurations/linker/linker.ld

.PHONY: all clean

all: WinterOS.bin

WinterOS.bin: $(OBJECTS)
	$(LD) -T $(LINKER.LD_PATH) -o WinterOS.bin $(LDFLAGS) $(OBJECTS) -lgcc

%.o: %.cpp
	$(CC) -MD -c $< -o $@ $(CCFLAGS)

%.o: %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	find . -type f -name '*.o' -delete
	rm WinterOS.bin
