#ifndef __GLOB_H__
#define __GLOB_H__

/*
 * MIT License
 *
 * include/libc/glob.h
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

#define GLOB_APPEND   (1<<0)
#define GLOB_DOOFFS   (1<<1)
#define GLOB_ERR      (1<<2)
#define GLOB_MARK     (1<<3)
#define GLOB_NOCHECK  (1<<4)
#define GLOB_NOESCAPE (1<<5)
#define GLOB_NOSORT   (1<<6)

enum {
	GLOB_ABORTED,
	GLOB_NOMATCH,
	GLOB_NOSPACE
};

int glob(const char* restrict, int, int(*)(const char*, int), glob_t* restrict);
void globfree(glob_t* glob);

#endif /* ! __GLOB_H__ */
