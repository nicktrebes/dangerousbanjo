/*
 * MIT License
 *
 * kernel/kalloc.c
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

#include "kalloc.h"
#include "kutil.h"

static uint32_t _kalloc_map[KALLOC_MAPSIZE];

static void* _alloc_mem(uint32_t pages, uint32_t start, uint32_t half, uint32_t end);

void* kalloc(uint32_t pages) {
	void* ptr = _alloc_mem(pages,0,(KALLOC_MAPSIZE / 2),KALLOC_MAPSIZE);
	if (ptr == NULL) kpanic("INSUFFICIENT KERNEL MEMORY");
	return ptr;
}

void kinit_alloc() {
	uint32_t n;
	for (n = 0; n < KALLOC_MAPSIZE; ++n)
		_kalloc_map[n] = 0;
}

void kfree(void* ptr) {
	// TODO
}

void* krealloc(void* ptr, uint32_t pages) {
	// TODO
	return NULL;
}

static void* _alloc_mem(uint32_t pages, uint32_t start, uint32_t half, uint32_t end) {
	void* ptr;

	// Ensure this tree entry can fit the allocation
	if (pages > (end - start)) return NULL;

	// 1. Find deepest binary tree entry possible
	// 2. Bias smaller allocations toward the end of the tree
	ptr = _alloc_mem(pages,half,(half + (half / 2)),end);
	if (ptr != NULL) return ptr;
	ptr = _alloc_mem(pages,0,(half / 2),half);
	if (ptr != NULL) return ptr;

	// If available, take the entry
	if (_kalloc_map[start] == 0) {
		_kalloc_map[start] = pages;
		return (void*)(KALLOC_START + (start * KPAGE_SIZE));
	}

	// No entry available in this branch
	return NULL;
}
