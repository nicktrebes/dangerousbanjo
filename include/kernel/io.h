#ifndef __KERNEL_IO_H__
#define __KERNEL_IO_H__

/*
 * MIT License
 *
 * include/kernel/info.h
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

#include <kernel/types.h>

u8 inb(u16 port);
u8 inb_p(u16 port);
u16 inw(u16 port);
u16 inw_p(u16 port);
u32 inl(u16 port);
u32 inl_p(u16 port);

void insb(u16 port, void* addr, u32 count);
void insw(u16 port, void* addr, u32 count);
void insl(u16 port, void* addr, u32 count);

void outb(u8 b, u16 port);
void outb_p(u8 b, u16 port);
void outw(u16 w, u16 port);
void outw_p(u16 w, u16 port);
void outl(u32 l, u16 port);
void outl_p(u32 l, u16 port);

void outsb(u16 port, const void* addr, u32 count);
void outsw(u16 port, const void* addr, u32 count);
void outsl(u16 port, const void* addr, u32 count);

#endif /* ! __KERNEL_IO_H__ */
