#ifndef __FTW_H__
#define __FTW_H__

/*
 * MIT License
 *
 * include/libc/ftw.h
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

#include <sys/stat.h>

enum {
	FTW_F,
	FTW_D,
	FTW_DNR,
	FTW_DP,
	FTW_NS,
	FTW_SL,
	FTW_SLN
};

enum {
	FTW_PHYS,
	FTW_MOUNT,
	FTW_DEPTH,
	FTW_CHDIR
};

int ftw(const char*, int (*)(const char*, const struct stat*, int), int);
int nftw(const char*, int (*)(const char*, const struct stat*, int, struct FTW*), int, int);

#endif /* ! __FTW_H__ */
