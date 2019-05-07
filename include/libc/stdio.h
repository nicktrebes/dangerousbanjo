#ifndef __STDIO_H__
#define __STDIO_H__

/*
 * MIT License
 *
 * include/libc/stdio.h
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

#include <stdarg.h>
#include <unistd.h>

#define EOF          ((int)(-1))
#define FILENAME_MAX (256)
#define FOPEN_MAX    (8 /* TODO */)
#define L_ctermid    (32)
#define L_tmpnam     (32)
#define P_tmpdir     ("/tmp")
#define TMP_MAX      (10000 /* TODO */)

enum {
	_IONBF,
	_IOLBF,
	_IOFBF
};

extern FILE* _STDIN_PTR;
extern FILE* _STDERR_PTR;
extern FILE* _STDOUT_PTR;

#define stdin  (_STDIN_PTR)
#define stderr (_STDERR_PTR)
#define stdout (_STDOUT_PTR)

#define getc fgetc

void clearerr(FILE* file);
char* ctermid(char* buf);
int dprintf(int fd, const char* restrict fmt, ...) __format(printf,2,3);
int fclose(FILE* file);
FILE* fdopen(int fd, const char* path);
int feof(FILE* file);
int ferror(FILE* file);
int fflush(FILE* file);
int fgetc(FILE* file);
int fgetpos(FILE* restrict file, fpos_t* restrict pos);
char* fgets(char* restrict buf, int len, FILE* restrict file);
int fileno(FILE* file);
void flockfile(FILE* file);
FILE* fmemopen(void* restrict addr, size_t len, const char* restrict path);
FILE* fopen(const char* restrict path, const char* restrict mode);
int fprintf(FILE* restrict file, const char* restrict fmt, ...) __format(printf,2,3);
int fputc(int c, FILE* file);
int fputs(const char* restrict str, FILE* restrict file);
size_t fread(void* restrict buf, size_t size, size_t count, FILE* restrict file);
FILE* freopen(const char* restrict path, const char* restrict mode, FILE* restrict file);
int fscanf(FILE* restrict file, const char* restrict fmt, ...) __format(scanf,2,3);
int fseek(FILE* file, long pos, int whence);
int fseeko(FILE* file, off_t off, int whence);
int fsetpos(FILE* file, const fpos_t* pos);
long ftell(FILE* file);
off_t ftello(FILE* file);
int ftrylockfile(FILE* file);
void funlockfile(FILE* file);
size_t fwrite(const void* restrict buf, size_t size, size_t count, FILE* restrict file);
int getchar(void);
int getc_unlocked(FILE* file);
int getchar_unlocked(void);
ssize_t getdelim(char** restrict lineptr, size_t* restrict n, int delim, FILE* restrict file);
ssize_t getline(char** restrict lineptr, size_t *restrict n, FILE* restrict file);
char* gets(char* buf);
FILE* open_memstream(char** ptr, size_t* szptr);
int pclose(FILE* file);
void perror(const char* msg);
FILE* popen(const char* path, const char* mode);
int printf(const char* restrict fmt, ...) __format(printf,1,2);
int putc(int c, FILE* file);
int putchar(int c);
int putc_unlocked(int c, FILE* file);
int putchar_unlocked(int c);
int puts(const char* str);
int remove(const char* path);
int rename(const char* path0, const char* path1);
int renameat(int fd0, const char* path0, int fd1, const char* path1);
void rewind(FILE* file);
int scanf(const char* restrict fmt, ...) __format(scanf,1,2);
void setbuf(FILE* restrict file, char* restrict buf);
int setvbuf(FILE* restrict, char* restrict buf, int mode, size_t size);
int snprintf(char* restrict buf, size_t len, const char* restrict fmt, ...) __format(printf,3,4);
int sprintf(char* restrict buf, const char* restrict fmt, ...) __format(printf,2,3);
int sscanf(const char* restrict str, const char* restrict fmt, ...) __format(scanf,2,3);
char* tempnam(const char* dir, const char* pfx);
FILE* tmpfile(void);
char* tmpnam(char* buf);
int ungetc(int c, FILE* file);
int vdprintf(int fd, const char* restrict fmt, va_list args) __format(printf,2,0);
int vfprintf(FILE* restrict file, const char* restrict fmt, va_list args) __format(printf,2,0);
int vfscanf(FILE* restrict file, const char* restrict fmt, va_list args) __format(scanf,2,0);
int vprintf(const char* restrict fmt, va_list args) __format(printf,1,0);
int vscanf(const char* restrict fmt, va_list args) __format(scanf,1,0);
int vsnprintf(char* restrict buf, size_t len, const char* restrict fmt, va_list args) __format(printf,3,0);
int vsprintf(char* restrict buf, const char* restrict fmt, va_list args) __format(printf,2,0);
int vsscanf(const char* restrict str, const char* restrict fmt, va_list args) __format(scanf,2,0);

#define /* ! __STDIO_H__ */
