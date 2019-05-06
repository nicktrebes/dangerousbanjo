/*
 * MIT License
 *
 * libc/stdio.c
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

void clearerr(FILE* file) {
	// TODO
}

char* ctermid(char* buf) {
	// TODO
	return NULL;
}

int fclose(FILE* file) {
	// TODO
	return 0;
}

FILE* fdopen(int fd, const char* path) {
	// TODO
	return NULL;
}

int feof(FILE* file) {
	// TODO
	return 0;
}

int ferror(FILE* file) {
	// TODO
	return 0;
}

int fflush(FILE* file) {
	// TODO
	return 0;
}

int fgetc(FILE* file) {
	// TODO
	return 0;
}

int fgetpos(FILE* restrict file, fpos_t* restrict pos) {
	// TODO
	return 0;
}

char* fgets(char* restrict buf, int len, FILE* restrict file) {
	// TODO
	return NULL;
}

int fileno(FILE* file) {
	// TODO
	return 0;
}

void flockfile(FILE* file) {
	// TODO
}

FILE* fmemopen(void* restrict addr, size_t len, const char* restrict path) {
	// TODO
	return NULL;
}

FILE* fopen(const char* restrict path, const char* restrict mode) {
	// TODO
	return NULL;
}

int fputc(int c, FILE* file) {
	// TODO
	return 0;
}

int fputs(const char* restrict str, FILE* restrict file) {
	// TODO
	return 0;
}

size_t fread(void* restrict buf, size_t size, size_t count, FILE* restrict file) {
	// TODO
	return 0;
}

FILE* freopen(const char* restrict path, const char* restrict mode, FILE* restrict file) {
	// TODO
	return NULL;
}

int fseek(FILE* file, long pos, int whence) {
	// TODO
	return 0;
}

int fseeko(FILE* file, off_t off, int whence) {
	// TODO
	return 0;
}

int fsetpos(FILE* file, const fpos_t* pos) {
	// TODO
	return 0;
}

long ftell(FILE* file) {
	// TODO
	return 0;
}

off_t ftello(FILE* file) {
	// TODO
	return 0;
}

int ftrylockfile(FILE* file) {
	// TODO
	return 0;
}

void funlockfile(FILE* file) {
	// TODO
}

size_t fwrite(const void* restrict buf, size_t size, size_t count, FILE* restrict file) {
	// TODO
	return 0;
}

int getchar(void) {
	return fgetc(stdin);
}

int getc_unlocked(FILE* file) {
	// TODO
	return 0;
}

int getchar_unlocked(void) {
	return getc_unlocked(stdin);
}

ssize_t getdelim(char** restrict lineptr, size_t* restrict n, int delim, FILE* restrict file) {
	// TODO
	return 0;
}

ssize_t getline(char** restrict lineptr, size_t *restrict n, FILE* restrict file) {
	// TODO
	return 0;
}

char* gets(char* buf) {
	return fgets(stdin);
}

FILE* open_memstream(char** ptr, size_t* szptr) {
	// TODO
	return NULL;
}

int pclose(FILE* file) {
	// TODO
	return 0;
}

void perror(const char* msg) {
	// TODO
}

FILE* popen(const char* path, const char* mode) {
	// TODO
	return NULL;
}

int putc(int c, FILE* file) {
	// TODO
	return 0;
}

int putchar(int c) {
	return putc(stdout);
}

int putc_unlocked(int c, FILE* file) {
	// TODO
	return 0;
}

int putchar_unlocked(int c) {
	return putc_unlocked(c,stdout);
}

int puts(const char* str) {
	return fputs(str,stdout);
}

int remove(const char* path) {
	// TODO
	return 0;
}

int rename(const char* path0, const char* path1) {
	// TODO
	return 0;
}

int renameat(int fd0, const char* path0, int fd1, const char* path1) {
	// TODO
	return 0;
}

void rewind(FILE* file) {
	// TODO
}

void setbuf(FILE* restrict file, char* restrict buf) {
	// TODO
}

int setvbuf(FILE* restrict, char* restrict buf, int mode, size_t size) {
	// TODO
	return 0;
}

char* tempnam(const char* dir, const char* pfx) {
	// TODO
	return NULL;
}

FILE* tmpfile(void) {
	// TODO
	return NULL;
}

char* tmpnam(char* buf) {
	// TODO
	return NULL;
}

int ungetc(int c, FILE* file) {
	// TODO
	return 0;
}
