#ifndef __UNISTD_H__
#define __UNISTD_H__

/*
 * MIT License
 *
 * include/libc/unistd.h
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

#include <stddef.h>
#include <sys/types.h>

#define X_OK (01)
#define W_OK (02)
#define R_OK (04)
#define F_OK (010)

enum {
	_PC_2_SYMLINKS,
	_PC_ALLOC_SIZE_MIN,
	_PC_ASYNC_IO,
	_PC_CHOWN_RESTRICTED,
	_PC_FILESIZEBITS,
	_PC_LINK_MAX,
	_PC_MAX_CANON,
	_PC_MAX_INPUT,
	_PC_NAME_MAX,
	_PC_NO_TRUNC,
	_PC_PATH_MAX,
	_PC_PIPE_BUF,
	_PC_PRIO_IO,
	_PC_REC_INCR_XFER_SIZE,
	_PC_REC_MAX_XFER_SIZE,
	_PC_REC_MIN_XFER_SIZE,
	_PC_REC_XFER_ALIGN,
	_PC_SYMLINK_MAX,
	_PC_SYNC_IO,
	_PC_TIMESTAMP_RESOLUTION,
	_PC_VDISABLE
};

enum {
	_SC_2_C_BIND,
	_SC_2_C_DEV,
	_SC_2_CHAR_TERM,
	_SC_2_FORT_DEV,
	_SC_2_FORT_RUN,
	_SC_2_LOCALEDEF,
	_SC_2_PBS,
	_SC_2_PBS_ACCOUNTING,
	_SC_2_PBS_CHECKPOINT,
	_SC_2_PBS_LOCATE,
	_SC_2_PBS_MESSAGE,
	_SC_2_PBS_TRACK,
	_SC_2_SW_DEV,
	_SC_2_UPE,
	_SC_2_VERSION,
	_SC_ADVISORY_INFO,
	_SC_AIO_LISTIO_MAX,
	_SC_AIO_MAX,
	_SC_AIO_PRIO_DELTA_MAX,
	_SC_ARG_MAX,
	_SC_ASYNCHRONOUS_IO,
	_SC_ATEXIT_MAX,
	_SC_BARRIERS,
	_SC_BC_BASE_MAX,
	_SC_BC_DIM_MAX,
	_SC_BC_SCALE_MAX,
	_SC_BC_STRING_MAX,
	_SC_CHILD_MAX,
	_SC_CLK_TCK,
	_SC_CLOCK_SELECTION,
	_SC_COLL_WEIGHTS_MAX,
	_SC_CPUTIME,
	_SC_DELAYTIMER_MAX,
	_SC_EXPR_NEST_MAX,
	_SC_FSYNC,
	_SC_GETGR_R_SIZE_MAX,
	_SC_GETPW_R_SIZE_MAX,
	_SC_HOST_NAME_MAX,
	_SC_IOV_MAX,
	_SC_IPV6,
	_SC_JOB_CONTROL,
	_SC_LINE_MAX,
	_SC_LOGIN_NAME_MAX,
	_SC_MAPPED_FILES,
	_SC_MEMLOCK,
	_SC_MEMLOCK_RANGE,
	_SC_MEMORY_PROTECTION,
	_SC_MESSAGE_PASSING,
	_SC_MONOTONIC_CLOCK,
	_SC_MQ_OPEN_MAX,
	_SC_MQ_PRIO_MAX,
	_SC_NGROUPS_MAX,
	_SC_OPEN_MAX,
	_SC_PAGE_SIZE,
	_SC_PRIORITIZED_IO,
	_SC_PRIORITY_SCHEDULING,
	_SC_RAW_SOCKETS,
	_SC_RE_DUP_MAX,
	_SC_READER_WRITER_LOCKS,
	_SC_REALTIME_SIGNALS,
	_SC_REGEXP,
	_SC_RTSIG_MAX,
	_SC_SAVED_IDS,
	_SC_SEM_NSEMS_MAX,
	_SC_SEM_VALUE_MAX,
	_SC_SEMAPHORES,
	_SC_SHARED_MEMORY_OBJECTS,
	_SC_SHELL,
	_SC_SIGQUEUE_MAX,
	_SC_SPAWN,
	_SC_SPIN_LOCKS,
	_SC_SPORADIC_SERVER,
	_SC_SS_REPL_MAX,
	_SC_STREAM_MAX,
	_SC_SYMLOOP_MAX,
	_SC_SYNCHRONIZED_IO,
	_SC_THREAD_ATTR_STACKADDR,
	_SC_THREAD_ATTR_STACKSIZE,
	_SC_THREAD_CPUTIME,
	_SC_THREAD_DESTRUCTOR_ITERATIONS,
	_SC_THREAD_KEYS_MAX,
	_SC_THREAD_PRIO_INHERIT,
	_SC_THREAD_PRIO_PROTECT,
	_SC_THREAD_PRIORITY_SCHEDULING,
	_SC_THREAD_PROCESS_SHARED,
	_SC_THREAD_ROBUST_PRIO_INHERIT,
	_SC_THREAD_ROBUST_PRIO_PROTECT,
	_SC_THREAD_SAFE_FUNCTIONS,
	_SC_THREAD_SPORADIC_SERVER,
	_SC_THREAD_STACK_MIN,
	_SC_THREAD_THREADS_MAX,
	_SC_THREADS,
	_SC_TIMEOUTS,
	_SC_TIMER_MAX,
	_SC_TIMERS,
	_SC_TRACE,
	_SC_TRACE_EVENT_FILTER,
	_SC_TRACE_EVENT_NAME_MAX,
	_SC_TRACE_INHERIT,
	_SC_TRACE_LOG,
	_SC_TRACE_NAME_MAX,
	_SC_TRACE_SYS_MAX,
	_SC_TRACE_USER_EVENT_MAX,
	_SC_TTY_NAME_MAX,
	_SC_TYPED_MEMORY_OBJECTS,
	_SC_TZNAME_MAX,
	_SC_V7_ILP32_OFF32,
	_SC_V7_ILP32_OFFBIG,
	_SC_V7_LP64_OFF64,
	_SC_V7_LPBIG_OFFBIG,
	_SC_V6_ILP32_OFF32,
	_SC_V6_ILP32_OFFBIG,
	_SC_V6_LP64_OFF64,
	_SC_V6_LPBIG_OFFBIG,
	_SC_VERSION,
	_SC_XOPEN_CRYPT,
	_SC_XOPEN_ENH_I18N,
	_SC_XOPEN_REALTIME,
	_SC_XOPEN_REALTIME_THREADS,
	_SC_XOPEN_SHM,
	_SC_XOPEN_STREAMS,
	_SC_XOPEN_UNIX,
	_SC_XOPEN_UUCP,
	_SC_XOPEN_VERSION
};

#define _SC_PAGESIZE (_SC_PAGE_SIZE)

enum {
	F_LOCK,
	F_TEST,
	F_TLOCK,
	F_ULOCK
};

enum {
	SEEK_SET,
	SEEK_CUR,
	SEEK_END
};

enum {
	STDIN_FILENO,
	STDOUT_FILENO,
	STDERR_FILENO
};

extern char** environ;
extern char* optarg;
extern int opterr, optind, optopt;

int access(const char* path, int flags);
unsigned alarm(unsigned seconds);
int chdir(const char* path);
int chown(const char* path, uid_t owner, gid_t group);
int close(int fd);
size_t confstr(int name, char* buf, size_t len);
char* crypt(const char* key, const char* salt);
int dup(int fd);
int dup2(int fd0, int fd1);
void _exit(int status) __noreturn;
void encrypt(char block[64], int edflag);
int execl(const char* path, const char* arg, ...);
int execle(const char* path, const char* arg, ...);
int execlp(const char* file, const char* arg, ...);
int execv(const char* path, char* const argv[]);
int execve(const char* path, char* const argv[], char* const envp[]);
int execvp(const char* file, char* const argv[]);
int faccessat(int fd, const char* path, int mode, int flags);
int fchdir(int fd);
int fchown(int fd, uid_t owner, gid_t group);
int fchownat(int fd, const char* path, uid_t owner, gid_t group, int flags);
int fdatasync(int fd);
int fexecve(int fd, char* const argv[], char* const envp[]);
pid_t fork(void);
long fpathconf(int fd, int name);
int fsync(int fd);
int ftruncate(int fd, off_t length);
char* getcwd(char* buf, size_t len);
gid_t getegid(void);
uid_t geteuid(void);
gid_t getgid(void);
int getgroups(int size, gid_t list[]);
long gethostid(void);
int gethostname(char* buf, size_t len);
char* getlogin(void);
int getlogin_r(char* buf, size_t len);
int getopt(int argc, char* const argv[], const char* opts);
pid_t getpgid(pid_t pid);
pid_t getpgrp(void);
pid_t getpid(void);
pid_t getppid(void);
pid_t getsid(pid_t pid);
uid_t getuid(void);
int isatty(int fd);
int lchown(const char* path, uid_t owner, gid_t group);
int link(const char* path0, const char* path1);
int linkat(int fd0, const char* path0, int fd1, const char* path1, int flags);
int lockf(int fd, int cmd, off_t len);
off_t lseek(int fd, off_t offset, int whence);
int nice(int incr);
long pathconf(const char* path, int name);
int pause(void);
int pipe(int fd[2]);
ssize_t pread(int fd, void* buf, size_t len, off_t off);
ssize_t pwrite(int fd, const void* buf, size_t len, off_t off);
ssize_t read(int fd, void* buf, size_t len);
ssize_t readlink(const char* restrict path, char* restrict buf, size_t len);
ssize_t readlinkat(int fd, const char* restrict path, char* restrict buf, size_t len);
int rmdir(const char* path);
int setegid(gid_t egid);
int seteuid(uid_t euid);
int setgid(gid_t gid);
int setpgid(pid_t pid, pid_t pgid);
pid_t setpgrp(void);
int setregid(gid_t rgid, gid_t egid);
int setreuid(uid_t ruid, uid_t euid);
pid_t setsid(void);
int setuid(uid_t uid);
unsigned sleep(unsigned seconds);
void swab(const void* restrict src, void* restrict dst, ssize_t nbytes);
int symlink(const char* path0, const char* path1);
int symlinkat(const char* path0, int fd, const char* path1);
void sync(void);
long sysconf(int name);
pid_t tcgetpgrp(int fd);
int tcsetpgrp(int fd, pid_t pgrp);
int truncate(const char* path, off_t length);
char* ttyname(int fd);
int ttyname_r(int fd, char* buf, size_t len);
int unlink(const char* path);
int unlinkat(int fd, const char* path, int flags);
ssize_t write(int fd, const void* buf, size_t len);

#endif /* ! __UNISTD_H__ */
