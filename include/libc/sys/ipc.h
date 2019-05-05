#ifndef __SYS_IPC_H__
#define __SYS_IPC_H__

/*
 * MIT License
 *
 * include/libc/sys/ipc.h
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

#define IPC_CREAT   (1<<15)
#define IPC_EXCL    (1<<14)
#define IPC_NOWAIT  (1<<13)
#define IPC_PRIVATE ((key_t)(-1) /* TODO */)

enum {
	IPC_RMID,
	IPC_SET,
	IPC_STAT
};

struct ipc_perm {
	uid_t  uid;
	gid_t  gid;
	uid_t  cuid;
	gid_t  cgid;
	mode_t mode;
};

key_t ftok(const char* path, int id);

#endif /* ! __SYS_IPC_H__ */
