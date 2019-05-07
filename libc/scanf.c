/*
 * MIT License
 *
 * libc/scanf.c
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
	FILE* file;
	struct {
		const char* buf;
		size_t      ptr;
	} str;
} _scanf_src_t;

typedef int (*_scanf_read_t)(_scanf_src_t* restrict, int* restrict);

typedef struct {
	_scanf_src_t  src;
	_scanf_read_t read;
	int           str;
} _scanf_t;

static int _scanf_internal(_scanf_t* restrict data, const char* restrict fmt, va_list args);
static int _scanf_read_file(_scanf_src_t* restrict src, int* restrict c);
static int _scanf_read_str(_scanf_src_t* restrict src, int* restrict c);

int fscanf(FILE* restrict file, const char* restrict fmt, ...) __format(scanf,2,3) {
	va_list args;
	int ret;

	va_start(args,fmt);
	ret = vfscanf(file,fmt,args);
	va_end(args);

	return ret;
}

int scanf(const char* restrict fmt, ...) __format(scanf,1,2) {
	va_list args;
	int ret;

	va_start(args,fmt);
	ret = vfscanf(stdin,fmt,args);
	va_end(args);

	return ret;
}

int sscanf(const char* restrict str, const char* restrict fmt, ...) __format(scanf,2,3) {
	va_list args;
	int ret;

	va_start(args,fmt);
	ret = vsscanf(str,fmt,args);
	va_end(args);

	return ret;
}

int vfscanf(FILE* restrict file, const char* restrict fmt, va_list args) __format(scanf,2,0) {
	_scanf_t data;
	data.src.file = file;
	data.read = _scanf_read_file;
	data.str = 0;
	return _scanf_internal(&data,fmt,args);
}

int vscanf(const char* restrict fmt, va_list args) __format(scanf,1,0) {
	return vfscanf(stdin,fmt,args);
}

int vsscanf(const char* restrict str, const char* restrict fmt, va_list args) __format(scanf,2,0) {
	_scanf_t data;
	data.src.str.buf = str;
	data.src.str.ptr = 0;
	data.read = _scanf_read_str;
	data.str = 1;
	return _scanf_internal(&data,fmt,args);
}

static int _scanf_internal(_scanf_t* restrict data, const char* restrict fmt, va_list args) {
	// TODO
	return 0;
}

static int _scanf_read_file(_scanf_src_t* restrict src, int* restrict c) {
	int res = fgetc(src->file);
	if (res < 0) return 1;
	*c = res;
	return 0;
}

static int _scanf_read_str(_scanf_src_t* restrict src, int* restrict c) {
	int res = src->str.buf[src->str.ptr];
	if (res == 0) return 1;
	*c = res;
	++src->str.ptr;
	return 0;
}
