/*
 * MIT License
 *
 * kernel/int_handler.c
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

#include "kattr.h"
#include "kio.h"
#include "kpage.h"
#include "kutil.h"
#include "kvaddr.h"

#define PAGE_PROT  (1<<4)
#define PAGE_WRITE (1<<3)
#define PAGE_USER  (1<<2)
#define PAGE_RSRV  (1<<1)
#define PAGE_FETCH (1<<0)

static inline void _flush_tlb(void);
static inline uint32_t _get_cr2(void);

void CDECL int14_handler(uint32_t error) {
	uint32_t *pd, *pt;
	uint32_t pde, pdi, pti, vaddr;

	vaddr = _get_cr2();
	klogf("%s operation on virtual address 0x%08x\n",
		((error & PAGE_WRITE) ? "Read" : "Write"),vaddr);

	if (error & PAGE_PROT) {
		// TODO
		kpanic("PAGE PROTECTION VIOLATION");
	} else if (error & PAGE_USER) {
		// TODO
		kpanic("PRIVILEGE VIOLATION");
	} else if (error & PAGE_RSRV) {
		// TODO
		kpanic("RESERVED WRITE");
	} else if (error & PAGE_FETCH) {
		// TODO
		kpanic("INSTRUCTION FETCH");
	}

	pd = (uint32_t*)0xFFFFF000;
	pdi = (vaddr >> 22);
	pde = pd[pdi];
	if ((pde & 1) == 0) {
		pde = (((uint32_t)kpage_alloc()) | 0x003);
		pd[pdi] = pde;
	}

	pt = (uint32_t*)(0xFFC00000 + pdi);
	pti = ((vaddr >> 12) & 0x000003FF);
	pt[pti] = (((uint32_t)kpage_alloc()) | 0x003);

	_flush_tlb();
	outb(0x20,0x20);
}

void irq0_handler(void) {
	// TODO
	outb(0x20,0x20);
}

void irq1_handler(void) {
	// TODO
	outb(0x20,0x20);
}

void irq2_handler(void) {
	// TODO
	outb(0x20,0x20);
}

void irq3_handler(void) {
	// TODO
	outb(0x20,0x20);
}

void irq4_handler(void) {
	// TODO
	outb(0x20,0x20);
}

void irq5_handler(void) {
	// TODO
	outb(0x20,0x20);
}

void irq6_handler(void) {
	// TODO
	outb(0x20,0x20);
}

void irq7_handler(void) {
	// TODO
	outb(0x20,0x20);
}

void irq8_handler(void) {
	// TODO
	outb(0xA0,0x20);
	outb(0x20,0x20);
}

void irq9_handler(void) {
	// TODO
	outb(0xA0,0x20);
	outb(0x20,0x20);
}

void irq10_handler(void) {
	// TODO
	outb(0xA0,0x20);
	outb(0x20,0x20);
}

void irq11_handler(void) {
	// TODO
	outb(0xA0,0x20);
	outb(0x20,0x20);
}

void irq12_handler(void) {
	// TODO
	outb(0xA0,0x20);
	outb(0x20,0x20);
}

void irq13_handler(void) {
	// TODO
	outb(0xA0,0x20);
	outb(0x20,0x20);
}

void irq14_handler(void) {
	// TODO
	outb(0xA0,0x20);
	outb(0x20,0x20);
}

void irq15_handler(void) {
	// TODO
	outb(0xA0,0x20);
	outb(0x20,0x20);
}

static inline void _flush_tlb(void) {
	asm volatile ( "movl %%cr3, %%eax" : : );
	asm volatile ( "movl %%eax, %%cr3" : : );
}

static inline uint32_t _get_cr2(void) {
	uint32_t cr2;
	asm volatile ( "movl %%cr2, %0" : "=a"(cr2) : );
	return cr2;
}
