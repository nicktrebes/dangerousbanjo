/*
 * MIT License
 *
 * kernel/idt.c
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

#include <stdint.h>
#include "idt.h"
#include "kio.h"

extern int irq0();
extern int irq1();
extern int irq2();
extern int irq3();
extern int irq4();
extern int irq5();
extern int irq6();
extern int irq7();
extern int irq8();
extern int irq9();
extern int irq10();
extern int irq11();
extern int irq12();
extern int irq13();
extern int irq14();
extern int irq15();
extern int load_idt();

typedef struct {
	uint16_t offset_low;
	uint16_t select;
	uint8_t zero;
	uint8_t type;
	uint16_t offset_high;
} __attribute__((packed)) idt_entry_t;

static idt_entry_t _idt[256];

static void _load_irq(uint8_t idx, uint32_t irq_addr);

void kinit_idt(void) {
	/* remapping the PIC */
	outb(0x20,0x11);
	outb(0xA0,0x11);
	outb(0x21,0x20);
	outb(0xA1,40);
	outb(0x21,0x04);
	outb(0xA1,0x02);
	outb(0x21,0x01);
	outb(0xA1,0x01);
	outb(0x21,0x0);
	outb(0xA1,0x0);

	_load_irq(32,(uint32_t)irq0);
	_load_irq(33,(uint32_t)irq1);
	_load_irq(34,(uint32_t)irq2);
	_load_irq(35,(uint32_t)irq3);
	_load_irq(36,(uint32_t)irq4);
	_load_irq(37,(uint32_t)irq5);
	_load_irq(38,(uint32_t)irq6);
	_load_irq(39,(uint32_t)irq7);
	_load_irq(40,(uint32_t)irq8);
	_load_irq(41,(uint32_t)irq9);
	_load_irq(42,(uint32_t)irq10);
	_load_irq(43,(uint32_t)irq11);
	_load_irq(44,(uint32_t)irq12);
	_load_irq(45,(uint32_t)irq13);
	_load_irq(46,(uint32_t)irq14);
	_load_irq(47,(uint32_t)irq15);

	load_idt(_idt,(sizeof(idt_entry_t) * 256));
}

static void _load_irq(uint8_t idx, uint32_t irq_addr) {
	_idt[idx].offset_low = (uint16_t)(irq_addr & 0x0000FFFF);
	_idt[idx].select = 0x0008;
	_idt[idx].zero = 0x0000;
	_idt[idx].type = 0x008E;
	_idt[idx].offset_high = (uint16_t)((irq_addr >> 16) & 0x0000FFFF);
}
