#ifndef __SYS_STAT_H__
#define __SYS_STAT_H__

/*
 * MIT License
 *
 * include/libc/sys/stat.h
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

#define S_IFBLK  (0x01000)
#define S_IFCHR  (0x02000)
#define S_IFIFO  (0x03000)
#define S_IFREG  (0x04000)
#define S_IFDIR  (0x05000)
#define S_IFLNK  (0x06000)
#define S_IFSOCK (0x07000)
#define S_IFMT   (0x07000)

#define S_ISBLK(m)  ((m & S_IFMT) == S_IFBLK)
#define S_ISCHR(m)  ((m & S_IFMT) == S_IFCHR)
#define S_ISDIR(m)  ((m & S_IFMT) == S_IFDIR)
#define S_ISFIFO(m) ((m & S_IFMT) == S_IFIFO)
#define S_ISREG(m)  ((m & S_IFMT) == S_IFREG)
#define S_ISLNK(m)  ((m & S_IFMT) == S_IFLNK)
#define S_ISSOCK(m) ((m & S_IFMT) == S_IFSOCK)

#define S_IXOTH (01)
#define S_IWOTH (02)
#define S_IROTH (04)
#define S_IRWXO (07)
#define S_IXGRP (010)
#define S_IWGRP (020)
#define S_IRGRP (040)
#define S_IRWXG (070)
#define S_IXUSR (0100)
#define S_IWUSR (0200)
#define S_IRUSR (0400)
#define S_IRWXU (0700)
#define S_ISVTX (01000)
#define S_ISGID (02000)
#define S_ISUID (04000)

#define UTIME_NOW  (0x3B9ACA00)
#define UTIME_OMIT (0x3B9ACA01)

int chmod(const char* path, mode_t mode);
int fchmod(int fd, mode_t mode);
int fchmodat(int fd, const char* path, mode_t mode, int flags);
int fstat(int fd, struct stat* buf);
int fstatat(int fd, const char* restrict path, struct stat* restrict buf, int flags);
int futimens(int fd, const struct timespec times[2]);
int lstat(const char* restrict path, struct stat* restrict buf);
int mkdir(const char* path, mode_t mode);
int mkdirat(int fd, const char* path, mode_t mode);
int mkfifo(const char* path, mode_t mode);
int mkfifoat(int fd, const char* path, mode_t mode);
int mknod(const char* path, mode_t mode, dev_t dev);
int mknodat(int fd, const char* path, mode_t mode, dev_t dev);
int stat(const char* restrict path, struct stat* buf);
mode_t umask(mode_t mode);
int utimensat(int fd, const char* path, const struct timespec times[2], int flags);

#endif /* ! __SYS_STAT_H__ */
