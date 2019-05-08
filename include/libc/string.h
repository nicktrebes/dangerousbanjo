#ifndef __STRING_H__
#define __STRING_H__

/*
 * MIT License
 *
 * include/libc/string.h
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

#include <locale.h>

void* memccpy(void* restrict, const void* restrict, int, size_t);
void* memchr(const void*, int, size_t);
int memcmp(const void*, const void*, size_t);
void* memcpy(void* restrict, const void* restrict, size_t);
void* memmove(void*, const void*, size_t);
void* memset(void*, int, size_t);
char* stpcpy(char* restrict, const char* restrict);
char* stpncpy(char* restrict, const char* restrict, size_t);
char* strcat(char* restrict, const char* restrict);
char* strchr(const char*, int);
int strcmp(const char*, const char*);
int strcoll(const char*, const char*);
int strcoll_l(const char*, const char*, locale_t);
char* strcpy(char* restrict, const char* restrict);
size_t strcspn(const char*, const char*);
char* strdup(const char*);
char* strerror(int);
char* strerror_l(int, locale_t);
int strerror_r(int, char*, size_t);
size_t strlen(const char*);
char* strncat(char* restrict, const char* restrict, size_t);
int strncmp(const char*, const char*, size_t);
char* strncpy(char* restrict, const char* restrict, size_t);
char* strndup(const char*, size_t);
size_t strnlen(const char*, size_t);
char* strpbrk(const char*, const char*);
char* strrchr(const char*, int);
char* strsignal(int);
size_t strspn(const char*, const char*);
char* strstr(const char*, const char*);
char* strtok(char* restrict, const char* restrict);
char* strtok_r(char* restrict, const char* restrict, char** restrict);
size_t strxfrm(char* restrict, const char* restrict, size_t);
size_t strxfrm_l(char* restrict, const char* restrict,
	size_t, locale_t);

#endif /* ! __STRING_H__ */
