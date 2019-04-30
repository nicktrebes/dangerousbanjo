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
static void _kfree(uint32_t idx, uint32_t size);
static int _krealloc(uint32_t idx, uint32_t req, uint32_t* old);

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
	uint32_t idx = ((((uint32_t)ptr) - KALLOC_START) / KPAGE_SIZE);
	uint32_t n, size = _kalloc_map[idx];
	if (size) {
		for (n = 0; n < size; ++n)
			kpage_umap((((uint32_t)ptr) + (n * KPAGE_SIZE)),1);
		_kfree(idx,_kalloc_maxblock);
	}
}

void* krealloc(void* src, uint32_t pages) {
	void* dst;
	uint32_t n, old = 0;
	uint32_t idx = ((((uint32_t)src) - KALLOC_START) / KPAGE_SIZE);

	if (pages == 0) {
		kfree(src);
		return NULL;
	} else if (_krealloc(idx,pages,&old)) {
		return src;
	}

	dst = kalloc(pages);
	if (dst == NULL) return NULL;
	for (n = 0; (n < old) && (n < pages); ++n) {
		uint16_t flags = 0;
		uint32_t paddr = kpage_resolve((((uint32_t)src) + (n * KPAGE_SIZE)),&flags);
		kpage_map((((uint32_t)dst) + (n * KPAGE_SIZE)),paddr,flags);
		kpage_umap((((uint32_t)src) + (n * KPAGE_SIZE)),0);
	}
	for (; n < old; ++n)
		kpage_umap((((uint32_t)src) + (n * KPAGE_SIZE)),1);

	_kfree(idx,_kalloc_maxblock);
	return dst;
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

static void _kfree(uint32_t idx, uint32_t size) {
	// TODO
}

static int _krealloc(uint32_t idx, uint32_t req, uint32_t* old) {
	// TODO: try static reallocation
	return 0;
}
