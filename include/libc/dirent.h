#ifndef __DIRENT_H__
#define __DIRENT_H__

/*
 * MIT License
 *
 * include/libc/dirent.h
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

#define NAME_MAX (255)

int alphasort(const struct dirent** d0, const struct dirent** d1);
int closedir(DIR* dir);
int dirfd(DIR* dir);
DIR* fdopendir(int fd);
DIR* opendir(const char* path);
struct dirent* readdir(DIR* dir);
int readdir_r(DIR* restrict dir, struct dirent* restrict entry,
	struct dirent** restrict result);
void rewinddir(DIR* dir);
int scandir(const char* path, struct dirent*** list,
	int (*sel)(const struct dirent*),
	int (*cmp)(const struct dirent**, const struct dirent**));
void seekdir(DIR* dir, long loc);
long telldir(DIR* dir);

#endif /* ! __DIRENT_H__ */
