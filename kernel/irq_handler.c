/*
 * MIT License
 *
 * kernel/irq_handler.c
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

#include "kio.h"

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
