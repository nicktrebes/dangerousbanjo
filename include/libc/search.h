#ifndef __SEARCH_H__
#define __SEARCH_H__

/*
 * MIT License
 *
 * include/libc/search.h
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

typedef enum { FIND, ENTER } ACTION;
typedef enum { preorder, postorder, endorder, leaf } VISIT;

int hcreate(size_t);
void hdestroy(void);
ENTRY* hsearch(ENTRY, ACTION);
void insque(void*, void*);
void* lfind(const void*, const void*, size_t*,
	size_t, int (*)(const void*, const void*));
void* lsearch(const void*, void*, size_t*,
	size_t, int (*)(const void*, const void*));
void remque(void*);
void* tdelete(const void* restrict, void** restrict,
	int(*)(const void*, const void*));
void* tfind(const void*, void* const*,
	int(*)(const void*, const void*));
void* tsearch(const void*, void**,
	int(*)(const void*, const void*));
void twalk(const void*,
	void (*)(const void*, VISIT, int ));

#endif /* ! __SEARCH_H__ */
