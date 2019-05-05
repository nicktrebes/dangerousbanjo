#ifndef __SYS_SELECT_H__
#define __SYS_SELECT_H__

/*
 * MIT License
 *
 * include/libc/sys/select.h
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

#include <time.h>

#define FD_SETSIZE (1024)

#define FD_CLEAR(fd,set) _fd_clear(fd, set)
#define FD_ISSET(fd,set) _fd_isset(fd, set)
#define FD_SET(fd,set)   _fd_set(fd, set)
#define FD_ZERO(set)     _fd_zero(set)

typedef struct {
	int fd[FD_SETSIZE];
} fd_set;

void FD_CLEAR(int fd, fd_set* set);
int FD_ISSET(int fd, fd_set* set);
void FD_SET(int fd, fd_set* set);
void FD_ZERO(fd_set* set);

#endif /* ! __SYS_SELECT_H__ */
