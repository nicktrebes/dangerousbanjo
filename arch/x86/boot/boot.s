/*
 * MIT License
 *
 * arch/x86/boot/boot.s
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

# Define multiboot header constants
.set ALIGN,    (1<<0)
.set MEMINFO,  (1<<1)
.set FLAGS,    (ALIGN | MEMINFO)
.set MAGIC,    (0x1BADB002)
.set CHECKSUM, (-(MAGIC + FLAGS))

# Define higher-half base address
.set HHBASE, 0xC0000000

# Multiboot header
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Allocate stack
.section .boot_stack, "aw", @nobits
.align 16
stack_bottom:
.skip 16384
stack_top:

# Allocate pages for paging
.section .bss, "aw", @nobits
.align 4096
boot_pd:
.skip 4096
boot_pt0:
.skip 4096
# Declare kernel variables for multiboot info and magic
.global kmultiboot_info
.type kmultiboot_info, @object
kmultiboot_info:
.skip 4
.global kmultiboot_magic
.type kmultiboot_magic, @object
kmultiboot_magic:
.skip 4

.section .text
.extern kmain
.global _start
.global khalt
.type kmain, @function
.type _start, @function
.type khalt, @function

_start:
	# Move multiboot info and magic to kernel variables
	movl $(kmultiboot_info - HHBASE), %edi
	movl %ebx, (%edi)
	movl $(kmultiboot_magic - HHBASE), %edi
	movl %eax, (%edi)

	# Physical address of boot_pt0
	movl $(boot_pt0 - HHBASE), %edi
	movl $0, %esi
	movl $1024, %ecx

1:
	# Physical page address
	movl %esi, %edx
	# Map VGA text buffer as "present, writable"
	cmpl $0x000B8000, %esi
	je 2f
	# Map kernel data as "present, writable"
	cmpl $(_kernel_data), %esi
	jge 2f
	# Map kernel text/rodata and other data as "present"
	jmp 3f

2:
	# "present, writable"
	orl $0x003, %edx
	jmp 4f

3:
	# "present"
	orl $0x001, %edx

4:
	# Map page with appropriate flags
	movl %edx, (%edi)
	addl $4096, %esi
	addl $4, %edi
	loop 1b

5:
	# Identity map
	movl $(boot_pt0 - HHBASE + 0x003), boot_pd - HHBASE + 0
	# Higher-half map
	movl $(boot_pt0 - HHBASE + 0x003), boot_pd - HHBASE + 768 * 4
	# Recursive entry
	movl $(boot_pd - HHBASE + 0x003), boot_pd - HHBASE + 1023 * 4

	# Set cr3 to the address of the page directory
	movl $(boot_pd - HHBASE), %ecx
	movl %ecx, %cr3

	# Enable paging and the write-protect bit
	movl %cr0, %ecx
	orl $0x80010000, %ecx
	movl %ecx, %cr0

	# Jump to higher half with an absolute jump
	lea 6f, %ecx
	jmp *%ecx

6:
	# Reload crc3 to force a TLB flush
	movl %cr3, %ecx
	movl %ecx, %cr3

	# Set up stack
	mov $stack_top, %esp

	# Enter C environment
	call kmain

khalt:
	cli
1:	hlt
	jmp 1b

.size _start, . - _start
