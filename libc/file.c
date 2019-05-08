/*
 * MIT License
 *
 * libc/file.c
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

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define _FILE_OPEN  (1<<0)
#define _FILE_EOF   (1<<1)
#define _FILE_ERR   (1<<2)
#define _FILE_READ  (1<<3)
#define _FILE_WRITE (1<<4)

void clearerr(FILE* file) {
	file->flags &= (~_FILE_ERR);
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
	return (file->flags & _FILE_EOF);
}

int ferror(FILE* file) {
	return (file->flags & _FILE_ERR);
}

int fflush(FILE* file) {
	size_t start = 0;

	if ((file->flags & (_FILE_OPEN | _FILE_WRITE)) == 0) {
		file->flags |= _FILE_ERR;
		return EOF;
	} else if (file->flags & _FILE_ERR)
		return EOF;

	while (start < file->ptr) {
		ssize_t res = write(file->fd,(file->buf + start),(file->ptr - start));
		if (res < 0) {
			file->flags |= _FILE_ERR;
			return EOF;
		}
		start += res;
	}

	file->pos += file->ptr;
	file->ptr = 0;
	return 0;
}

int fgetc(FILE* file) {
	if ((file->flags & (_FILE_OPEN | _FILE_READ)) == 0) {
		file->flags |= _FILE_ERR;
		return EOF;
	} else if (file->flags & _FILE_ERR)
		return EOF;
	else if (file->ptr == file->len) {
		// TODO
	}
	return file->buf[file->ptr++];
}

int fgetpos(FILE* restrict file, fpos_t* restrict pos) {
	if ((file->flags & _FILE_OPEN) == 0) {
		errno = EBADF;
		return (-1);
	}
	*pos = file->pos;
	return 0;
}

char* fgets(char* restrict buf, int len, FILE* restrict file) {
	// TODO
	return NULL;
}

int fileno(FILE* file) {
	if ((file->flags & _FILE_OPEN) == 0) {
		errno = EBADF;
		return (-1);
	}
	return file->fd;
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

int ungetc(int c, FILE* file) {
	// TODO
	return 0;
}
