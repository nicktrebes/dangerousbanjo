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

int fscanf(FILE* restrict file, const char* restrict fmt, ...) __format(scanf,2,3) {
	va_list args;
	int ret;

	va_start(args,fmt);
	ret = vfscanf(file,fmt,args);
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

int scanf(const char* restrict fmt, ...) __format(scanf,1,2) {
	va_list args;
	int ret;

	va_start(args,fmt);
	ret = vfscanf(stdin,fmt,args);
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

int sscanf(const char* restrict str, const char* restrict fmt, ...) __format(scanf,2,3) {
	va_list args;
	int ret;

	va_start(args,fmt);
	ret = vsscanf(str,fmt,args);
	va_end(args);

	return ret;
}

int vdprintf(int fd, const char* restrict fmt, va_list args) __format(printf,2,0) {
	// TODO
	return 0;
}

int vfprintf(FILE* restrict file, const char* restrict fmt, va_list args) __format(printf,2,0) {
	// TODO
	return 0;
}

int vfscanf(FILE* restrict file, const char* restrict fmt, va_list args) __format(scanf,2,0) {
	// TODO
	return 0;
}

int vprintf(const char* restrict fmt, va_list args) __format(printf,1,0) {
	return vfprintf(stdout,fmt,args);
}

int vscanf(const char* restrict fmt, va_list args) __format(scanf,1,0) {
	return vfscanf(stdin,fmt,args);
}

int vsnprintf(char* restrict buf, size_t len, const char* restrict fmt, va_list args) __format(printf,3,0) {
	// TODO
	return 0;
}

int vsprintf(char* restrict buf, const char* restrict fmt, va_list args) __format(printf,2,0) {
	// TODO
	return 0;
}

int vsscanf(const char* restrict str, const char* restrict fmt, va_list args) __format(scanf,2,0) {
	// TODO
	return 0;
}
