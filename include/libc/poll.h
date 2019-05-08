#ifndef __POLL_H__
#define __POLL_H__

/*
 * MIT License
 *
 * include/libc/poll.h
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

#include <sys/types.h>

#define POLLIN     (1<<0)
#define POLLRDNORM (1<<1)
#define POLLRDBAND (1<<2)
#define POLLPRI    (1<<3)
#define POLLOUT    (1<<4)
#define POLLWRNORM (1<<5)
#define POLLWRBAND (1<<6)
#define POLLERR    (1<<7)
#define POLLHUP    (1<<8)
#define POLLNVAL   (1<<9)

int poll(struct pollfd [], nfds_t, int);

#endif /* ! __POLL_H__ */
