#include <kernel/io.h>
#ifdef __KERNEL_X86__

/*
 * MIT License
 *
 * arch/x86/kernel/io.c
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

u8 inb(u16 port) {
	u8 b;
	asm volatile ( "inb %1, %0" : "=a"(b) : "Nd"(port) );
	return b;
}

u8 inb_p(u16 port) {
	// TODO
	return 0;
}

u16 inw(u16 port) {
	u16 w;
	asm volatile ( "inw %1, %0" : "=a"(w) : "Nd"(port) );
	return w;
}

u16 inw_p(u16 port) {
	// TODO
	return 0;
}

u32 inl(u16 port) {
	u32 l;
	asm volatile ( "inl %1, %0" : "=a"(l) : "Nd"(port) );
	return l;
}

u32 inl_p(u16 port) {
	// TODO
	return 0;
}

void insb(u16 port, void* addr, u32 count) {
	// TODO
}

void insw(u16 port, void* addr, u32 count) {
	// TODO
}

void insl(u16 port, void* addr, u32 count) {
	// TODO
}

void outb(u8 b, u16 port) {
	asm volatile ( "outb %0, %1" : : "a"(b), "Nd"(port) );
}

void outb_p(u8 b, u16 port) {
	// TODO
}

void outw(u16 w, u16 port) {
	asm volatile ( "outw %0, %1" : : "a"(w), "Nd"(port) );
}

void outw_p(u16 w, u16 port) {
	// TODO
}

void outl(u32 l, u16 port) {
	asm volatile ( "outl %0, %1" : : "a"(l), "Nd"(port) );
}

void outl_p(u32 l, u16 port) {
	// TODO
}

void outsb(u16 port, const void* addr, u32 count) {
	// TODO
}

void outsw(u16 port, const void* addr, u32 count) {
	// TODO
}

void outsl(u16 port, const void* addr, u32 count) {
	// TODO
}

#endif /* __KERNEL_X86__ */
