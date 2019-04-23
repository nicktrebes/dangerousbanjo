CSRC = $(wildcard *.c)
COBJ = $(CSRC:.c=.o)
SSRC = $(wildcard *.s)
SOBJ = $(SSRC:.s=.o)

%.o: %.c
	$(CC) -c $< -o $@ -std=gnu99 -ffreestanding -O2 -nostdinc -Wall -Wextra -I../include

%.o: %.s
	$(AS) $< -o $@

../.build/boot/$(KERNEL).bin: $(COBJ) $(SOBJ) linker.ld
	mkdir -p ../.build/boot
	$(CC) -T linker.ld -o $@ -ffreestanding -O2 -nostdlib $(SOBJ) $(COBJ) -lgcc

all: ../.build/boot/$(KERNEL).bin

clean:
	rm -rf *.o