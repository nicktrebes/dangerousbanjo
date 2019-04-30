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
static uint32_t _kalloc_maxblock;

static void* _kalloc(uint32_t idx, uint32_t size, uint32_t req);

void* kalloc(uint32_t pages) {
	uint32_t n;
	for (n = 0; n < KALLOC_MAPSIZE; n += _kalloc_maxblock) {
		void* ptr = _kalloc(n,_kalloc_maxblock,pages);
		if (ptr != NULL) return ptr;
	}

	kpanic("INSUFFICIENT KERNEL MEMORY");
	return NULL;
}

void kinit_alloc() {
	uint32_t n;

	_kalloc_maxblock = 1;
	while ((KALLOC_MAPSIZE & _kalloc_maxblock) == 0)
		_kalloc_maxblock <<= 1;

	for (n = 0; n < KALLOC_MAPSIZE; ++n)
		_kalloc_map[n] = ((n % _kalloc_maxblock) ? 0 : _kalloc_maxblock);
}

void kfree(void* ptr) {
	// TODO
}

void* krealloc(void* src, uint32_t pages) {
	// TODO
	return NULL;
}

static void* _kalloc(uint32_t idx, uint32_t size, uint32_t req) {
	void* ptr;
	uint32_t entry, taken;

	// Ensure this branch is sufficient
	if (size < req) return NULL;

	// Get branch info
	entry = _kalloc_map[idx];
	taken = (entry & 0x80000000);
	entry = (entry & 0x7FFFFFFF);

	// Full-size entry case
	if (entry == size) {
		// Entry is taken
		if (taken) return NULL;

		// Request uses entire entry
		if ((entry >> 1) < req) {
			_kalloc_map[idx] = (0x80000000 | entry);
			return (void*)(KALLOC_START + (idx * KPAGE_SIZE));
		}

		// Split entry
		entry >>= 1;
		_kalloc_map[idx] = entry;
		_kalloc_map[idx + entry] = entry;
	}

	// Try buddy entries
	size >>= 1;
	ptr = _kalloc(idx,size,req);
	if (ptr != NULL) return ptr;
	return _kalloc((idx + size),size,req);
}
