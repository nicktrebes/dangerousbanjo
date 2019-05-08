#ifndef __MQUEUE_H__
#define __MQUEUE_H__

/*
 * MIT License
 *
 * include/libc/mqueue.h
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

#include <signal.h>

typedef int mqd_t;

int mq_close(mqd_t);
int mq_getattr(mqd_t, struct mq_attr*);
int mq_notify(mqd_t, const struct sigevent*);
mqd_t mq_open(const char*, int, ...);
ssize_t mq_receive(mqd_t, char*, size_t, unsigned*);
int mq_send(mqd_t, const char*, size_t, unsigned);
int mq_setattr(mqd_t, const struct mq_attr* restrict, struct mq_attr* restrict);
ssize_t mq_timedreceive(mqd_t, char* restrict, size_t,
	unsigned* restrict, const struct timespec* restrict);
int mq_timedsend(mqd_t, const char*, size_t, unsigned, const struct timespec*);
int mq_unlink(const char*);

#endif /* ! __MQUEUE_H__ */
