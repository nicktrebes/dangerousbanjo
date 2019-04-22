/*
 * MIT License
 *
 * kernel/kio.c
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

uint8_t inb(uint16_t port) {
	uint8_t ret;
	asm volatile ( "inb %1, %0" : "=a"(ret) : "d"(port) );
	return ret;
}

void outb(uint8_t value, uint16_t port) {
	asm volatile ( "outb %0, %1" : : "a"(value), "d"(port) );
}

void serial_init(uint16_t port) {
	outb((port + 1),0x00);
	outb((port + 3),0x80);
	outb((port + 0),0x03);
	outb((port + 1),0x00);
	outb((port + 3),0x03);
	outb((port + 2),0xC7);
	outb((port + 4),0x0B);
}

uint8_t serial_read(uint16_t port) {
start:
	if (!(inb(port + 5) & 0x01))
		goto start;
	return inb(port);
}

void serial_write(uint16_t port, uint8_t value) {
start:
	if (!(inb(port + 5) & 0x20))
		goto start;
	outb(value,port);
}
