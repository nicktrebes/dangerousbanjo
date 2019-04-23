/*
 * MIT License
 *
 * kernel/kutil.c
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
#include "kio.h"
#include "kutil.h"
#include "vga.h"

#define KPORT_COM1 (0x03F8)

typedef void (*kout_t)(char);
typedef void (*kouts_t)(const char* str);

extern void khalt(void);

static void out_log(char c);
static void out_logstr(const char* str);
static size_t print_arg(kout_t out, kouts_t outs, const char* fmt, size_t ptr, va_list* argptr);
static void print_d64(kout_t out, int64_t d64, unsigned width);
static void print_u64(kout_t out, uint64_t u64, unsigned width);
static void print_x64(kout_t out, uint64_t u64, unsigned width);

void* kcopy(void* dst, const void* src, size_t len) {
	size_t len32 = (len / 4), n;
	for (n = 0; n < len32; ++n)
		((uint32_t*)dst)[n] = ((uint32_t*)src)[n];
	for (n = (len - (len % 4)); n < len; ++n)
		((uint8_t*)dst)[n] = ((uint8_t*)src)[n];
	return dst;
}

size_t klen(const char* str) {
	size_t len = 0;
	while (str[len]) ++len;
	return len;
}

void klogf(const char* fmt, ...) {
	va_list args;
	va_start(args,fmt);
	klogfv(fmt,args);
	va_end(args);
}

void klogfv(const char* fmt, va_list args) {
	size_t ptr = 0;
	char c;
	while ((c = fmt[ptr++])) {
		if (c == '%') {
			if (!(ptr = print_arg(out_log,out_logstr,fmt,ptr,&args))) {
				out_logstr("\n%% KPRINTF ERROR %%\n");
				break;
			}
		} else vga_putc(c);
	}
}

void kpanic(const char* msg) {
	vga_write("\nKERNEL PANIC: ");
	vga_write(msg);
	vga_write("!\n");
	khalt();
}

void kprintf(const char* fmt, ...) {
	va_list args;
	va_start(args,fmt);
	kprintfv(fmt,args);
	va_end(args);
}

void kprintfv(const char* fmt, va_list args) {
	size_t ptr = 0;
	char c;
	while ((c = fmt[ptr++])) {
		if (c == '%') {
			if (!(ptr = print_arg(vga_putc,vga_write,fmt,ptr,&args))) {
				vga_write("\n%% KPRINTF ERROR %%\n");
				break;
			}
		} else vga_putc(c);
	}
}

static void out_log(char c) {
	serial_write(KPORT_COM1,(uint8_t)(c & 0x7F));
}

static void out_logstr(const char* str) {
	char c;
	for (; (c = *str); ++str)
		out_log(c);
}

static size_t print_arg(kout_t out, kouts_t outs, const char* fmt, size_t ptr, va_list* argptr) {
	va_list args = *argptr;
	unsigned width = 0;
	int arg64 = 0, argz = 0;
	char c;

	for (c = fmt[ptr]; (c >= '0') && (c <= '9'); c = fmt[++ptr])
		width = ((width * 10) + (unsigned)(c - '0'));

select:
	switch (c = fmt[ptr++]) {
	case '%':
		if (arg64 || argz || width) return 0;
		out('%');
		break;
	case 's':
		if (arg64 || argz || width) return 0;
		outs(va_arg(args,const char*));
		break;
	case 'l':
		if (argz) return 0;
		arg64 = 1;
		goto select;
	case 'z':
		if (arg64) return 0;
		argz = 1;
		goto select;
	case 'd':
		if (argz) return 0;
		else if (arg64) print_d64(out,va_arg(args,int64_t),width);
		else print_d64(out,(int64_t)va_arg(args,int32_t),width);
		break;
	case 'u':
		if (argz) print_u64(out,(uint64_t)va_arg(args,size_t),width);
		else if (arg64) print_u64(out,va_arg(args,uint64_t),width);
		else print_u64(out,(uint64_t)va_arg(args,uint32_t),width);
		break;
	case 'x':
		if (argz) print_x64(out,(uint64_t)va_arg(args,size_t),width);
		else if (arg64) print_x64(out,va_arg(args,uint64_t),width);
		else print_x64(out,(uint64_t)va_arg(args,uint32_t),width);
		break;
	default:
		return 0;
	}

	*argptr = args;
	return ptr;
}

static void print_d64(kout_t out, int64_t d64, unsigned width) {
	if (d64 < 0) {
		d64 = (-d64);
		out('-');
	}
	print_u64(out,(uint64_t)d64,width);
}

static void print_u64(kout_t out, uint64_t u64, unsigned width) {
	uint64_t power = 10000000000000000000L;
	unsigned place = 20;
	int started = (width >= 20);

	for (; width > 20; --width)
		out('0');

	for (; place; --place) {
		uint64_t digit = (u64 / power);
		u64 = (u64 % power);
		power /= 10;
		if (started == 0) {
			if (digit || (width >= place))
				started = 1;
		}
		if (started) out('0' + (char)digit);
	}

	if (!started) out('0');
}

static const char* _charset_hex = "0123456789ABCDEF";

static void print_x64(kout_t out, uint64_t u64, unsigned width) {
	uint64_t mask = 0xF000000000000000L, place;
	int shift = 60, started = (width >= 16);

	for (; width > 16; --width)
		out('0');

	for (; shift >= 0; mask >>= 4, shift -= 4) {
		place = ((u64 & mask) >> shift);
		if (started == 0) {
			if (place || ((width * 4) >= shift))
				started = 1;
		}
		if (started) out(_charset_hex[place]);
	}

	if (!started) out('0');
}
