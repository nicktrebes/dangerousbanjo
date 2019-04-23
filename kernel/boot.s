/* https://wiki.osdev.org/Bare_bones#Bootstrap_Assembly */

.set ALIGN,    1<<0             /* align loaded modules on page boundaries */
.set MEMINFO,  1<<1             /* provide memory map */
.set FLAGS,    ALIGN | MEMINFO  /* this is the Multiboot 'flag' field */
.set MAGIC,    0x1BADB002       /* 'magic number' lets bootloader find the header */
.set CHECKSUM, -(MAGIC + FLAGS) /* checksum of above, to prove we are multiboot */

.set HHBASE, 0xC0000000

# Multiboot header
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Allocate stack
.section .bootstrap_stack, "aw", @nobits
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

.section .text
.global _start
.type _start, @function
_start:
	# Physical address of boot_pt0
	movl $(boot_pt0 - HHBASE), %edi
	# Map to 0
	movl $0, %esi
	# Map 1023 pages; 1024 is VGA
	movl $1023, %ecx

1:
	# Only map the kernel
	cmpl $(_kernel_start - HHBASE), %esi
	jl 2f
	cmpl $(_kernel_end - HHBASE), %esi
	jge 3f

	# Map physical address as "present, writable". Note that this maps
	# .text and .rodata as writable. Mind security and map them as non-writable.
	movl %esi, %edx
	orl $0x003, %edx
	movl %edx, (%edi)

2:
	# Size of page is 4096 bytes.
	addl $4096, %esi
	# Size of entries in boot_page_table1 is 4 bytes.
	addl $4, %edi
	# Loop to the next entry if we haven't finished.
	loop 1b

3:
	# Map VGA video memory to 0xC03FF000 as "present, writable".
	movl $(0x000B8000 | 0x003), boot_pt0 - HHBASE + 1023 * 4
	# Map the page table to both virtual addresses 0x00000000 and 0xC0000000.
	movl $(boot_pt0 - HHBASE + 0x003), boot_pd - HHBASE + 0
	movl $(boot_pt0 - HHBASE + 0x003), boot_pd - HHBASE + 768 * 4

	# Set cr3 to the address of the boot_page_directory.
	movl $(boot_pd - HHBASE), %ecx
	movl %ecx, %cr3

	# Enable paging and the write-protect bit.
	movl %cr0, %ecx
	orl $0x80010000, %ecx
	movl %ecx, %cr0

	# Jump to higher half with an absolute jump.
	lea 4f, %ecx
	jmp *%ecx

4:
	# Unmap the identity mapping as it is now unnecessary.
	movl $0, boot_pd + 0

	# Reload crc3 to force a TLB flush so the changes to take effect.
	movl %cr3, %ecx
	movl %ecx, %cr3

	# Set up stack
	mov $stack_top, %esp
	# Push multiboot info and magic
	addl $(HHBASE), %ebx
	push %eax
	push %ebx

	/*
	This is a good place to initialize crucial processor state before the
	high-level kernel is entered. It's best to minimize the early
	environment where crucial features are offline. Note that the
	processor is not fully initialized yet: Features such as floating
	point instructions and instruction set extensions are not initialized
	yet. The GDT should be loaded here. Paging should be enabled here.
	C++ features such as global constructors and exceptions will require
	runtime support to work as well.
	*/

	call kmain

.global khalt
.type khalt, @function
khalt:
	cli
1:	hlt
	jmp 1b

.size _start, . - _start
