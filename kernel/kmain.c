/*
 * MIT License
 *
 * kernel/kmain.c
 * Copyright (C) 2019 Nick Trebes
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "gdt.h"
#include "idt.h"
#include "kio.h"
#include "kpage.h"
#include "kutil.h"
#include "kvaddr.h"
#include "multiboot.h"
#include "vga.h"

#define KVERSION_MAJOR (0)
#define KVERSION_MINOR (3)

//extern multiboot_info_t* kmultiboot_info;
extern uint32_t kmultiboot_magic;

void kmain() {
	const uint16_t* bda = (const uint16_t*)KVADDR_BIOS_DATA;
	uint32_t n;

	vga_init();
	kprintf("%s %u.%u\n","DANGEROUSBANJO",KVERSION_MAJOR,KVERSION_MINOR);

	if (kmultiboot_magic != MULTIBOOT_BOOTLOADER_MAGIC)
		kpanic("INVALID MULTIBOOT INFO");

	kprintf("%s","\nInitializing serial ports:\n");
	for (n = 1; n <= 4; ++n) {
		uint16_t port = bda[n - 1];
		if (port) {
			kprintf("%s%u=0x%x\n","COM",n,(uint32_t)port);
			serial_init(port);
		}
	}

	kprintf("%s","Initializing GDT...");
	kinit_gdt();
	kprintf("%s","done.\n");

	kprintf("%s","Initializing memory map...");
	kpage_init();
	kprintf("%s","done.\n");

	kprintf("%s","Initializing IDT...");
	kinit_idt();
	kprintf("%s","done.\n");

	kprintf("%s","\nGoodbye!\n");
}
