#ifndef __SIGNAL_H__
#define __SIGNAL_H__

/*
 * MIT License
 *
 * include/libc/signal.h
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

#define SIG_DFL  _sig_dfl
#define SIG_ERR  _sig_err
#define SIG_HOLD _sig_hold
#define SIG_IGN  _sig_ign

#define SIGRTMIN  (0 /* TODO */)
#define SIGRTMAX  (0 /* TODO */)
#define RTSIG_MAX ((SIGRTMAX - SIGRTMIN) + 1)

#define SIGABRT (6)
#define SIGFPE  (8)
#define SIGILL  (4)
#define SIGINT  (2)
#define SIGSEGV (11)
#define SIGTERM (15)

// TODO: other constants

enum {
	SIGEV_NONE,
	SIGEV_SIGNAL,
	SIGEV_THREAD
};

void _sig_dfl(int);
void _sig_err(int);
void _sig_hold(int);
void _sig_ign(int);

int kill(pid_t pid);
int killpg(pid_t pid, int);
void psiginfo(const siginfo_t*, const char*);
void psignal(int, const char*);
int pthread_kill(pthread_t, int);
int pthread_sigmask(int, const sigset_t* restrict, sigset_t* restrict);
int raise(int);
int sigaction(int, const struct sigaction* restrict, struct sigaction* restrict);
int sigaddset(sigset_t*, int);
int signaltstack(const stack_t* restrict, stack_t* restrict);
int sigdelset(sigset_t*, int);
int sigemptyset(sigset_t*);
int sigfillset(sigset_t*);
int sighold(int);
int sigignore(int);
int siginterrupt(int, int);
int sigismember(const sigset_t*, int);
void (*signal(int, void (*)(int)))(int);
int sigpause(int);
int sigpending(sigset_t*);
int sigprocmask(int, const sigset_t* restrict, sigset_t* restrict);
int sigqueue(pid_t pid, int, union sigval);
int sigrelse(int);
void (*sigset(int, void (*)(int)))(int);
int sigsuspend(const sigset_t*);
int sigtimedwait(const sigset_t* restrict, siginfo_t* restrict, const struct timespec* restrict);
int sigwait(const sigset_t* restrict, int* restrict);
int sigwaitinfo(const sigset_t* restrict, siginfo_t* restrict);

#endif /* ! __SIGNAL_H__ */
