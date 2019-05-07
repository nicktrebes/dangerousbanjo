#ifndef __FCNTL_H__
#define __FCNTL_H__

/*
 * MIT License
 *
 * include/libc/fcntl.h
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

#include <unistd.h>

#define AT_FDCWD   (0x7FFFFFFF)
#define FD_CLOEXEC (1 /* TODO */)

#define O_CLOEXEC   (1<<0)
#define O_CREAT     (1<<1)
#define O_DIRECTORY (1<<2)
#define O_EXCL      (1<<3)
#define O_NOCTTY    (1<<4)
#define O_NOFOLLOW  (1<<5)
#define O_TRUNC     (1<<6)
#define O_TTY_INIT  (1<<7 /* may be set to zero */)

#define O_APPEND   (1<<0)
#define O_DSYNC    (1<<1)
#define O_NONBLOCK (1<<2)
#define O_RSYNC    (1<<3)
#define O_SYNC     (1<<4)

#define O_EXEC   (1<<0)
#define O_RDONLY (1<<1)
#define O_RDWR   (1<<2)
#define O_SEARCH (1<<3)
#define O_WRONLY (1<<4)

#define O_ACCMODE (1 /* TODO */)

enum {
	F_DUPFD,
	F_DUPFD_CLOEXEC,
	F_GETFD,
	F_SETFD,
	F_GETFL,
	F_SETFL,
	F_GETLK,
	F_SETLK,
	F_SETLKW,
	F_GETOWN,
	F_SETOWN
};

enum {
	F_UNLCK,
	F_RDLCK,
	F_WRLCK
};

enum {
	POSIX_FADV_DONTNEED,
	POSIX_FADV_NOREUSE,
	POSIX_FADV_NORMAL,
	POSIX_FADV_RANDOM,
	POSIX_FADV_SEQUENTIAL,
	POSIX_FADV_WILLNEED
};

int creat(const char* path, mode_t mode);
int fcntl(int fd, int cmd, ...);
int open(const char* path, int flags, ...);
int openat(int fd, const char* path, int flags, ...);
int posix_fadvise(int fd, off_t off, off_t len, int advice);
int posix_fallocate(int fd, off_t off, off_t len);

#endif /* ! __FCNTL_H__ */
