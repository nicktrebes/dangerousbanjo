#ifndef __STDLIB_H__
#define __STDLIB_H__

/*
 * MIT License
 *
 * include/libc/stdlib.h
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

#include <stddef.h>
#include <sys/wait.h>
#include <unistd.h>

#define EXIT_FAILURE (1)
#define EXIT_SUCCESS (0)
#define RAND_MAX     (32767 /* TODO */)
#define MB_CUR_MAX   (1)

#define _Exit(status) _exit(status)
#define exit(status)  _exit(status)

long a64l(const char*);
void abort(void) __noreturn;
int abs(int);
int atexit(void (*)(void));
double atof(const char*);
int atoi(const char*);
long atol(const char*);
long long atoll(const char*);
void* bsearch(const void*, const void*, size_t, size_t,
	int (*)(const void*, const void*));
void* calloc(size_t, size_t);
div_t div(int, int);
double drand48(void);
double erand48(unsigned short [3]);
void free(void*);
char* getenv(const char*);
int getsubopt(char**, char* const*, char**);
int grantpt(int);
char* initstate(unsigned, char*, size_t);
long jrand48(unsigned short [3]);
char* l64a(long);
long labs(long);
void lcong48(unsigned short [7]);
ldiv_t ldiv(long, long);
long long llabs(long long);
lldiv_t lldiv(long long, long long);
long lrand48(void);
void* malloc(size_t);
int mblen(const char*, size_t);
char* mkdtemp(char*);
int mkstemp(char*);
long mrand48(void);
long nrand48(unsigned short [3]);
int posix_memalign(void**, size_t, size_t);
int posix_openpt(int);
char* ptsname(int);
int putenv(char*);
void qsort(void*, size_t, size_t,
	int (*)(const void*, const void*));
int rand(void);
int rand_r(unsigned*);
long random(void);
void* realloc(void*, size_t);
char* realpath(const char* restrict, char* restrict);
unsigned short* seed48(unsigned short [3]);
int setenv(const char*, const char*, int);
void setkey(const char*);
char* setstate(char*);
void srand(unsigned);
void srand48(long);
void srandom(unsigned);
double strtod(const char* restrict, char** restrict);
float strtof(const char* restrict, char** restrict);
long strtol(const char* restrict, char** restrict, int);
long double strtold(const char* restrict, char** restrict);
long long strtoll(const char* restrict, char** restrict, int);
unsigned long strtoul(const char* restrict, char** restrict, int);
unsigned long long strtoull(const char* restrict, char** restrict, int);
int system(const char*);
int unlockpt(int);
int unsetenv(const char*);

#endif /* ! __STDLIB_H__ */
