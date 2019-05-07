#include <kernel/types.h>
#ifdef __KERNEL_X86__

/*
 * MIT License
 *
 * arch/x86/boot/kmain.c
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

#include <kernel/info.h>
#include <kutil.h>
#include <multiboot.h>
#include <vga.h>

extern multiboot_info_t* kmultiboot_info __unused;
extern u32 kmultiboot_magic;

void kmain(void) {
	vga_init();

	kprintf("%s %u.%u.%u\n",KERNEL_NAME,
		KERNEL_VERSION_MAJOR,
		KERNEL_VERSION_MINOR,
		KERNEL_VERSION_PATCH);

	if (kmultiboot_magic != MULTIBOOT_BOOTLOADER_MAGIC)
		kpanic("INVALID MULTIBOOT");

	khalt();
}

#endif /* ! __KERNEL_X86__ */
