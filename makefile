.build/boot/$(KERNEL).bin:
	make -C kernel

.build/boot/grub/grub.cfg:
	mkdir -p .build/boot/grub
	cp grub.cfg .build/boot/grub/grub.cfg

$(KERNEL).iso: .build/boot/grub/grub.cfg verify
	grub-mkrescue -o $@ .build

all: $(KERNEL).iso

clean:
	rm -rf .build $(KERNEL).iso kernel.log
	make -C kernel clean

test: all
	qemu-system-$(ARCH) -m 4G -cdrom $(KERNEL).iso -serial file:kernel.log

verify: .build/boot/$(KERNEL).bin
	grub-file --is-x86-multiboot .build/boot/$(KERNEL).bin