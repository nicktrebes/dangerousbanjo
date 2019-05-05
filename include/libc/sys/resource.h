#ifndef __SYS_RESOURCE_H__
#define __SYS_RESOURCE_H__

/*
 * MIT License
 *
 * include/libc/sys/resource.h
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

#include <sys/time.h>

#define PRIO_PROCESS    (1<<0)
#define PRIO_PGRP       (1<<1)
#define PRIO_USER       (1<<2)
#define RLIM_INFINITY   (0)
#define RLIM_SAVED_CUR  (RLIM_INFINITY)
#define RLIM_SAVED_MAX  (RLIM_INFINITY)
#define RUSAGE_CHILDREN (1<<0)
#define RUSAGE_SELF     (1<<1)

enum {
	RLIMIT_CORE,
	RLIMIT_CPU,
	RLIMIT_DATA,
	RLIMIT_FSIZE,
	RLIMIT_NOFILE,
	RLIMIT_STACK,
	RLIMIT_AS
};

typedef u32 rlim_t;

struct rlimit {
	rlim_t rlim_cur;
	rlim_t rlim_max;
};

struct rusage {
	struct timeval ru_utime;
	struct timeval ru_stime;
};

int getpriority(int which, id_t who);
int getrlimit(int resource, struct rlimit* rlim);
int getrusage(int who, struct rusage* usage);
int setpriority(int which, id_t who, int prio);
int setrlimit(int resource, const struct rlimit* rlim);

#endif /* ! __SYS_RESOURCE_H__ */
