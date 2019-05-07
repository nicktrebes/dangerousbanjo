#ifndef __SYS_MMAN_H__
#define __SYS_MMAN_H__

/*
 * MIT License
 *
 * include/libc/sys/mman.h
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

#include <stdint.h>
#include <sys/types.h>

#define MAP_FAILED ((void*)UINTPTR_MAX)

// TODO
#define MAP_FIXED   (1<<0)
#define MAP_PRIVATE (1<<0)
#define MAP_SHARED  (1<<0)

#define MCL_CURRENT (1<<0)
#define MCL_FUTURE  (1<<0)

#define MS_ASYNC      (1<<0)
#define MS_INVALIDATE (1<<1)
#define MS_SYNC       (1<<2)

#define POSIX_MADV_DONTNEED   (1<<0)
#define POSIX_MADV_NORMAL     (1<<1)
#define POSIX_MADV_RANDOM     (1<<2)
#define POSIX_MADV_SEQUENTIAL (1<<3)
#define POSIX_MADV_WILLNEED   (1<<4)

#define POSIX_TYPED_MEM_ALLOCATE        (1<<0)
#define POSIX_TYPED_MEM_ALLOCATE_CONTIG (1<<1)
#define POSIX_TYPED_MEM_MAP_ALLOCATABLE (1<<2)

// TODO
#define PROT_EXEC  (1<<0)
#define PROT_NONE  (1<<0)
#define PROT_READ  (1<<0)
#define PROT_WRITE (1<<0)

int mlock(const void* addr, size_t len);
int mlockall(int flags);
void* mmap(void* addr, size_t len, int prot, int flags, int fd, off_t offset);
int mprotect(void* addr, size_t len, int prot);
int msync(void* addr, size_t len, int flags);
int munlock(const void* addr, size_t len);
int munlockall(void);
int munmap(void* addr, size_t len);
int posix_madvise(void* addr, size_t len, int advice);
int posix_mem_offset(const void* restrict addr, size_t len,
	off_t* restrict offset, size_t* restrict clen, int* restrict fd);
int posix_typed_mem_get_info(int fd, struct posix_typed_mem_info* info);
int posix_typed_mem_open(const char* name, int oflag, int tflag);
int shm_open(const char* name, int oflag, mode_t mode);
int shm_unlink(const char* name);

#endif /* ! __SYS_MMAN_H__ */
