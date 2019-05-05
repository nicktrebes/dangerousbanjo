#ifndef __SYS_TYPES_H__
#define __SYS_TYPES_H__

/*
 * MIT License
 *
 * include/libc/sys/types.h
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

#include <asm/mcontext.h>
#include <kernel/types.h>

/* Integer typedefs */

typedef s32    blkcnt_t;
typedef s32    blksize_t;
typedef u64    clock_t;
typedef s32    clockid_t;
typedef s32    dev_t;
typedef u32    fsblkcnt_t;
typedef u32    fsfilcnt_t;
typedef s32    gid_t;
typedef s32    id_t;
typedef u32    ino_t;
typedef s32    key_t;
typedef s32    mode_t;
typedef u16    msglen_t;
typedef u16    msgqnum_t;
typedef s32    nlink_t;
typedef s32    off_t;
typedef s32    pid_t;
typedef u32    rlim_t;
typedef u32    sigset_t;
typedef uptr_t size_t;
typedef sptr_t ssize_t;
typedef s32    suseconds_t;
typedef s64    time_t;
typedef s32    uid_t;

/* Structure declarations (if needed) */

struct siginfo;
union  sigval;
struct timespec;
struct timeval;

typedef struct siginfo siginfo_t;

/* Structure definitions */

struct ipc_perm {
	uid_t  uid;
	gid_t  gid;
	uid_t  cuid;
	gid_t  cgid;
	mode_t mode;
};

struct itimerspec {
	struct timespec it_interval;
	struct timespec it_value;
};

struct itimerval {
	struct timeval it_interval;
	struct timeval it_value;
};

struct msqid_ds {
	struct ipc_perm msg_perm;
	msgqnum_t       msg_qnum;
	msglen_t        msg_qbytes;
	pid_t           msg_lspid;
	pid_t           msg_lrpid;
	time_t          msg_stime;
	time_t          msg_rtime;
	time_t          msg_ctime;
};

struct posix_typed_mem_info {
	size_t posix_tmi_length;
};

struct pthread {
	// TODO
};

struct pthread_attr {
	// TODO
};

struct pthread_barrier {
	// TODO
};

struct pthread_barrierattr {
	// TODO
};

struct pthread_cond {
	// TODO
};

struct pthread_condattr {
	// TODO
};

struct pthread_key {
	// TODO
};

struct pthread_mutex {
	// TODO
};

struct pthread_mutexattr {
	// TODO
};

struct pthread_once {
	// TODO
};

struct pthread_rwlock {
	// TODO
};

struct pthread_spinlock {
	// TODO
};

struct rlimit {
	rlim_t rlim_cur;
	rlim_t rlim_max;
};

struct rusage {
	struct timeval ru_utime;
	struct timeval ru_stime;
};

struct sigaction {
	void     (*sa_handler)(int);
	sigset_t sa_mask;
	int      sa_flags;
	void     (*sa_sigaction)(int, siginfo_t*, void*);
};

struct sigevent {
	int             sigev_notify;
	int             sigev_signo;
	union sigval    sigev_value;
	void            (*sigev_notify_function)(union sigval);
	pthread_attr_t* sigev_notify_attributes;
};

struct siginfo {
	int          si_signo;
	int          si_code;
	int          si_errno;
	pid_t        si_pid;
	uid_t        si_uid;
	void*        si_addr;
	int          si_status;
	long         si_band;
	union sigval si_value;
};

union sigval {
	int   sigval_int;
	void* sigval_ptr;
};

struct stack {

};

struct timer {
	// TODO
};

struct timespec {
	time_t tv_sec;
	long   tv_nsec;
};

struct timeval {
	time_t      tv_sec;
	suseconds_t tv_usec;
};

struct timezone {
	int tz_minuteswest;
	int tz_dsttime;
};

struct tm {
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday;
	int tm_yday;
	int tm_isdst;
};

struct trace_attr {
	// TODO
};

struct trace_event_id {
	// TODO
};

struct trace_event_set {
	// TODO
};

struct trace_id {
	// TODO
};

struct ucontext {
	struct ucontext* uc_link;
	sigset_t         uc_sigmask;
	struct stack     uc_stack;
	mcontext_t       uc_mcontext;
};

/* Structure typedefs */

typedef struct pthread*            pthread_t; // NOTE: This is a pointer typedef!
typedef struct pthread_attr        pthread_attr_t;
typedef struct pthread_barrier     pthread_barrier_t;
typedef struct pthread_barrierattr pthread_barrierattr_t;
typedef struct pthread_cond        pthread_cond_t;
typedef struct pthread_condattr    pthread_condattr_t;
typedef struct pthread_key         pthread_key_t;
typedef struct pthread_mutex       pthread_mutex_t;
typedef struct pthread_mutexattr   pthread_mutexattr_t;
typedef struct pthread_once        pthread_once_t;
typedef struct pthread_rwlock      pthread_rwlock_t;
typedef struct pthread_spinlock    pthread_spinlock_t;
typedef struct stack               stack_t;
typedef struct timer*              timer_t; // NOTE: This is a pointer typedef!
typedef struct trace_attr          trace_attr_t;
typedef struct trace_event_id      trace_event_id_t;
typedef struct trace_event_set     trace_event_set_t;
typedef struct trace_id            trace_id_t;
typedef struct ucontext            ucontext_t;

#endif /* ! __SYS_TYPES_H__ */
