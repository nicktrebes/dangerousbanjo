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
#include "kutil.h"
#include "vga.h"

typedef enum {
	KPRINT_ERROR,
	KPRINT_S,
	KPRINT_D,
	KPRINT_LD,
	KPRINT_LLD,
	KPRINT_U,
	KPRINT_LU,
	KPRINT_LLU,
	KPRINT_ZU,
	KPRINT_X,
	KPRINT_LX,
	KPRINT_LLX,
	KPRINT_ZX
} kprintf_t;

static const char* print_arg(const char* fmt, kprintf_t* arg, unsigned* prec, int* cap);
static void print_d64(int64_t d64, unsigned prec);
static void print_u64(uint64_t u64, unsigned prec);
static void print_x64(uint64_t u64, unsigned prec, int cap);

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

void kprintf(const char* fmt, ...) {
	kargs_t args;
	kprintf_t arg;
	unsigned prec;
	int cap, esc = 0;
	char c;

	kargs_start(args,fmt);
	for (; (c = (*fmt)); ++fmt) {
		if (esc) {
			esc = 0;
			vga_putc(c);
			continue;
		}

		switch (c) {
		case '\\':
			esc = 1;
			break;
		case '%':
			fmt = print_arg(fmt,&arg,&prec,&cap);
			switch (arg) {
			case KPRINT_ERROR:
				vga_write("\n<%KPRINT FORMAT ERROR%>\n");
				return;
			case KPRINT_S:
				vga_write(kargs_next(args,const char*));
				break;
			case KPRINT_D:
				print_d64((int64_t)kargs_next(args,int16_t),prec);
				break;
			case KPRINT_LD:
				print_d64((int64_t)kargs_next(args,int32_t),prec);
				break;
			case KPRINT_LLD:
				print_d64(kargs_next(args,int64_t),prec);
				break;
			case KPRINT_U:
				print_u64((uint64_t)kargs_next(args,uint16_t),prec);
				break;
			case KPRINT_LU:
				print_u64((uint64_t)kargs_next(args,uint32_t),prec);
				break;
			case KPRINT_LLU:
				print_u64(kargs_next(args,uint64_t),prec);
				break;
			case KPRINT_ZU:
				print_u64((uint64_t)kargs_next(args,size_t),prec);
				break;
			case KPRINT_X:
				print_x64((uint64_t)kargs_next(args,uint16_t),prec,cap);
				break;
			case KPRINT_LX:
				print_x64((uint64_t)kargs_next(args,uint32_t),prec,cap);
				break;
			case KPRINT_LLX:
				print_x64(kargs_next(args,uint64_t),prec,cap);
				break;
			case KPRINT_ZX:
				print_x64((uint64_t)kargs_next(args,size_t),prec,cap);
				break;
			}
			break;
		default:
			vga_putc(c);
		}
	}
}

static const char* print_arg(const char* fmt, kprintf_t* arg, unsigned* prec, int* cap) {

}

static void print_d64(int64_t d64, unsigned prec) {

}

static void print_u64(uint64_t u64, unsigned prec) {

}

static void print_x64(uint64_t u64, unsigned prec, int cap) {

}
