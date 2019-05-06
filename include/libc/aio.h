#ifndef __AIO_H__
#define __AIO_H__

/*
 * MIT License
 *
 * include/libc/aio.h
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

#include <fcntl.h>
#include <signal.h>

enum {
	AIO_ALLDONE,
	AIO_CANCELED,
	AIO_NOTCANCELED,
	LIO_NOP,
	LIO_NOWAIT,
	LIO_READ,
	LIO_WAIT,
	LIO_WRITE
};

int aio_cancel(int fd, struct aiocb* ptr);
int aio_error(const struct aiocb* ptr);
int aio_fsync(int fd, struct aiocb* ptr);
int aio_read(struct aiocb* ptr);
ssize_t aio_return(struct aiocb* ptr);
int aio_suspend(const struct aiocb* const list[], int items,
	const struct timespec* timeout);
int aio_write(struct aiocb* ptr);
int lio_listio(int mode, struct aiocb* restrict const list[restrict],
	int items, struct sigevent* restrict sevp);

#endif /* ! __AIO_H__ */
