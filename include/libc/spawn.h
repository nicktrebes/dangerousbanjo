#ifndef __SPAWN_H__
#define __SPAWN_H__

/*
 * MIT License
 *
 * include/libc/spawn.h
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

#include <sched.h>
#include <signal.h>

typedef struct {
	// TODO
} posix_spawn_file_actions_t;

typedef struct {
	// TODO
} posix_spawnattr_t;

#define POSIX_SPAWN_RESETIDS      (1<<0)
#define POSIX_SPAWN_SETPGROUP     (1<<1)
#define POSIX_SPAWN_SETSCHEDPARAM (1<<2)
#define POSIX_SPAWN_SETSCHEDULER  (1<<3)
#define POSIX_SPAWN_SETSIGDEF     (1<<4)
#define POSIX_SPAWN_SETSIGMASK    (1<<5)

int posix_spawn(pid_t* restrict, const char* restrict,
	const posix_spawn_file_actions_t*,
	const posix_spawnattr_t* restrict, char* const [restrict],
	char *const [restrict]);
int posix_spawn_file_actions_addclose(posix_spawn_file_actions_t*, int);
int posix_spawn_file_actions_adddup2(posix_spawn_file_actions_t*, int, int);
int posix_spawn_file_actions_addopen(posix_spawn_file_actions_t* restrict,
	int, const char* restrict, int, mode_t);
int posix_spawn_file_actions_destroy(posix_spawn_file_actions_t*);
int posix_spawn_file_actions_init(posix_spawn_file_actions_t*);
int posix_spawnattr_destroy(posix_spawnattr_t*);
int posix_spawnattr_getflags(const posix_spawnattr_t* restrict,
	short* restrict);
int posix_spawnattr_getpgroup(const posix_spawnattr_t* restrict,
	pid_t* restrict);
int posix_spawnattr_getschedparam(const posix_spawnattr_t* restrict,
	struct sched_param* restrict);
int posix_spawnattr_getschedpolicy(const posix_spawnattr_t* restrict,
	int* restrict);
int posix_spawnattr_getsigdefault(const posix_spawnattr_t* restrict,
	sigset_t* restrict);
int posix_spawnattr_getsigmask(const posix_spawnattr_t* restrict,
	sigset_t* restrict);
int posix_spawnattr_init(posix_spawnattr_t*);
int posix_spawnattr_setflags(posix_spawnattr_t*, short);
int posix_spawnattr_setpgroup(posix_spawnattr_t*, pid_t);
int posix_spawnattr_setschedparam(posix_spawnattr_t* restrict,
	const struct sched_param* restrict);
int posix_spawnattr_setschedpolicy(posix_spawnattr_t*, int);
int posix_spawnattr_setsigdefault(posix_spawnattr_t* restrict,
	const sigset_t* restrict);
int posix_spawnattr_setsigmask(posix_spawnattr_t* restrict,
	const sigset_t* restrict);
int posix_spawnp(pid_t* restrict, const char* restrict,
	const posix_spawn_file_actions_t*,
	const posix_spawnattr_t* restrict,
	char* const [restrict], char* const [restrict]);

#endif /* ! __SPAWN_H__ */
