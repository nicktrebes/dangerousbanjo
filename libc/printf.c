/*
 * MIT License
 *
 * libc/printf.c
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

#include <stdio.h>

typedef union {
	int   fd;
	FILE* file;
	struct {
		char*  buf;
		size_t len, ptr;
	} str;
} _printf_dst_t;

typedef int (*_printf_putc_t)(_printf_dst_t*, int);
typedef int (*_printf_puts_t)(_printf_dst_t* restrict, const char* restrict);

typedef struct {
	_printf_dst_t  dst;
	_printf_putc_t putc;
	_printf_puts_t puts;
	int            sn;
} _printf_t;

static int _printf_internal(_printf_t* restrict data, const char* restrict fmt, va_list args);
static int _printf_putc_fd(_printf_dst_t* dst, int c);
static int _printf_putc_file(_printf_dst_t* dst, int c);
static int _printf_putc_sn(_printf_dst_t* dst, int c);
static int _printf_putc_str(_printf_dst_t* dst, int c);
static int _printf_puts_fd(_printf_dst_t* restrict dst, const char* restrict str);
static int _printf_puts_file(_printf_dst_t* restrict dst, const char* restrict str);
static int _printf_puts_sn(_printf_dst_t* restrict dst, const char* restrict str);
static int _printf_puts_str(_printf_dst_t* restrict dst, const char* restrict str);

int dprintf(int fd, const char* restrict fmt, ...) __format(printf,2,3) {
	va_list args;
	int ret;

	va_start(args,fmt);
	ret = vdprintf(fd,fmt,args);
	va_end(args);

	return ret;
}

int fprintf(FILE* restrict file, const char* restrict fmt, ...) __format(printf,2,3) {
	va_list args;
	int ret;

	va_start(args,fmt);
	ret = vfprintf(file,fmt,args);
	va_end(args);

	return ret;
}

int printf(const char* restrict fmt, ...) __format(printf,1,2) {
	va_list args;
	int ret;

	va_start(args,fmt);
	ret = vfprintf(stdout,fmt,args);
	va_end(args);

	return ret;
}

int snprintf(char* restrict buf, size_t len, const char* restrict fmt, ...) __format(printf,3,4) {
	va_list args;
	int ret;

	va_start(args,fmt);
	ret = vsnprintf(buf,len,fmt,args);
	va_end(args);

	return ret;
}

int sprintf(char* restrict buf, const char* restrict fmt, ...) __format(printf,2,3) {
	va_list args;
	int ret;

	va_start(args,fmt);
	ret = vsprintf(buf,fmt,args);
	va_end(args);

	return ret;
}

int vdprintf(int fd, const char* restrict fmt, va_list args) __format(printf,2,0) {
	_printf_t data;
	data.dst.fd = fd;
	data.putc = _printf_putc_fd;
	data.puts = _printf_puts_fd;
	data.sn = 0;
	return _printf_internal(&data,fmt,args);
}

int vfprintf(FILE* restrict file, const char* restrict fmt, va_list args) __format(printf,2,0) {
	_printf_t data;
	data.dst.file = file;
	data.putc = _printf_putc_file;
	data.puts = _printf_puts_file;
	data.sn = 0;
	return _printf_internal(&data,fmt,args);
}

int vprintf(const char* restrict fmt, va_list args) __format(printf,1,0) {
	return vfprintf(stdout,fmt,args);
}

int vsnprintf(char* restrict buf, size_t len, const char* restrict fmt, va_list args) __format(printf,3,0) {
	_printf_t data;
	data.dst.str.buf = buf;
	data.dst.str.len = len;
	data.dst.str.ptr = 0;
	data.putc = _printf_putc_sn;
	data.putc = _printf_puts_sn;
	data.sn = 1;
	return _printf_internal(&data,fmt,args);
}

int vsprintf(char* restrict buf, const char* restrict fmt, va_list args) __format(printf,2,0) {
	_printf_t data;
	data.dst.str.buf = buf;
	data.dst.str.len = 0;
	data.dst.str.ptr = 0;
	data.putc = _printf_putc_str;
	data.putc = _printf_puts_str;
	data.sn = 0;
	return _printf_internal(&data,fmt,args);
}

static int _printf_internal(_printf_t* restrict data, const char* restrict fmt, va_list args) {
	// TODO
	return 0;
}

static int _printf_putc_fd(_printf_dst_t* dst, int c) {
	// TODO
	return 0;
}

static int _printf_putc_file(_printf_dst_t* dst, int c) {
	// TODO
	return 0;
}

static int _printf_putc_sn(_printf_dst_t* dst, int c) {
	// TODO
	return 0;
}

static int _printf_putc_str(_printf_dst_t* dst, int c) {
	// TODO
	return 0;
}

static int _printf_puts_fd(_printf_dst_t* restrict dst, const char* restrict str) {
	// TODO
	return 0;
}

static int _printf_puts_file(_printf_dst_t* restrict dst, const char* restrict str) {
	// TODO
	return 0;
}

static int _printf_puts_sn(_printf_dst_t* restrict dst, const char* restrict str) {
	// TODO
	return 0;
}

static int _printf_puts_str(_printf_dst_t* restrict dst, const char* restrict str) {
	// TODO
	return 0;
}
